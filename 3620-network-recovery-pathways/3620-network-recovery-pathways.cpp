class Solution {
public:
    typedef long long ll;
    bool isPossible(int n, vector<vector<pair<int, int>>>& adj, vector<bool>& online, long long k, int w) {

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        vector<ll> dist(n, LLONG_MAX);
        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto [v, wt]: adj[u]) {
                if(online[v] && wt >= w && dist[u]+wt < dist[v]) {
                    dist[v] = dist[u]+wt;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int s = INT_MAX;
        int e = INT_MIN;
        for(auto edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            s = min(s, edge[2]);
            e = max(e, edge[2]);
        }
        int ans = -1;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(isPossible(n, adj, online, k, mid)) {
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }

        return ans;
    }
};