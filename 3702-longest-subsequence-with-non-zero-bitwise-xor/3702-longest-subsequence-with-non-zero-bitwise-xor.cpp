class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_ = 0;
        bool hasNonZero = false;

        for(auto& num: nums) {
            xor_ ^= num;
            if(num != 0) hasNonZero = true;
        }

        if(xor_ != 0) return nums.size();
        else {
            if(hasNonZero) return nums.size()-1;
            else return 0;
        }
    }
};