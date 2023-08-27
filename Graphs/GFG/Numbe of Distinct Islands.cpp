class Solution {
  public:
    
    
    void bfs(int node_row , int node_col , vector<vector<int>>& grid , vector<vector<bool>> &visited , set < vector< int > > & ans , int n , int m ){
        queue<pair<int,int>> q ;
        vector < pair<int,int> > temp ;
        vector<int> v ;
        q.push({node_row,node_col});
        visited[node_row][node_col] = true;
        pair<int,int> base = {node_row,node_col};
        
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second ;
            temp.push_back(q.front()) ;
            // temp.insert(q.front()) ;
            q.pop() ;
            
            for (int row = -1; row <= 1; row += 2) {
                    int r = i + row;
                    int c = j;

                    if (r >= 0 && r < n && grid[r][c] == 1 && visited[r][c] == false) {
                        visited[r][c] = true;
                        q.push(make_pair(r, c));
                    }
                }

                for (int col = -1; col <= 1; col += 2) {
                    int r = i;
                    int c = j + col;

                    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && visited[r][c] == false) {
                        visited[r][c] = true;
                        q.push(make_pair(r, c));
                    }
                }
                
            
        }
        
        // cout << "New set " << endl;
        sort(temp.begin(),temp.end()) ;
        for(auto it : temp){
            it.first  -= base.first ;
            it.second -= base.second ;
            // cout << it.first << " " << it.second << endl;
            v.push_back(it.first);
            v.push_back(it.second);
        }
        
        ans.insert(v) ;
        
    }
    
  
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size() ;
        int m = grid[0].size() ;
    
        set < vector< int > > ans ;
        vector<vector<bool>> visited ( n , vector<bool> (m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j] == false) {
                    bfs(i,j,grid,visited,ans,n,m);
                }
            }
        }
        
        return ans.size() ;
        
        
        
    }
};