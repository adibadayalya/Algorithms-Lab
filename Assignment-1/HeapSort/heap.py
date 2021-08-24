import random
def heapify(arr, i, n):
 largest = i
 l = 2*i+1
 r=2*i+2
 if (l<n and arr[largest]<arr[l]):
     largest = l
 if (r<n and arr[largest]<arr[r]):
     largest = r
 if(largest != i):
     arr[i],arr[largest]=arr[largest],arr[i]
     heapify(arr, largest, n)    
 
def HeapSort(arr, n):
 for i in range(n//2 -1 ,-1,-1):
     heapify(arr,i,n)
 for i in range(n-1,0,-1):
     arr[i],arr[0]=arr[0],arr[i]
     heapify(arr,0,i)

if __name__ == '__main__':
    arr = [random.randint(1,10000) for _ in range(100)]
    HeapSort(arr,100)
    print(arr)