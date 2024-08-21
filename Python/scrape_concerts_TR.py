import requests
from bs4 import BeautifulSoup
import time
import re
import pandas as pd
from datetime import datetime

BASE_URL = 'https://www.teatroreal.es/es/temporada-actual/conciertos#toContent'
EXCEL_FILE = 'TRReg.xlsx'
LOG_FILE = 'logTeatroReal.txt'

def extract_concert_info(url):
    try:
        response = requests.get(url)
        response.raise_for_status()  # Verifica que la solicitud fue exitosa
        soup = BeautifulSoup(response.content, 'html.parser')
        
        concerts = []

        # Buscar el bloque que contiene los conciertos
        concert_blocks = soup.find_all('div', class_='page-thumb-artist__block block_tr_0 block_lang_tr_es conciertos')

        for block in concert_blocks:
            try:
                # Extraer el enlace del concierto
                link_tag = block.find('a')
                relative_url = link_tag['href'] if link_tag else 'No disponible'
                
                # Limpiar la URL de espacios en blanco y caracteres %20 al final
                more_info_url = relative_url.strip()
                if more_info_url.endswith('%20'):
                    more_info_url = more_info_url[:-3]
                if more_info_url.startswith('/'):
                    more_info_url = f"https://www.teatroreal.es{more_info_url}"

                # Extraer el título
                title_tag = block.find('span', class_='title')
                title = title_tag.get_text(strip=True) if title_tag else 'No disponible'
                
                # Extraer la fecha
                date_tag = block.find('span', class_='date')
                date = date_tag.get_text(strip=True) if date_tag else 'No disponible'

                # Extraer el programa del concierto y la hora
                program, hour = extract_program(more_info_url) if more_info_url != 'No disponible' else ('No disponible', 'No disponible')
                
                # Extraer el precio del concierto
                price = extract_price(more_info_url) if more_info_url != 'No disponible' else 'No disponible'

                # Extraer la imagen del concierto
                image_url = extract_image(more_info_url) if more_info_url != 'No disponible' else 'No disponible'

                concerts.append({
                    'Título': title,
                    'Fecha': date,
                    'Más información': more_info_url,
                    'Información': program,
                    'Hora': hour,
                    'Precio': price,
                    'Imagen': image_url
                })

                # Pausa de 1 segundo entre cada solicitud
                time.sleep(1)

            except Exception as e:
                print(f"Error al procesar un concierto: {e}")

        return concerts
    except requests.RequestException as e:
        print(f"Error al hacer la solicitud para {url}: {e}")
        return []

def extract_program(url):
    try:
        response = requests.get(url)
        response.raise_for_status()  # Verifica que la solicitud fue exitosa
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Buscar la sección de texto del programa
        program_section = soup.find('section', class_='text-intro-show')
        program_paragraphs = program_section.find_all('p') if program_section else []
        program = ' '.join(p.get_text(strip=True) for p in program_paragraphs) if program_paragraphs else 'No disponible'

        # Extraer la hora del programa en formato hh:mm
        hour_match = re.search(r'\b\d{2}:\d{2}\b', program)
        hour = hour_match.group(0) if hour_match else 'No disponible'
        
        return program, hour
    except requests.HTTPError as http_err:
        print(f"Error HTTP al hacer la solicitud para {url}: {http_err}")
        return 'No disponible', 'No disponible'
    except Exception as e:
        print(f"Error al extraer detalles del programa de {url}: {e}")
        return 'No disponible', 'No disponible'

def extract_price(url):
    try:
        response = requests.get(url)
        response.raise_for_status()  # Verifica que la solicitud fue exitosa
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Buscar la sección que contiene el precio
        price_tag = soup.find('span', class_='ticket-col-2')
        price = price_tag.get_text(strip=True) if price_tag else 'No disponible'
        
        return price
    except requests.HTTPError as http_err:
        print(f"Error HTTP al hacer la solicitud para {url}: {http_err}")
        return 'No disponible'
    except Exception as e:
        print(f"Error al extraer detalles del precio de {url}: {e}")
        return 'No disponible'

def extract_image(url):
    try:
        response = requests.get(url)
        response.raise_for_status()  # Verifica que la solicitud fue exitosa
        soup = BeautifulSoup(response.content, 'html.parser')

        # Buscar la sección que contiene la imagen
        image_section = soup.find('div', class_='field field--name-field-imagen field--type-image field--label-hidden field--item')
        if not image_section:
            return 'No disponible'

        # Buscar la imagen de mayor resolución
        picture_tag = image_section.find('picture')
        sources = picture_tag.find_all('source') if picture_tag else []

        highest_res_image_url = ''
        highest_res = 0

        for source in sources:
            srcset = source['srcset']
            if srcset:
                res = int(srcset.split(' ')[-1].split('x')[0])
                if res > highest_res:
                    highest_res = res
                    highest_res_image_url = srcset.split(' ')[0]
                    if highest_res_image_url.startswith('/'):
                        highest_res_image_url = f"https://www.teatroreal.es{highest_res_image_url}"

        return highest_res_image_url if highest_res_image_url else 'No disponible'
        
    except requests.HTTPError as http_err:
        print(f"Error HTTP al hacer la solicitud para {url}: {http_err}")
        return 'No disponible'
    except Exception as e:
        print(f"Error al extraer detalles de la imagen de {url}: {e}")
        return 'No disponible'

def read_existing_data(filename):
    try:
        return pd.read_excel(filename)
    except FileNotFoundError:
        return pd.DataFrame()

def write_log(message):
    with open(LOG_FILE, 'a') as log_file:
        log_file.write(f"{datetime.now()}: {message}\n")

def main():
    # Extraer los datos actuales de conciertos
    current_concerts = extract_concert_info(BASE_URL)
    current_df = pd.DataFrame(current_concerts)

    # Leer los datos existentes del archivo Excel
    existing_df = read_existing_data(EXCEL_FILE)

    # Comparar los datos y actualizar si hay cambios
    if not existing_df.empty:
        changes_made = False
        for index, row in current_df.iterrows():
            if not row.equals(existing_df.loc[index]):
                changes_made = True
                write_log(f"Se actualizó el concierto '{row['Título']}' con fecha '{row['Fecha']}'.")
        
        if not changes_made:
            write_log("No se encontraron cambios en los datos de los conciertos.")
    else:
        write_log("Archivo Excel no encontrado. Creando nuevo archivo.")

    # Guardar los datos actualizados en el archivo Excel
    current_df.to_excel(EXCEL_FILE, index=False)
    write_log("Datos de conciertos guardados/actualizados en el archivo Excel.")

    # Imprimir los datos de los conciertos
    for concert in current_concerts:
        print(f"Título: {concert['Título']}")
        print(f"Fecha: {concert['Fecha']}")
        print(f"Más información: {concert['Más información']}")
        print(f"Información: {concert['Información']}")
        print(f"Hora: {concert['Hora']}")
        print(f"Precio: {concert['Precio']}")
        print(f"Imagen: {concert['Imagen']}")
        print("-------------")

if __name__ == "__main__":
    main()
