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
    public:
    void merge(long long arr[], long long l, long long m, long long r){
        long long leftLenth=m-l+1;
        long long rightLength=r-m;
        auto leftAr = new long long[leftLenth];
        auto rightAr = new long long[rightLength];
        for(long long i=0;i<leftLenth;i++){
            leftAr[i]=arr[l+i];
        }
        for(long long i=0;i<rightLength;i++){
            rightAr[i]=arr[i+m+1];
        }
        long long i1=0,i2=0,im=l;
        while(i1<leftLenth&&i2<rightLength){
            if(leftAr[i1]<=leftAr[i2]){
                arr[im]=leftAr[i1];
                i1++;
            }
            else{
                arr[im]=rightAr[i2];
                i2++;
            }
            im++;
        }
        while(i1<leftLenth){
            arr[im]=leftAr[i1];
            im++;
            i1++;
        }
        while(i2<rightLength){
            arr[im]=rightAr[i2];
            im++;
            i2++;
        }
        free(rightAr);
        free(leftAr);
    }
    public:
    void mergeSort(long long arr[], long long l, long long r){
        if(l<r){
            int mid = l +(r-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
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
    long long k = 10000;
    ofstream dataFile("comparativeAnalysis.csv");
    vector<long long>qs;
    vector<long long>hs;
    vector<long long>ms;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    Solution obj;
    while(k<=1000000)
    {
        auto arr = new long long[k];
        srand(0);
        for(long long i=0;i<k;i++){
            arr[i]=rand();
        }
        start = high_resolution_clock::now();
        obj.quickSort(arr,0,k-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        qs.push_back(duration.count());
        for(long long i=0;i<k;i++){
            arr[i]=rand();
        }
        start = high_resolution_clock::now();
        obj.mergeSort(arr,0,k-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ms.push_back(duration.count());
        for(long long i=0;i<k;i++){
            arr[i]=rand();
        }
        start = high_resolution_clock::now();
        obj.heapSort(arr,k);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        hs.push_back(duration.count());
        k+=50000;
        free(arr);
    }
    k = 10000;
    ofstream qsFile("quickSort.csv");
    ofstream msFile("mergeSort.csv");
    ofstream hsFile("heapSort.csv");
    for(int i=0;i<ms.size();i++){
        qsFile<<k<<','<<qs[i]<<'\n';
        msFile<<k<<','<<ms[i]<<'\n';
        hsFile<<k<<','<<hs[i]<<'\n';
        k+=50000;
    }
    return 0;
}