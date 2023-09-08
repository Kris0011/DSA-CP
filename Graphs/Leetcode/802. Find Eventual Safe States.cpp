class Solution {
public:

    // In this method , first reverse the all edges of the graph . ex 1->2 to 2->1 .
    // then get all the indegrees of the reversed graph . Then appy KAHN's algo to find topoSort . That will be the answer


    vector<int> topoSort(int V, vector<int> adj[] , vector<int>& iDeg ) 
	{
	    // code here
	    vector<bool> visited (V,false) ;
	    vector<int> ans ;
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

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size() ;
        vector<int> adj[V] ;
        vector<int> iDeg (V,0) ;

        for(int i=0;i<V;i++){
            for(auto it: graph[i]){
                adj[it].push_back(i) ;
                iDeg[i]++;
            }
        }
        

        vector<int> ans = topoSort(V , adj , iDeg) ;
        sort(ans.begin(),ans.end());
        return ans ;

        
    }
};