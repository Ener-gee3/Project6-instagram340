// Reel.h

#pragma once
#ifndef REEL_H
#define REEL_H

#include "Post.h"

class Reel : public Post {
public:
    Reel(const std::string& title, const std::string& mediaURL, int duration);
    virtual ~Reel();

    // Overriding pure virtual from Post
    void expire() override;
    // Overriding the base class's virtual
    void editPost() const override;
    void display() const override;
};

#endif // REEL_H
