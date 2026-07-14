class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& nums, int i, int gcd1, int gcd2) {
        if(i >= nums.size()) {
            if(gcd1 != -1 && gcd2 != -1) return gcd1 == gcd2;
            return 0;
        }

        if(dp[i][gcd1+1][gcd2+1] != -1) return dp[i][gcd1+1][gcd2+1];


        int op1 = solve(nums, i+1, (gcd1==-1)?nums[i]:__gcd(gcd1, nums[i]), gcd2)%MOD;
        int op2 = solve(nums, i+1, gcd1, (gcd2 == -1)?nums[i]:__gcd(nums[i], gcd2))%MOD;
        int op3 = solve(nums, i+1, gcd1, gcd2)%MOD;

        return dp[i][gcd1+1][gcd2+1] = ((op1 + op2)%MOD + op3)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));
        dp.resize(n, vector<vector<int>>(maxi+2, vector<int>(maxi+2, -1)));
        return solve(nums, 0, -1, -1);
    }
};