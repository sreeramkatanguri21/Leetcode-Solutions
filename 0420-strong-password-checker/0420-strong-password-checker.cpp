class Compare {
    public:
        bool operator()(auto& a, auto& b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
};
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.length();
        bool hasLower = false;
        bool hasUpper = false;
        bool hasDigit = false;
        int cnt = 0;
        int firstIdx = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        
        for(int i=0; i<n; i++) {
            char ch = password[i];
            if(isupper(ch)) hasUpper = true;
            else if(islower(ch)) hasLower = true;
            else if(isdigit(ch)) hasDigit = true;
            if(i-1>=0 && password[i-1] != ch) {
                int len = i-firstIdx;
                if(len > 2) pq.push({len%3, len});
                cnt += len/3;
                firstIdx = i;

            }
        }
        int len = n-firstIdx;
        if(len > 2) pq.push({len%3, len});
        cnt += len/3;
        
        int ans = 0;
        if(n > 20) {
            int extra = n-20;
            ans += extra;
            while(extra-- && !pq.empty()) {
                auto top = pq.top();
                pq.pop();
                top.second--;
                if(top.second > 0) {
                    pq.push({top.second%3, top.second});
                }
            }

            int d = 0;
            while(!pq.empty()) {
                d += pq.top().second/3;
                pq.pop();
            }

            ans += max(d,  (!hasLower + !hasUpper + !hasDigit));

            return ans;
        }
        else if(n < 6){
            ans += max({cnt, (!hasLower + !hasUpper + !hasDigit), 6-n});
            return ans;
        }
        else {
            ans += max(cnt, (!hasLower + !hasUpper + !hasDigit));
            return ans;
        }
    }
};