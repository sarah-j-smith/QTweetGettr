#ifndef TWEET_H
#define TWEET_H

#include <vector>

class Tweet;
using TweetPtr = std::unique_ptr<Tweet>;
using TweetList = std::vector<TweetPtr>;

class Tweet
{
public:
    Tweet();

    static TweetList tweetsFromArray();
};

#endif // TWEET_H
