class Solution {
public:
    unordered_map<int, unordered_set<int>> mpp;
    bool check(unordered_set<int>& st, int s, int e) {
        for(int i=s; i<=e; i++) {
            if(st.count(i)) return false;
        }

        return true;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        int cnt = 0;
        int m = reservedSeats.size();
        for(int i=0; i<m; i++) {
            auto v = reservedSeats[i];
            mpp[v[0]].insert(v[1]);
        }

        int rowCount = 0;
        for(auto [r, st]: mpp) {
            rowCount++;
            
            if(check(st, 2, 9)) {
                    cnt += 2;
            }
            else if(check(st, 2, 5) || check(st, 4, 7) || check(st, 6, 9)) {
                cnt++;
            }

        }

        return cnt + (n-rowCount)*2;




        
        // for(int i=1; i<=n; i++) {
        //     if(!mpp.count(i)) {
        //         cnt += 2;
        //         continue;
        //     }
        //     if(check(i, 2, 9)) {
        //             cnt += 2;
        //     }
        //     else if(check(i, 2, 5) || check(i, 4, 7) || check(i, 6, 9)) {
        //         cnt++;
        //     }
        // }

        // int cnt = 0;
        // ranges::sort(reservedSeats);
        // int j = 0;
        // int m = reservedSeats.size();
        // for(int i=1; i<=n; i++) {
        //     if(j < m && reservedSeats[j][0] == i) {
        //         unordered_set<int> st;
        //         while(j < m && reservedSeats[j][0] == i) {
        //             st.insert(reservedSeats[j++][1]);
        //         }
        //         if(check(st, 2, 9)) {
        //             cnt += 2;
        //         }
        //         else if(check(st, 2, 5) || check(st, 4, 7) || check(st, 6, 9)) {
        //             cnt++;
        //         }
        //     }
        //     else {
        //         cnt += 2;
        //     }
        // }

        // return cnt;
    }
};