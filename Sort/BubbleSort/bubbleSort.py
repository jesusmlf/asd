def BubbleSort(arr:list,n:int):
        for i in range(0,n):
            for j in range(0,n-i-1):
                if arr[j] > arr[j+1]:
                    aux = arr[j]
                    arr[j] = arr[j+1]
                    arr[j+1] = aux

def run():
    a = input("")
    A = [14,13,11,10]
    n = len(A)
    print(A)
    BubbleSort(A,n)
    print(A)

if __name__ == '__main__':
    run()