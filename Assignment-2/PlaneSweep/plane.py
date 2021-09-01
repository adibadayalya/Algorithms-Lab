import random

def PlaneSweep2DMaxima(arr):
    stack = []
    for i in range(100):
        while len(stack) > 0 and stack[-1][1] <= arr[i][1]:
            stack.pop()
        stack.append(arr[i])
    while(len(stack)>0):
        print(stack.pop())

if __name__ == '__main__':
    arr = [[(random.randint(1,1000)),(random.randint(1,1000))] for _ in range(100)]
    arr.sort()
    PlaneSweep2DMaxima(arr)
