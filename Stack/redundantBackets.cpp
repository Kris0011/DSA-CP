#include <bits/stdc++.h>
using namespace std ;

bool Brackets(string s){    
        //code here
        stack<char> st ;
        for( int i=0; i < s.size() ; ++i){
            if( s[i]=='(' || s[i]=='+' || s[i]=='*' || s[i]=='-' || s[i] =='/'){
                st.push(s[i]) ;
            }    
            else if( s[i] == ')'){
                int cnt = 0;
                while(st.top()!= '('){
                    char x= st.top() ;
                    st.pop() ;
                    if( x=='+' || x=='*' || x=='-' ||  x =='/' ){
                        cnt++;
                    }
                }
                st.pop() ;
                if( cnt == 0){
                    return false ;
                }
            }
        }
        return true  ;
    }


int main() {

    string str ;
    cin >> str ;
    cout << Brackets(str) ;
    return 0;
}