#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Solution
{
    public:
    int partition(long long arr[], long long l, long long r){
        long long pivot = arr[r];
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
    srand(0);
    auto arr = new long long [10];
    for(int i=0;i<10;i++){
        arr[i]=(long long)(rand());
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    Solution ob;
    ob.quickSort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}