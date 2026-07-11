class DisjointSet{
    vector<int> parent, rank, size, edgeSize;
    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            edgeSize.resize(n+1, 0);
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

            if(pu == pv) {
                edgeSize[pu]++;
                return;
            }

            if(size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
                edgeSize[pv] += edgeSize[pu] + 1;
            }
            else {
                parent[pv] = pu;
                size[pu] += size[pv];
                edgeSize[pu] += edgeSize[pv] + 1;
            }
        }

        int getEdgeSize(int u) {
            return edgeSize[u];
        }

        int getSize(int u) {
            return size[u];
        }
};
class Solution {
public:
    void dfs(int src, vector<vector<int>>& adj, vector<bool>& vis, int &m, int &e) {
        vis[src] = true;
        m++; 

        // traverse all neighbouring nodes
        for(auto v: adj[src]) {
            e++; // (src - v) -> edge found
            if(!vis[v]) {
                dfs(v, adj, vis, m, e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Approach - 2 -> DSU -> T.C - O((V + E)*(alpha)) , S.C - O(V)

        //create a dsu
        DisjointSet ds(n);
        //iterate over the edge list and connect the nodes using DSU, along with keep track of total number of edges in each component using edgeSize arr
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            ds.unionBySize(u, v);
        }

        // traverse over each component and check if it is complete
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(i == ds.findParent(i)) {
                int e = ds.getEdgeSize(i);
                int m = ds.getSize(i);
                if(e == m*(m-1)/2) ans++;
            }
        }

        return ans;




        // // Approach - 1 -> BFS/DFS -> T.C - O(V + E) , S.C - O(V)
        // //create a graph using adj list
        // vector<vector<int>> adj(n);
        // for(auto edge: edges) {
        //     int u = edge[0];
        //     int v = edge[1];

        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        // // create a variable ans to track total no of complete connected components, intialise with 0
        // int ans = 0;
        // //Maintain a visited arr to keep track of visited status of each node
        // vector<bool> vis(n, false);
        // //use bfs/dfs to traverse each component and track the total no of nodes and total no of edges in it
        // for(int i=0; i<n; i++) {
        //     if(!vis[i]) {
        //         int m = 0;
        //         int e = 0;
        //         dfs(i, adj, vis, m, e); // m -> total no of nodes in curr component and e -> total no of edges
        //         if(e == m*(m-1)) {
        //             // complete component
        //             ans++;
        //         }
        //     }
        // }

        // return ans;

    }
};