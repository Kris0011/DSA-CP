#include <bits/stdc++.h>
using namespace std ;
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



int main() {
    return 0;
}