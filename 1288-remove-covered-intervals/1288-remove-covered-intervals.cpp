class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [&](auto& a, auto& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int cnt = 1;
        int prev = 0;
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] >= intervals[prev][0] && intervals[i][1] <= intervals[prev][1]) {
                continue;
            }
            cnt++;
            prev = i;
        }

        return cnt;
    }
};