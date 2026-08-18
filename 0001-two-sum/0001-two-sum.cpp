class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mpp; // {num, idx};

        for(int i=0; i<n; i++) {
            if(mpp.count(target-nums[i])) {
                return {mpp[target-nums[i]], i};
            }

            mpp[nums[i]] = i;
        }

        return {-1, -1};
        
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         if(nums[i] + nums[j] == target) return {i, j};
        //     }
        // }

        // return {-1, -1};
    }
};