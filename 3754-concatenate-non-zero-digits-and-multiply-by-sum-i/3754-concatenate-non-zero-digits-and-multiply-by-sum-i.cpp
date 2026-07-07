class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        ll x = 0;
        ll sum = 0;
        ll i = 1;
        while(n){
            if(n%10 != 0) {
                x += (n%10)*i;
                i *= 10;
                sum += n%10;
            }
            n /= 10;
        }

        return x*sum;
    }
};