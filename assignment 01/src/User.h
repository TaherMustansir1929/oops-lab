#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>

class User {
private:
    const int userId;  // CONST DATA MEMBER #2
    char* username;
    char* password;
    char* email;
    char* phone;
    bool isActive;
    
    static int userCount;  // STATIC DATA MEMBER #1: tracks total users created

    void copyString(char*& dest, const char* src) {
        if (src) {
            dest = new char[strlen(src) + 1];
            strcpy(dest, src);
        } else {
            dest = nullptr;
        }
    }

    void deleteString(char*& str) {
        if (str) {
            delete[] str;
            str = nullptr;
        }
    }

protected:
    // Protected members accessible to derived classes
    void setUsername(const char* uname) {
        deleteString(username);
        copyString(username, uname);
    }

public:
    // Default Constructor
    User() : userId(++userCount), username(nullptr), password(nullptr), 
             email(nullptr), phone(nullptr), isActive(true) {
        copyString(username, "guest");
        copyString(password, "password");
        copyString(email, "guest@example.com");
        copyString(phone, "0000000000");
    }

    // Parameterized Constructor
    User(const char* uname, const char* pass, const char* em, 
         const char* ph, bool active = true)
        : userId(++userCount), isActive(active) {
        copyString(username, uname);
        copyString(password, pass);
        copyString(email, em);
        copyString(phone, ph);
    }

    // Copy Constructor
    User(const User& other)
        : userId(other.userId), isActive(other.isActive) {
        copyString(username, other.username);
        copyString(password, other.password);
        copyString(email, other.email);
        copyString(phone, other.phone);
    }

    // Virtual Destructor (important for polymorphism)
    virtual ~User() {
        deleteString(username);
        deleteString(password);
        deleteString(email);
        deleteString(phone);
    }

    // Assignment Operator
    User& operator=(const User& other) {
        if (this != &other) {
            // Note: userId is const, cannot be reassigned
            deleteString(username);
            deleteString(password);
            deleteString(email);
            deleteString(phone);
            
            copyString(username, other.username);
            copyString(password, other.password);
            copyString(email, other.email);
            copyString(phone, other.phone);
            isActive = other.isActive;
        }
        return *this;
    }

    // Virtual display function (polymorphism)
    virtual void display() const {
        std::cout << "\n=== User Details ===\n";
        std::cout << "User ID: " << userId << "\n";
        std::cout << "Username: " << (username ? username : "N/A") << "\n";
        std::cout << "Email: " << (email ? email : "N/A") << "\n";
        std::cout << "Phone: " << (phone ? phone : "N/A") << "\n";
        std::cout << "Status: " << (isActive ? "Active" : "Inactive") << "\n";
        std::cout << "====================\n";
    }

    // Authenticate user (const function)
    bool authenticate(const char* pass) const {
        if (!password || !pass) return false;
        return strcmp(password, pass) == 0;
    }

    // Update profile
    void updateProfile(const char* newEmail, const char* newPhone) {
        if (newEmail) {
            deleteString(email);
            copyString(email, newEmail);
        }
        if (newPhone) {
            deleteString(phone);
            copyString(phone, newPhone);
        }
        std::cout << "Profile updated successfully!\n";
    }

    // Pure virtual function for polymorphism
    virtual const char* getRole() const = 0;

    // STATIC MEMBER FUNCTION #1: Get total user count
    static int getUserCount() {
        return userCount;
    }

    // Getters
    int getUserId() const { return userId; }
    const char* getUsername() const { return username; }
    const char* getPassword() const { return password; }
    const char* getEmail() const { return email; }
    const char* getPhone() const { return phone; }
    bool getIsActive() const { return isActive; }

    // Setters
    void setPassword(const char* pass) {
        deleteString(password);
        copyString(password, pass);
    }
    void setEmail(const char* em) {
        deleteString(email);
        copyString(email, em);
    }
    void setPhone(const char* ph) {
        deleteString(phone);
        copyString(phone, ph);
    }
    void setIsActive(bool active) { isActive = active; }
};

// Initialize static member
int User::userCount = 0;

#endif // USER_H
