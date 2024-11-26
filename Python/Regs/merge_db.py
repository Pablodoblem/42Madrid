import pandas as pd
import os

# Función para combinar múltiples archivos Excel
def combinar_archivos_excel(archivos):
    # Lista para almacenar los DataFrames
    dfs = []
    
    # Diccionario para mapear nombres de archivo a valores en la columna "Procedencia"
    procedencia_map = {
        'AudNacReg.xlsx': 'Auditorio Nacional',
        'TRReg.xlsx': 'Teatro Real',
        'TeaMonReg.xlsx': 'Teatro Monumental',
        'JuanMarchReg.xlsx': 'Fundación Juan March'
    }
    
    # Iterar sobre todos los archivos
    for archivo in archivos:
        # Leer todas las hojas del archivo
        hojas = pd.read_excel(archivo, sheet_name=None, engine='openpyxl')
        
        # Iterar sobre cada hoja y agregarla al DataFrame
        for nombre_hoja, df in hojas.items():
            # Normalizar nombres de columnas (eliminar espacios, pasar a minúsculas)
            df.columns = df.columns.str.strip().str.lower()
            
            # Agregar columna "Procedencia" con el valor correspondiente
            df['procedencia'] = procedencia_map.get(archivo, 'Desconocido')
            
            # Agregar a la lista de DataFrames
            dfs.append(df)

    # Unir todos los DataFrames y asegurarse de que todas las columnas estén presentes
    df_combinado = pd.concat(dfs, axis=0, ignore_index=True, sort=False)

    # Rellenar los valores vacíos con 'null'
    df_combinado.fillna('null', inplace=True)

    return df_combinado

# Lista de archivos a combinar
archivos = ['AudNacReg.xlsx', 'TRReg.xlsx', 'TeaMonReg.xlsx', 'JuanMarchReg.xlsx']  # Añadir aquí otros archivos si es necesario

# Combinar los archivos
df_combinado = combinar_archivos_excel(archivos)

# Guardar el archivo combinado
df_combinado.to_excel('archivo_combinado.xlsx', index=False, engine='openpyxl')

print("Archivos combinados correctamente en 'archivo_combinado.xlsx'")
