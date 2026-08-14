class DSU {
    public:
        vector<int> parent;
        vector<int> size;
    
        DSU(int n) {
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i=0; i<n+1; i++) {
                parent[i] = i;
            }
        }

        int findParent(int u) {
            if(parent[u] == u) return u;
            return parent[u] = findParent(parent[u]);
        }

        void unionBySize(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;

            if(size[pu] > size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            else {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }

};
class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();

        DSU ds(n);
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]] = i;
        }

        for(int i=1; i<=threshold; i++) {
            vector<int> factors;
            for(int j=1; j*j<=i; j++) {
                if(i%j == 0) {
                    int val1 = j;
                    int val2 = i/j;
                    if(mpp.count(val1)) factors.push_back(val1);
                    if(val1 != val2 && mpp.count(val2)) factors.push_back(val2);
                }
            }
            int m = factors.size();
            for(int k=0; k<m-1; k++) {
                ds.unionBySize(mpp[factors[k]], mpp[factors[k+1]]);
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(ds.findParent(i) == i) cnt++;
        }

        return cnt;
    }
};