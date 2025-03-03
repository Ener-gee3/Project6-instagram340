// User.h

#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include "Post.h"
#include "LinkedBag.h"

class User {
private:
    std::string username;
    std::string email;
    std::string password;
    std::string bio;
    std::string profilePicture;

    // A bag of Post* (polymorphic pointers to Reels or Stories)
    LinkedBag<Post*> posts;

public:
    // Constructor
    User(const std::string& username,
        const std::string& email,
        const std::string& password,
        const std::string& bio,
        const std::string& profilePicture);

    // Getters
    std::string getUsername() const;
    std::string getEmail() const;
    std::string getBio() const;
    std::string getProfilePicture() const;

    // Setter
    void setPassword(const std::string& newPassword);

    // Post management
    bool addPost(Post* newPost);
    bool removePost(Post* post);
    void displayAllPosts() const;
    Post* getKthPost(int k) const;

    // Display user profile (excluding password)
    void displayProfile() const;

    // Overloaded operator== so LinkedBag can compare Users if needed
    bool operator==(const User& otherUser) const;
};

#endif // USER_H
