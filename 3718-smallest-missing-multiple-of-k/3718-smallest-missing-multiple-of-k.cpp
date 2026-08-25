class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(begin(nums), end(nums));
        int i = 1;
        while(true) {
            if(!st.count(k*i)) return k*i;
            i++;
        }

        return -1;
    }
};