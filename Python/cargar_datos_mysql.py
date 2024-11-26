import pandas as pd
import mysql.connector

# Función para conectar a la base de datos MySQL
def conectar_bd():
    return mysql.connector.connect(
        host="db5016660208.hosting-data.io",  # Ejemplo: mariadb.ionos.es
        user="dbu1498781",
        password="kyXbb5c*GPgK5W*",
        database="dbs13499224"
    )

# Función para cargar los datos de los archivos Excel a la base de datos
def cargar_datos():
    archivos_excel = [
        "AudNacRegCSV.csv",  # Añade tus archivos aquí
        # "otro_archivo.xlsx",
        # ...
    ]
    
    connection = conectar_bd()
    cursor = connection.cursor()

    for archivo in archivos_excel:
        # Leer los datos del archivo
        df = pd.read_csv(archivo, delimiter=';', encoding='latin1')
        df['Fecha'] = pd.to_datetime(df['Fecha'], errors='coerce')  # Asegurarse de que la fecha está en formato correcto

        # Insertar los datos de cada fila en la base de datos
        for _, row in df.iterrows():
            cursor.execute("""
                INSERT INTO conciertos (Título, Sala, Fecha, Hora, Más información, Programa, Precio, Imagen)
                VALUES (%s, %s, %s, %s, %s, %s, %s, %s)
            """, (row['Título'], row['Sala'], row['Fecha'], row['Hora'], row['Más información'], row['Programa'], row['Precio'], row['Imagen']))

        connection.commit()  # Confirmar la transacción

    cursor.close()
    connection.close()

# Llamar a la función para cargar los datos
if __name__ == "__main__":
    cargar_datos()
