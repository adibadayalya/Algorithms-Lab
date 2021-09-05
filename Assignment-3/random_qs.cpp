#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Solution
{
    public:
    int partition(long long arr[], long long l, long long r){
        srand(0);
        long long temp = l + rand()%(r-l);
        long long pivot = arr[temp];
        swap(arr[r],arr[temp]);
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
    void quickSort(long long arr[], long long l, long long r){
        if(l<r){
            long long pi = partition(arr,l,r);
            quickSort(arr,l,pi-1);
            quickSort(arr,pi+1,r);
        }
    }
};

int main(){
    //10 100 1000 10000 100000 1000000
    long long len[] = {10,100,1000,10000,100000,1000000};
    auto arr1 =  new long long[len[0]];
    auto arr2 =  new long long[len[1]];
    auto arr3 =  new long long[len[2]];
    auto arr4 =  new long long[len[3]];
    auto arr5 =  new long long[len[4]];
    auto arr6 =  new long long[len[5]];
    vector<long long>avg(6.0);
    vector<long long>ans[6];
    srand(0);
    Solution obejct;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    int n=10;
    while(n--)
    {
        for(long long i=0;i<len[0];i++){
        arr1[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.quickSort(arr1,0,len[0]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[0].push_back(duration.count());
        avg[0]+=duration.count();
    }

    n=10;
    while(n--)
    {
        for(long long i=0;i<len[1];i++){
            arr2[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.quickSort(arr2,0,len[1]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[1].push_back(duration.count());
        avg[1]+=duration.count();
    }

    n=10;
    while(n--)
    {
        for(long long i=0;i<len[2];i++){
            arr3[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.quickSort(arr3,0,len[2]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[2].push_back(duration.count());
        avg[2]+=duration.count();
    }

    n=10;
    while(n--)
    {
        for(long long i=0;i<len[3];i++){
            arr4[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.quickSort(arr4,0,len[3]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[3].push_back(duration.count());
        avg[3]+=duration.count();
    }

    n=10;
    while(n--)
    {
        for(long long i=0;i<len[4];i++){
            arr5[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.quickSort(arr5,0,len[4]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[4].push_back(duration.count());
        avg[4]+=duration.count();
    }

    n=10;
    while(n--)
    {    
        for(long long i=0;i<len[5];i++){
            arr6[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.quickSort(arr6,0,len[5]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[5].push_back(duration.count());
        avg[5]+=duration.count();
    }
    ofstream dataFile("./timeDataR.csv");
    for(int i=0;i<6;i++){
        long double temp = avg[i]/10;
        dataFile<<len[i]<<',';
        dataFile<<temp<<'\n';
    }
    return 0;
}
