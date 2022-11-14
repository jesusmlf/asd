import pandas as pd
def normalize(s):
    replacements = (
        ("á", "a"),
        ("é", "e"),
        ("í", "i"),
        ("ó", "o"),
        ("ú", "u"),
        ("à", "a"),
        ("è", "e"),
        ("ì", "i"),
        ("ò", "o"),
        ("ù", "u"),
        ("Á", "A"),
        ("É", "E"),
        ("Í", "I"),
        ("Ó", "O"),
        ("Ú", "U"),
        ("À", "A"),
        ("È", "E"),
        ("Ì", "I"),
        ("Ò", "O"),
        ("Ù", "U"),
    )
    for a,b in replacements:
        s = s.replace(a,b)
    return s

def run():
    archivo = pd.read_excel("Data/BD_Personas.xlsx")
    pais = list(archivo["Pais de origen"])
    nombres = list(archivo["Nombre"])
    altura = list(archivo["Altura"])
    telefono = list(archivo["telefono"])
    print(type(telefono[0]))

    for i in range(0,len(archivo)):
        nombres[i]=normalize(nombres[i].strip())
        pais[i] = normalize(pais[i].strip())
        #print(f"Nombre: {nombres[i]} - Pais: {pais[i]}")
    
    archivo_new = pd.DataFrame({"Pais de origen":pais,
                                "Nombre":nombres,
                                "Altura":altura,
                                "telefono":telefono})
    archivo_new.to_csv("BD_Personas.csv",index=False)

if __name__ == '__main__':
    run()