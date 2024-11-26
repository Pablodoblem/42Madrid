import pandas as pd

# Archivos a combinar
archivo1 = 'AudNacReg.xlsx'
archivo2 = 'TRReg.xlsx'

# Leer los archivos
df1 = pd.read_excel(archivo1, engine='openpyxl')
df2 = pd.read_excel(archivo2, engine='openpyxl')

# Normalizar nombres de columnas (opcional: todo en minúsculas)
df1.columns = df1.columns.str.strip().str.lower()
df2.columns = df2.columns.str.strip().str.lower()

# Unificar manualmente columnas similares (ejemplo: "Función" en df2)
equivalencias_columnas = {
    'función': 'funcion',  # Renombramos "Función" para que coincida
    'Más información': 'más información',
    'Información': 'información'

    # Agregar más equivalencias si es necesario
}
df2.rename(columns=equivalencias_columnas, inplace=True)

# Combinar asegurando que se incluyan todas las columnas
df_combinado = pd.concat([df1, df2], axis=0, ignore_index=True, sort=False)

# Rellenar valores vacíos
df_combinado.fillna('null', inplace=True)

# Guardar el archivo combinado
df_combinado.to_excel('archivo_combinado.xlsx', index=False, engine='openpyxl')

print("Archivos combinados correctamente en 'archivo_combinado.xlsx'")
