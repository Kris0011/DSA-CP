class Solution {
public:
    bool dfs( int start , vector<int> adj[] ,  vector<bool>& vis, vector<bool>& pVis){
        vis[start] = true; 
        pVis[start] = true;
        for(auto it : adj[start]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pVis) == true){
                    return true;
                }
            }
            else if(pVis[it]){
                return true;
            }
        }
        
        pVis[start] = false  ;
        return false ; 
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis (V,false);
        vector<bool> pVis (V,false) ;
        
    
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pVis) == true){
                    return true;
                }
            }
        }
        
        return false;
    }
    
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N] ;
	    for(int i=0;i<P;i++){
	        int u = prerequisites[i].first ;
	        int v = prerequisites[i].second ;
	        adj[u].push_back(v) ;
	    }
	    
	    return (!isCyclic(N,adj)) ;
	}
};