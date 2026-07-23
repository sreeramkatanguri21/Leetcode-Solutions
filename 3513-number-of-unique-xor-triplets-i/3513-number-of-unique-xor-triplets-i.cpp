class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;

        int ans = 1;
        int i;
        for(i=31; i>=0; i--) {
            if(((n >> i) & 1)) {
                ans = 1 << i;
                break;
            }
        }

        while(i--) {
            cout << i << " ";
            ans = ans | (1 << i);
        }

        return ans+1;
    }
};