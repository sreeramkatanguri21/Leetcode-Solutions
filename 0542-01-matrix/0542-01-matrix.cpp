class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            } 
        }

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int d = p.second;
            dist[r][c] = d;

            for(int k=0; k<4; k++) {
                int newR = r + dx[k];
                int newC = c + dy[k];
                if(newR >= 0 && newR < m && newC >= 0 && newC < n && !vis[newR][newC]) {
                    q.push({{newR, newC}, d+1});
                    vis[newR][newC] = 1;
                }
            }
        }

        return dist;
    }
};