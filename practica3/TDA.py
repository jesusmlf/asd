"""
Grupo: 2AM1

Intregrantes:
-Aguilar Hernández Rodrigo Javier
-López Fabián Jesús Manuel
-Rico Mendoza Josué
"""

import pandas as pd

class Libro():
    def  __init__ (self,Hoja):
        self.Hoja = Hoja

class Hoja():
    def __init__ (self,alto, ancho, titulo, tipo_fuente):
        self.alto = alto
        self.ancho = ancho
        self.titulo = titulo
        self.tipo_fuente = tipo_fuente

def menu():
    print(
        """
        --Programa de ordenamiento de libros--

        1.- Ordenar por dimensiones (alto).
        2.- Ordenar por dimensiones (ancho).
        3.- Ordenar por titulo de pagina (ascendente).
        4.- Ordenar por titulo de pagina (descendente).
        5.- Ordenar por tipo de fuente (ascendente).
        6.- Ordenar por tipo de fuente (descendente).
        """
    )
    opcion = int(input("Ingrese la opcion deseada: "))
    return opcion

def AbrirArchivo():
    file = pd.read_excel("BD_Libros.xlsx")
    return file

def ordenarAncho(libros):
    n = len(libros)
    for i in range(1,n):
        j = i - 1
        key = libros[i]
        while(j>=0 and key.Hoja.ancho < libros[j].Hoja.ancho):
            libros[j+1] = libros[j]
            j -= 1

        libros[j+1] = key

def ordenarAltura(libros):
    n = len(libros)
    for i in range(1,n):
        j = i - 1
        key = libros[i]
        while(j>=0 and key.Hoja.alto < libros[j].Hoja.alto):
            libros[j+1] = libros[j]
            j -= 1

        libros[j+1] = key

def imprimirLibro(libro):
    n = len(libro)
    for i in range(0,n):
        print(f"""
Titulo: {libro[i].Hoja.titulo}    
Alto: {round(libro[i].Hoja.alto,2)}    Ancho: {round(libro[i].Hoja.ancho,2)}    Fuente: {libro[i].Hoja.tipo_fuente}\n""")

def ordenarTituloAscendente(libros):
    n = len(libros)
    for i in range(1,n):
        j = i - 1
        key = libros[i]
        while(j>=0 and ord(key.Hoja.titulo[0].upper()) < ord(libros[j].Hoja.titulo[0].upper())):
            libros[j+1] = libros[j]
            j -= 1

        libros[j+1] = key

def ordenarTituloDescendente(libros):
    n = len(libros)
    for i in range(1,n):
        j = i - 1
        key = libros[i]
        while(j>=0 and ord(key.Hoja.titulo[0].upper()) > ord(libros[j].Hoja.titulo[0].upper())):
            libros[j+1] = libros[j]
            j -= 1
        libros[j+1] = key

def ordenarFuenteAscendente(libros):
    n = len(libros)
    for i in range(1,n):
        j = i - 1
        key = libros[i]
        while(j>=0 and ord((key.Hoja.tipo_fuente[0].upper())) < ord(libros[j].Hoja.tipo_fuente[0].upper())):
            libros[j+1] = libros[j]
            j -= 1

        libros[j+1] = key

def ordenarFuenteDescendente(libros):
    n = len(libros)
    for i in range(1,n):
        j = i - 1
        key = libros[i]
        while(j>=0 and ord(key.Hoja.tipo_fuente[0].upper()) > ord(libros[j].Hoja.tipo_fuente[0].upper())):
            libros[j+1] = libros[j]
            j -= 1

        libros[j+1] = key

def run():
    data = AbrirArchivo()
    data_titulo = list(data["Titulo"])
    data_alto = list(data["Alto"])
    data_ancho = list(data["Ancho"])
    data_fuente = list(data["Fuente"])
    
    cantidad_datos = len(data_titulo)

    hojas = []
    libros = []

    for i in range(0,cantidad_datoz s):
        hoja = Hoja(data_alto[i],data_ancho[i],data_titulo[i],data_fuente[i])
        hojas.append(hoja)

    for i in range(0,cantidad_datos):
        libro = Libro(hojas[i])
        libros.append(libro)    

    opcion = menu()
    
    if opcion == 1:
        ordenarAltura(libros)
        imprimirLibro(libros)
    if opcion == 2:
        ordenarAncho(libros)
        imprimirLibro(libros)
    if opcion == 3:
        ordenarTituloAscendente(libros)
        imprimirLibro(libros)

    if opcion == 4:
        ordenarTituloDescendente(libros)
        imprimirLibro(libros)

    if opcion == 5:
        ordenarFuenteAscendente(libros)
        imprimirLibro(libros)
    
    if opcion == 6:
        ordenarFuenteDescendente(libros)
        imprimirLibro(libros)

if __name__ == '__main__':
    run()