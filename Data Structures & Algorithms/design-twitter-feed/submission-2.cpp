class Twitter {
private:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;

    int timestamp;

    struct Comparator{
        bool operator()(const pair<int,int> &a, const pair<int,int> &b){
            return a.second > b.second;
        }
    };
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timestamp});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comparator> minHeap;
        //Get following tweets
        for(auto &followeeId : following[userId]){
            for(auto &tweet: tweets[followeeId]){
                minHeap.push(tweet);
                if(minHeap.size() > 10){
                    minHeap.pop();
                }
            }
        }

        //Get tweets from self
        for(auto &tweet : tweets[userId]){
            minHeap.push(tweet);
            if(minHeap.size() > 10) minHeap.pop();
        }
        vector<int> res;
        while(!minHeap.empty()){
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
