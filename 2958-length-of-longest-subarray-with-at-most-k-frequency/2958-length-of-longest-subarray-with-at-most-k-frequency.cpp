class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int r =  0;
        int n = nums.size();
        unordered_map<int, int> freq;
        int maxLen = 0;
        while(r < n) {
            freq[nums[r]]++;
            while(freq[nums[r]] > k) {
                freq[nums[l]]--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};