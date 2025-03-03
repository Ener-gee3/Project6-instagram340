// Instagram340.h

#pragma once
#ifndef INSTAGRAM340_H
#define INSTAGRAM340_H

#include "LinkedBag.h"
#include "User.h"
#include <string>

/**
 * This class only contains a LinkedBag of Users.
 *  - createUser(...) puts a new User at the end
 *  - getUser(indexK) retrieves the Kth user in the bag
 */
class Instagram340 {
private:
    LinkedBag<User> users;

public:
    Instagram340();
    ~Instagram340();

    void createUser(const std::string& username,
        const std::string& email,
        const std::string& password,
        const std::string& bio,
        const std::string& profilePicture);

    // Retrieve the Kth user in the bag (1-based index)
    User getUser(int indexK);
};

#endif
