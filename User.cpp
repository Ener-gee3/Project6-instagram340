// User.cpp

#include "User.h"
#include <iostream>

// Constructor
User::User(const std::string& username,
    const std::string& email,
    const std::string& password,
    const std::string& bio,
    const std::string& profilePicture)
    : username(username), email(email), password(password),
    bio(bio), profilePicture(profilePicture)
{
}

// Getters
std::string User::getUsername() const { return username; }
std::string User::getEmail() const { return email; }
std::string User::getBio() const { return bio; }
std::string User::getProfilePicture() const { return profilePicture; }

// Setter
void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}

// Post management
bool User::addPost(Post* newPost) {
    return posts.add(newPost);
}

bool User::removePost(Post* post) {
    return posts.remove(post);
}

void User::displayAllPosts() const {
    std::vector<Post*> postVector = posts.toVector();
    for (auto* postPtr : postVector) {
        if (postPtr) {
            postPtr->display();
            std::cout << "-------------------------------\n";
        }
    }
}

Post* User::getKthPost(int k) const {
    auto nodePtr = posts.findKthItem(k);
    if (nodePtr) {
        return nodePtr->getItem();
    }
    return nullptr;
}

void User::displayProfile() const {
    // Don’t show password
    std::cout << "Username: " << username
        << "\nEmail: " << email
        << "\nBio: " << bio
        << "\nProfile Picture: " << profilePicture
        << std::endl;
}

// Overloaded equality operator
bool User::operator==(const User& otherUser) const {
    // Decide if two Users are “equal” by username + email
    return (username == otherUser.username && email == otherUser.email);
}
