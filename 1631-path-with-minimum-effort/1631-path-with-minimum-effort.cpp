class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == m-1 && c == n-1) return d;

            if(d > dist[r][c]) continue;

            for(int k=0; k<4; k++) {
                int newR = r + dx[k];
                int newC = c + dy[k];

                if(newR >= 0 && newR < m && newC >= 0 && newC < n && max(dist[r][c], abs(heights[r][c]-heights[newR][newC])) < dist[newR][newC]) {
                    dist[newR][newC] = max(dist[r][c], abs(heights[r][c]-heights[newR][newC]));
                    pq.push({dist[newR][newC], {newR, newC}});
                }
            }

        }

        return -1;
    }
};