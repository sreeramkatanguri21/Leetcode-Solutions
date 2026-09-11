class Solution {
public:
    typedef long long ll;
    ll pow(ll a, ll b) {
        ll res = 1;
        while(b > 0) {
            if(b&1) {
                res *= a;
            }
            a *= a;
            b >>= 1;
        }
        return res;
    }
    int solve(string& s, int idx, int tight, int lz, int mask, int n) {
        if(idx == s.length()) {
            return 1;
        }

        int lb = 0;
        int ub = (tight)?(s[idx]-'0'):9;

        int ans = 0;
        for(int dig=lb; dig<=ub; dig++) {
            if(mask & (1 << dig)) continue;
            ans += solve(s, idx+1, (tight && (dig==ub)), (lz && dig==0),(lz && dig==0)?mask:(mask | (1 << dig)), n);
            if(n == 0) cout << ans;
        }

        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        ll val = pow(10, n)-1;
        string s = to_string(val);
        return solve(s, 0, 1, 1, 0, n);
    }
};