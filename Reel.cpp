// Reel.cpp

#include "Reel.h"
#include <iostream>

Reel::Reel(const std::string& title, const std::string& mediaURL, int duration)
    : Post(title, mediaURL, duration)
{
}

Reel::~Reel() {
    // no special resource handling
}

void Reel::display() const {
    Post::display();
    std::cout << "Post Type: Reel\n";
}

void Reel::editPost() const {
    std::cout << "Editing Reel: Adding filters, AR effects, and music.\n";
}

void Reel::expire() {
    // Reels "never" expire, but we must implement the method anyway
    std::cout << "Reel does not expire.\n";
}
