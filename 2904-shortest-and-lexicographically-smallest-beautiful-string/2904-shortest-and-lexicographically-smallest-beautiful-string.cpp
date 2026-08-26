class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.length();
        string ans = "";
        for(int i=0; i<n; i++) {
            string str = "";
            int cnt = 0;
            for(int j=i; j<n; j++) {
                str.push_back(s[j]);
                if(s[j] == '1') cnt++;
                if(cnt == k) {
                    if(ans.length() == 0 || 
                        str.length() < ans.length() || 
                        (str.length() == ans.length() && str < ans)) {
                        ans = str;
                    }
                    break;
                }
            }
        }

        return ans;
    }
};