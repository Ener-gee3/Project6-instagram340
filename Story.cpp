// Story.cpp

#include "Story.h"
#include <iostream>

Story::Story(const std::string& title, const std::string& mediaURL, int duration)
    : Post(title, mediaURL, duration)
{
    // Keep our own “story clock” if we want
    time_stamp = std::chrono::steady_clock::now();
}

void Story::display() const {
    Post::display(); // Show base details
    int hoursRemaining = computeTimeToExpiration();
    if (hoursRemaining > 0) {
        std::cout << "Post Type: Story - " << hoursRemaining
            << " hours left until expiration.\n";
    }
    else {
        std::cout << "Post Type: Story - This story has expired.\n";
    }
}

void Story::editPost() const {
    std::cout << "Editing Story: Adding filters, music, stickers, and effects.\n";
}

// Implementation of the pure virtual from Post
void Story::expire() {
    // In principle, you might do something like:
    isExpired = true;
    std::cout << "Story is now expired!\n";
}

// Private helper for Story
int Story::computeTimeToExpiration() const {
    const int secondsInHour = 3600;
    const int expiresAfter = 24 * secondsInHour;

    auto time_now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = time_now - time_stamp;
    return static_cast<int>((expiresAfter - elapsed_seconds.count()) / secondsInHour);
}
