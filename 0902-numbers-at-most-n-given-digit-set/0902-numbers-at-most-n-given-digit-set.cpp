class Solution {
public:
    int dp[10][2][2];
    int solve(string& s, int idx, int tight, int lz, vector<string>& digits) {
        if(idx == s.length()) return 1;
        if(dp[idx][tight][lz] != -1) return dp[idx][tight][lz];
        int ans = 0;
        for(int i=0; i<digits.size(); i++) {
            int dig = stoi(digits[i]);
            if((tight && dig > s[idx]-'0') || (!lz && dig == 0)) {
                continue;
            }

            ans += solve(s, idx+1, tight && (dig == s[idx]-'0'), lz && dig==0, digits);
        }

        return dp[idx][tight][lz] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        digits.push_back("0");
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 1, digits)-1;
    }
};