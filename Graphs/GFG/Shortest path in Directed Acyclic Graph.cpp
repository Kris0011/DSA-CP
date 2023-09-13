// User function Template for C++
class Solution {
  public:
  
    void dfs(int node , vector<pair<int,int>> adj[] , vector<bool>& vis , stack<int>& st ){
	    vis[node] = true ;
	    for(auto it : adj[node]){
	        if(!vis[it.first]){
	            dfs(it.first,adj,vis,st);
	        }
	    }
	    st.push(node) ;
	    return ;
	    
	}
    
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<bool> vis (N,false) ;
	    vector<int> d (N,1e9) ;
	    stack<int> st ;
	    vector<pair<int,int> > adj[N] ;
	    
	    
	    for(int i=0;i<M;i++){
	        int u = edges[i][0] ;
	        int v = edges[i][1] ;
	        int w = edges[i][2] ;
	        adj[u].push_back({v,w}) ;
	    }
	    
	    
	    for(int i=0;i<N ; ++i){
	        if(!vis[i]){
	            dfs(i , adj , vis , st) ;
	        }
	    }
	    
	    d[0] = 0 ;
	    while(!st.empty()){
	        int node = st.top() ;
	        st.pop() ;
	        for(auto it : adj[node]){
	            int temp = it.second + d[node] ;
	            if(temp < d[it.first] ){
	                d[it.first] = temp ;
	            }
	        }
	    }
	    
	    for(int i=0 ; i<N ;i++ ){
	        if(d[i] == 1e9){
	            d[i] = -1 ;
	        }
	       // cout << it << " " << INT_MAX << endl ;
	    }
	    
	    return d;
    }
};