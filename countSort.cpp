#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[],int l,int r){

    int k=arr[0];
    for(int i=l;i<r;i++){
        k=max(k,arr[i]);
    }

    int count[10]={0};
    for(int i=l;i<r;i++){
        count[arr[i]]++;
    }

    for(int i=l+1;i<=k;i++){
        count[i
        ]+=count[i-1];
    }

    int output[r];

    for(int i=r-1;i>=l;i--){
        output[--count[arr[i]]]=arr[i];
    }

    for(int i=l;i<r;i++){
        arr[i]=output[i];
    }

}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    countSort(arr,0,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;


}