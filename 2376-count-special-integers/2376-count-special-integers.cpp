class Solution {
public:
    typedef long long ll;
    int dp[10][2][2][(1 << 10)];
    int solve(string& s, int idx, int tight, int lz, int mask, int n) {
        if(idx == s.length()) {
            return 1;
        }

        if(dp[idx][tight][lz][mask] != -1) return dp[idx][tight][lz][mask];

        int lb = 0;
        int ub = (tight)?(s[idx]-'0'):9;

        int ans = 0;
        for(int dig=lb; dig<=ub; dig++) {
            if(mask & (1 << dig)) continue;
            ans += solve(s, idx+1, (tight && (dig==ub)), (lz && dig==0),(lz && dig==0)?mask:(mask | (1 << dig)), n);
        }

        return dp[idx][tight][lz][mask] = ans;
    }
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 1, 0, n)-1;
    }
};
