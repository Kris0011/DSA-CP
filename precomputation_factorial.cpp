#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+10;
long long fact[N];
int main(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<=N;i++){
        fact[i] = fact[i-1]*i;
    }
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        cout << fact[a] << endl;
    }
}
