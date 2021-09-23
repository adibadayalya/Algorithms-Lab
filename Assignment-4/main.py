from collections import defaultdict
from random import randint
import networkx as nx
import matplotlib.pyplot as plt

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.visual = []
    
    def addEdge(self,v,w):
        self.graph[v].append(w)
        self.visual.append([v,w])
    
    def BFS(self,s):
        visited = [False]*10000
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
    def visualize(self):
        options = {
        'node_color': 'yellow',
        'node_size': 1000,
        'width': 2,
        'arrowstyle': '-|>',
        'arrowsize': 6,
        }
        G = nx.Graph()
        G.add_edges_from(self.visual)
        nx.draw_networkx(G, arrows=True,**options)
        plt.show()


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
    graph.visualize()

          
