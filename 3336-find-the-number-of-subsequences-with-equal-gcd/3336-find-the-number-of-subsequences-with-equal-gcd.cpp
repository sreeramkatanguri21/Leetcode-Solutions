class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& nums, int i, int gcd1, int gcd2) {
        if(i >= nums.size()) {
            if(gcd1 != 0 && gcd2 != 0) return gcd1 == gcd2;
            return 0;
        }

        if(dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2];


        int op1 = solve(nums, i+1, (gcd1==0)?nums[i]:__gcd(gcd1, nums[i]), gcd2)%MOD;
        int op2 = solve(nums, i+1, gcd1, (gcd2 == 0)?nums[i]:__gcd(nums[i], gcd2))%MOD;
        int op3 = solve(nums, i+1, gcd1, gcd2)%MOD;

        return dp[i][gcd1][gcd2] = ((op1 + op2)%MOD + op3)%MOD;
    }
    int solveTab(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));
        dp.resize(n+1, vector<vector<int>>(maxi+1, vector<int>(maxi+1, 0)));

        for(int i=1; i<=maxi; i++) {
            dp[n][i][i] = 1;
        }
        for(int i=n-1; i>=0; i--) {
            for(int gcd1=maxi; gcd1>=0; gcd1--) {
                for(int gcd2=maxi; gcd2>=0; gcd2--) {
                    int op1 = dp[i+1][(gcd1==0)?nums[i]:__gcd(gcd1, nums[i])][gcd2]%MOD;
                    int op2 = dp[i+1][gcd1][(gcd2 == 0)?nums[i]:__gcd(nums[i], gcd2)]%MOD;
                    int op3 = dp[i+1][gcd1][gcd2]%MOD;

                    dp[i][gcd1][gcd2] = ((op1 + op2)%MOD + op3)%MOD;
                }
            }
        }


        return dp[0][0][0];
    }
    int solveTabSO(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));
        //dp.resize(n+1, vector<vector<int>>(maxi+1, vector<int>(maxi+1, 0)));
        vector<vector<int>> curr(maxi+1, vector<int>(maxi+1, 0));
        vector<vector<int>> next(maxi+1, vector<int>(maxi+1, 0));

        for(int i=1; i<=maxi; i++) {
            next[i][i] = 1;
        }
        for(int i=n-1; i>=0; i--) {
            for(int gcd1=maxi; gcd1>=0; gcd1--) {
                for(int gcd2=maxi; gcd2>=0; gcd2--) {
                    int op1 = next[(gcd1==0)?nums[i]:__gcd(gcd1, nums[i])][gcd2]%MOD;
                    int op2 = next[gcd1][(gcd2 == 0)?nums[i]:__gcd(nums[i], gcd2)]%MOD;
                    int op3 = next[gcd1][gcd2]%MOD;

                    curr[gcd1][gcd2] = ((op1 + op2)%MOD + op3)%MOD;
                }
            }
            next = curr;
        }


        return next[0][0];
    }
    int subsequencePairCount(vector<int>& nums) {
        // int n = nums.size();
        // int maxi = *max_element(begin(nums), end(nums));
        // dp.resize(n+1, vector<vector<int>>(maxi+1, vector<int>(maxi+1, -1)));
        // return solve(nums, 0, 0, 0);

        return solveTabSO(nums);
    }
};