class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mpp;

        int cnt = 0;
        for(int i=0; i<s.length(); i++) {
            mpp[s[i]] = i;
            if(mpp.count('a') && mpp.count('b') && mpp.count('c')) cnt += min({mpp['a'], mpp['b'], mpp['c']})+1;
        }
        return cnt;
    }
};