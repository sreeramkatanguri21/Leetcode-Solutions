class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = -1;
        int maxi2 = -1;
        while(n) {
            int r = n%10;
            if(maxi1 == -1 || r >= maxi1)  {
                maxi2 = maxi1;
                maxi1 = r;
            }
            else maxi2 = max(maxi2, r);

            n /= 10;
        }

        return maxi1*maxi2;
    }
};