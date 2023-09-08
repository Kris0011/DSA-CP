class Solution {
  public:
    // Function to detect cycle in a directed graph.
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
};