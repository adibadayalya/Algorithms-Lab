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

// A structure to represent a subset for union-find
class subset {
public:
	int parent;
	int rank;
};

//find the set in which element i is present
int find(subset subsets[], int i)
{
	// find root and make root as parent of i
	if (subsets[i].parent != i)
		subsets[i].parent
			= find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

//union of set x and y
void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x); //finding root of x 
	int yroot = find(subsets, y); //finding root of y

	//appending a smaller rank tree to the one with higher rank
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	// if both the ranks are same then one of them is made out to be the root
	//and its rank is increased by 1
	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->weight > b1->weight;
}

//kruskal's MST
void KruskalMST(Graph* graph)
{
	int V = graph->V;
	Edge result[V]; // Tnis will store the resultant MST
	int e = 0; // An index variable, used for result[]
	int i = 0; // An index variable, used for sorted edges

	//sorting the edges in non decresing order of their weights 
	//qsort(pointer to first edge, number of edgesm size of each edgem compare fucntion)
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]),myComp);

	//subset for each vertex v
	// Allocate memory for creating V ssubsets
	subset* subsets = new subset[(V * sizeof(subset))];

	// Create V subsets with single elements i.e itself 
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Number of edges to be taken is equal to V-1 since a cycle is to be avoided 
	while (e < V - 1 && i < graph->E)
	{
		// Step 2: Pick the smallest edge. And increment
		// the index for next iteration
		Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		//if including this edge does not cause a cycle i.e the parents of 
		//source and destination are not the same then the edge is added to the MST 
		//and union operation is performed later
		if (x != y) {
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		//if addding the edge causes a cycle to occur then it is discarded
	}

	//result[] array contains the built MST
	cout << "Following are the edges in the constructed MST\n";
	int minimumCost = 0;
	for (i = 0; i < e; ++i)
	{
		cout << result[i].src << " ---> " << result[i].dest<< " weight === " << result[i].weight << '\n';
		minimumCost = minimumCost + result[i].weight;
	}
	//cost of MST
	cout << "Minimum Cost Spanning Tree: " << minimumCost<<'\n';
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
	KruskalMST(graph);
	return 0;
}
