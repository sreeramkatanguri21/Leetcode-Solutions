class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        if(low > 123456789) return {};
        int digits = 0;
        int t = low;
        int firstDigit = 0;
        while(t) {
            digits++;
            if(t < 10) firstDigit = t;
            t /= 10;
        }
        bool maxReached = false;
        vector<int> ans;
        while(true) {
            int k = firstDigit;
            while(k+digits <= 10) {
                int num = 0;
                for(int i=0; i<digits; i++) {
                    num = num*10 + (k+i);
                }

                if(num >= low && num <= high) ans.push_back(num);
                if(num > high || num == 123456789) {
                    maxReached = true;
                    break;
                }
                
                k++;
            }
            if(maxReached) break;
            firstDigit = 1;
            digits++;
            //cout << digits << endl;
        }

        return ans;

    }
};