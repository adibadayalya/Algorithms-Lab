#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Solution
{
    public:
    void heapify(long long arr[], long long n, long long i){
        long long largest=i;
        long long left = 2*i +1;
        long long right = 2*i +2;
        if((left<n)&&(arr[left]>arr[largest])){
            largest=left;
        }
        if((right<n)&&(arr[right]>arr[largest])){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
    public:
    void heapSort(long long arr[], long long n){
        for(long long i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
        for(long long i=n-1;i>0;i--){
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
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
    vector<long long>ans[6];
    vector<long long>avg(6.0);
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
        obejct.heapSort(arr1,len[0]);
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
        obejct.heapSort(arr2,len[1]);
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
        obejct.heapSort(arr3,len[2]);
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
        obejct.heapSort(arr4,len[3]);
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
        obejct.heapSort(arr5,len[4]);
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
        obejct.heapSort(arr6,len[5]);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[5].push_back(duration.count());
        avg[5]+=duration.count();
    }
    ofstream dataFile("../timeDataH.csv");
    for(int i=0;i<6;i++){
        long double temp = avg[i]/10;
        dataFile<<len[i]<<',';
        dataFile<<temp<<'\n';
    }

    return 0;
}
