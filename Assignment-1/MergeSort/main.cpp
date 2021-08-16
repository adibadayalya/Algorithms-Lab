#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Solution
{
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
    srand(0);
    Solution obejct;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    int n=100;
    while(n--)
    {
        for(long long i=0;i<len[0];i++){
        arr1[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.mergeSort(arr1,0,len[0]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[0].push_back(duration.count());
    }

    n=100;
    while(n--)
    {
        for(long long i=0;i<len[1];i++){
            arr2[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.mergeSort(arr2,0,len[1]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[1].push_back(duration.count());
    }

    n=100;
    while(n--)
    {
        for(long long i=0;i<len[2];i++){
            arr3[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.mergeSort(arr3,0,len[2]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[2].push_back(duration.count());
    }

    n=100;
    while(n--)
    {
        for(long long i=0;i<len[3];i++){
            arr4[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.mergeSort(arr4,0,len[3]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[3].push_back(duration.count());
    }

    n=100;
    while(n--)
    {
        for(long long i=0;i<len[4];i++){
            arr5[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.mergeSort(arr5,0,len[4]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[4].push_back(duration.count());
    }

    n=100;
    while(n--)
    {    
        for(long long i=0;i<len[5];i++){
            arr6[i]=rand();
        }
        start = high_resolution_clock::now();
        obejct.mergeSort(arr6,0,len[5]-1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        ans[5].push_back(duration.count());
    }
    ofstream dataFile("timeData.csv");
    dataFile<<"10,100,1000,10000,100000,1000000\n";
    for(int i=0;i<100;i++){
        for(int j=0;j<6;j++){
            if(j!=5){
                dataFile<<ans[j][i]<<',';
            }
            else {
                dataFile<<ans[j][i]<<'\n';
            }
        }
    }

    return 0;
}
