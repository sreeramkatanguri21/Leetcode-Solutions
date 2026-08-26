class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> v;
        int n = s.length();

        for(int i=0; i<n; i++) {
            string str = "";
            int cnt = 0;
            for(int j=i; j<n; j++) {
                str.push_back(s[j]);
                if(s[j] == '1') cnt++;
                if(cnt == k) {
                    v.push_back(str);
                    break;
                }
            }
        }

        string ans = "";
        for(auto str: v) {
            if(ans.length() == 0 || str.length() < ans.length() || (str.length() == ans.length() && str < ans)) {
                ans = str;
            }
        }
        return ans;
    }
};