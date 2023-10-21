class Solution {
public:

    void bfs( vector<vector<int>>& heights , vector<vector<int>> &visited , queue< pair<int,int>> q , int n , int m){

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()){
            int r = q.front().first ;
            int c = q.front().second ;
            int node = heights[r][c] ;
            q.pop() ;

            for (int i = 0; i < 4; i++) {
                int newRow = r + dr[i];
                int newCol = c + dc[i];

                if ( newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && heights[newRow][newCol]>= node && visited[newRow][newCol] == 0 ){
                    visited[newRow][newCol] = 1 ;
                    q.push({newRow,newCol}) ;
                }
            }


        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size() ;
        int m = heights[0].size() ;
        vector<vector<int>> ans ;
        vector<vector<int>> pacific( n , vector<int> (m,0)) ;
        vector<vector<int>> atlantic( n , vector<int> (m,0)) ;

        queue< pair<int,int> > q1 ;
        queue< pair<int,int> > q2 ;

        for(int i=0 ; i<m ;i++){
            pacific[0][i] = 1 ;
            q1.push({0,i}) ;

            atlantic[n-1][i] = 1 ;
            q2.push({n-1,i}) ;
        }
        for(int i=0 ; i< n ;i++){
            pacific[i][0] = 1 ;
            q1.push({i,0}) ;

            atlantic[i][m-1] = 1 ;
            q2.push({i,m-1}) ;
        }

    

        bfs(heights , pacific , q1 , n , m) ;
        bfs(heights , atlantic , q2 , n , m) ;


        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<m ; j++){
                if( pacific[i][j] && atlantic[i][j] ){
                    ans.push_back({i,j}) ;
                }
            }
        }

        return ans ;
        
    }
};