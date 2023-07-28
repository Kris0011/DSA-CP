#include<bits/stdc++.h>
using namespace std  ;

void removeMiddle( stack<int> &st , int &mid , int count ){
    
    if(count == mid){
        st.pop() ;
        return ;
    }

    int x = st.top() ;
    st.pop() ;
    removeMiddle(st , mid , count+1  ); 
    st.push(x) ;
}

int main(){
    stack<int> st ;
    st.push(1) ;
    st.push(2) ;
    st.push(3) ;
    st.push(4) ;
    st.push(5) ;

    int mid = st.size() /2  ;

    removeMiddle(st,mid , 0 ) ;

    while( !st.empty()){
        cout << st.top() << " ";
        st.pop() ;
    }
}