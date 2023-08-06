string FirstNonRepeating(string A){
		    // Code here
		    
		    queue<char> q ;
		    unordered_map<char , int> hsh ;
		    string ans ;
		    
		    for( int i=0; i < A.size() ; ++i){
		       hsh[A[i]]++ ;
		       
		       q.push(A[i]) ;
		       
		       while(!q.empty()){
		           if( hsh[q.front()]>1){
		               q.pop() ;
		           }
		           else{
		               ans += q.front() ;
		               break ;
		           }
		       }
		       
		       if( q.empty()){
		           ans += "#" ;
		       }
		    }
		    return ans ;
		}