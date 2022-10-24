def run():
    pass

def Sort(arr:list, tam:int):
    if(tam>1):
        i , j , k = 0
        mitad = tam/2
        arrIzq[mitad] = 
        #Si sobran elementos en el arreglo de la izquierda los almacena en el arreglo original
        for i in range(0,mitad):
            arrIzq[i] = arreglo[k]
            i+=1
            k+=1

        #Si sobran elementos en el arreglo de la derecha los almacena en el arreglo original
        for i in range(0,tam-mitad):
            arrDer[j] = arreglo[k]
            j+=1
            k+=1
        Sort(arrIzq,mitad)
        Sort(arrDer,tam-mitad)
        Mezcla(arrIzq,mitad,arrDer,tam-mitad,arr)

def Mezcla(arrIzq,tamIzq,arrDer,tamDer,arr):
    pass

if __name__ == '__main__':
    run()