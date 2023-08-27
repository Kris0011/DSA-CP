class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size() ;
        vector<vector<bool>> visited( n , vector<bool> (m,false)) ;
        queue<pair<int,int>> q;
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;++j){
                if( (i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1){
                    visited[i][j] = true;
                    q.push({i,j}) ;
                }
            }
        }
        

        while(!q.empty()){
            int i=q.front().first ;
            int j=q.front().second ;
            q.pop();

            for (int row = -1; row <= 1; row += 2) {
                int r = i + row;
                int c = j;

                if (r >= 0 && r < n  && visited[r][c] == false && grid[i][j]==1) {
                    visited[r][c] = true;
                    q.push({ r , c });
                }
            }

            for (int col = -1; col <= 1; col += 2) {
                int r = i;
                int c = j + col;

                if (r >= 0 && r < n && c >= 0 && c < m && visited[r][c] == false && grid[i][j]==1) {
                    visited[r][c] = true;
                    q.push({ r , c });
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;++j){
                if( visited[i][j]==false && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count ;
    }
};