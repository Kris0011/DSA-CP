class Solution {
public:
    void bfs(pair<int,int> p , vector< vector<bool> > & visited , vector<vector<char>>& grid , int n , int m ){
        queue< pair<int,int> >  q ;
        q.push(p) ;
        visited[p.first][p.second] = true ;
        
        while(!q.empty()){
            pair<int,int> node = q.front() ;
            int  i = node.first ;
            int j = node.second ;
            q.pop() ;
    
            for (int row = -1; row <= 1; row += 2) {
                    int r = i + row;
                    int c = j;

                    if (r >= 0 && r < n && grid[r][c] == '1' && visited[r][c] == false) {
                        visited[r][c] = true;
                        q.push(make_pair(r, c));
                    }
                }

                for (int col = -1; col <= 1; col += 2) {
                    int r = i;
                    int c = j + col;

                    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1' && visited[r][c] == false) {
                        visited[r][c] = true;
                        q.push(make_pair(r, c));
                    }
                }
           
        }
        
        return ;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector< vector<bool> > visited( n , vector<bool> (m, false)) ;
        
        queue<int> q ;
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++ ;
                    pair<int,int> p ;
                    p.first = i ; p.second = j ;
                    bfs( p , visited , grid , n , m ) ;
                }
            }
        }
        
        return count ;
    }
};