// Post.cpp

#include "Post.h"

Post::Post(const std::string& title, const std::string& mediaURL, int duration)
    : title(title), mediaURL(mediaURL), duration(duration), isExpired(false)
{
    // Stamp this post's creation time
    this->time_stamp = std::chrono::steady_clock::now();
}

void Post::display() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Media URL: " << mediaURL << std::endl;
    std::cout << "Duration: " << duration << " seconds" << std::endl;
    std::cout << "Time to expiration: " << computeTimeToExpiration() << " hours" << std::endl;
}

void Post::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Post::setDuration(int duration) {
    this->duration = duration;
}

bool Post::operator==(const Post& otherPost) const {
    // Compare by title only, for demonstration
    return (this->title == otherPost.title);
}

int Post::computeTimeToExpiration() const {
    // For demonstration, we pretend a 24hr expiration
    const int secondsInHour = 3600;
    const int expiresAfter = 24 * secondsInHour;

    auto time_now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = time_now - this->time_stamp;
    // Convert remaining time to hours
    return static_cast<int>((expiresAfter - elapsed_seconds.count()) / secondsInHour);
}
