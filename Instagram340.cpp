// Instagram340.cpp

#include "Instagram340.h"
#include <stdexcept>    // for out_of_range

Instagram340::Instagram340() {
    // Users bag starts empty; nothing else special
}

Instagram340::~Instagram340() {
    // Clear out the bag
    users.clear();
}

void Instagram340::createUser(const std::string& username,
    const std::string& email,
    const std::string& password,
    const std::string& bio,
    const std::string& profilePicture)
{
    User newUser(username, email, password, bio, profilePicture);
    // place newUser at the *end* (append) rather than front
    users.append(newUser);
}

User Instagram340::getUser(int indexK) {
    // Note: indexK is 0-based or 1-based? 
    // Our findKthItem code is using 1-based indexing. 
    // If the caller wants 0-based, adjust accordingly.
    auto userNode = users.findKthItem(indexK + 1);
    if (userNode) {
        return userNode->getItem();
    }
    throw std::out_of_range("Invalid user index: " + std::to_string(indexK));
}
