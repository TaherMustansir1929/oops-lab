#ifndef BUYER_H
#define BUYER_H

#include "User.h"
#include <iostream>
#include <cstring>

// Forward declarations
class Listing;
class Marketplace;
class Seller;

class Buyer : public User {
private:
    Listing** favorites;   // AGGREGATION #2: Array of pointers to Listings
    int favoriteCount;
    int maxFavorites;
    float budget;
    char* preferredBrand;

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
    Buyer() : User(), favorites(nullptr), favoriteCount(0), maxFavorites(10),
              budget(0.0f), preferredBrand(nullptr) {
        favorites = new Listing*[maxFavorites];
        for (int i = 0; i < maxFavorites; i++) {
            favorites[i] = nullptr;
        }
        copyString(preferredBrand, "Any");
    }

    // Parameterized Constructor
    Buyer(const char* uname, const char* pass, const char* em, const char* ph,
          float bud, const char* brand, int maxFav = 10)
        : User(uname, pass, em, ph), favoriteCount(0), maxFavorites(maxFav),
          budget(bud) {
        favorites = new Listing*[maxFavorites];
        for (int i = 0; i < maxFavorites; i++) {
            favorites[i] = nullptr;
        }
        copyString(preferredBrand, brand);
    }

    // Copy Constructor
    Buyer(const Buyer& other) : User(other), favoriteCount(other.favoriteCount),
                                 maxFavorites(other.maxFavorites), budget(other.budget) {
        favorites = new Listing*[maxFavorites];
        for (int i = 0; i < favoriteCount; i++) {
            favorites[i] = other.favorites[i];  // Shallow copy (aggregation)
        }
        for (int i = favoriteCount; i < maxFavorites; i++) {
            favorites[i] = nullptr;
        }
        copyString(preferredBrand, other.preferredBrand);
    }

    // Destructor
    ~Buyer() override {
        // Only delete the array, not the pointed-to objects (aggregation)
        delete[] favorites;
        deleteString(preferredBrand);
    }

    // Override display
    void display() const override {
        User::display();
        std::cout << "Role: Buyer\n";
        std::cout << "Budget: $" << budget << "\n";
        std::cout << "Preferred Brand: " << (preferredBrand ? preferredBrand : "N/A") << "\n";
        std::cout << "Favorites: " << favoriteCount << "/" << maxFavorites << "\n";
    }

    // Override getRole
    const char* getRole() const override {
        return "Buyer";
    }

    // Add a listing to favorites
    void addFavorite(Listing* listing) {
        if (!listing) {
            std::cout << "Invalid listing!\n";
            return;
        }
        
        if (favoriteCount >= maxFavorites) {
            std::cout << "Favorites list is full! Maximum " << maxFavorites << " allowed.\n";
            return;
        }
        
        // Check if already in favorites
        for (int i = 0; i < favoriteCount; i++) {
            if (favorites[i] == listing) {
                std::cout << "Listing already in favorites!\n";
                return;
            }
        }
        
        favorites[favoriteCount++] = listing;
        std::cout << "Listing added to favorites!\n";
    }

    // Remove a listing from favorites
    void removeFavorite(Listing* listing) {
        if (!listing) return;
        
        for (int i = 0; i < favoriteCount; i++) {
            if (favorites[i] == listing) {
                // Shift remaining elements
                for (int j = i; j < favoriteCount - 1; j++) {
                    favorites[j] = favorites[j + 1];
                }
                favorites[--favoriteCount] = nullptr;
                std::cout << "Listing removed from favorites!\n";
                return;
            }
        }
        std::cout << "Listing not found in favorites!\n";
    }

    // View favorites
    void viewFavorites() const;

    // Send message to seller (defined later to avoid circular dependency)
    void sendMessage(Marketplace* marketplace, const char* receiverName, 
                    const char* content);

    // Getters
    Listing* const* getFavorites() const { return favorites; }
    int getFavoriteCount() const { return favoriteCount; }
    int getMaxFavorites() const { return maxFavorites; }
    float getBudget() const { return budget; }
    const char* getPreferredBrand() const { return preferredBrand; }

    // Setters
    void setBudget(float bud) { budget = bud; }
    void setPreferredBrand(const char* brand) {
        deleteString(preferredBrand);
        copyString(preferredBrand, brand);
    }
};

#endif // BUYER_H
