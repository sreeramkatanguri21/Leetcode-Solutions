class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int q1 = 0, q2 = 0;
        int sum1 = 0, sum2 = 0;
        for(int i=0; i<n/2; i++) {
            if(num[i] == '?') q1++;
            else sum1 += num[i]-'0';
        }

        for(int i=n/2; i<n; i++) {
            if(num[i] == '?') q2++;
            else sum2 += num[i]-'0';
        }

        if(q1 > q2) {
            int diffSum = sum2 - sum1;
            int diffQ = q1-q2;
            if(diffSum < 0) return true;
            if(diffQ%2 == 0 && diffSum == diffQ/2*9) return false;
            else return true;
        }
        else if(q2 > q1) {
            int diffSum = sum1 - sum2;
            int diffQ = q2-q1;
            if(diffSum < 0) return true;
            if(diffQ%2 == 0 && diffSum == diffQ/2*9) return false;
            else return true;
        }
        else {
            return sum1 != sum2;
        }
    }
};