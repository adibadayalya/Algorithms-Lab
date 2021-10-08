#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    map<int, bool> mp;
    vector<int>vertices;
    vector<int>*adj;
public:
    Graph(int V){
        this->V = V;
        adj = new vector<int>[V];
    }
    void addEdge(int v, int w){
        vertices.push_back(v);
        adj[v].push_back(w);
        mp[v]=false;
    }
    void DFS(int k){
        mp[k]=true;
        cout<<k<<' ';
        for(int i=0;i<adj[k].size();i++){
            if(!mp[adj[k][i]]){
                DFS(adj[k][i]);
            }
        }
    }
    void DFS_Start(){
        for(int i=0;i<vertices.size();i++){
            if(mp[vertices[i]]==false){
                DFS(vertices[i]);
            }
        }
    }
};

int main(){
    //ofstream timeFile("time.csv");
    int N;
    int T=1;
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
        g.DFS_Start(); 
        cout<<'\n';
    }
    return 0;
}