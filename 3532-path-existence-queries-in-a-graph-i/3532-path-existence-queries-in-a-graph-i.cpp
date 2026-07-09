class DisjointSet{
    vector<int> parent, rank, size;
    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i=0; i<n+1; i++) {
                parent[i] = i;
            }
        }

        int findParent(int u) {
            if(u == parent[u]) return u;
            return parent[u] = findParent(parent[u]);
        }

        void unionByRank(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            }
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }

        void unionBySize(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        DisjointSet ds(n);
        for(int i=0; i<n-1; i++) {
            if(abs(nums[i]-nums[i+1]) <= maxDiff) ds.unionBySize(i, i+1);
        }

        vector<bool> ans;
        for(auto query: queries) {
            int u = query[0];
            int v = query[1];
            ans.push_back(ds.findParent(u) == ds.findParent(v));
        }

        return ans;
    }
};