// Story.h

#pragma once
#ifndef STORY_H
#define STORY_H

#include "Post.h"
#include <chrono>

/**
 * A Story is a Post that actually expires.
 * We'll keep a separate time stamp from the base, if desired.
 */
class Story : public Post {
private:
    // This time_stamp overshadowing the base’s. If you want them truly separate,
    // that’s fine. If not, remove it and use the base's time_stamp. 
    std::chrono::steady_clock::time_point time_stamp;

    int computeTimeToExpiration() const;  // story-specific approach

public:
    Story(const std::string& title, const std::string& mediaURL, int duration);
    void display() const override;
    void editPost() const override;
    void expire() override;  // Must define to satisfy pure virtual from Post
};

#endif // STORY_H
