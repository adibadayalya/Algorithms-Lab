import random
import time
import csv
class Solution:
    def partition(self, arr, l, r, randomised):
        pivot=arr[r]
        if randomised == True:
            temp = random.randint(l,r-1)
            pivot=arr[temp]
        i =l-1
        for j in range(l,r):
            if(arr[j]<pivot):
                i+=1
                arr[j],arr[i]=arr[i],arr[j]
        i+=1
        arr[i],arr[r]=arr[r],arr[i]
        return (i)
    def quickSort(self, arr, l,r, randomised):
        if(l<r):
            pi = self.partition(arr,l,r,randomised)
            self.quickSort(arr,l,pi-1, randomised)
            self.quickSort(arr,pi+1,r,randomised)


if __name__ == '__main__':
    k =1000
    with open('compEnd.csv',mode = 'w') as end_comp:
        with open('compRandom.csv', mode='w') as rand_comp:
            fieldNames = ['lenght','time']
            writer = csv.DictWriter(end_comp, fieldnames=fieldNames)
            writer2 = csv.DictWriter(rand_comp, fieldnames=fieldNames)
            while k<=100000:
                start = time.time()
                arr = [random.randint(1,100000) for _ in range(k)]
                Solution().quickSort(arr,0,k-1, False)
                stop = time.time()
                duration = stop -start
                writer.writerow({'lenght':k,'time':int(duration*1000)})
                start = time.time()
                arr = [random.randint(1,100000) for _ in range(k)]
                Solution().quickSort(arr,0,k-1, True)
                stop = time.time()
                duration = stop -start
                writer2.writerow({'lenght':k,'time':int(duration*1000)})
                k+=1000