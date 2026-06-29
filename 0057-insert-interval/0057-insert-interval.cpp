class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) ans.push_back(intervals[i++]);

        if(i == intervals.size()) {
            ans.push_back(newInterval);
            return ans;
        }

        if(intervals[i][0] < newInterval[0] && intervals[i][1] <= newInterval[1]) ans.push_back({intervals[i][0], newInterval[1]});
        else if(intervals[i][0] < newInterval[0] && intervals[i][1] > newInterval[1]) ans.push_back(intervals[i]);
        else if(intervals[i][0] >= newInterval[0] && intervals[i][1] <= newInterval[1]) ans.push_back(newInterval);
        else if(intervals[i][0] >= newInterval[0] && intervals[i][0] <= newInterval[1] && intervals[i][1] > newInterval[1]) ans.push_back({newInterval[0], intervals[i][1]});
        else {
            ans.push_back(newInterval);
            ans.push_back(intervals[i]);
        }
        i++;


        while(i < intervals.size()) {
            if(intervals[i][0] > ans.back()[1]) ans.push_back(intervals[i]);
            else if(intervals[i][1] > ans.back()[1]) ans.back()[1] = intervals[i][1];
            i++;
        }
        return ans;
        
    }
};