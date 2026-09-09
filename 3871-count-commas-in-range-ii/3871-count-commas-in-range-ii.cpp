class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long val = 999;
        while(n > val) {
            ans += (n-val);
            val = val*1000 + 999;
        }

        return ans;
    }
};