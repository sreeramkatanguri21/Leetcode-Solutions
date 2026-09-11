class SegmentTree {
    vector<int> segTree;
    int n;
    public:
        SegmentTree(int n) {
            this->n = n;
            segTree.resize(4*n, -1);
        }

        void buildTree(int i, int s, int e, vector<int>& arr) {
            if(s == e) {
                segTree[i] = s;
                return;
            }

            int mid = s + (e-s)/2;
            buildTree(2*i+1, s, mid, arr);
            buildTree(2*i+2, mid+1, e, arr);

            int leftMaxIdx = segTree[2*i+1];
            int rightMaxIdx = segTree[2*i+2];

            if(arr[leftMaxIdx] >= arr[rightMaxIdx]) {
                segTree[i] = leftMaxIdx;
            }
            else segTree[i] = rightMaxIdx;
        }

        int queryMaxIdx(int i, int s, int e, int l, int r, vector<int>& heights) {
            
            if(s > r || e < l) return -1;
            if(s >= l && e <= r) {
                return segTree[i];
            }

            int mid = s + (e-s)/2;
            int leftMaxIdx = queryMaxIdx(2*i+1, s, mid, l, r, heights);
            int rightMaxIdx = queryMaxIdx(2*i+2, mid+1, e, l, r, heights);

            if(leftMaxIdx == -1) return rightMaxIdx;
            if(rightMaxIdx == -1) return leftMaxIdx;
            if(heights[leftMaxIdx] >= heights[rightMaxIdx]) {
                return leftMaxIdx;
            }
            else return rightMaxIdx;
        }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SegmentTree seg(n);
        seg.buildTree(0, 0, n-1, heights);

        vector<int> ans;
        for(auto q: queries) {
            int l = min(q[0], q[1]), r = max(q[0], q[1]);

            if(r == l || heights[r] > heights[l]) {
                ans.push_back(r);
                continue;
            }

            int s = r+1;
            int e = n-1;

            int idx = -1;
            while(s <= e) {
                int mid = s + (e-s)/2;

                int left = seg.queryMaxIdx(0, 0, n-1, s, mid, heights);
                if(heights[left] > max(heights[l], heights[r])) {
                    idx = left;
                    e = mid-1;
                }
                else {
                    s = mid+1;
                }
            }
            ans.push_back(idx);

        }

        return ans;
    }
};