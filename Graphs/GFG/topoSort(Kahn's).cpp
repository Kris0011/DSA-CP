class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
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
};