/*
存user id:vector<int>
存user id以及他發的貼文 unordered map<int,unordered_set<int>> 前面是user id後面是貼文id
存user id以及他追蹤的人 unordered map<int,unordered_set<int>> 
*/
class Twitter {
private:
    vector<int> UserIdList;
    unordered_map<int,vector<pair<int,int>>>user_post; // pair前面是 timestamp後面是 post id
    unordered_map<int,unordered_set<int>> user_follow;
    int time_stamp;
public:
    Twitter() {
        time_stamp=0;
    }
    
    void output() {
        cout << "========== 系統狀態 Trace ==========" << endl;

        // 1. 印出 user_post (使用者與他們的貼文)
        cout << "[User Posts]" << endl;
        for (const auto& user : user_post) {
            int userId = user.first;
            const vector<pair<int, int>>& posts = user.second;

            cout << "  User " << userId << " 發布了 " << posts.size() << " 篇貼文: ";
            for (const auto& p : posts) {
                // p.first 是 time_stamp, p.second 是 tweetId
                cout << "{time:" << p.first << ", id:" << p.second << "} ";
            }
            cout << endl;
        }

        cout << "------------------------------------" << endl;

        // 2. 印出 user_follow (使用者與他們的追蹤名單)
        cout << "[User Follows]" << endl;
        for (const auto& user : user_follow) {
            int userId = user.first;
            const unordered_set<int>& followees = user.second;

            cout << "  User " << userId << " 追蹤了 " << followees.size() << " 人: ";
            for (int followeeId : followees) {
                cout << followeeId << " ";
            }
            cout << endl;
        }
        cout << "====================================" << endl;
    }

    void postTweet(int userId, int tweetId) {
        user_post[userId].push_back({time_stamp,tweetId});
        time_stamp++;
    }
    
    vector<int> getNewsFeed(int userId) { //找出10個最近的貼文
        vector<int> result;
        unordered_map<int,int> shift; //user if to shift
        vector<int> candidate;
        //儲存user自己以及user所有追蹤的人的id還有把他們的shift設計成0
        candidate.push_back(userId);
        shift.insert({userId,0});
        for(int followeeId : user_follow[userId]){
            candidate.push_back(followeeId);
            shift.insert({followeeId,0});
        }

        // Find the 10 max timestamp
        for(int i=0;i<10;i++){
            pair<int,int> max = {INT_MIN,INT_MIN}; //前面是 timestamp 後面是 貼文id
            int shift_id = INT_MIN;
            for(int j=0;j<candidate.size();j++){ //
                /*注意要先檢查邊界*/
                if( shift[candidate[j]] < user_post[ candidate[j] ].size() &&
                    user_post[ candidate[j] ][ user_post[candidate[j]].size()-1-shift[candidate[j]] ].first > max.first ){

                    max = user_post[ candidate[j] ][ user_post[ candidate[j] ].size()-1-shift[candidate[j]] ];
                    shift_id = candidate[j];
                }
            }
            if(max.second!=INT_MIN){
                shift[shift_id]++;
                result.push_back(max.second);
            }
        }
        return result;   
    }

    void follow(int followerId, int followeeId) {
        user_follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_follow[followerId].erase(followeeId);
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
