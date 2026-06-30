class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);

        for(auto e: roads) {
            degree[e[0]]++;
            degree[e[1]]++;
        }

        sort(rbegin(degree), rend(degree));
        int i = n;
        long long sum = 0;
        for(auto val: degree) {
            sum += val*1LL*i;
            i--;
        }

        return sum;
    }
};