class Solution {
public:
        void bfs(pair<int,int> p , vector< vector<bool> > & visited , vector<vector<int>>& grid , int n , int m , int color , int newColor){    
        queue< pair<int,int> >  q ;
        q.push(p) ;
        visited[p.first][p.second] = true ;
        grid[p.first][p.second] = newColor ;
        
        while(!q.empty()){
            pair<int,int> node = q.front() ;
            int  i = node.first ;
            int j = node.second ;
            q.pop() ;
    
            for (int row = -1; row <= 1; row += 2) {
                int r = i + row;
                int c = j;

                if (r >= 0 && r < n && grid[r][c] == color && visited[r][c] == false) {
                    visited[r][c] = true;
                    grid[r][c] = newColor;
                    q.push(make_pair(r, c));
                }
            }

            for (int col = -1; col <= 1; col += 2) {
                int r = i;
                int c = j + col;

                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == color && visited[r][c] == false) {
                    visited[r][c] = true;
                    grid[r][c] = newColor;
                    q.push(make_pair(r, c));
                }
            }
           
        }
        
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        pair<int,int> node ;
        int n = image.size() ;
        int m = image[0].size(); 
        node.first = sr ;
        node.second = sc ;
        vector< vector<bool> > visited( n , vector<bool> (m, false)) ;
        
        int color = image[sr][sc] ;
        
        bfs( node , visited , image , n , m , color , newColor  );
        
        return image ;
        
    }
};