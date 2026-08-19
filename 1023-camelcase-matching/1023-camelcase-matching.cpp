class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;

        for(auto& word: queries) {
            int i = 0;
            int j = 0;
            bool match = true;
            while(i < word.size() && j < pattern.size()) {
                if(word[i] == pattern[j]) {
                    i++;
                    j++;
                }
                else if(isupper(word[i])) {
                    match = false;
                    break;
                }
                else i++;
            }
            if(!match) {
                ans.push_back(false);
                continue;
            }
            if(j == pattern.size()) {
                bool isValid = true;
                while(i < word.size()) {
                    if(isupper(word[i])) {
                        isValid = false;
                        break;
                    }
                    i++;
                }

                ans.push_back(isValid);
            }
            else ans.push_back(false);
        }

        return ans;
    }
};