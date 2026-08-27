class Solution {
public:
    bool solve(string& curr, int i, string& target, vector<int> freq, bool isGreater) {
        if(i == target.length()) {
            return isGreater;
        }

        for(char ch='a'; ch<='z'; ch++) {
            if(freq[ch-'a'] <= 0) continue;
            if(!isGreater && ch < target[i]) continue;

            curr.push_back(ch);
            freq[ch-'a']--;
            if(solve(curr, i+1, target, freq, isGreater || (ch > target[i]))) {
                return true;
            }

            curr.pop_back();
            freq[ch-'a']++;
        }

        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26);
        for(auto ch: s) {
            freq[ch-'a']++;
        }

        string curr = "";
        solve(curr, 0, target, freq, false);

        return curr;
    }
};