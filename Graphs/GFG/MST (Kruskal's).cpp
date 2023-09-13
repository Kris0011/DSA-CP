
class DSU {
    vector<int> parent, rank;

public:
    DSU(int v) {
        parent.resize(v + 1);
        rank.resize(v + 1, 0);
        for (int i = 0; i <= v; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pv] > rank[pu]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        DSU dSet(V);
        vector<vector<int>> edges;

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int v = it[0], w = it[1];
                edges.push_back({w, i, v});
            }
        }
        
        sort(edges.begin() , edges.end()) ;

        int sum = 0;
        
        for(auto it : edges ){
            int w = it[0];
            int u = it[1] ;
            int v = it[2] ;
            
            if (dSet.find(u) != dSet.find(v)) {
                sum += w;
                dSet.unionByRank(u, v);
            }
        }

        return sum;
    }
};
