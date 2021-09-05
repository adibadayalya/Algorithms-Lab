#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Solution
{
    public:
    int partition(vector<long long>&arr, long long l, long long r, bool randomised){
        long long pivot;
        if(randomised){
            srand(0);
            long long temp = l + (rand()%(r-l));
            pivot = arr[temp];
            swap(arr[temp],arr[r]);
        } else{
            pivot = arr[r];
        }
        long long i = l-1;
        for(long long j=l;j<r;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[r]);
        return (i+1);
    }
    public:
    void quickSort(vector<long long>&arr, long long l, long long r, bool randomised){
        if(l<r){
            long long pi = partition(arr,l,r,randomised);
            quickSort(arr,l,pi-1,randomised);
            quickSort(arr,pi+1,r,randomised);
        }
    }
};

int main(){
    ofstream randomData("./compRandom.csv");
    ofstream endData("./compEnd.csv");
    srand(0);
    Solution obejct;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long long k =1000;
    while(k<=100000){
        vector<long long>v1,v2;
        for(long long i=0;i<k;i++){
            long long temp = rand();
            v1.push_back(temp);
            v2.push_back(temp);
        }
        start = high_resolution_clock::now();
        obejct.quickSort(v1,0,k-1,false);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        endData<<k<<','<<duration.count()<<'\n';
        start = high_resolution_clock::now();
        obejct.quickSort(v2,0,k-1,true);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        randomData<<k<<','<<duration.count()<<'\n';
        v1.clear();
        v2.clear();
        k+=1000;
    }
    return 0;
}
