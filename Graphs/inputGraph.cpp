#include <bits/stdc++.h>
using namespace std ;

int main() {
    int n , m ;
    cin >> n >> m;

    vector< vector< pair<int,int> > > adj ;   // Store as a list format

    for(int i=0 ; i<m ; i++){
        int u , v , weight; 
        cin >> u >> v >> weight;

        // both index should store bcz of undirected graph
        // first part of pair will denote the node and second will be weight
        adj[u].push_back(make_pair(v,weight));   
        adj[v].push_back(make_pair(u,weight));
        
    }


    int adj2[n+1][m+1] ; // To store in matrix format

    for( int i=0;i<m;++i){
        int u , v, weight ;
        cin >> u ,  v , weight ;

        //Taking intersection of both values and storing the weight into it 

        adj2[u][v] = weight ;
        adj2[v][u] = weight ;
    }




    return 0;
}