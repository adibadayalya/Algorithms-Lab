from collections import defaultdict
from random import randint

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    
    def addEdge(self,v,w):
        self.graph[v].append(w)
    
    def BFS(self,s):
        visited = [False]*(max(self.graph)+1)
        queue = []
        queue.append(s)
        visited[s]=True
        while queue:
            s = queue.pop(0)
            print(s,end=" ")
            for i in self.graph[s]:
                if visited[i]==False:
                    visited[i]=True
                    queue.append(i)

if __name__ == '__main__':
    graph = Graph()
    n=int(input("Enter the number of vertices: "))
    edgeSet = []
    q=[]
    for i in range(n):
        p = [randint(0,n-1),randint(0,n-1)]
        check = False
        for edge in edgeSet:
            if edge == p:
                check = True
                break
        if check:
            i-=1
        else:
            graph.addEdge(p[0],p[1])
            edgeSet.append(p)
        if i==0:
            q=p
    graph.BFS(q[0])

          
