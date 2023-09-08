class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) 
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
	
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      int n = prerequisites.size() ;
      vector<int> adj[numCourses] ;
	    for(int i=0;i<n;i++){
	        int u = prerequisites[i][0] ;
	        int v = prerequisites[i][1] ;
	        adj[u].push_back(v) ;
	    }
	    vector<int> ans = topoSort(numCourses , adj ) ;
			if(ans.size() != numCourses){
				return {} ;
			}
		reverse(ans.begin() , ans.end());
	    return ans;
    }
};