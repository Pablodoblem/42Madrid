from fastapi import Request
from fastapi.responses import HTMLResponse
from fastapi.templating import Jinja2Templates
import pandas as pd

templates = Jinja2Templates(directory="templates")

async def obtener_conciertos(request: Request, df: pd.DataFrame):
    total_conciertos = len(df)
    return templates.TemplateResponse("index.html", {"request": request, "conciertos": df.to_dict(orient='records'), "total_conciertos": total_conciertos})

async def filtrar_conciertos(request: Request, df: pd.DataFrame, mes: int):
    df['Fecha'] = pd.to_datetime(df['Fecha'], format='%d/%m/%Y', errors='coerce')
    if mes:
        df = df[df['Fecha'].dt.month == mes]
    
    total_conciertos = len(df)
    return templates.TemplateResponse("index.html", {"request": request, "conciertos": df.to_dict(orient='records'), "total_conciertos": total_conciertos})
