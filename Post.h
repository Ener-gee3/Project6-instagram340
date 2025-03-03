// Post.h

#pragma once
#ifndef POST_H
#define POST_H

#include <string>
#include <iostream>
#include <chrono>

/**
 * Base class Post
 * - title
 * - mediaURL
 * - duration
 * - isExpired
 * - time_stamp
 *
 * Pure virtual function: expire()
 * Another virtual function: editPost()
 */
class Post {
protected:
    std::string title;
    std::string mediaURL;
    int duration;
    bool isExpired;
    std::chrono::steady_clock::time_point time_stamp;

    // This was originally inside Post.cpp:
    // Moved it here or kept it private/protected, either is fine
    int computeTimeToExpiration() const;

public:
    Post(const std::string& title, const std::string& mediaURL, int duration);
    virtual ~Post() = default;

    virtual void display() const;                 // Just prints basic info
    virtual void expire() = 0;                    // Pure virtual => Must override in child
    virtual void setDuration(int duration);
    virtual void editPost() const = 0;            // Must override in child

    void setTitle(const std::string& title);
    bool operator==(const Post& otherPost) const;
};

#endif // POST_H
