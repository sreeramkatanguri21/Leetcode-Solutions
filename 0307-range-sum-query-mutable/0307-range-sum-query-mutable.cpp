class FenwickTree {
    vector<int> fen;
    int N;

    public:
        FenwickTree(int n) {
            N = n+1; // since Fenwick Tree is using 1-based indexing, so the size of fen must be n+1
            fen.resize(N, 0);
        }

        void buildTree(vector<int>& arr) {
            for(int i=1; i<N; i++) {
                fen[i] += arr[i-1];
                int parent = i + (i & (-i));
                if(parent < N) {
                    fen[parent] += fen[i];
                }
            }
        }

        void update(int i, int diff) {
            while(i < N) {
                fen[i] += diff;
                i += (i & (-i));
            }
        }

        int sum(int i) {
            int s = 0;
            while(i > 0) {
                s += fen[i];
                i += -(i & (-i));
            }

            return s;
        }

        int rangeSum(int l, int r) {
            return sum(r) - sum(l-1);
        }
};
class NumArray {
public:
    FenwickTree* f;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        f = new FenwickTree(n);
        f->buildTree(nums);
        arr = nums;
    }
    
    void update(int index, int val) {
        int original = arr[index];
        int diff = val - original;
        arr[index] = val;
        f->update(index+1, diff);
    }
    
    int sumRange(int left, int right) {
        return f->rangeSum(left+1, right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */