class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long val = 999;
        int i = 1;
        while(n > val) {
            ans += (n-val);
            val = val*1000 + 999;
        }

        return ans;

        // if(n > 999) {
        //     ans += (n-999);
        // }
        // if(n > 99999) {
        //     ans += (n-99999);
        // }
        // if(n > 9999999) {
        //     ans += (n-9999999);
        // }
        // if(n > 999999999) {
        //     ans += (n-999999999);
        // }
        // if(n > 99999999999) {
        //     ans += (n-99999999999);
        // }
        // if(n > 99999999999) {
        //     ans += (n-99999999999);
        // }
    }
};