import pandas as pd

def cargar_datos():
    df = pd.read_csv("AudNacRegCSV.csv", delimiter=';', encoding='latin1')
    df['Fecha'] = pd.to_datetime(df['Fecha'], errors='coerce')
    return df
