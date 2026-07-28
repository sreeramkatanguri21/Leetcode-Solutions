class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(auto ch: s) freq[ch]++;

        int i = 0;
        int j = s.length()-1;
        char middle = '#';
        for(char ch='a'; ch<='z'; ch++) {
            if(freq[ch] > 0) {
                if(freq[ch]&1) middle = ch;

                for(int k=0; k<freq[ch]/2; k++) {
                    s[i++] = ch;
                    s[j--] = ch;
                }
            }
        }

        if(i == j) {
            s[i] = middle;
        }

        return s;
    }
};