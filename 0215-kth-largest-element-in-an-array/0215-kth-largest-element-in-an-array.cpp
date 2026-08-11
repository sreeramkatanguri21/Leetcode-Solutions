class Solution {
public:
    int partition(vector<int>& nums, int s, int e) {
        int k = e;
        int pivot = nums[s];
        for(int i=e; i>s; i--) {
            if(nums[i] > pivot) {
                swap(nums[i], nums[k]);
                k--;
            }
        }
        swap(nums[s], nums[k]);

        return k;
    }
    int solve(vector<int>& nums, int k, int s, int e, int n) {
        if(s == e) return nums[s];
        if(s > e) return -1;

        int pi = partition(nums, s, e);
        if(pi == n-k) return nums[pi];
        if(n-k < pi) {
            return solve(nums, k, s, pi-1, n);
        }
        else {
            return solve(nums, k, pi+1, e, n);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        // Approach-4 -> Quicksort
        int n = nums.size();
        return solve(nums, k, 0, n-1, n);




        //Approach-3 -> Min Heap
        // priority_queue<int, vector<int>, greater<>> pq;

        // for(auto num: nums) {
        //     if(pq.size() < k) {
        //         pq.push(num);
        //     }
        //     else {
        //         if(num > pq.top()) {
        //             pq.pop();
        //             pq.push(num);
        //         }
        //     }
        // }

        // return pq.top();


        //Approach-2 -> Max Heap
        // priority_queue<int> pq(nums.begin(), nums.end());

        // while(k>1) {
        //     k--;
        //     pq.pop();
        // }

        // return pq.top();



        // Approach-1 
        // sort(rbegin(nums), rend(nums));
        // return nums[k-1];


    }
};