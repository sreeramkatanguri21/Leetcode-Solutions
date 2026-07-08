class Solution {
public:
    int mod = 1e9 + 7;
    typedef long long ll;
    ll pow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<ll> prefSum(n, 0);
        vector<ll> prefNonZeroNum(n, 0);
        vector<ll> prefNonZeroCnt(n, 0);

        for (int i=0; i<n; i++) {
            int digit = s[i] - '0';

            if (i) {
                prefSum[i] = prefSum[i-1];
                prefNonZeroNum[i] = prefNonZeroNum[i-1];
                prefNonZeroCnt[i] = prefNonZeroCnt[i-1];
            }

            if (digit) {
                prefSum[i] = (prefSum[i] + digit) % mod;
                prefNonZeroCnt[i]++;
                prefNonZeroNum[i] = (prefNonZeroNum[i] * 10 + digit) % mod;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            ll sum = prefSum[r] - (l ? prefSum[l-1] : 0);
            sum = (sum % mod + mod) % mod;

            ll cnt = prefNonZeroCnt[r] - (l ? prefNonZeroCnt[l-1] : 0);
            ll num = prefNonZeroNum[r] - (l ? (prefNonZeroNum[l-1] * pow(10, cnt)) % mod : 0);
            num = (num % mod + mod) % mod;

            ans.push_back((int)((sum * num) % mod));
        }

        return ans;
    }
};