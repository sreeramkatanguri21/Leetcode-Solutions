class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();

        return min({max(maxi, mini)+1, max(n-maxi, n-mini), mini+1+n-maxi, maxi+1+n-mini});
    }
};