// InstagramMain.cpp

#include <iostream>
#include <string>
#include "Instagram340.h"
#include "User.h"
#include "Reel.h"
#include "Story.h"

using namespace std;

/**
 * Displays the menu of options for one user
 * and prompts them to choose an action repeatedly.
 */
void displayUserMenu(User& user) {
    int userChoice = 0;
    do {
        cout << "\nHi, " << user.getUsername() << ", what would you like to do:\n"
            << "1. Display Profile\n"
            << "2. Modify Password\n"
            << "3. Create Post (choose Reel or Story)\n"
            << "4. Display All Posts\n"
            << "5. Display Kth Post\n"
            << "6. Modify Post (title)\n"
            << "7. Delete Post\n"
            << "8. Edit a Post (calls editPost() )\n"
            << "0. Logout\n"
            << "Choice: ";
        cin >> userChoice;

        switch (userChoice) {
        case 1: {
            // Display user profile
            user.displayProfile();
            break;
        }
        case 2: {
            // Modify password
            cout << "Enter new password: ";
            {
                std::string newPass;
                cin >> newPass;
                user.setPassword(newPass);
                cout << "Password updated.\n";
            }
            break;
        }
        case 3: {
            // Create post (Reel or Story)
            int postType;
            cout << "Enter 1 for Reel, 2 for Story: ";
            cin >> postType;

            cout << "Enter title: ";
            cin.ignore(); // flush leftover newline
            std::string title;
            getline(cin, title);

            cout << "Enter media URL: ";
            std::string mediaURL;
            cin >> mediaURL;

            cout << "Enter duration (in seconds): ";
            int duration;
            cin >> duration;

            if (postType == 1) {
                // Create a Reel
                Post* newPost = new Reel(title, mediaURL, duration);
                user.addPost(newPost);
            }
            else if (postType == 2) {
                // Create a Story
                Post* newPost = new Story(title, mediaURL, duration);
                user.addPost(newPost);
            }
            else {
                cout << "Invalid choice of post type!\n";
            }
            break;
        }
        case 4: {
            // Display all posts
            user.displayAllPosts();
            break;
        }
        case 5: {
            // Display Kth post
            cout << "Enter the value k (1-based): ";
            int k;
            cin >> k;
            Post* p = user.getKthPost(k);
            if (!p) {
                cout << "Invalid k. The user has only "
                    << userChoice << " posts.\n";
            }
            else {
                p->display();
            }
            break;
        }
        case 6: {
            // Modify the title of an existing post
            cout << "Which post index (1-based)? ";
            int k;
            cin >> k;
            Post* p = user.getKthPost(k);
            if (!p) {
                cout << "Invalid index.\n";
            }
            else {
                cout << "Enter new title: ";
                cin.ignore();
                std::string newTitle;
                getline(cin, newTitle);
                p->setTitle(newTitle);
                cout << "Title updated.\n";
            }
            break;
        }
        case 7: {
            // Delete a post
            cout << "Which post index to delete (1-based)? ";
            int k;
            cin >> k;
            Post* p = user.getKthPost(k);
            if (!p) {
                cout << "Invalid index.\n";
            }
            else {
                bool removed = user.removePost(p);
                if (removed) {
                    delete p; // Since we used new Post() earlier
                    cout << "Post removed.\n";
                }
                else {
                    cout << "Something went wrong removing post.\n";
                }
            }
            break;
        }
        case 8: {
            // Edit a post (which calls the derived class's editPost())
            cout << "Which post index to edit (1-based)? ";
            int k;
            cin >> k;
            Post* p = user.getKthPost(k);
            if (!p) {
                cout << "Invalid index.\n";
            }
            else {
                p->editPost();  // Polymorphic call
            }
            break;
        }
        case 0: {
            cout << "Logging you out.\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (userChoice != 0);
}

int main() {
    // We have an Instagram340 system that can store multiple Users,
    // but here we’ll just do one demonstration user.
    Instagram340 instagram;

    cout << "Welcome to Instagram340!\n";
    // Prompt user for details
    std::string username, email, password, bio, profilePicture;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    cin.ignore(); // flush leftover newline
    cout << "Enter bio: ";
    getline(cin, bio);

    cout << "Enter profile picture URL: ";
    cin >> profilePicture;

    // Create user
    instagram.createUser(username, email, password, bio, profilePicture);

    // Retrieve the first user we just created
    // Note that getUser(0) in code calls findKthItem(1) because it's 1-based inside
    User currentUser = instagram.getUser(0);

    // Now display user menu
    displayUserMenu(currentUser);

    cout << "Program finished.\n";
    return 0;
}
