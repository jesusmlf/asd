def InsertionSort2(arr:list,n:int):
    for i in range(1,n):
        key = arr[i]
        j = i - 1
        while (j>=0 and arr[j] > key):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key

def run():
    a = input("")
    A = [14,13,11,10]
    n = len(A)
    print(A)
    InsertionSort2(A,n)
    print(A)

if __name__ == '__main__':
    run()
