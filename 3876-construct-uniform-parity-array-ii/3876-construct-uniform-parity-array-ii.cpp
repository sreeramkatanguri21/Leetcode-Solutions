class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minEven = INT_MAX;
        int minOdd = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]&1) minOdd = min(minOdd, nums[i]);
            else minEven = min(minEven, nums[i]);
        }

        if(minEven == INT_MAX || minOdd == INT_MAX) return true;

        if((minEven-minOdd) >= 1) return true;
        else return false;
        
    }
};