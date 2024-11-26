import requests
from bs4 import BeautifulSoup
from openpyxl import Workbook
import os  # Para manejar rutas

# URL de la página principal
base_url = "https://www.march.es/es/madrid?date=&type=concierto"

# Headers para las solicitudes HTTP
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36"
}

# Ruta de guardado del archivo Excel
save_dir = "/home/pamarti2/42_official_repo_git/42Madrid/Python/Regs"
os.makedirs(save_dir, exist_ok=True)  # Crea el directorio si no existe
excel_file_path = os.path.join(save_dir, "JuanMarchReg.xlsx")

# Función para extraer datos adicionales desde la página de "Más información"
def extract_concert_details(url):
    try:
        response = requests.get(url, headers=headers)
        if response.status_code == 200:
            soup = BeautifulSoup(response.text, "html.parser")

            # Extraer "Ciclo"
            cycle_tag = soup.find("span", class_="c-titular c-titular-contenido text-uppercase")
            cycle = cycle_tag.get_text(strip=True) if cycle_tag else "Ciclo no disponible"

            # Extraer "Sub-Ciclo"
            sub_cycle_tag = soup.find("span", class_="c-titular c-titular-cuarto-nivel")
            sub_cycle = sub_cycle_tag.get_text(strip=True) if sub_cycle_tag else "Sub-Ciclo no disponible"

            # Extraer "Descripción"
            description_div = soup.find("div", class_="offset-md-1 col-md-10 offset-xxl-2 col-xxl-8 text-center")
            description_tag = description_div.find("p") if description_div else None
            description = description_tag.get_text(strip=True) if description_tag else "Descripción no disponible"

            # Extraer "Fecha"
            date_div = soup.find("div", class_="d-flex align-items-start mb-5 p-acto__fechas")
            date_tag = date_div.find("span", class_="c-enlace__text") if date_div else None
            date = date_tag.get_text(strip=True) if date_tag else "Fecha no disponible"

            # Extraer "Ubicación"
            location_div = soup.find("div", class_="p-acto__detail-item mb-5")
            location_tag = location_div.find("span", class_="c-enlace__text") if location_div else None
            location = location_tag.get_text(strip=True) if location_tag else "Ubicación no disponible"

            return {
                "Ciclo": cycle,
                "Sub-Ciclo": sub_cycle,
                "Descripción": description,
                "Fecha": date,
                "Ubicación": location,
            }
        else:
            return {
                "Ciclo": "Error en la solicitud",
                "Sub-Ciclo": "Error en la solicitud",
                "Descripción": "Error en la solicitud",
                "Fecha": "Error en la solicitud",
                "Ubicación": "Error en la solicitud",
            }
    except Exception as e:
        print(f"Error al acceder a {url}: {e}")
        return {
            "Ciclo": "Error en la solicitud",
            "Sub-Ciclo": "Error en la solicitud",
            "Descripción": "Error en la solicitud",
            "Fecha": "Error en la solicitud",
            "Ubicación": "Error en la solicitud",
        }

# Función principal para extraer los conciertos desde la página principal
def extract_concerts_to_excel():
    response = requests.get(base_url, headers=headers)
    if response.status_code == 200:
        soup = BeautifulSoup(response.text, "html.parser")
        main_container = soup.find("div", class_="snippet-container snippet-container--73 mb-1 js-ver-mas-container")
        
        if main_container:
            concerts = main_container.find_all("div", recursive=False)
            print("Conciertos encontrados...\n")
            
            # Crear el archivo Excel
            workbook = Workbook()
            sheet = workbook.active
            sheet.title = "Conciertos"
            
            # Escribir encabezados en el archivo Excel
            sheet.append([
                "Título", "Más Información", "Imagen", "Ciclo", "Sub-Ciclo", 
                "Descripción", "Fecha", "Ubicación"
            ])
            
            # Procesar cada concierto
            for concert in concerts:
                # Extraer título y URL de "Más información"
                title_tag = concert.find("p", class_="c-titular c-titular-cuarto-nivel c-titular-cuarto-nivel--con-hover mb-0")
                title = title_tag.get_text(strip=True) if title_tag else "Título no disponible"
                link_tag = concert.find("a", class_="mb-2 c-snippet__titular js-snippet__titular")
                relative_url = link_tag.get("href") if link_tag else None
                more_info_url = f"https://www.march.es{relative_url}" if relative_url else None
                
                if more_info_url:
                    print(f"Accediendo a la URL de más información: {more_info_url}")
                else:
                    print("No se encontró la URL de más información.")
                
                # Extraer imagen
                img_tag = concert.find("img", class_="w-100-mobile-small u-objet-fit-complete")
                image_url = img_tag.get("src") if img_tag else "Imagen no disponible"
                
                # Extraer datos adicionales desde la URL de "Más información"
                if more_info_url:
                    extra_details = extract_concert_details(more_info_url)
                else:
                    extra_details = {}

                # Agregar los datos al archivo Excel
                sheet.append([
                    title,
                    more_info_url,
                    image_url,
                    extra_details.get("Ciclo", "Ciclo no disponible"),
                    extra_details.get("Sub-Ciclo", "Sub-Ciclo no disponible"),
                    extra_details.get("Descripción", "Descripción no disponible"),
                    extra_details.get("Fecha", "Fecha no disponible"),
                    extra_details.get("Ubicación", "Ubicación no disponible"),
                ])
            
            # Guardar el archivo Excel en la ruta especificada
            workbook.save(excel_file_path)
            print(f"Datos guardados en '{excel_file_path}'.")
        else:
            print("No se encontraron conciertos en el contenedor principal.")
    else:
        print(f"Error al acceder a la página principal. Código de estado: {response.status_code}")

# Ejecutar la función principal
extract_concerts_to_excel()
