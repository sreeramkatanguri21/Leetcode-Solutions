class DisjointSet{
    vector<int> parent, rank, size;
    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i=0; i<n+1; i++) {
                parent[i] = i;
            }
        }

        int findParent(int u) {
            if(u == parent[u]) return u;
            return parent[u] = findParent(parent[u]);
        }

        void unionByRank(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            }
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }

        void unionBySize(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m*n);

        vector<int> vis(m*n, 0);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    vis[i*n+j] = 1;
                    if(i-1 >= 0 && grid[i-1][j] == '1') {
                        ds.unionBySize(i*n+j, (i-1)*n+j);
                        vis[(i-1)*n+j] = 1;
                    }
                    if(j-1 >= 0 && grid[i][j-1] == '1') {
                        ds.unionBySize(i*n+j, i*n+j-1);
                        vis[i*n+j-1] = 1;
                    }
                }
            }
        }
        
        int cnt = 0;
        for(int i=0; i<m*n; i++) {
            if(vis[i] && i == ds.findParent(i)) cnt++;
        }

        return cnt;
    }
};