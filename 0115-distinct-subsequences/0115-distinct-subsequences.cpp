class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int solve(int i, int j, string& s, string& t) {
        if(i == m & j == n) return 1;
        if(i == m && j != n) return 0;
        if(i != m && j == n) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) {
            return dp[i][j] = solve(i+1, j+1, s, t) + solve(i+1, j, s, t);
        }
        else {
            return dp[i][j] = solve(i+1, j, s, t);
        }
    }
    int numDistinct(string s, string t) {
        m = s.length();
        n = t.length();
        dp.resize(m+1, vector<int>(n+1, -1));
        return solve(0, 0, s, t);
    }
};