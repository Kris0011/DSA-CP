#include<bits/stdc++.h>
using namespace std ;

int lower_bound(vector<int> v , int key){
    int low = 0  , high = v.size()-1 , mid;
    while( high - low > 1){
        mid = high-low /2 ;
        if( v[mid ] < key){
            low = mid+1;
        } 
        else{
            high = mid ;
        }

        if( v[low] >= key){
            return low ;
        }
        else if( v[high] >= key){
            return high;
        }
        else{
            return -1;
        }
    }
}

int higher_bound(vector<int> v , int key){
    int low = 0  , high = v.size()-1 , mid;
    while( high - low > 1){
        mid = high-low /2 ;
        if( v[mid ] <= key){
            low = mid+1;
        } 
        else{
            high = mid ;
        }

        if( v[low] > key){
            return low ;
        }
        else if( v[high] > key){
            return high;
        }
        else{
            return -1;
        }
    }
}
int main(){
    vector<int> v;
    int n;
    cin >> n ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int key ;
    cin >> key;
    int lb= lower_bound( v , key );

}