#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
void printArr(int dist[], int n)
{
	printf("Vertex \t      \t Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t ---> \t\t %d\n", i, dist[i]);
}

int minDistance(int dist[], bool included[],int V){
    int mn = INT_MAX, mn_index; 
    for(int i=0;i<V;i++){
        if(included[i]==false && dist[i]<=mn){
            mn_index = i;
            mn = dist[i];
        }
    }
    return mn_index;
}

void Dijkstra(int src, int V){
    int dist[V];
	bool included[V];
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX, included[i] = false;
	}
	dist[src]=0;
	for (int count=0; count<V-1;count++){
		int u = minDistance(dist,included,V);
		included[u]=true;
		for(int v=0;v<V;v++){
			if(!included[v] && graph[u][v] && dist[u]!=INT_MAX
				&& dist[u] + graph[u][v]<dist[v]){
					dist[v] = dist[u] + graph[u][v];
				}
		}
	}
	printArr(dist,V);
}


int main()
{
	int V;
	int E; // Number of edges in graph
	cout<<"Enter the number of Vertices:\n";
	cin>>V;
	cout<<"Enter the number of Edges:\n";
	cin>>E;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			graph[i][j]=0;
		}
	}
	srand(time(0));
	set<pair<int, int> >edgeSet;
	for(int i=0;i<V;i++){
		//cout<<"test\n";
		int sz = edgeSet.size();
		sz+=2;
		while(edgeSet.size()<sz){
			srand(time(0));
			int x = i;
			int y = rand()%V;
			if(x==y){
				continue;
			}
			pair<int,int>p,pp;
			p.first = x;
			p.second = y;
			pp.first = y;
			pp.second =x;
			if(graph[x][y]!=0){
				continue;
			}
			else{
				//srand(time(0));
				int weight = rand()%15 + 1;
				graph[x][y]=weight;
				graph[y][x]=weight;
				edgeSet.insert(p);
				edgeSet.insert(pp);
			}
		}
	}
	E-=V;
	while(E--){
		srand(time(0));
		int x = rand()%V;
		int y = rand()%V;
		pair<int,int>p,pp;
		p.first = x;
		p.second = y;
		pp.first = y;
		pp.second =x;
		if(graph[x][y]!=0){
			continue;
		}
		else{
			//srand(time(0));
			int weight = rand()%15 + 1;
			graph[x][y]=weight;
			graph[y][x]=weight;
			edgeSet.insert(p);
			edgeSet.insert(pp);
		}
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<graph[i][j]<<' ';
		}
		cout<<'\n';
	}
	cout<"-------------\n";
	Dijkstra(0,V);
	return 0;
}
