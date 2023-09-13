class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({S,0});
        
        vector<int> ans(V,1e9);
        vector<bool> visited (V,false) ;
        
        ans[S] =  0 ;
    
        while(!pq.empty()){
            vector<int> node = pq.top() ;
            pq.pop() ;
     
            for(auto it : adj[node[0]]){
                if( it[1]+node[1] < ans[it[0]] ){
                    ans[it[0]] = it[1]+node[1] ;
                    pq.push( {it[0] , ans[it[0]]});
                }
            }
            
            
            
        }
        
        return ans;
        
    }
};