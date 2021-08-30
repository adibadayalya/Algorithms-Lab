#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int> > v;
    srand(0);
    set<pair<int,int> > st;
    ofstream dataFile("./bruteForce.csv");
    ofstream maximaFile("./maxima.csv");
    for(int i=0;i<100;i++){
        int x = rand()%200;
        int y = rand()%200;
        pair<int, int>p = make_pair(x,y);
        if(st.find(p)!=st.end()){
            i--;
            continue;
        }
        st.insert(p);
        v.push_back(p);
    }
    pair<int,int>p=v[0];
    for(int i=0;i<100;i++){
        dataFile<<v[i].first<<","<<v[i].second<<'\n';
    }
    //cout<<"--------, ----------\n";
    bool maxima = true;
    for(int i=0;i<v.size();i++){
        maxima=true;
        for(int j=0;j<v.size();j++){
            if((i!=j)&&(v[i].first<=v[j].first)&&(v[i].second<=v[j].second)){
                maxima=false;
                break;
            }
        }
        if(maxima){
            maximaFile<<v[i].first<<","<<v[i].second<<'\n';
        }
    }
    return 0;
}