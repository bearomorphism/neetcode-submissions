class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        auto &q = posts[userId];
        if (q.size() == 10) q.pop_back();
        q.push_front({time_, tweetId});
        time_++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> v;
        for (int i : followings[userId]) {
            for (auto p : posts[i]) {
                v.push_back(p);
            }
        }

        for (auto p : posts[userId]) {
            v.push_back(p);
        }

        sort(v.rbegin(), v.rend());
        if (v.size() > 10) {
            v.resize(10);
        }

        vector<int> ret;
        for (auto p : v) {
            ret.push_back(p.second);
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> followings;
    unordered_map<int, deque<pair<int, int>>> posts;
    int time_{};
};
