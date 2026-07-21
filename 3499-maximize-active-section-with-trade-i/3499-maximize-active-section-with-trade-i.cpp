class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int maxi = 0;
        int one = 0;
        int cnt = 0;
        vector<int> zero;
        for(int i=0; i<n; i++) {
            if(s[i] == '0') cnt++;
            else if(s[i] == '1') {
                one++;
                if(cnt!=0)zero.push_back(cnt);
                cnt = 0;
            }
        }
        if(cnt!=0)zero.push_back(cnt);
        for(int i=0; i < ((int)zero.size()-1); i++) {
            maxi = max(maxi, zero[i]+zero[i+1]);
        }

        return maxi+one;
    }
};