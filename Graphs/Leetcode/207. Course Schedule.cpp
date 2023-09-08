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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size() ;
        vector<int> adj[numCourses] ;
	    for(int i=0;i<n;i++){
	        int u = prerequisites[i][0] ;
	        int v = prerequisites[i][1] ;
	        adj[u].push_back(v) ;
	    }
	    
	    return (!isCyclic(numCourses,adj)) ;
    }
};