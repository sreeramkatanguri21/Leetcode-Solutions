class Solution {
public:
    typedef long long ll;
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        unordered_map<int,int> freq;
        for(auto num: nums) freq[num]++;

        for(auto p: freq) {
            if(p.first == 1) {
                int cnt = p.second&1? p.second: p.second-1;
                maxi = max(maxi, cnt);
            }
            else {
                ll num = p.first;
                int cnt = 0;
                while(freq.count(num)) {
                    if(freq[num] > 1) {
                        cnt += 2;
                        // Handle Overflow case
                        if(num > 1e9/num) break;
                        num *= num;
                    }
                    else {
                        cnt++;
                        maxi = max(maxi, cnt);
                        break;
                    }
                }
                maxi = max(maxi, cnt-1);
            }
        }

        return maxi;
    }
};