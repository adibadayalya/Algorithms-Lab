import random
class Solution:
    def merge(self,arr, left, right, mid):
        l = mid-left+1
        r = right-mid
        L = [arr[i] for i in range(left,left+l)]
        R = [arr[i] for i in range(mid+1,mid+1+r)]
        i = 0
        j = 0
        k=left
        while(i<l and j<r):
            if(L[i]<=R[j]):
                arr[k]=L[i]
                i+=1
            else:
                arr[k]=R[j]
                j+=1
            k+=1
        while(i<l):
            arr[k]=L[i]
            i+=1
        while(j<r):
            arr[k]=R[j]
            j+=1
    
    def mergeSort(self, arr, l,r):
        if(l<r):
            mid = l + (r-l)//2
            self.mergeSort(arr,l,mid)
            self.mergeSort(arr,mid+1,r)
            self.merge(arr,l,r,mid)


if __name__ == '__main__':
    arr = [random.randint(1,10000) for _ in range(100)]
    Solution().mergeSort(arr,0,99)
    print(arr)