#ifndef TWEET_H
#define TWEET_H

#include <vector>

#include <QJsonArray>

class Tweet
{
public:
    Tweet();

    static std::vector<Tweet> tweetsFromArray(const QJsonArray &tweetData);
};

#endif // TWEET_H
