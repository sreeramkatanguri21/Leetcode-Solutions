class Solution {
public:
    int solve(vector<int>& nums, int i, int j) {
        if(i > j) return 0;

        int ans1 = nums[i] - solve(nums, i+1, j);
        int ans2 = nums[j] - solve(nums, i, j-1);

        return max(ans1,ans2);
    }
    int solveMem(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans1 = nums[i] - solveMem(nums, i+1, j, dp);
        int ans2 = nums[j] - solveMem(nums, i, j-1, dp);

        return dp[i][j] = max(ans1,ans2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solveMem(nums, 0, n-1, dp)>=0;
    }
};