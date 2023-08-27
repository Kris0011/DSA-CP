class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
	    int m = grid[0].size() ;
	    vector<vector<bool> > visited (n, vector<bool> (m, false)) ;
	    vector<vector<int> > mat (n, vector<int> (m, 0)) ;
	    
	    queue < vector<int> > q ;
	    
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j] == 0){
	                visited[i][j] = true;
	                q.push({i,j,0});
	            }
	            
	        }
	    }
	    
	    
	    while(!q.empty()){
	        int i = q.front()[0];
	        int j = q.front()[1];
	        int d = q.front()[2];
					q.pop();
	        
	        mat[i][j] = d ;
	        
	        
	        for (int row = -1; row <= 1; row += 2) {
                int r = i + row;
                int c = j;

                if (r >= 0 && r < n  && visited[r][c] == false) {
                    visited[r][c] = true;
                    q.push({ r , c , d+1});
                }
            }

            for (int col = -1; col <= 1; col += 2) {
                int r = i;
                int c = j + col;

                if (r >= 0 && r < n && c >= 0 && c < m && visited[r][c] == false) {
                    visited[r][c] = true;
                    q.push({ r , c , d+1});
                }
            }
	    }
	    
	    
	    return mat ;
    }
};