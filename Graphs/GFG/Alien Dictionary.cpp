// User function Template for C++

class Solution{
    public:
    
    vector<int> topoSort(int V, vector<vector<int>>& adj) 
	{
	    // code here
	    vector<bool> visited (V,false) ;
	    vector<int> ans ;
	    vector<int> iDeg (V,0) ;
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            iDeg[it]++ ;
	        }
	    } 
	    
	    queue<int> q ;
	    for(int i=0;i<V;i++){
	        if(iDeg[i] == 0){
	            q.push(i) ;
	        }
	    }
	   
	    while(!q.empty()) {
	       int node = q.front() ;
	       ans.push_back(node) ;
	       q.pop() ;
	       
	       for(auto it : adj[node]){
	           iDeg[it] -- ;
	           if(iDeg[it] == 0){
	               q.push(it) ;
	           }
	       }
	    }
	    return ans;
	}
    
    
    void getEdge(string & a , string& b , vector<vector<int>> & adj) {
        int n = a.length() ;
        int m = b.length() ;
        int len = (n<m)?n:m ;
        for(int i=0;i<len;i++){
            if(a[i] != b[i]){
                adj[a[i]-'a'].push_back(b[i]-'a') ;
                break;            }
        }
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> alpha (K) ;
        vector<vector<int>> adj (K) ;
        for(int i=0;i<N-1;i++){
            getEdge(dict[i],dict[i+1],adj) ;
        }
        string str ;
        vector<int> ans = topoSort(K , adj) ;
        for(int i=0;i<K;i++){
            str.push_back(ans[i]+'a') ;
        }
        
        return str;
    }
};