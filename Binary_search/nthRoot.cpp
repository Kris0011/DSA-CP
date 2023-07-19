#include<bits/stdc++.h>
using namespace std ;
double accuracy = 1e-5;

double sum ( double n , int x ){
    double temp=1;
    for(int i=0;i<x;i++){
        temp*=n;
    }
    return temp;
}

int main(){
    double n;
    int x ;
    cin >> n >> x;
    double low=1 , high = n , mid ;
    while( high - low > accuracy){
        mid = (high+low) /2 ;
        if( sum(mid,x) < n){
            low = mid;
        }
        else{           
            high = mid ;
        }
    }
    cout << high << " " << low ;
}