import random

class Solution:
    def BruteForce2DMaxima(arr):
        maxima = True
        for i in range(100):
            maxima = True
            for j in range(100):
                if(i!=j and arr[i][0]<=arr[j][0] and arr[i][1]<=arr[j][1]):
                    maxima = False
                    break
            if(maxima):
                print(arr[i])


if __name__ =='__main__':
    arr = [[random.randint(1,1000), random.randint(1,1000)] for _ in range(100)]
    Solution.BruteForce2DMaxima(arr)