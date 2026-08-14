class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++) {
            unordered_map<int,int> mpp;
            for(int j=i; j<n; j++) {
                mpp[s[j]]++;
                if(mpp[s[j]] > 2) break;

                ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};