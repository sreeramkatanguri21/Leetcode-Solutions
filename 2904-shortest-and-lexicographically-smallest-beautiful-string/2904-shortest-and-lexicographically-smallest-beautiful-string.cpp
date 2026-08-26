class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int l = 0;
        int r = 0;
        int cnt = 0;

        while(r < n) {
            if(s[r] == '1') {
                cnt++;
            }
            while(cnt == k) {
                string str = s.substr(l, r-l+1);
                if(ans.length() == 0 || 
                    str.length() < ans.length() || 
                    (str.length() == ans.length() && str < ans)) {
                    ans = str;
                }

                if(s[l] == '1') cnt--;
                l++;
            }

            r++;
        }

        return ans;







        // int n = s.length();
        // string ans = "";
        // for(int i=0; i<n; i++) {
        //     string str = "";
        //     int cnt = 0;
        //     for(int j=i; j<n; j++) {
        //         str.push_back(s[j]);
        //         if(s[j] == '1') cnt++;
        //         if(cnt == k) {
        //             if(ans.length() == 0 || 
        //                 str.length() < ans.length() || 
        //                 (str.length() == ans.length() && str < ans)) {
        //                 ans = str;
        //             }
        //             break;
        //         }
        //     }
        // }

        return ans;
    }
};