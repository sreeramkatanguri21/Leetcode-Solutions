class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(auto e: roads) {
            adj[e[0]-1].push_back({e[1]-1, e[2]});
            adj[e[1]-1].push_back({e[0]-1, e[2]});
        }
        vector<int> dist(n, INT_MAX);
        pq.push({INT_MAX, 0});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto [v, wt]: adj[u]) {
                if(min(dist[u], wt) < dist[v]) {
                    dist[v] = min(dist[u], wt);
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1];
    }
};