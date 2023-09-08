// User function Template for C++

class Solution {
  public:
 
    // A node which is part of cycle and a node which is pointing to a cycle that can't be safe node . 
    bool dfs(int node, vector<int> adj[] , vector<bool>& vis , vector<bool>& pathVis){
        vis[node] = true; 
        pathVis[node] = true ;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)){
                    return true;
                }
            }
            else if(pathVis[it]) {
                return true; 
            } 
        }
        
        pathVis[node] = false; 
        return false ;
        
    }
    
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis (V,false) ;
        vector<bool> pathVis ( V, false) ;
        vector<int> ans ;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool check = dfs(i,adj,vis,pathVis) ;
                // if(check){
                // }
            }
            
            if(!pathVis[i]){
                   ans.push_back(i) ;
            }
        }
        return ans ;
    }
};