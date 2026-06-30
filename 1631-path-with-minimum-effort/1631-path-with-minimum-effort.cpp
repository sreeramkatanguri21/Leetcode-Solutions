class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool dfs(int i, int j, int m, int n, vector<vector<int>>& heights, int effort, vector<vector<bool>>& vis) {
        if(i == m-1 && j == n-1) return true;
        vis[i][j] = true;

        for(int k=0; k<4; k++) {
            int newR = i + dx[k];
            int newC = j + dy[k];

            if(newR >= 0 && newR < m && newC >= 0 && newC < n && abs(heights[i][j] - heights[newR][newC]) <= effort && !vis[newR][newC]) {
                bool ans = dfs(newR, newC, m, n, heights, effort, vis);
                if(ans) return true;
            }
        }

        return false;
    }
    bool isPossible(vector<vector<int>>& heights, int effort) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        return dfs(0, 0, m, n, heights, effort, vis);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        //Approach - 2 -> B.S + DFS/BFS -> T.C - O(m*n*log(1e6))
        int m = heights.size();
        int n = heights[0].size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                maxi = max(maxi, heights[i][j]);
                mini = min(mini, heights[i][j]);
            }
        }
        int s = 0;
        // int e = 1e6-1;
        int e = maxi-mini;
        int ans = -1;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(isPossible(heights, mid)) {
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }

        return ans;

        // Approach - 1 -> Dijakstra Algo -> T.C - O(m*nlog(m*n)), S.C - O(m*n)
        // int m = heights.size();
        // int n = heights[0].size();

        // vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        // priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
        // dist[0][0] = 0;
        // pq.push({0, {0, 0}});

        // while(!pq.empty()) {
        //     auto it = pq.top();
        //     pq.pop();
        //     int d = it.first;
        //     int r = it.second.first;
        //     int c = it.second.second;
        //     if(r == m-1 && c == n-1) return d;

        //     if(d > dist[r][c]) continue;

        //     for(int k=0; k<4; k++) {
        //         int newR = r + dx[k];
        //         int newC = c + dy[k];

        //         if(newR >= 0 && newR < m && newC >= 0 && newC < n && max(dist[r][c], abs(heights[r][c]-heights[newR][newC])) < dist[newR][newC]) {
        //             dist[newR][newC] = max(dist[r][c], abs(heights[r][c]-heights[newR][newC]));
        //             pq.push({dist[newR][newC], {newR, newC}});
        //         }
        //     }

        // }

        // return -1;
    }
};