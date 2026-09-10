class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    //char dir[4] = {'U', 'D', 'L', 'R'};
    int m, n;
    bool isValid(int r, int c) {
        return r>=0 && r<m && c>=0 && c<n;
    }
    int findDir(int curr, int next) {
        if(curr == 0) return 0;
        return curr != next;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dist(m*n, vector<vector<int>>(k+1, vector<int>(5, INT_MAX)));

        priority_queue<tuple<int,int,int,char>, vector<tuple<int,int,int,char>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0 , 0});
        dist[0][0][0] = grid[0][0];

        while(!pq.empty()) {
            auto [cost, t, u, d] = pq.top();
            pq.pop();

            if(u == m*n-1) {
                return cost;
            }

            if(cost > dist[u][t][d]) continue;

            int r = u/n;
            int c = u%n;
            for(int i=0; i<4; i++) {
                int newR = r + dx[i];
                int newC = c + dy[i];
                int chanDir = findDir(d, i+1);
                if(isValid(newR, newC) && chanDir+t <= k && cost+grid[newR][newC] < dist[newR*n+newC][chanDir+t][i+1]) {
                    dist[newR*n+newC][chanDir+t][i+1] = cost+grid[newR][newC];
                    pq.push({dist[newR*n+newC][chanDir+t][i+1], chanDir+t, newR*n+newC, i+1});
                }
            }
        }

        return -1;

    }
};