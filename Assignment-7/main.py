from random import randint
import math

class Graph:
	def __init__(self, vertices):
		self.V = vertices 
		self.graph = [] 

	def addEdge(self, u, v, w):
		self.graph.append([u, v, w])

	def BellmanFord(self, S):
		dist=[float("Inf")] * self.V
		dist[S] = 0
		for _ in range(self.V-1):
			for u,v,w in self.graph:
				if(dist[u]!=float("Inf") and dist[u] + w < dist[v]):
					dist[v] = dist[u]+w
		for u,v,w in self.graph:
			if(dist[u]!=float("Inf") and dist[u] + w < dist[v]):
				print("THE GRAPH CONTAINS A NEGATIVE CYCLE")
				return
		
		print("Vertex\t    \t Distance from Source")
		for i in range(self.V):
			print("%d \t ----> \t \t %d" %(i,dist[i]))

if __name__ == '__main__':
	V = int(input("Enter the number of Vertices: "))
	E = int(input("Enter the number of Edges: "))
	edgeSet = []
	g = Graph(V)
	for i in range(V):
		k = len(edgeSet)
		k+=1
		while len(edgeSet) < k:
			q = randint(0,V-1)
			p = [q,i]
			flag = True
			for edge in edgeSet:
				if edge == p:
					flag = False
					break
			if q!=i and flag:
				edgeSet.append(p)
				wt = randint(-5,20)
				if wt == 0:
					wt+=1 
				p.append(wt)
				g.addEdge(p[0],p[1],p[2])
				print(str(p[0]) + " ---> "+ str(p[1])+" weight === "+ str(p[2]))
	E-=V
	while E > 0:
		k = len(edgeSet)
		k+=1
		while len(edgeSet) < k:
			i = randint(0,V-1)
			q = randint(0,V-1)
			p = [q,i]
			flag = True
			for edge in edgeSet:
				if edge == p:
					flag = False
					break
			if q!=i and flag:
				edgeSet.append(p)
				if wt == 0:
					wt+=1 
				wt = randint(-5,20)
				p.append(wt)
				g.addEdge(p[0],p[1],p[2])
				print(str(p[0]) + " ---> "+ str(p[1])+" weight === "+ str(p[2]))
		E-=1
	g.BellmanFord(0)
