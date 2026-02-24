#pragma once

#include "User.h"
#include <iostream>
#include <cstring>

// Forward declarations
class Listing;
class Marketplace;
class Car;

class Seller : public User {
private:
    char* shopName;
    float rating;          // 0.0 to 5.0
    int totalSales;
    char* address;
    char* sellerSince;     // date format: "DD/MM/YYYY"

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
    Seller() : User(), shopName(nullptr), rating(0.0f), totalSales(0),
               address(nullptr), sellerSince(nullptr) {
        copyString(shopName, "Unknown Shop");
        copyString(address, "Unknown Address");
        copyString(sellerSince, "01/01/2024");
    }

    // Parameterized Constructor
    Seller(const char* uname, const char* pass, const char* em, const char* ph,
           const char* shop, float rat, const char* addr, const char* since)
        : User(uname, pass, em, ph), rating(rat), totalSales(0) {
        copyString(shopName, shop);
        copyString(address, addr);
        copyString(sellerSince, since);
    }

    // Copy Constructor
    Seller(const Seller& other) : User(other), rating(other.rating),
                                   totalSales(other.totalSales) {
        copyString(shopName, other.shopName);
        copyString(address, other.address);
        copyString(sellerSince, other.sellerSince);
    }

    // Destructor
    ~Seller() override {
        deleteString(shopName);
        deleteString(address);
        deleteString(sellerSince);
    }

    // Override display
    void display() const override {
        User::display();
        std::cout << "Role: Seller\n";
        std::cout << "Shop Name: " << (shopName ? shopName : "N/A") << "\n";
        std::cout << "Rating: " << rating << "/5.0\n";
        std::cout << "Total Sales: " << totalSales << "\n";
        std::cout << "Address: " << (address ? address : "N/A") << "\n";
        std::cout << "Seller Since: " << (sellerSince ? sellerSince : "N/A") << "\n";
    }

    // Override getRole
    const char* getRole() const override {
        return "Seller";
    }

    // Create a listing (defined later to avoid circular dependency)
    void createListing(Marketplace* marketplace, const Car& car, 
                      const char* title, const char* description);

    // Update a listing
    void updateListing(Marketplace* marketplace, int listingId, 
                      float newPrice, const char* newDescription);

    // Delete a listing
    void deleteListing(Marketplace* marketplace, int listingId);

    // View my listings
    void viewMyListings(const Marketplace* marketplace) const;

    // Getters
    const char* getShopName() const { return shopName; }
    float getRating() const { return rating; }
    int getTotalSales() const { return totalSales; }
    const char* getAddress() const { return address; }
    const char* getSellerSince() const { return sellerSince; }

    // Setters
    void setShopName(const char* shop) {
        deleteString(shopName);
        copyString(shopName, shop);
    }
    void setRating(float rat) { rating = rat; }
    void setTotalSales(int sales) { totalSales = sales; }
    void incrementSales() { totalSales++; }
    void setAddress(const char* addr) {
        deleteString(address);
        copyString(address, addr);
    }
    void setSellerSince(const char* since) {
        deleteString(sellerSince);
        copyString(sellerSince, since);
    }
};

