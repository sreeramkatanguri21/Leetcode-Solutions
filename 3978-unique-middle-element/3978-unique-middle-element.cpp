class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto num: nums) freq[num]++;

        return freq[nums[nums.size()/2]] == 1;
    }
};