class Solution {
public:
    void dfs(int k, vector<vector<int>>& adj, vector<bool>& infected) {
        infected[k] = true;

        for(auto v: adj[k]) {
            if(!infected[v]) {
                dfs(v, adj, infected);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto e: invocations) {
            adj[e[0]].push_back(e[1]);
        }
        vector<bool> infected(n, false);
        dfs(k, adj, infected);
        bool allNodes = false;
        for(int i=0; i<n; i++) {
            if(!infected[i]) {
                for(auto v: adj[i]) {
                    if(infected[v]) {
                        allNodes = true;
                        break;
                    }
                }
            }
            if(allNodes) break;
        }

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(allNodes || !infected[i]) ans.push_back(i);
        }

        return ans;
    }
};