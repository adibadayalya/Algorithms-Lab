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
    ofstream bruteTime("./bruteTime.csv");
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
    v.clear();
    long long size [] = {10,100,1000,10000,100000,1000000};
    int l =0;
    st.clear();
    vector<pair<int, int> > ans;
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
        for(int i=0;i<v.size();i++){
        maxima=true;
        for(int j=0;j<v.size();j++){
            if((i!=j)&&(v[i].first<=v[j].first)&&(v[i].second<=v[j].second)){
                maxima=false;
                break;
            }
        }
            if(maxima){
                ans.push_back(v[i]);
            }
        }
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        bruteTime<<size[l]<<','<<duration.count()<<'\n';
        l++;
        ans.clear();
    }
    return 0;
}