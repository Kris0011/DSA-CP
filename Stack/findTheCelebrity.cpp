 int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st ;
        for(int i=0; i < n ; i++){
            st.push(i) ;
        }
        
        while( st.size() > 1){
            int a = st.top() ;
            st.pop() ;
            int b = st.top() ;
            st.pop() ;
            if( M[a][b] == 1 ){
                st.push(b) ;
            }
            else {
                st.push(a);
            }
        }

        int c1 = 0 , c2 = 0 , ans= st.top() ; // ans will be checked later if he dont know someone and everybody should know him
        
        for(int i=0; i < n;i++){
            if(M[ans][i] == 0){
                c1++;
            }
        }
        
        for(int i=0; i < n;i++){
            if(M[i][ans] == 1){
                c2++;
            }
        }
        
        if( (c1 == n) && (c2 == n-1) ){
            return ans ;
        }
        else{
            return -1 ;
        }
        
    }