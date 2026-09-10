class Solution {
public:
    typedef long long ll;
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        ll totalSum = accumulate(begin(nums), end(nums), 0LL);
        ll sum = 0;
        for(int i=n/2; i<n; i++) {
            sum += nums[i];
        }
        int cnt = 0;
        if(sum != totalSum-sum) cnt++;
        for(int i=0; i<n/2-1; i++) {
            sum -= nums[n-n/2+i];
            sum += nums[i];

            if(2*sum != totalSum) cnt++;
        }

        return cnt;
    }
};