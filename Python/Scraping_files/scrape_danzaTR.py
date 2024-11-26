import requests
from bs4 import BeautifulSoup
import time
import pandas as pd
from datetime import datetime
import os

# Definir los directorios
DIRECTORY = '/home/pamarti2/42_official_repo_git/42Madrid/Python/Regs'
DIRECTORY2 = '/home/pamarti2/42_official_repo_git/42Madrid/Python/Regs/Logs'

# Especificar las rutas de los archivos
EXCEL_FILE = os.path.join(DIRECTORY, 'TRReg.xlsx')
LOG_FILE = os.path.join(DIRECTORY2, 'logTeatroReal.txt')

BASE_URL = 'https://www.teatroreal.es/es/temporada-actual/danza#toContent'

def extract_opera_info(url):
    try:
        response = requests.get(url)
        response.raise_for_status()  # Verifica que la solicitud fue exitosa
        soup = BeautifulSoup(response.content, 'html.parser')
        
        operas = []

        # Buscar el bloque que contiene las óperas
        opera_blocks = soup.find_all('div', class_='col-xs-6 col-sm-4 col-md-3')
        print(f"Número de bloques de espectáculos de danza encontrados: {len(opera_blocks)}")

        for block in opera_blocks:
            try:
                # Extraer el enlace de la ópera
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

                # Extraer la información de la ópera y las funciones
                program, functions = extract_program_and_functions(more_info_url) if more_info_url != 'No disponible' else ('No disponible', [])

                # Filtrar funciones duplicadas y eliminar las que tienen fecha no disponible
                filtered_functions = []
                seen_functions = set()
                for function in functions:
                    if "Fecha no disponible" not in function:
                        if function not in seen_functions:
                            seen_functions.add(function)
                            filtered_functions.append(function)

                # Extraer la imagen
                image_url = extract_image(more_info_url) if more_info_url != 'No disponible' else 'No disponible'

                # Crear un evento para cada función
                for function in filtered_functions:
                    operas.append({
                        'Título': title,
                        'Fecha': date,
                        'Más información': more_info_url,
                        'Programa': program,
                        'Función': function,
                        'Precio': more_info_url,  # La URL del evento como precio
                        'Imagen': image_url
                    })

                # Pausa de 1 segundo entre cada solicitud
                time.sleep(1)

            except Exception as e:
                print(f"Error al procesar una ópera: {e}")

        return operas
    except requests.RequestException as e:
        print(f"Error al hacer la solicitud para {url}: {e}")
        return []

def extract_program_and_functions(url):
    try:
        response = requests.get(url)
        response.raise_for_status()  # Verifica que la solicitud fue exitosa
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Buscar la sección de texto del programa
        program_section = soup.find('div', class_='wrap-text-free collapsible-mobile')
        if program_section:
            program_paragraphs = program_section.find_all('p')
            program = ' '.join(p.get_text(strip=True) for p in program_paragraphs)
            print(f"Programa extraído de {url}: {program[:100]}...")  # Muestra los primeros 100 caracteres del programa
        else:
            program = 'No disponible'
            print(f"Sección de programa no encontrada en {url}")

        # Extraer las funciones
        functions = []
        functions_sections = soup.find_all('div', class_='functions-show__block')
        if functions_sections:
            seen_functions = set()
            for functions_section in functions_sections:
                # Si la clase contiene "hide", entonces se procesa igualmente
                function_items = functions_section.find_all('div', class_='functions-show__block--item')
                for item in function_items:
                    date_tag = item.find('div', class_='functions-show__block--item-date')
                    hour_tag = item.find('div', class_='functions-show__block--item-hour')
                    date = date_tag.get_text(strip=True) if date_tag else 'Fecha no disponible'
                    hour = hour_tag.get_text(strip=True) if hour_tag else 'Hora no disponible'
                    function = f"{date} - {hour}"
                    
                    # Añadir a la lista solo si no se ha visto antes
                    if function not in seen_functions and "Fecha no disponible" not in function:
                        seen_functions.add(function)
                        functions.append(function)
                        print(f"Función extraída de {url}: {function}")
        else:
            print(f"Sección de funciones no encontrada en {url}")
        
        return program, functions
    except requests.HTTPError as http_err:
        print(f"Error HTTP al hacer la solicitud para {url}: {http_err}")
        return 'No disponible', []
    except Exception as e:
        print(f"Error al extraer detalles del programa y funciones de {url}: {e}")
        return 'No disponible', []

def extract_image(url):
    try:
        response = requests.get(url)
        response.raise_for_status()  # Verifica que la solicitud fue exitosa
        soup = BeautifulSoup(response.content, 'html.parser')

        # Extraer la imagen
        image_url = 'No disponible'
        image_tag = soup.find('div', class_='page-thumb-artist__block--img')
        if image_tag:
            # Buscar el primer srcset
            source_tag = image_tag.find('source')
            if source_tag:
                srcset = source_tag.get('srcset')
                if srcset:
                    # Extraer la URL
                    srcset_parts = srcset.split()
                    if srcset_parts:
                        relative_src = srcset_parts[0]
                        image_url = f"http://www.teatroreal.es{relative_src}"
                        print(f"Imagen extraída de {url}: {image_url}")
        return image_url
    except requests.HTTPError as http_err:
        print(f"Error HTTP al hacer la solicitud para {url}: {http_err}")
        return 'No disponible'
    except Exception as e:
        print(f"Error al extraer imagen de {url}: {e}")
        return 'No disponible'

def read_existing_data(filename, sheet_name):
    try:
        return pd.read_excel(filename, sheet_name=sheet_name)
    except FileNotFoundError:
        return pd.DataFrame()
    except ValueError:  # Si la hoja no existe
        return pd.DataFrame()

def write_log(message):
    with open(LOG_FILE, 'a') as log_file:
        log_file.write(f"{datetime.now()}: {message}\n")

def main():
    print("Inicio de la extracción de datos de espectáculos de danza...")
    # Extraer los datos actuales de óperas
    current_operas = extract_opera_info(BASE_URL)
    current_df = pd.DataFrame(current_operas)

    print(f"Datos extraídos: {current_df}")

    # Leer los datos existentes del archivo Excel
    existing_df = read_existing_data(EXCEL_FILE, 'Danza')

    # Comparar los datos y actualizar si hay cambios
    if not existing_df.empty:
        changes_made = False
        for index, row in current_df.iterrows():
            if index < len(existing_df) and not row.equals(existing_df.loc[index]):
                changes_made = True
                write_log(f"Se actualizó la ópera '{row['Título']}' con fecha '{row['Fecha']}'.")
        
        if not changes_made:
            write_log("No se encontraron cambios en los datos de las danzas.")
    else:
        write_log("Archivo Excel o pestaña 'Danza' no encontrados. Creando nuevo archivo/pestaña.")

    # Guardar los datos actualizados en el archivo Excel
    with pd.ExcelWriter(EXCEL_FILE, mode='a', if_sheet_exists='replace') as writer:
        current_df.to_excel(writer, sheet_name='Danza', index=False)
    write_log("Datos de óperas guardados/actualizados en el archivo Excel.")

    # Imprimir los datos de las óperas
    for opera in current_operas:
        print(f"Título: {opera['Título']}")
        print(f"Fecha: {opera['Fecha']}")
        print(f"Más información: {opera['Más información']}")
        print(f"Programa: {opera['Programa']}")
        print(f"Función: {opera['Función']}")
        print(f"Precio: {opera['Precio']}")
        print(f"Imagen: {opera['Imagen']}")
        print("-------------")

if __name__ == "__main__":
    main()
