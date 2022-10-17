def ObetenerNumerosArchivo(ruta:str):
    numeros = []
    with open(ruta,"r") as f:
        for line in f:
            numeros.append(int(line))
    return numeros

def SelectionSort(arr:list,n:int):
    for i in range(0,n):
        j = i + 1
        key = arr[i]
        while(j<n):
            min = arr[j]
            if arr[i] > arr[j]:
                min = arr[j]
            j+=1
        arr[i] = min
        arr[j-1] = key

def GenerarArchivo(numeros,n):
    with open("./numeros_ordenados.txt","w") as f:
        for i in range(0,n):
            f.write(str(numeros[i]))
            if i != n-1:
                f.write("\n")

def run():
    #numeros = ObetenerNumerosArchivo("numeros.txt")
    A = [14,33,27,10,25,35,19,23,42,44]
    n = len(A)
    SelectionSort(A,n)
    print(A)
    #GenerarArchivo(numeros,len(numeros))
if __name__ == '__main__':
    run()
