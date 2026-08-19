class Compare {
    public:
        bool operator()(auto& a, auto& b) {
            if(a.first == b.first ) {
                return a.second < b.second;
            }

            return a.first > b.first;
        }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, Compare> pq;

        unordered_map<string, int> mpp;
        for(auto word: words) {
            mpp[word]++;
        }

        for(auto [s, f]: mpp) {
            pq.push({f, s});
            if(pq.size() > k) pq.pop();
        }

        vector<string> ans;
        while(!pq.empty()) {
            auto [f, s] = pq.top();
            pq.pop();
            ans.push_back(s);
        }
        ranges::reverse(ans);
        return ans;
    }
};