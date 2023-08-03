#include <bits/stdc++.h>
using namespace std ;

vector<int>  NSE ( vector<int> arr){

    stack<int> st ;
    int n = arr.size() ;
    vector<int> ans(n) ;
    st.push(-1) ;

    for(int i = n-1 ; i >= 0 ; --i  ){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop() ;
        }
        ans[i] = st.top() ;
        st.push( arr[i]) ;
    }

    return ans ;
}

int main() {
    int n = 5;
    // cin >> n ;
    vector<int> arr ={ 1, 14,  2 , 12 , 4 } , ans ;
   
    ans = NSE( arr ) ;

     for( int i=0 ; i < n; ++i){
        cout << ans[i] << " " ;
    }
    return 0;
}