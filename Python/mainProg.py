from fastapi import FastAPI, Form
from fastapi.staticfiles import StaticFiles
from fastapi.templating import Jinja2Templates
from fastapi.responses import HTMLResponse
from starlette.requests import Request
import pandas as pd

app = FastAPI()

# Configuración para archivos estáticos
app.mount("/static", StaticFiles(directory="static"), name="static")

# Configuración de plantillas
templates = Jinja2Templates(directory="templates")

# Ruta para mostrar todos los conciertos
@app.get("/", response_class=HTMLResponse)
async def index(request: Request):
    df = pd.read_csv('AudNacRegCSV.csv', delimiter=';', encoding='latin1')
    total_conciertos = df.shape[0]  # Cuenta total de conciertos
    return await obtener_conciertos(request, df, total_conciertos)

# Función para obtener conciertos
async def obtener_conciertos(request: Request, df: pd.DataFrame, total_conciertos: int):
    # Convierte el DataFrame a una lista de diccionarios
    conciertos = df.to_dict(orient='records')
    # Renderiza la plantilla con los conciertos
    return templates.TemplateResponse("index.html", {
        "request": request,
        "conciertos": conciertos,
        "total_conciertos": total_conciertos
    })

# Ruta para filtrar conciertos por mes
@app.post("/filtrar", response_class=HTMLResponse)
async def filtrar_conciertos(request: Request, mes: int = Form(...)):
    df = pd.read_csv('AudNacRegCSV.csv', delimiter=';', encoding='latin1')

    # Filtrar conciertos por mes
    if mes:
        df['Fecha'] = pd.to_datetime(df['Fecha'], format='%Y-%m-%d')  # Cambiado el formato a YYYY-MM-DD
        df = df[df['Fecha'].dt.month == mes]

    total_conciertos = df.shape[0]  # Cuenta total de conciertos filtrados
    return await obtener_conciertos(request, df, total_conciertos)

# Aquí podrías agregar más rutas o funciones según sea necesario
