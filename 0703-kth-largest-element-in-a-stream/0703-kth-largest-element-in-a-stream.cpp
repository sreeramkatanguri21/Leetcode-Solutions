class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        int n = nums.size();
        for(int i=0; i<min(k, n); i++) {
            pq.push(nums[i]);
        }

        for(int i=k; i<n; i++) {
            int num = nums[i];
            if(num > pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < size) {
            pq.push(val);
        }
        else if(val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */