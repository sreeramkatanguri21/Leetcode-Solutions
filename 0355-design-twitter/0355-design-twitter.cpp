class Twitter {
public:
    unordered_map<int, unordered_set<int>> followedIds;
    unordered_map<int, vector<pair<int,int>>> posts;
    int t;
    Twitter() {
        t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({++t, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        for(auto &p: posts[userId]) {
            pq.push(p);
            if(pq.size() > 10) pq.pop();
        }

        for(auto &id: followedIds[userId]) {
            for(auto &p: posts[id]) {
                pq.push(p);
                if(pq.size() > 10) pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        ranges::reverse(ans);
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followedIds[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followedIds[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */