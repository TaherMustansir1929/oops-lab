#pragma once

#include "Car.h"
#include "Seller.h"
#include <iostream>
#include <cstring>

class Listing {
private:
    const int listingId;      // CONST DATA MEMBER #3
    Car car;                  // Composition: Listing owns Car
    Seller* const seller;     // CONST POINTER #1 (AGGREGATION #1): Points to external Seller
    char* title;
    char* description;
    bool isApproved;
    char* datePosted;
    
    static int listingCount;  // STATIC DATA MEMBER #2: tracks total listings

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
    Listing() : listingId(++listingCount), car(), seller(nullptr),
                title(nullptr), description(nullptr), isApproved(false),
                datePosted(nullptr) {
        copyString(title, "Untitled");
        copyString(description, "No description");
        copyString(datePosted, "01/01/2024");
    }

    // Parameterized Constructor
    Listing(const Car& c, Seller* s, const char* t, const char* desc, 
            const char* date)
        : listingId(++listingCount), car(c), seller(s), isApproved(false) {
        copyString(title, t);
        copyString(description, desc);
        copyString(datePosted, date);
    }

    // Copy Constructor
    Listing(const Listing& other)
        : listingId(other.listingId), car(other.car), seller(other.seller),
          isApproved(other.isApproved) {
        copyString(title, other.title);
        copyString(description, other.description);
        copyString(datePosted, other.datePosted);
    }

    // Destructor
    ~Listing() {
        deleteString(title);
        deleteString(description);
        deleteString(datePosted);
        // seller is not deleted (aggregation - doesn't own it)
        // car is automatically destroyed (composition)
    }

    // Assignment Operator
    Listing& operator=(const Listing& other) {
        if (this != &other) {
            // Note: listingId and seller are const, cannot be reassigned
            deleteString(title);
            deleteString(description);
            deleteString(datePosted);
            
            car = other.car;
            copyString(title, other.title);
            copyString(description, other.description);
            copyString(datePosted, other.datePosted);
            isApproved = other.isApproved;
        }
        return *this;
    }

    // Display listing details (const function)
    void display() const {
        std::cout << "\n========== LISTING #" << listingId << " ==========\n";
        std::cout << "Title: " << (title ? title : "N/A") << "\n";
        std::cout << "Description: " << (description ? description : "N/A") << "\n";
        std::cout << "Status: " << (isApproved ? "APPROVED" : "PENDING") << "\n";
        std::cout << "Posted: " << (datePosted ? datePosted : "N/A") << "\n";
        if (seller) {
            std::cout << "Seller: " << seller->getUsername() 
                     << " (Shop: " << seller->getShopName() << ")\n";
        }
        car.display();
        std::cout << "========================================\n";
    }

    // Approve listing
    void approve() {
        if (!isApproved) {
            isApproved = true;
            std::cout << "Listing #" << listingId << " approved!\n";
        } else {
            std::cout << "Listing #" << listingId << " is already approved.\n";
        }
    }

    // Reject listing
    void reject() {
        if (isApproved) {
            isApproved = false;
            std::cout << "Listing #" << listingId << " rejected!\n";
        } else {
            std::cout << "Listing #" << listingId << " is already not approved.\n";
        }
    }

    // Update listing details
    void updateDetails(const char* newTitle, const char* newDesc, float newPrice) {
        if (newTitle) {
            deleteString(title);
            copyString(title, newTitle);
        }
        if (newDesc) {
            deleteString(description);
            copyString(description, newDesc);
        }
        if (newPrice > 0) {
            car.setPrice(newPrice);
        }
        std::cout << "Listing #" << listingId << " updated!\n";
    }

    // STATIC MEMBER FUNCTION #2: Get total listing count
    static int getListingCount() {
        return listingCount;
    }

    // Getters
    int getListingId() const { return listingId; }
    const Car& getCar() const { return car; }
    Car& getCar() { return car; }
    Seller* getSeller() const { return seller; }
    const char* getTitle() const { return title; }
    const char* getDescription() const { return description; }
    bool getIsApproved() const { return isApproved; }
    const char* getDatePosted() const { return datePosted; }

    // Setters
    void setTitle(const char* t) {
        deleteString(title);
        copyString(title, t);
    }
    void setDescription(const char* desc) {
        deleteString(description);
        copyString(description, desc);
    }
    void setIsApproved(bool approved) { isApproved = approved; }
    void setDatePosted(const char* date) {
        deleteString(datePosted);
        copyString(datePosted, date);
    }
};

// Initialize static member
int Listing::listingCount = 0;

