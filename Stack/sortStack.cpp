#include <bits/stdc++.h>
using namespace std ;


void insertSorted( stack<int> &st , int n){
    if( st.empty() || ( !st.empty() && st.top() < n)){
        st.push(n);
        return  ;
    }

    int temp = st.top() ;
    st.pop() ;


    insertSorted( st ,n) ;

    st.push(temp) ;
}

void sortStack( stack<int> & st){

    if( st.empty()){
        return ;
    }

    int x = st.top() ;
    st.pop() ;
    
    sortStack(st) ;

    insertSorted( st ,  x) ;



}

int main() {
    stack<int> st ;
    st.push(1) ;
    st.push(2) ;
    st.push(3) ;
    st.push(4) ;
    st.push(5) ;

    sortStack( st) ;

    while( !st.empty()){
        cout << st.top() << " ";
        st.pop() ;
    }

    return 0;
}