class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(begin(occupiedIntervals), end(occupiedIntervals));
        vector<vector<int>> merged;

        for(auto v: occupiedIntervals) {
            if(merged.empty()) merged.push_back(v);
            else {
                if(v[0] <= merged.back()[1] && v[1] <= merged.back()[1]) continue;
                else if((v[0] <= merged.back()[1] && v[1] > merged.back()[1]) || merged.back()[1] + 1 == v[0]) {
                    merged.back()[1] = v[1];
                }
                else merged.push_back(v);
            }
        }

        vector<vector<int>> ans;
        for(int i=0; i<merged.size(); i++) {
            if(merged[i][0] < freeStart && merged[i][1] >= freeStart && merged[i][1] <= freeEnd) {
                ans.push_back({merged[i][0],freeStart-1});
            }
            else if(merged[i][0] < freeStart && merged[i][1] > freeEnd) {
                ans.push_back({merged[i][0], freeStart-1});
                ans.push_back({freeEnd+1, merged[i][1]});
            }
            else if(merged[i][0] >= freeStart && merged[i][0] <= freeEnd && merged[i][1] > freeEnd) {
                ans.push_back({freeEnd+1, merged[i][1]});
            }
            else if(merged[i][0] >= freeStart && merged[i][1] <= freeEnd) continue;
            else {
                ans.push_back(merged[i]);
            }
        }

        return ans;
    }
};