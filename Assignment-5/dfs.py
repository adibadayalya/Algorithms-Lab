from collections import defaultdict
from random import randint
import networkx as nx
import matplotlib.pyplot as plt

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.visual = []
        self.vertices = []
        self.visited = [False] * 10000
    
    def addEdge(self,v,w):
        self.graph[v].append(w)
        self.visual.append([v,w])
        self.vertices.append(v)

    def DFS(self,k):
        self.visited[k]=True
        print(k,end=" ")
        for i in self.graph[k]:
            if self.visited[i]==False:
                self.DFS(i)
    
    def DFS_Start(self):
        for i in self.vertices:
            if self.visited[i] == False:
                self.DFS(i)

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
    while len(edgeSet) < n:
        p = [randint(0,n-1),randint(0,n-1)]
        check = False
        for edge in edgeSet:
            if edge == p:
                check = True
                break
        if check == False:    
            graph.addEdge(p[0],p[1])
            edgeSet.append(p)
    graph.DFS_Start()
    graph.visualize()

          
