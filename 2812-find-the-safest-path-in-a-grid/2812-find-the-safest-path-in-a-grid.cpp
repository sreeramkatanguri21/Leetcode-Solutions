// class Solution {
// public:
//     vector<int> dx = {-1, 1, 0, 0};
//     vector<int> dy = {0, 0, 1, -1};
//     // bool canTravel(int i, int j, int d, vector<pair<int,int>>& thieves) {
//     //     for(auto [r, c] : thieves) {
//     //         if(abs(i-r)+abs(j-c) < d) return false;
//     //     }

//     //     return true;
//     // }
//     bool dfs(int i, int j, int n, int d, vector<vector<int>>& grid, vector<vector<int>>& dist, vector<vector<bool>>& vis) {
//         vis[i][j] = true;
//         if(i == n-1 && j == n-1) return true;


//         for(int k=0; k<4; k++) {
//             int newR = i + dx[k];
//             int newC = j + dy[k];

//             if(newR >= 0 && newR < n && newC >= 0 && newC < n && dist[newR][newC] >= d && !vis[newR][newC]) {
//                 bool ans = dfs(newR, newC, n, d, grid, dist, vis);
//                 if(ans) return true;
//             }
//         }

//         return false;
//     }
//     bool isPossible(vector<vector<int>>& grid, int n, int d, vector<vector<int>>& dist) {
//         if(dist[0][0] < d) return false;

//         vector<vector<bool>> vis(n, vector<bool>(n, false));
//         return dfs(0, 0, n, d, grid, dist, vis);
//     }
//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         int n = grid.size();
//         // vector<pair<int,int>> thieves;
//         // for(int i=0; i<n; i++) {
//         //     for(int j=0; j<n; j++) {
//         //         if(grid[i][j] == 1) thieves.push_back({i, j});
//         //     }
//         // }

//         vector<vector<int>> dist(n, vector<int>(n, -1));
//         vector<vector<int>> vis(n, vector<int>(n, 0));

//         queue<pair<pair<int,int>,int>> q;
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<n; j++) {
//                 if(grid[i][j] == 1) {
//                     q.push({{i, j}, 0});
//                     vis[i][j] = 1;
//                 }
//             } 
//         }

//         while(!q.empty()) {
//             auto p = q.front();
//             q.pop();
//             int r = p.first.first;
//             int c = p.first.second;
//             int d = p.second;
//             dist[r][c] = d;

//             for(int k=0; k<4; k++) {
//                 int newR = r + dx[k];
//                 int newC = c + dy[k];
//                 if(newR >= 0 && newR < n && newC >= 0 && newC < n && !vis[newR][newC]) {
//                     q.push({{newR, newC}, d+1});
//                     vis[newR][newC] = 1;
//                 }
//             }
//         }

//         int s = 0;
//         int e = n-1;
//         int ans = -1;

//         while(s <= e) {
//             int mid = s + (e - s)/2;
//             if(isPossible(grid, n, mid, dist)) {
//                 ans = mid;
//                 s = mid+1;
//             }
//             else e = mid-1;
//         }
//         return ans;
//     }
// };


class Solution {
public:

    typedef pair<int,pair<int,int>> ppi;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int maximumSafenessFactor(vector<vector<int>>&grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dist(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && ni<m &&
                   nj>=0 && nj<n &&
                   dist[ni][nj]==-1){
                    dist[ni][nj]=dist[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }
        priority_queue<ppi>pq;
        vector<vector<int>>vis(m,vector<int>(n,INT_MIN));
        pq.push({dist[0][0],{0,0}});
        vis[0][0] = dist[0][0];
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            int safe=cur.first;
            int i=cur.second.first;
            int j=cur.second.second;
            if(safe < vis[i][j]) continue;
            //if(vis[i][j]) continue;
            //v[i][j]=1;
            if(i==m-1 && j==n-1){
                return safe;
            }
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0 && ni<m &&
                   nj>=0 && nj<n && min(safe, dist[ni][nj]) > vis[ni][nj]
                   //&& !vis[ni][nj]
                   ){
                    vis[ni][nj]=min(safe,dist[ni][nj]);
                    pq.push({vis[ni][nj],{ni,nj}});
                }
            }
        }
        return -1;
    }
};