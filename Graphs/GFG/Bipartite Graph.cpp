class Solution {
public:

    bool check(int V , int start , vector<int>adj[] , vector<int>& color){
        
	    queue<int> q  ;
	    q.push(start) ;
	    color[start] = 0 ;
	    
	    while(!q.empty()){
	        int node= q.front();
	       // cout << node << " " << color[node] << endl;
	        q.pop() ;
	        for(auto it : adj[node]){
	            if(color[it] == -1){
	                color[it] = (color[node]? 0 :1 ) ;
	                q.push(it) ;
	            }
	            else if(color[it] == color[node]){
	                return false;                
	             }
	        } 
	    }
	    return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1) ;
	    
	    for(int i=0;i<V;i++){
	        if(color[i] == -1 ){
	            bool ans = check(V,i,adj,color);
	            if(ans == false){
	                return false;
	            }
	        }
	    }
	    return true;
	    
	    
	}

};