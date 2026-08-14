class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = 0;
        int l = 0;
        int r = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;
        while(r < n) {
            mpp[nums[r]]++;
            if(mpp[nums[r]] > k) cnt++;
            if(cnt > 0) {
                if(mpp[nums[l]] > k) cnt--;
                mpp[nums[l]]--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;

        // int l = 0;
        // int r =  0;
        // int n = nums.size();
        // unordered_map<int, int> freq;
        // int maxLen = 0;
        // while(r < n) {
        //     freq[nums[r]]++;
        //     while(freq[nums[r]] > k) {
        //         freq[nums[l]]--;
        //         l++;
        //     }

        //     maxLen = max(maxLen, r-l+1);
        //     r++;
        // }

        // return maxLen;
    }
};