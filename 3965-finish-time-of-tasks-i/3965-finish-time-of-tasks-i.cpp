class Solution {
public:
    typedef long long ll;
    ll solve(int root, int n, vector<vector<int>>& adj, vector<int>& baseTime) {
        if(adj[root].size() == 0) return baseTime[root];

        ll e = LLONG_MAX;
        ll l = LLONG_MIN;

        for(auto v: adj[root]) {
            auto it = solve(v, n, adj, baseTime);
            e = min(e, it);
            l = max(l, it);
        }

        ll f = (l-e+(ll)baseTime[root])+l;

        return f;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        auto ans = solve(0, n, adj, baseTime);
        return ans;
    }
};