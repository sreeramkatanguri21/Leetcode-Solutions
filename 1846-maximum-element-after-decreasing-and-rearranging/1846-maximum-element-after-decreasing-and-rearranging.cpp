class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        arr[0] = 1;
        for(int i=1; i<n; i++) {
            if(abs(arr[i]-arr[i-1]) <= 1) continue;
            arr[i] = arr[i-1] + 1;
        }

        return arr[n-1];
    }
};