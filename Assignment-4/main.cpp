#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Graph{
    int V;
    list<int>*adj;
public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }
    void BFS(int s){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        list<int>queue;
        visited[s]=true;
        queue.push_back(s);
        list<int>::iterator i;
        while(!queue.empty()){
            s=queue.front();
            //cout<<s<<' ';
            queue.pop_front();
            for(i = adj[s].begin();i!=adj[s].end();i++){
                if(!visited[*i]){
                    visited[*i]=true;
                    queue.push_back(*i);
                }
            }
        }
    }
};

int main(){
    ofstream timeFile("time.csv");
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    int N;
    int T;
    cout<<"Enter Number of Test Cases: ";
    cin>>T;
    while(T--){
        cout<<"Enter the number of Vertices: ";
        cin>>N;
        Graph g(N);
        srand(0);
        set<pair<int, int> >st;
        pair<int, int>p,q,r;
        /* for(int i=0;i<N;i++){
            cout<<i<<'\n';
        }  */
        for(int i=0;i<2*N;i++){
            p.first = rand()%N;
            p.second = rand()%N;
            if(i==0){
                r=p;
            }
            q=make_pair(p.second,p.first);
            if(st.find(p)==st.end()&&st.find(q)==st.end()){
                g.addEdge(p.first,p.second);
                //g.addEdge(q.first,q.second);
                st.insert(p);
                //cout<<p.first<<' '<<p.second<<'\n';
                //cout<<q.first<<' '<<q.second<<'\n';
            } else{
                i--;
            }
        }
        start = high_resolution_clock::now();
        g.BFS(r.first); 
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        timeFile<<N<<','<<duration.count()<<'\n';
    }
    return 0;
}