class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = -1;
        int maxi2 = -1;
        while(n) {
            int digit = n%10;
            if(maxi1 == -1 || digit >= maxi1)  {
                maxi2 = maxi1;
                maxi1 = digit;
            }
            else maxi2 = max(maxi2, digit);

            n /= 10;
        }

        return maxi1*maxi2;
    }
};