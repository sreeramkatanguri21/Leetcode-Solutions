class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> v;
        int n = arr.size();

        for(int i=0; i<n; i++) {
            v.push_back({arr[i], i});
        }

        sort(begin(v), end(v));
        int rank = 1;
        vector<int> ans(n);
        
        for(int i=0; i<n; i++) {
            if(i-1 >= 0 && v[i-1].first != v[i].first) rank++;
            ans[v[i].second] = rank; 
        }

        return ans;
    }
};