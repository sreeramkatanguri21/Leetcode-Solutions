class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Approach-3 -> Min Heap
        priority_queue<int, vector<int>, greater<>> pq;

        for(auto num: nums) {
            if(pq.size() < k) {
                pq.push(num);
            }
            else {
                if(num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }

        return pq.top();


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