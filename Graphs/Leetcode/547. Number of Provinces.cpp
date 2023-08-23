class Solution {
public:


    void dfs(int node ,vector<int>adj[], int V , vector<bool> & visited){
        
        visited[node] = true;
    
        for(auto it: adj[node]){
            
            if(!visited[it]) {
                dfs(it , adj , V , visited  ) ;
            }
        }
        return ;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V = isConnected.size() ;
        vector<int>adj[V+1];
        int i=1;
        
        for(auto& v: isConnected)
        {
            int j=0;
            for(auto& v1:v)
            {
                j++;
                if(v1==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                
            }
            i++;
        }
        
        
        vector<bool> visited(V+1,false) ;
        int count = 0 ;
        
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                
                count ++ ;
                dfs( i , adj , V , visited) ;
            }
        }
        return count ;
    }
};