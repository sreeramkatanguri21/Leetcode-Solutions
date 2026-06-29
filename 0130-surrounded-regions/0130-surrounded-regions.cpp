class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    void dfs(int i, int j, vector<vector<char>>& board, int m, int n, vector<vector<int>>& vis) {
        vis[i][j] = 1;

        for(int k=0; k<4; k++) {
            int newR =  i + dx[k];
            int newC = j + dy[k];
            
            if(newR >= 0 && newR < m && newC >= 0 && newC < n && board[newR][newC] == 'O' && !vis[newR][newC]) {
                dfs(newR, newC, board, m, n, vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, board, m, n, vis);
            }
            if(board[i][n-1] == 'O' && !vis[i][n-1]) {
                dfs(i, n-1, board, m, n, vis);
            }
        }

        for(int j=0; j<n; j++) {
            if(board[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, board, m, n, vis);
            }
            if(board[m-1][j] == 'O' && !vis[m-1][j]) {
                dfs(m-1, j, board, m, n, vis);
            }
        }


        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};