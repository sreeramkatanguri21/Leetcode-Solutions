class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge: connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        int cnt = 0;
        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        while(!q.empty()) {
            auto u = q.front();
            q.pop();

            for(auto [v, wt]: adj[u]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    cnt += wt;
                }
            }
        }

        return cnt;
    }
};