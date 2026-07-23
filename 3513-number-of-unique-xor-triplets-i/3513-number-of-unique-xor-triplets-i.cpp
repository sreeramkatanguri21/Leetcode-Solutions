class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;

        int i;
        for(i=31; i>=0; i--) {
            if((n >> (i-1) & 1)) return (1 << i);
        }

        return -1;
    }
};