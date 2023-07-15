#include<iostream>
using namespace std;

// we have an array and we have to find sum of elements from l to r 
const int N = 1e5+10;
long long pf[N];
long long a[N];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pf[i] = pf[i-1]+a[i];
    }
    int t;
    cin >> t;
    while(t--){
        int l,r,ans;
        cin >> l >> r;
        ans = pf[r]-pf[l-1];
        cout << ans << endl;
    }
}
