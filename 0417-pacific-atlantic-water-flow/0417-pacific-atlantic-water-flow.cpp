class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    void bfs(queue<pair<int,int>> q, vector<vector<int>>& heights, vector<vector<bool>> &vis, int m, int n) {

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int k=0; k<4; k++) {
                int newR = r + dx[k];
                int newC = c + dy[k];

                if(newR >= 0 && newR < m && newC >= 0 && newC < n && heights[newR][newC] >= heights[r][c] && !vis[newR][newC]) {
                    q.push({newR, newC});
                    vis[newR][newC] = true;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        queue<pair<int,int>> qp, qa;
        for(int i=0; i<m; i++) {
            qp.push({i, 0});
            pacific[i][0] = true;
            qa.push({i, n-1});
            atlantic[i][n-1] = true;
        }
        for(int j=0; j<n; j++) {
            qp.push({0, j});
            pacific[0][j] = true;
            qa.push({m-1, j});
            atlantic[m-1][j] = true;
        }

        bfs(qp, heights, pacific, m, n);
        bfs(qa, heights, atlantic, m, n);

        vector<vector<int>> ans;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};