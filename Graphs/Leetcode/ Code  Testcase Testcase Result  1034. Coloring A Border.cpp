class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int parentColor = grid[row][col] ;
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> visited ( n , vector<int>(m,0));
        queue < pair<int,int> > q ;
        q.push({row,col}) ;
        visited[row][col] =1 ;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            int r = q.front().first ;
            int c = q.front().second ;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = r + dr[i];
                int newCol = c + dc[i];

                if ( newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol]== parentColor && visited[newRow][newCol]==0){
                    visited[newRow][newCol] = 1 ;
                    q.push({newRow,newCol}) ;
                }
            }
        }

        for(auto i : visited){
            for(auto j : i){
                cout << j << " " ;
            }
            cout << endl;
        }

        for(int r=0 ; r<n ;r++){
            for(int c=0;c<m;c++){

                if( (r==0 || c==0 || r==n-1 || c==m-1) && visited[r][c]==1) {
                    // cout << r << " " << c << endl;
                    grid[r][c] = color ;
                    continue;
                }

                int flag = 0 ;

                for (int i = 0; i < 4; i++) {
                    int newRow = r + dr[i];
                    int newCol = c + dc[i];

                    if ( newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && visited[newRow][newCol]==0 && visited[r][c] ==1){
                    
                        // cout << r << " " << c << endl;
                        flag = 1 ;
                        break;
                    }
                        
                }
                if(flag){
                    grid[r][c] = color ;
                }
            }
        }

        return grid ;
    }
};