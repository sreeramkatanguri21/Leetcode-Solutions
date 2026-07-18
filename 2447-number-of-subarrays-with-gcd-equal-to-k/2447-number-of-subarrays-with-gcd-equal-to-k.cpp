class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            int val = nums[i];
            for(int j=i; j<n; j++) {
                val = gcd(val, nums[j]);
                cnt += val==k;
            }
        }

        return cnt;
    }
};