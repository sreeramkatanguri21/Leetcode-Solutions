class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(n, 0));
        vector<int> degree(n, 0);
        for(auto e: roads) {
            adj[e[0]][e[1]] = 1;
            adj[e[1]][e[0]] = 1;
            degree[e[0]]++;
            degree[e[1]]++;
        }
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                maxi = max(maxi, adj[i][j]?(degree[i]+degree[j]-1):(degree[i]+degree[j]));
            }
        }

        return maxi;
    }
};