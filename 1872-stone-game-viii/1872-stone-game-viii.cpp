class Solution {
public:
    int n;
    int solve(vector<int>& stones, vector<int>& pre, int i, vector<int>& dp) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
            int ans = INT_MIN;
            for(int j=(i==0)?i+1:i; j<n; j++) {
                ans = max(ans, pre[j] - solve(stones, pre, j+1, dp));
            }
            return dp[i] = ans;

    }
    int solveTab(vector<int>& stones, vector<int>& pre) {
        vector<int> dp(n+1, 0);
        dp[n-1] = pre[n-1];
        for(int i=n-2; i>=0; i--) {
            if(i == 0) dp[i] = dp[i+1];
            else dp[i] = max(dp[i+1], pre[i]-dp[i+1]);
        }

        return dp[0];
    }
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<int> pre(n, 0);

        pre[0] = stones[0];
        for(int i=1; i<n; i++) {
            pre[i] = pre[i-1] + stones[i];
        }
        // vector<int> dp(n, -1);
        // return solve(stones, pre, 0, dp);
        return solveTab(stones, pre);
    }
};