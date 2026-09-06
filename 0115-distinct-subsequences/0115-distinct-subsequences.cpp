class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int solve(int i, int j, string& s, string& t) {
        if(i == m & j == n) return 1;
        if(i == m && j != n) return 0;
        if(i != m && j == n) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s[i] == t[j]) {
            ans = solve(i+1, j+1, s, t);
        }

        ans += solve(i+1, j, s, t);

        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        m = s.length();
        n = t.length();
        dp.resize(m+1, vector<int>(n+1, -1));
        return solve(0, 0, s, t);
    }
};