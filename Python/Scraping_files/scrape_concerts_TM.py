import requests
from bs4 import BeautifulSoup
import re
import pandas as pd  # Para guardar la información en Excel
import os  # Para manejar rutas

# URL de la página principal
url = "https://www.teatromonumental.es"

# Lista para almacenar los datos
data = []

# Realizamos la petición HTTP
response = requests.get(url)

# Verificamos que la petición fue exitosa
if response.status_code == 200:
    # Parseamos el contenido HTML
    soup = BeautifulSoup(response.text, 'html.parser')

    # Encontramos el grid con los eventos
    events_grid = soup.find_all("div", class_="card-content")

    # Recorremos cada evento dentro del grid
    for event in events_grid:
        # Extraemos la imagen
        image_div = event.find("div", class_="imagen_eventos card-img-top")
        image_url = image_div['style'].split("url('")[1].split("')")[0] if image_div else "No disponible"

        # Extraemos la categoría
        category = event.find("p", class_="card-category")
        category_text = category.text.strip() if category else "No disponible"

        # Extraemos el título
        title = event.find("h5", class_="card-title")
        title_text = title.text.strip() if title else "No disponible"

        # Extraemos el link de compra
        buy_link = event.find("a", class_="btn btn-monumental comprar_boton")
        buy_url = buy_link['href'] if buy_link else "No disponible"

        # Extraemos el link de más información
        info_link = event.find("a", class_="mt-auto btn btn-link f_right info_boton")
        info_url = info_link['href'] if info_link else "No disponible"

        # Extraemos la fecha
        date_span = event.find("span")
        date_text = date_span.text.strip() if date_span else "No disponible"

        # Inicializamos variables para Programa, Precio y Hora
        program_text = "No disponible"
        price_text = "No disponible"
        hour_text = "No disponible"

        # Si tenemos una URL de más información, hacemos un segundo scraping
        if info_url != "No disponible":
            event_response = requests.get(info_url)
            if event_response.status_code == 200:
                event_soup = BeautifulSoup(event_response.text, 'html.parser')

                # Extraemos el programa desde el div con clase box-content
                program_div = event_soup.find("div", class_="box-content")
                program_text = program_div.text.strip() if program_div else "No disponible"

                # Extraemos precio y hora desde el bloque correspondiente
                price_hour_block = event_soup.find("div", class_="col-12 col-md-6 col-lg-6")
                if price_hour_block:
                    # Buscamos texto con el símbolo del euro (€) para el precio
                    price_match = re.search(r'[\d,]+€', price_hour_block.text)
                    price_text = price_match.group() if price_match else "No disponible"

                    # Buscamos texto con ":" para identificar la hora
                    hour_match = re.search(r'\d{1,2}:\d{2}', price_hour_block.text)
                    hour_text = hour_match.group() if hour_match else "No disponible"

        # Añadimos los datos a la lista
        data.append({
            "Título": title_text,
            "Categoría": category_text,
            "Fecha": date_text,
            "Hora": hour_text,
            "Precio": price_text,
            "Imagen": image_url,
            "Programa": program_text,
            "Link de compra": buy_url,
            "Más información": info_url
        })

else:
    print(f"Error al acceder a la página. Código de estado: {response.status_code}")

# Crear un DataFrame de pandas con los datos
df = pd.DataFrame(data)

# Directorio de guardado
save_dir = r"/home/pamarti2/42_official_repo_git/42Madrid/Python/Regs"
os.makedirs(save_dir, exist_ok=True)  # Crea el directorio si no existe

# Nombre del archivo Excel
excel_file = os.path.join(save_dir, "TeaMonReg.xlsx")

# Guardar el DataFrame en el archivo Excel
df.to_excel(excel_file, index=False)

print(f"Información guardada en {excel_file} con éxito.")
