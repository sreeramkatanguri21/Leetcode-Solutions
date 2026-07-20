class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = k%(m*n);
        vector<int> temp;

        for(int idx=m*n-k; idx<m*n; idx++) {
            temp.push_back(grid[idx/n][idx%n]);
        }

        for(int idx=m*n-k-1; idx>=0; idx--) {
            grid[(idx+k)/n][(idx+k)%n] = grid[idx/n][idx%n];
        }

        for(int idx=0; idx<k; idx++) {
            grid[idx/n][idx%n] = temp[idx];
        }

        return grid;






        // Approach-1 -> Brute Force ->  T.C - O(k*m*n) , S.C -> O(1)
        // int m = grid.size();
        // int n = grid[0].size();
        // k = k%(m*n);
        // for(int i=0; i<k; i++) {
        //     int last = grid[m-1][n-1];
        //     for(int idx=m*n-1; idx>=1; idx--) {
        //         grid[idx/n][idx%n] = grid[(idx-1)/n][(idx-1)%n];
        //     }
        //     grid[0][0] = last;
        // }

        // return grid;
    }
};