class SegmentTree {
    vector<int> segTree;
    
    public:
    SegmentTree(int n) {
        segTree.resize(4*n, -1);
    }
    
    void buildTree(int i, int s, int e, vector<int>& arr) {
        if(s == e) {
            segTree[i] = arr[s];
            return;
        }
        
        int mid = s + (e-s)/2;
        buildTree(2*i+1, s, mid, arr);
        buildTree(2*i+2, mid+1, e, arr);
        
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    void update(int i, int s, int e, int idx, int val) {
        if(s == e) {
            segTree[i] = val;
            return;
        }

        int mid = s + (e-s)/2;
        if(idx <= mid) {
            update(2*i+1, s, mid, idx, val); 
        }
        else {
            update(2*i+2, mid+1, e, idx, val);
        }

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int querySum(int i, int s, int e, int l, int r) {
        
        if(s > r || e < l) return 0;
        if(s >= l && e <= r) return segTree[i];
        
        int mid = s + (e-s)/2;
        return querySum(2*i+1, s, mid, l, r) + querySum(2*i+2, mid+1, e, l, r);
    }
};
class NumArray {
public:
    SegmentTree* s;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        s = new SegmentTree(n);
        s->buildTree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        s->update(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return s->querySum(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */