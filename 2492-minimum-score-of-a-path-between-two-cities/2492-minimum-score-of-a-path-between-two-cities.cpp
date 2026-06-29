class DisjointSet{
    vector<int> parent, rank, size, dist;
    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            dist.resize(n+1, INT_MAX);
            parent.resize(n+1);
            for(int i=0; i<n+1; i++) {
                parent[i] = i;
            }
        }

        int findParent(int u) {
            if(u == parent[u]) return u;
            return parent[u] = findParent(parent[u]);
        }

        void unionBySize(int u, int v, int wt) {
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) {
                dist[pu] = min(dist[pu], wt);
                return;
            }

            if(size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
                dist[pv] = min({dist[pv], dist[pu], wt});
            }
            else {
                parent[pv] = pu;
                size[pu] += size[pv];
                dist[pu] = min({dist[pv], dist[pu], wt});
            }
        }

        int getDist(int u) {
            return dist[u];
        }
};

class Solution {
public:
    void dfs(int src, int n, vector<vector<pair<int,int>>>& adj, vector<int>& vis, int& ans) {
        vis[src] = 1;

        for(auto [v, wt]: adj[src]) {
            if(!vis[v]) {
                dfs(v, n, adj, vis, ans);
            }
            ans = min(ans, wt);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        DisjointSet ds(n);

        for(auto edge: roads) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            ds.unionBySize(u, v, wt);
        }

        int p = ds.findParent(1);
        return ds.getDist(p);



        // vector<vector<pair<int,int>>> adj(n);
        // for(auto e: roads) {
        //     adj[e[0]-1].push_back({e[1]-1, e[2]});
        //     adj[e[1]-1].push_back({e[0]-1, e[2]});
        // }
        // vector<int> vis(n, 0);
        // int ans = INT_MAX;
        // dfs(0, n, adj, vis, ans);
        // return ans;







        // priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // vector<vector<pair<int,int>>> adj(n);
        // for(auto e: roads) {
        //     adj[e[0]-1].push_back({e[1]-1, e[2]});
        //     adj[e[1]-1].push_back({e[0]-1, e[2]});
        // }
        // vector<int> dist(n, INT_MAX);
        // pq.push({INT_MAX, 0});

        // while(!pq.empty()) {
        //     auto [d, u] = pq.top();
        //     pq.pop();

        //     if(d > dist[u]) continue;

        //     for(auto [v, wt]: adj[u]) {
        //         if(min(dist[u], wt) < dist[v]) {
        //             dist[v] = min(dist[u], wt);
        //             pq.push({dist[v], v});
        //         }
        //     }
        // }

        // return dist[n-1];
    }
};