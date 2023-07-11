#include<iostream>
using namespace std;

// We have 2D array like square we want to sum small boxes within it in pre computation so that if we have to find sum of elements betwwen top left and bottom right points 

// for example we have 4x4 and tl is 2,2 and bl 4,4 then sum will be (2,2 + 2,3 + 2,4 )+ ( 3,2 + 3,3 + 3,4) + (4,2 + 4,3 + 4,4) 
const int N = 1e5+10;
long long pf[N][N];
long long a[N][N];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            pf[i][j] = a[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1]; // the element itself two boxes sum and extra part subtract 
        }
    }
    int t;
    cin >> t;
    while(t--){
        int tl1,tl2 , br1,br2 ;
        cin >> tl1 >> tl2 >> br1 >> br2;
        cout << pf[br1][br2] - pf[tl1-1][br2] - pf[br1][tl2-1] + pf[tl1-1][tl2-2];
    }
}
