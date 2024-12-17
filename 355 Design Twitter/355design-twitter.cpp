class Twitter {
public:
    Twitter() {
        
    }
    
    int time = 0;
    unordered_map<int,deque<pair<int,int>>> posts;
    unordered_map<int,unordered_set<int>> following;
    void postTweet(int userId, int tweetId) {
        posts[userId].push_front({tweetId, ++time});
        if (posts[userId].size() > 10) posts[userId].pop_back();
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,pair<int,int>>> q;
        if (posts[userId].size()) q.push({posts[userId][0].second, {userId, 0}});
        for (auto follow_id : following[userId]) if (posts[follow_id].size()) {
            q.push({posts[follow_id][0].second, {follow_id, 0}});
        }
        while (q.size() && res.size() < 10) {
            auto p = q.top(); q.pop();
            int t = p.first;
            int user_id = p.second.first;
            int j = p.second.second;
            res.push_back(posts[user_id][j].first);
            if (j + 1 < posts[user_id].size()) q.push({posts[user_id][j + 1].second, {user_id, j + 1}});
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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