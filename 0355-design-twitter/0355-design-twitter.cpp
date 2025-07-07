class Twitter {
public:
 int time = 0;  // Global timestamp
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>>followed;
    Twitter() {
      
    }   
    
    void postTweet(int userId, int tweetId) {
         posts[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // max-heap based on time

        // Add user's own tweets
        for (auto& tweet : posts[userId]) {
            pq.push(tweet);
        }

        // Add tweets from followed users
        for (int followeeId : followed[userId]) {
            for (auto& tweet : posts[followeeId]) {
                pq.push(tweet);
            }
        }

        // Extract up to 10 most recent tweets
        vector<int> feed;
        int count = 0;
        while (!pq.empty() && count < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; 
        followed[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followed[followerId].erase(followeeId);

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