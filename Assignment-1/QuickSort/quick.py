import random
class Solution:
    def partition(self, arr, l, r):
        pivot=arr[r]
        i =l-1
        for j in range(l,r):
            if(arr[j]<pivot):
                i+=1
                arr[j],arr[i]=arr[i],arr[j]
        i+=1
        arr[i],arr[r]=arr[r],arr[i]
        return (i)
    def quickSort(self, arr, l,r):
        if(l<r):
            pi = self.partition(arr,l,r)
            self.quickSort(arr,l,pi-1)
            self.quickSort(arr,pi+1,r)


if __name__ == '__main__':
    arr = [random.randint(1,10000) for _ in range(100)]
    Solution().quickSort(arr,0,99)
    print(arr)