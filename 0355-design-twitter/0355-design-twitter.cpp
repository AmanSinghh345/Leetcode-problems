class Twitter {
public:
    int time=0;
    unordered_map<int,unordered_set<int>> mat;
    unordered_map<int,vector<pair<int,int>>> umap;
    Twitter(){
    
    }
    
    void postTweet(int userId, int tweetId) {
        umap[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<>> pq;

        for(auto & it : umap[userId]){
            pq.push(it);
            if(pq.size()>10) pq.pop();
        }
        for(int followee:mat[userId]){
            for(auto & it : umap[followee]){
                pq.push(it);
                if(pq.size()>10) pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        mat[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
    
            mat[followerId].erase(followeeId);
        
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