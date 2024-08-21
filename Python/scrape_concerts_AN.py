import requests
from bs4 import BeautifulSoup
from datetime import datetime
import pandas as pd
import os

# Rutas de los archivos
STATE_FILE = 'AudNacReg.xlsx'
LOG_FILE = 'logAudNac.txt'

def clean_text(element):
    # Elimina etiquetas <br/> y espacios adicionales
    text = element.get_text(separator=' ').strip()
    return ' '.join(text.split())

def scrape_event_details(more_info_url):
    try:
        response = requests.get(more_info_url)
        response.raise_for_status()  # Asegurarse de que la solicitud fue exitosa

        soup = BeautifulSoup(response.content, 'html.parser')

        # Buscar el div con la clase 'content' que contiene los <h4>
        content_div = soup.find('div', class_='content')
        program = 'No disponible'
        if content_div:
            # Extraer todos los <h4> dentro del div 'content'
            program_tags = content_div.find_all('h4', style='text-align: center;')
            if program_tags:
                program = '\n'.join(clean_text(tag) for tag in program_tags)

        # Extraer el precio
        price_tag = soup.find('div', class_='rightColumn__item__text')
        price = price_tag.find('strong').text.strip() if price_tag and price_tag.find('strong') else 'No disponible'

        return program, price

    except requests.RequestException as e:
        print(f"Error al hacer la solicitud para {more_info_url}: {e}")
        return 'No disponible', 'No disponible'
    except Exception as e:
        print(f"Error al extraer detalles del evento: {e}")
        return 'No disponible', 'No disponible'

def parse_date_and_time(date_str):
    """Divide la cadena de fecha y hora en dos partes: fecha y hora."""
    try:
        # Suponiendo que la fecha y hora están separadas por 'T'
        date_part, time_part = date_str.split('T', 1)
        return date_part, time_part
    except ValueError:
        return date_str, 'No disponible'

def scrape_page(url):
    try:
        response = requests.get(url)
        response.raise_for_status()  # Asegurarse de que la solicitud fue exitosa

        soup = BeautifulSoup(response.content, 'html.parser')
        
        concerts = soup.find_all('li', class_='col-xs-12 col-sm-6 col-md-4 mb-5')
        data = []
        
        for concert in concerts:
            try:
                img_tag = concert.find('img')
                img_url = img_tag['src'] if img_tag else 'No disponible'
                
                hall_tag = concert.find('p', class_='camara location')
                hall = hall_tag.find('span').text if hall_tag and hall_tag.find('span') else 'No disponible'
                
                # Ajustar la información de la sala
                if hall != 'Sala de Cámara':
                    hall = 'Sala Sinfónica'
                
                title_tag = concert.find('h3', class_='eventitem__title')
                title = title_tag.text if title_tag else 'No disponible'
                
                date_tag = concert.find('span', class_='pat-localmoment')
                date_str = date_tag.text if date_tag else 'No disponible'
                
                # Dividir la fecha y hora en columnas separadas
                date, time = parse_date_and_time(date_str)
                
                more_info_tag = title_tag.find('a') if title_tag else None
                more_info_url = more_info_tag['href'] if more_info_tag else 'No disponible'
                
                # Asegúrate de que el URL esté completo
                if more_info_url and not more_info_url.startswith('http'):
                    more_info_url = f"https://www.auditorionacional.mcu.es{more_info_url}"
                
                # Extraer detalles adicionales desde la página vinculada
                program, price = scrape_event_details(more_info_url) if more_info_url != 'No disponible' else ('No disponible', 'No disponible')
                
                data.append({
                    'Título': title,
                    'Sala': hall,
                    'Fecha': date,
                    'Hora': time,
                    'Más información': more_info_url,
                    'Programa': program,
                    'Precio': price,
                    'Imagen': img_url
                })
            except Exception as e:
                print(f"Error al procesar un evento: {e}")
        
        return data

    except requests.RequestException as e:
        print(f"Error al hacer la solicitud para {url}: {e}")
        return []
    except Exception as e:
        print(f"Error al acceder a {url}: {e}")
        return []

def scrape_with_pagination(base_url, pages=25):
    all_data = []
    for _ in range(pages):
        data = scrape_page(base_url)
        if not data:
            break
        all_data.extend(data)
        try:
            response = requests.get(base_url)
            response.raise_for_status()  # Asegurarse de que la solicitud fue exitosa

            soup = BeautifulSoup(response.content, 'html.parser')
            next_page_tag = soup.find('li', class_='next')
            if next_page_tag:
                next_page_url = next_page_tag.find('a')['href']
                print(f"Siguiendo al siguiente enlace: {next_page_url}")
                base_url = next_page_url
            else:
                print("No hay más páginas.")
                break

        except requests.RequestException as e:
            print(f"Error al hacer la solicitud para la página siguiente: {e}")
            break
        except Exception as e:
            print(f"Error al acceder a la página siguiente: {e}")
            break
    
    return all_data

def save_to_excel(data):
    df = pd.DataFrame(data)
    df.to_excel(STATE_FILE, index=False)

def read_from_excel():
    if os.path.exists(STATE_FILE):
        df = pd.read_excel(STATE_FILE)
        return df.to_dict('records')
    return []

def log_execution(new_data, changes_detected):
    now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    with open(LOG_FILE, 'a', encoding='utf-8') as log_file:
        log_file.write(f"Verificación - {now}\n")
        if changes_detected:
            log_file.write(f"CAMBIO DETECTADO - {now}\n")
            for event in new_data:
                log_file.write(f"Título: {event['Título']}\n")
                log_file.write(f"Sala: {event['Sala']}\n")
                log_file.write(f"Fecha: {event['Fecha']}\n")
                log_file.write(f"Hora: {event['Hora']}\n")
                log_file.write(f"Más información: {event['Más información']}\n")
                log_file.write(f"Programa: {event['Programa']}\n")
                log_file.write(f"Precio: {event['Precio']}\n")
                log_file.write(f"Imagen: {event['Imagen']}\n")
                log_file.write("-------------\n")
        else:
            log_file.write("Sin cambios\n")
        log_file.write("\n")

def main():
    base_url = 'https://www.auditorionacional.mcu.es/es/programacion'
    new_data = scrape_with_pagination(base_url, pages=26)

    if os.path.exists(STATE_FILE):
        previous_data = read_from_excel()
        previous_df = pd.DataFrame(previous_data)
        new_df = pd.DataFrame(new_data)

        # Comparar los datos
        if not previous_df.equals(new_df):
            save_to_excel(new_data)
            log_execution(new_data, changes_detected=True)
        else:
            log_execution(new_data, changes_detected=False)
    else:
        # Guardar los datos en el archivo Excel por primera vez
        save_to_excel(new_data)
        log_execution(new_data, changes_detected=True)
    
    # Imprimir los datos en la terminal
    for event in new_data:
        print(f"Título: {event['Título']}")
        print(f"Sala: {event['Sala']}")
        print(f"Fecha: {event['Fecha']}")
        print(f"Hora: {event['Hora']}")
        print(f"Más información: {event['Más información']}")
        print(f"Programa: {event['Programa']}")
        print(f"Precio: {event['Precio']}")
        print(f"Imagen: {event['Imagen']}")
        print("-------------")

if __name__ == "__main__":
    main()
