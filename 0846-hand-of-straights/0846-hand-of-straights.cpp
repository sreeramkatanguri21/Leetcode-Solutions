class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;

        map<int, int> freq;
        for(auto &val: hand) {
            freq[val]++;
        }

        while(!freq.empty()) {
            auto it = freq.begin();
            auto [num, f] = *it;
            freq[num]--;
            if(freq[num] == 0) freq.erase(num);
            for(int i=1; i<groupSize; i++) {
                if(freq.count(num+i)) {
                    freq[num+i]--;
                    if(freq[num+i] == 0) freq.erase(num+i);
                }
                else {
                    return false;
                }
            }
        }

        return true;

    }
};