class Solution {
public:
    int ans = -1;
    void dfs(int src, int& t, vector<int>& edges, vector<int>& curr, vector<bool>& vis) {
        vis[src] = true;
        curr[src] = t++;

        if(edges[src] != -1) {
            if(vis[edges[src]] && curr[edges[src]] != -1) {
                ans = max(ans, t-curr[edges[src]]);
            }
            else if(!vis[edges[src]]) {
                dfs(edges[src], t, edges, curr, vis);
            }
        }

        curr[src] = -1;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, false);
        vector<int> curr(n, -1);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                int t = 0;
                dfs(i, t, edges, curr, vis);
            }
        }

        return ans;
    } 
};