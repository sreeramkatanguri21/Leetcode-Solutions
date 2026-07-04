class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n, INT_MIN);

        maxi[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            maxi[i] = max(nums[i], maxi[i+1]);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(i+k < n) ans = max(ans, nums[i]+maxi[i+k]);
        }

        return ans;
    }
};