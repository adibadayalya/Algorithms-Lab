#include <bits/stdc++.h>
using namespace std;

//Edge of the graph
class Edge {
public:
	int src, dest, weight;
};

//actual graph
class Graph {
public:
	
	int V, E; //V = number of vertices, E = NUmber of edges
	Edge* edge; //edge bucket
};

Graph* createGraph(int V, int E)
{
	//graph initialisation
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

void printArr(int dist[], int n)
{
	printf("Vertex \t      \t Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t ---> \t\t %d\n", i, dist[i]);
}

//Bellman-Ford algo
void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	//initializing al the diatances to infinity
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
    //setting source distance to 0
	dist[src] = 0;

    //relaxing all the edges V-1 times 
    //a sortest path from source to any other edge (if reachable) an have atmost V-1 
    //edges
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
            //if distace is not positive infinity for u and dist[u] + wight of u-v is 
            //less than the current dist[v] then it is updated
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	//the above process provides with a shortest path unless there is a negative weight ycle present 
    //if there is a negative weight cycle present, the value of the distance for certain vertices from 
    //source will decrease further and thus we can find out if there is a negative weight cycle in 
    //the graph
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			printf("The Graph contains a NEGATIVE WEIGHT CYCLE\n");
			return;
		}
	}
    //if no noegative weight cycle is present, then the distances are printed
    //if any node is not reachable from the source then the distance printed is 
    //infinity or here equal to INT_MAX
	printArr(dist, V);

	return;
}

int main()
{
	int V; // Number of vertices in graph
	int E; // Number of edges in graph
	cout<<"Enter the number of Vertices:\n";
	cin>>V;
	cout<<"Enter the number of Edges:\n";
	cin>>E;
	Graph* graph = createGraph(V, E);
	set< pair<int,int> >edgeTracker;
	int mxwt = 20;
	srand(time(0));
	for(int i=0;i<V;i++){
		int k = edgeTracker.size();
		k++;
		while(edgeTracker.size()<k){
			int y = rand()%V;
			pair<int,int>p;
			p.first = min(i,y);
			p.second = max(i,y);
			if(edgeTracker.find(p)==edgeTracker.end()&&i!=y){
				edgeTracker.insert(p);
				graph->edge[i].src=i;
				graph->edge[i].dest=y;
				graph->edge[i].weight= rand()%mxwt + 1;
				cout<<graph->edge[i].src<<"--->"<<graph->edge[i].dest<<" weight === "<<graph->edge[i].weight<<'\n';
			}
		}
	}
	E-=V;
	int count = V;
	while(E--){
		int k = edgeTracker.size();
		k++;
		while(edgeTracker.size()<k){
			int y = rand()%V;
			int i = rand()%V;
			pair<int,int>p;
			p.first = min(i,y);
			p.second = max(i,y);
			if(edgeTracker.find(p)==edgeTracker.end()&&i!=y){
				edgeTracker.insert(p);
				graph->edge[count].src=i;
				graph->edge[count].dest=y;
				graph->edge[count].weight= rand()%mxwt + 1;
				cout<<graph->edge[count].src<<"--->"<<graph->edge[count].dest<<" weight === "<<graph->edge[count].weight<<'\n';
				count++;
			}
		}
	}
    //using 0 as source vertex
	BellmanFord(graph, 0);
	return 0;
}
