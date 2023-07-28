#include <bits/stdc++.h>
using namespace std ;

void insertEnd ( stack<int> &st , int x){
    if( st.empty()){
        st.push( x) ;
        return ;
    }

    int temp = st.top() ;
    st.pop() ;

    insertEnd( st , x) ;

    st.push(temp) ;

}

void reverseStack( stack<int> &st){

    if(st.empty()){
        return ;
    }

    int x = st.top() ;
    st.pop() ;

    reverseStack( st) ;

    insertEnd(st , x) ;

}

int main() {
    stack<int> st ;
    st.push(1) ;
    st.push(2) ;
    st.push(3) ;
    st.push(4) ;
    st.push(5) ;


    reverseStack(st) ;

    while( !st.empty()){
        cout << st.top() << " ";
        st.pop() ;
    }
    return 0;
}