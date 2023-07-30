#include <bits/stdc++.h>
using namespace std ;

int balance( string s ){

    stack<char> st ;
    if(s.size()%2 !=0)
        return -1;

    for( int i=0 ; i < s.size() ; ++i){
        if( s[i] == '{' ){
            st.push('{') ;
        }
        else if( s[i] == '}'){
            if( !st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push('}') ;
            }
        }
    }    

    int cnt =0 ;
    while( !st.empty()){
        cout << st.top() << " ";
        if( st.top() == '{'){
            st.pop() ;
            if(st.top() == '}'){
        cout << st.top() << " ";

                cnt+=2 ;
                st.pop() ;
            }else if(st.top() == '{'){
        cout << st.top() << " ";

                cnt++;
                st.pop() ;
            }
        }
        else if( st.top() == '}'){
            cnt++ ;
            st.pop() ;
        }
    }

    return cnt ;
}


int main() {
    string str = "{}}{{{{}" ;
    // cin >> str ;
    cout << balance( str ) ;
     return 0;
}