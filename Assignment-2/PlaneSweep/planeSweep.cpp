#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main()
{
    vector<pair<int,int> > v;
    srand(0);
    set<pair<int,int> > st;
    ofstream dataFile("./allPoints.csv");
    ofstream maximaFile("./maxima.csv");
    ofstream planeTime("./planeTime.csv");
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
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
    sort(v.begin(),v.end());
    for(int i=0;i<100;i++){
        dataFile<<v[i].first<<","<<v[i].second<<'\n';
    }
    //cout<<"--------, ----------\n";
    stack<pair<int, int> >s;
    for(int i=0;i<v.size();i++){
        while(!s.empty() && s.top().second <= v[i].second){
            s.pop();
        }
        s.push(v[i]);
    }
    while(!s.empty()){
        maximaFile<<s.top().first<<','<<s.top().second<<'\n';
        s.pop();
    }
    long long size [] = {10,100,1000,10000,100000,1000000};
    int l =0;
    st.clear();
    while(l<6){
        st.clear();
        v.clear();
        for(int i=0;i<size[l];i++){
            int x = rand()%4000;
            int y = rand()%4000;
            pair<int, int>p = make_pair(x,y);
            if(st.find(p)!=st.end()){
                i--;
                continue;
            }
            st.insert(p);
            v.push_back(p);
        }
        start = high_resolution_clock::now();
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            while(!s.empty() && s.top().second <= v[i].second){
                s.pop();
            }
            s.push(v[i]);
        }
        while(!s.empty()){
            s.pop();
        }
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        planeTime<<size[l]<<','<<duration.count()<<'\n';
        l++;
    }
    return 0;
}