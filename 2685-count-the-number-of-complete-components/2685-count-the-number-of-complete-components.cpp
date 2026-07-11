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
        // Approach - 1 -> BFS/DFS -> T.C - O(V + E) , S.C - O(V)
        //create a graph using adj list
        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // create a variable ans to track total no of complete connected components, intialise with 0
        int ans = 0;
        //Maintain a visited arr to keep track of visited status of each node
        vector<bool> vis(n, false);
        //use bfs/dfs to traverse each component and track the total no of nodes and total no of edges in it
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                int m = 0;
                int e = 0;
                dfs(i, adj, vis, m, e); // m -> total no of nodes in curr component and e -> total no of edges
                if(e == m*(m-1)) {
                    // complete component
                    ans++;
                }
            }
        }

        return ans;

    }
};