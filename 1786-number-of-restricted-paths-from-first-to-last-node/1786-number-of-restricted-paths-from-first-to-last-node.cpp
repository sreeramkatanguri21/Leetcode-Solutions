class Solution {
public:
    int MOD = 1e9+7;
    int solve(int src, int des, vector<vector<pair<int,int>>>& adj, vector<int>& dist) {
        if(src == des) {
            return 1;
        }

        int ans = 0;
        for(auto [v, wt]: adj[src]) {
            if(dist[src] > dist[v]) {
                ans += solve(v, des, adj, dist);
            }
        }

        return ans;
    }
    int solveMem(int src, int des, vector<vector<pair<int,int>>>& adj, vector<int>& dist, vector<int>& dp) {
        if(src == des) {
            return 1;
        }
        if(dp[src] != -1) return dp[src];

        int ans = 0;
        for(auto [v, wt]: adj[src]) {
            if(dist[src] > dist[v]) {
                ans = (ans + solveMem(v, des, adj, dist, dp))%MOD;
            }
        }

        return dp[src] = ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto e: edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[n] = 0;
        pq.push({0, n});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto [v, wt]: adj[u]) {
                if(dist[u]+wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        vector<int> dp(n+1, -1);
        return solveMem(1, n, adj, dist, dp);
    }
};