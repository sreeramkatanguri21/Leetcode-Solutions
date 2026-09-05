class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mini(n, nums.back());
        vector<int> maxi(n, nums.front());


        for(int i=1; i<n; i++) {
            maxi[i] = max(maxi[i-1], nums[i]);
            mini[n-i-1] = min(mini[n-i], nums[n-i-1]);
        }


        for(int i=0; i<n; i++) {
            if(maxi[i]-mini[i] <= k) return i;
        }

        return -1;
    }
};