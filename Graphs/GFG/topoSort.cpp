class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node , vector<int> adj[] , vector<bool>& vis , stack<int>& st ){
	    vis[node] = true ;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node) ;
	    return ;
	    
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis (V,false) ;
	    vector<int> ans;
	    stack<int> st ;
	    
	    for(int i=0;i<V ; ++i){
	        if(!vis[i]){
	            dfs(i , adj , vis , st) ;
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top()) ;
	        st.pop() ;
	    }
	    
	    return ans ;
	}
};