from random import randint
class Graph():

	def __init__(self, vertices):
		self.V = vertices
		self.graph = [[0 for column in range(vertices)]
					for row in range(vertices)]

	def printSolution(self, dist):
		print ("Vertex \tDistance from Source")
		for node in range(self.V):
			print (node, "\t", dist[node])
	def minDistance(self, dist, sptSet):
		min = float("Inf")
		for u in range(self.V):
			if dist[u] < min and sptSet[u] == False:
				min = dist[u]
				min_index = u

		return min_index

	def dijkstra(self, src):

		dist = [float("Inf")] * self.V
		dist[src] = 0
		sptSet = [False] * self.V

		for _ in range(self.V):
			x = self.minDistance(dist, sptSet)
			sptSet[x] = True
			for y in range(self.V):
				if self.graph[x][y] > 0 and sptSet[y] == False and dist[y] > dist[x] + self.graph[x][y]:
						dist[y] = dist[x] + self.graph[x][y]

		self.printSolution(dist)

if __name__ == '__main__':
    V = int(input("Enter the number of Vertices:"))
    E = int(input("Enter the number of Edges:"))
    g = Graph(V)
    for i in range(V):
        flag = False 
        while flag == False:
            v = randint(0,V-1)
            if v == i or g.graph[i][v] !=0:
                continue
            weight = randint(1,20)
            g.graph[i][v] = weight
            g.graph[v][i] = weight
            flag = True
    E-=V
    while E > 0:
        flag = False 
        while flag == False:
            i = randint(0,V-1)
            j = randint(0,v-1)
            if i==j or g.graph[i][j] !=0:
                continue
            weight = randint(1,20)
            g.graph[i][j] = weight
            g.graph[j][i] = weight
            flag = True
            E-=1
    for row in g.graph:
        print(row)
    g.dijkstra(0)