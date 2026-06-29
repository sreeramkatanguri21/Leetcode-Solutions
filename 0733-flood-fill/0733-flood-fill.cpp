class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    void solve(vector<vector<int>>& image, int sr, int sc, int color, int intial, int m, int n, vector<vector<int>>& vis) {
        vis[sr][sc] = true;
        image[sr][sc] = color;

        for(int k=0; k<4; k++) {
            int newR = sr + dx[k];
            int newC = sc + dy[k];
            if(newR >= 0 && newR < m && newC >= 0 && newC < n && image[newR][newC] == intial && !vis[newR][newC]) {
                solve(image, newR, newC, color, intial, m, n, vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m =  image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, false));
        solve(image, sr, sc, color, image[sr][sc], m, n, vis);
        return image;
    }
};