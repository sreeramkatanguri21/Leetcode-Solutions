class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_map<int, bool> vis;
        for(auto num: nums) {
            mini = min(mini, num);
            maxi = max(maxi, num);

            vis[num] = true;
        }
        vector<int> ans;
        for(int i=mini; i<=maxi; i++) {
            if(!vis.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};