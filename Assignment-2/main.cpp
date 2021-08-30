#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Solution{
    public:
    void bruteForce(vector<pair<int,int> >&v){
        vector<pair<int,int> >ans;
        bool maxima = true;
        for(int i=0;i<v.size();i++){
            maxima=true;
            for(int j=0;j<v.size();j++){
                if((i!=j)&&(v[i].first <= v[j].first)&&(v[i].second <= v[j].second)){
                    maxima = false;
                    break;
                }
            }
            if(maxima){
                ans.push_back(v[i]);
            }
        }
        ans.clear();
    }
    void planeSweep(vector<pair<int,int> >&v){
        //vector<pair<int,int> >ans;
        sort(v.begin(),v.end());
        stack<pair<int, int> >s;
        for(int i=0;i<v.size();i++){
            while(!s.empty() && s.top().second <= v[i].second){
                s.pop();
            }
            s.push(v[i]);
        }
        while(!s.empty()){
            s.pop();
        }
    }
};

int main(){
    long long len[] = {10,100,1000,10000,100000,1000000};
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    ofstream bf("./bfTime.csv");
    ofstream ps("./psTime.csv");
    Solution object;
    int k = 10000;
    while(k<=1000000)
    {
        vector<pair<int, int> > v;
        set<pair<int,int> >st;
        for(int i=0;i<k;i++){
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
        object.bruteForce(v);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        bf<<k<<','<<duration.count()<<'\n';
        start = high_resolution_clock::now();
        object.planeSweep(v);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ps<<k<<','<<duration.count()<<'\n';
        k+=10000;
        v.clear();
        st.clear();
    }
    return 0;
}