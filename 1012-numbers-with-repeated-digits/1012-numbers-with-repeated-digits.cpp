class Solution {
public:
    int dp[10][2][2][1<<10][2];
    int solve(string& s, int idx, int tight, int lz, int mask, int isRepeated) {
        if(idx == s.length()) return isRepeated;
        if(dp[idx][tight][lz][mask][isRepeated] != -1) return dp[idx][tight][lz][mask][isRepeated];
        int lb = 0;
        int ub = tight?(s[idx]-'0'):9;

        int ans = 0;
        for(int dig=lb; dig<=ub; dig++) {
            ans += solve(s, idx+1, tight && dig==ub, lz && dig==0, (lz && dig==0)?mask: (mask | (1 << dig)), isRepeated || mask & (1 << dig));
        }

        return dp[idx][tight][lz][mask][isRepeated] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 1, 0, 0);
    }
};