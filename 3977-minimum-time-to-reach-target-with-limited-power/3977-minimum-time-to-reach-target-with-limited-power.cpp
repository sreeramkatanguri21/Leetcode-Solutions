class Solution {
public:
    typedef long long ll;
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e: edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<ll>> dist(n, vector<ll>(power+1, LLONG_MAX));
        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
        dist[source][power] = 0;
        pq.push({0, power, source});

        while(!pq.empty()) {
            auto [d, p, u] = pq.top();
            pq.pop();

            if(d > dist[u][p]) continue;
            if(cost[u] > p) continue;

            for(auto [v, t]: adj[u]) {
                if(dist[u][p] + t < dist[v][p-cost[u]]) {
                    dist[v][p-cost[u]] = dist[u][p] + t;
                    pq.push({dist[v][p-cost[u]], p-cost[u], v});
                }
            }
        }

        ll mini = *min_element(dist[target].begin(), dist[target].end());
        if(mini == LLONG_MAX) return {-1, -1};

        int maxi = INT_MIN;
        for(int p=power; p>=0; p--) {
            if(dist[target][p] == mini) {
                maxi = p;
                break;
            }
        }

        return {mini, maxi};
    }
};