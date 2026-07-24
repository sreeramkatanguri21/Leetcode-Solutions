class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist1(n+1, INT_MAX);
        vector<int> dist2(n+1, INT_MAX);
        queue<pair<int, int>> q;
        q.push({1, 0});
        dist1[1] = 0;

        while(!q.empty()) {
            auto [u, t] = q.front();
            q.pop();

            if(u == n && t == dist2[u]) return dist2[u];

            int color = ((t/change) & 1);
            int extraTime = change - t%change;

            for(auto v: adj[u]) {
                int d = t+time+(color==1?extraTime:0);

                if(dist1[v] == INT_MAX) {
                    dist1[v] = d;
                    q.push({v, dist1[v]});
                }
                else if(dist1[v] == d) continue;
                else if(dist2[v] == INT_MAX) {
                    dist2[v] = d;
                    q.push({v, dist2[v]});
                }
            }
        }
        
        return -1;
    }
};