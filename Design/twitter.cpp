#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Twitter{
private:
    struct Tweet{
        int tweetId;
        string msg;

        Tweet(int id, string msg){
            this->tweetId = id;
            this->msg = msg;
        }
        void print(){
            cout<<tweetId<<" -> "<<msg<<endl;
        }
    };
    unordered_map<int,unordered_set<int>> users;
    vector<pair<int,Tweet*>> tweets;

public:
    Twitter(){

    }
    void postTweet(int userId, int tweetId, string msg){
        auto tweet = new Tweet(tweetId,msg);
        tweets.push_back({userId,tweet});

    }
    void follow(int userId, int followeeId){
        users[userId].insert(followeeId);
    }
    void unfollow(int userId, int followeeId){
        users[userId].erase(followeeId);
    }
    vector<Tweet*> getTweets(int userId, int size=10){
        vector<Tweet*> arr;
        auto following  = users[userId];
        for(int i=tweets.size();i>=0;i--){
            auto user = tweets[i].first;
            auto tweet = tweets[i].second;
            if(user == userId || following.find(user)!=following.end()){
                arr.push_back(tweet);
                size--;
                if(size==0)break;
            }
        }
        return arr;
    }
};
int main(){
    Twitter twitter;
    twitter.postTweet(1,1,"hello");
    auto tweets = twitter.getTweets(1);
    twitter.postTweet(2,2,"hello");
    twitter.postTweet(3,3,"hello");
    twitter.postTweet(1,4,"how are you");
    twitter.postTweet(2,5,"i am fine");
    twitter.postTweet(4,6,"hello");
    
    twitter.follow(1,2);
    tweets = twitter.getTweets(1);
    for(auto it:tweets){
        it->print();
    }
    return 0;
}