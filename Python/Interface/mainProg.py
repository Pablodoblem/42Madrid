from fastapi import FastAPI, Form
from fastapi.staticfiles import StaticFiles
from fastapi.templating import Jinja2Templates
from fastapi.responses import HTMLResponse
from starlette.requests import Request
import mysql.connector
from database import cargar_datos  # Importar el script que hemos creado

app = FastAPI()

# Configuración para archivos estáticos
app.mount("/static", StaticFiles(directory="static"), name="static")

# Configuración de plantillas
templates = Jinja2Templates(directory="templates")

# Conectar a la base de datos MySQL
def conectar_bd():
    return mysql.connector.connect(
        host="tu_host_de_IONOS",
        user="tu_usuario",
        password="tu_contraseña",
        database="nombre_base_datos"
    )

# Ruta para mostrar todos los conciertos
@app.get("/", response_class=HTMLResponse)
async def index(request: Request):
    connection = conectar_bd()
    cursor = connection.cursor(dictionary=True)  # Usar un diccionario para que las columnas sean accesibles por nombre
    cursor.execute("SELECT * FROM conciertos")
    conciertos = cursor.fetchall()
    connection.close()

    total_conciertos = len(conciertos)  # Contar los conciertos obtenidos
    return await obtener_conciertos(request, conciertos, total_conciertos)

# Función para obtener conciertos
async def obtener_conciertos(request: Request, conciertos: list, total_conciertos: int):
    return templates.TemplateResponse("index.html", {
        "request": request,
        "conciertos": conciertos,
        "total_conciertos": total_conciertos
    })

# Ruta para filtrar conciertos por mes
@app.post("/filtrar", response_class=HTMLResponse)
async def filtrar_conciertos(request: Request, mes: int = Form(...)):
    connection = conectar_bd()
    cursor = connection.cursor(dictionary=True)
    cursor.execute("SELECT * FROM conciertos WHERE MONTH(Fecha) = %s", (mes,))
    conciertos = cursor.fetchall()
    connection.close()

    total_conciertos = len(conciertos)  # Contar los conciertos filtrados
    return await obtener_conciertos(request, conciertos, total_conciertos)
