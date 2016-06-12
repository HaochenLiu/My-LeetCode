/*
355. Design Twitter

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        /* empty */
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweetList[userId].push_back(seq);
        seqMap[seq++] = tweetId;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        set<int> priQueue;
        followList[userId].emplace(userId);
        for (int followeeId : followList[userId]) {
            for (int orderId : tweetList[followeeId]) {
                priQueue.emplace(orderId);
                if (priQueue.size() > 10) priQueue.erase(priQueue.begin());
            }
        }
        followList[userId].erase(followList[userId].find(userId));
        vector<int> newsRecent;
        for (int seqId : priQueue) newsRecent.push_back(seqMap[seqId]);
        reverse(newsRecent.begin(), newsRecent.end());
        return newsRecent;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followList[followerId].emplace(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto iter = followList[followerId].find(followeeId);
        if (iter != followList[followerId].end()) followList[followerId].erase(iter);
    }
    
    unordered_map<int, unordered_set<int>> followList;
    unordered_map<int, vector<int>> tweetList;
    unordered_map<int, int> seqMap;    // map order to tweetId
    int seq = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
