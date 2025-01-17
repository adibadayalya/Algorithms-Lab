from random import randint

class Graph:
	def __init__(self, vertices):
		self.V = vertices 
		self.graph = [] 

	def addEdge(self, u, v, w):
		self.graph.append([u, v, w])

	def find(self, parent, i):
		if parent[i] == i:
			return i
		return self.find(parent, parent[i])

	def union(self, parent, rank, x, y):
		xroot = self.find(parent, x)
		yroot = self.find(parent, y)
		if rank[xroot] < rank[yroot]:
			parent[xroot] = yroot
		elif rank[xroot] > rank[yroot]:
			parent[yroot] = xroot
		else:
			parent[yroot] = xroot
			rank[xroot] += 1

	def KruskalMST(self):
		result = []
		i = 0
		e = 0
		self.graph = sorted(self.graph,key=lambda item: item[2])
		parent = []
		rank = []
		for node in range(self.V):
			parent.append(node)
			rank.append(0)
		while e < self.V - 1:
			u, v, w = self.graph[i]
			i = i + 1
			x = self.find(parent, u)
			y = self.find(parent, v)
			if x != y:
				e = e + 1
				result.append([u, v, w])
				self.union(parent, rank, x, y)

		minimumCost = 0
		print ("Edges in the constructed MST")
		for u, v, weight in result:
			minimumCost += weight
			print("%d ---> %d weight === %d" % (u, v, weight))
		print("Minimum Spanning Tree cost:" , minimumCost)

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
			p = [min(q,i),max(q,i)]
			flag = True
			for edge in edgeSet:
				if edge == p:
					flag = False
					break
			if q!=i and flag:
				edgeSet.append(p)
				wt = randint(1,20)
				p.append(wt)
				g.addEdge(p[0],p[1],p[2])
				print(str(p[0]) + " ---> "+ str(p[1])+" weight === "+ str(p[2]))
	E-=V
	while E > 0:
		i = randint(0,V-1)
		k = len(edgeSet)
		k+=1
		while len(edgeSet) < k:
			q = randint(0,V-1)
			p = [min(q,i),max(q,i)]
			flag = True
			for edge in edgeSet:
				if edge == p:
					flag = False
					break
			if q!=i and flag:
				edgeSet.append(p)
				wt = randint(1,20)
				p.append(wt)
				g.addEdge(p[0],p[1],p[2])
				print(str(p[0]) + " ---> "+ str(p[1])+" weight === "+ str(p[2]))
		E-=1
	g.KruskalMST()
