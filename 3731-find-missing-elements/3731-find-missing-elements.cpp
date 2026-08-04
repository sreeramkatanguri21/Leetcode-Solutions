class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        auto [mini, maxi] = ranges::minmax(nums);
        vector<int> ans;
        for(int i=mini+1; i<maxi; i++) {
            if(!st.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};