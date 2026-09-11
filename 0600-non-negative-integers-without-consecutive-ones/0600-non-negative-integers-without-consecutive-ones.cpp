class Solution {
public:
    int dp[30][2][2];
    int solve(string& s, int idx, int tight, int prev, int size) {
        if(idx == size) return 1;

        if(dp[idx][tight][prev] != -1) return dp[idx][tight][prev];

        int lb = 0;
        int ub = (tight)?(s[idx]-'0'):1;

        int ans = 0;
        for(int dig=lb; dig<=ub; dig++) {
            if(prev == 1 && dig == 1) continue;

            ans += solve(s, idx+1, tight && dig==ub , dig, size);
        }

        return dp[idx][tight][prev] = ans;
    }
    int findIntegers(int n) {
        int bits = log2(n)+1;
        string s = "";
        for(int i=bits-1;i>=0; i--) {
            if(n & (1 << i)) s.push_back('1');
            else s.push_back('0');
        }
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 0, bits);
    }
};