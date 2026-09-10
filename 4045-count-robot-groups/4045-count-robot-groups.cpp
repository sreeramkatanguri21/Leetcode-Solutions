class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int cnt = 0;
        int n = position.size();
        for(int i=n-1; i>=0; ) {
            int currS = speed[i];
            int currP = position[i];
            int j = i-1;
            while(j >= 0 && (speed[j] > currS || currP-position[j] <= distance)) {
                currP = position[j];
                j--;
            }

            cnt++;
            i = j;
        }

        return cnt;
    }
};