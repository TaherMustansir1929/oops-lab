#pragma once

#include "User.h"
#include <iostream>
#include <cstring>

// Forward declaration
class Listing;
class Marketplace;

class Admin : public User {
private:
    int adminLevel;        // 1-5, higher = more privileges
    char* department;
    char* accessCode;
    char* lastLogin;
    int approvedCount;

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

public:
    // Default Constructor
    Admin() : User(), adminLevel(1), department(nullptr), accessCode(nullptr),
              lastLogin(nullptr), approvedCount(0) {
        copyString(department, "General");
        copyString(accessCode, "ADMIN123");
        copyString(lastLogin, "Never");
    }

    // Parameterized Constructor
    Admin(const char* uname, const char* pass, const char* em, const char* ph,
          int level, const char* dept, const char* code)
        : User(uname, pass, em, ph), adminLevel(level), approvedCount(0) {
        copyString(department, dept);
        copyString(accessCode, code);
        copyString(lastLogin, "Never");
    }

    // Copy Constructor
    Admin(const Admin& other) : User(other), adminLevel(other.adminLevel),
                                 approvedCount(other.approvedCount) {
        copyString(department, other.department);
        copyString(accessCode, other.accessCode);
        copyString(lastLogin, other.lastLogin);
    }

    // Destructor
    ~Admin() override {
        deleteString(department);
        deleteString(accessCode);
        deleteString(lastLogin);
    }

    // Override display
    void display() const override {
        User::display();
        std::cout << "Role: Administrator\n";
        std::cout << "Admin Level: " << adminLevel << "\n";
        std::cout << "Department: " << (department ? department : "N/A") << "\n";
        std::cout << "Approved Listings: " << approvedCount << "\n";
        std::cout << "Last Login: " << (lastLogin ? lastLogin : "Never") << "\n";
    }

    // Override getRole
    const char* getRole() const override {
        return "Admin";
    }

    // Approve a listing (declared here, defined later to avoid circular dependency)
    void approveListing(Listing* listing);

    // Remove a listing
    void removeListing(Marketplace* marketplace, int listingId);

    // View all listings
    void viewAllListings(const Marketplace* marketplace) const;

    // View all users (const pointer to const function)
    void viewAllUsers(User* const* users, int userCount) const {
        std::cout << "\n=== All Users ===\n";
        for (int i = 0; i < userCount; i++) {
            if (users[i]) {
                users[i]->display();
                std::cout << "------------------------\n";
            }
        }
    }

    // Getters
    int getAdminLevel() const { return adminLevel; }
    const char* getDepartment() const { return department; }
    const char* getAccessCode() const { return accessCode; }
    const char* getLastLogin() const { return lastLogin; }
    int getApprovedCount() const { return approvedCount; }

    // Setters
    void setAdminLevel(int level) { adminLevel = level; }
    void setDepartment(const char* dept) {
        deleteString(department);
        copyString(department, dept);
    }
    void setAccessCode(const char* code) {
        deleteString(accessCode);
        copyString(accessCode, code);
    }
    void setLastLogin(const char* login) {
        deleteString(lastLogin);
        copyString(lastLogin, login);
    }
    void incrementApprovedCount() { approvedCount++; }
};

