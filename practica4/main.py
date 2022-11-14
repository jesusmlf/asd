import pandas as pd

class Persona():
    def __init__(self,Datos):
        self.Datos = Datos

class Datos():
    def __init__(self,pais,nombre,altura,telefono):
        self.pais = pais
        self.nombre = nombre
        self.altura = altura
        self.telefono = telefono

def menu():
    print(
        """
        --Programa de ordenamiento de libros--

        1.- Mostrar lista de personas en desorden.
        2.- Ordenar lista de personas por Altura.
        3.- Ordenar lista de personas por la segunda letra del nombre.
        4.- Ordenar lista de personas por numero de telefono.
        5.- Ordenar lista de personas por pais de origen.
        """
    )
    opcion = int(input("Ingrese la opcion deseada: "))
    return opcion

def ImprimirPersonas(personas):
    n = len(personas)
    for i in range (0,n):
        print(f"""
Pais de origen: {personas[i].Datos.pais} 
Nombre: {personas[i].Datos.nombre} Altura:{personas[i].Datos.altura} Telefono: {personas[i].Datos.telefono}""")

def OrdenarAltura(personas):
    n = len(personas)
    #Selection sort
    for i in range(0,n):
        j = i + 1
        key = personas[i]
        while(j<n):
            min = personas[j]
            if float(personas[i].Datos.altura) > float(personas[j].Datos.altura):
                min = personas[j]
            j += 1
        personas[i] = min
        personas[j-1] = key
    
def AbrirArchivo():
    archivo = pd.read_csv("BD_Personas.csv")
    return archivo

def run():
    op = menu()
    archivo = AbrirArchivo()
    pais = list(archivo["Pais de origen"])
    nombre = list(archivo["Nombre"])
    altura = list(archivo["Altura"])
    telefono = list(archivo["telefono"])

    personas = []
    datos = []

    cantidadDatos = len(pais)
    for i in range(0,cantidadDatos):
        datos.append(Datos(pais[i],nombre[i],altura[i],telefono[i]))
        personas.append(Persona(datos[i]))
    
    if op == 1:
        #Mostrar lista de personas en desorden
        ImprimirPersonas(personas)
    if op == 2:
        #Ordenar lista de personas por altura
        OrdenarAltura(personas)
        ImprimirPersonas(personas)

if __name__ == '__main__':
    run()