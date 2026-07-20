class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<k; i++) {
            int last = grid[m-1][n-1];
            for(int idx=m*n-1; idx>=1; idx--) {
                grid[idx/n][idx%n] = grid[(idx-1)/n][(idx-1)%n];
            }
            grid[0][0] = last;
        }

        return grid;
    }
};