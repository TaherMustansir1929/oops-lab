#pragma once

#include "Marketplace.h"
#include "Admin.h"
#include "Seller.h"
#include "Buyer.h"
#include <iostream>
#include <cstring>

class App {
private:
    Marketplace marketplace;
    User** users;              // ARRAY OF OBJECTS: Polymorphic array for User* (Admin/Seller/Buyer)
    int userCount;
    int userCapacity;
    const char* const appName; // CONST DATA MEMBER #5: const pointer to const char
    bool isInitialized;

    void resizeUsers() {
        int newCapacity = userCapacity * 2;
        User** newUsers = new User*[newCapacity];
        
        for (int i = 0; i < userCount; i++) {
            newUsers[i] = users[i];
        }
        for (int i = userCount; i < newCapacity; i++) {
            newUsers[i] = nullptr;
        }
        
        delete[] users;
        users = newUsers;
        userCapacity = newCapacity;
        std::cout << "User capacity expanded to " << newCapacity << "\n";
    }

public:
    // Default Constructor
    App() : marketplace(), users(nullptr), userCount(0), userCapacity(20),
            appName("Car Marketplace System"), isInitialized(false) {
        users = new User*[userCapacity];
        for (int i = 0; i < userCapacity; i++) {
            users[i] = nullptr;
        }
    }

    // Parameterized Constructor
    App(const char* name, int initUserCap = 20)
        : marketplace(), userCount(0), userCapacity(initUserCap),
          appName(name), isInitialized(false) {
        users = new User*[userCapacity];
        for (int i = 0; i < userCapacity; i++) {
            users[i] = nullptr;
        }
    }

    // Destructor
    ~App() {
        cleanup();
    }

    // Initialize app with sample data
    void initialize() {
        if (isInitialized) {
            std::cout << "App already initialized.\n";
            return;
        }
        
        std::cout << "\n=== Initializing " << appName << " ===\n";
        
        // Create default admin
        Admin* admin = new Admin("admin", "admin123", "admin@pakwheels.com", 
                                "0300-1234567", 5, "Management", "ADMIN123");
        registerUser(admin);
        
        // Create sample sellers
        Seller* seller1 = new Seller("seller1", "pass123", "seller1@email.com",
                                    "0301-1111111", "AutoHub", 4.5f,
                                    "Main Boulevard, Lahore", "01/01/2020");
        Seller* seller2 = new Seller("seller2", "pass456", "seller2@email.com",
                                    "0302-2222222", "Elite Motors", 4.8f,
                                    "Clifton, Karachi", "15/06/2021");
        registerUser(seller1);
        registerUser(seller2);
        
        // Create sample buyers
        Buyer* buyer1 = new Buyer("buyer1", "pass789", "buyer1@email.com",
                                 "0303-3333333", 5000000.0f, "Toyota", 15);
        Buyer* buyer2 = new Buyer("buyer2", "pass000", "buyer2@email.com",
                                 "0304-4444444", 8000000.0f, "Honda", 10);
        registerUser(buyer1);
        registerUser(buyer2);
        
        // Create sample cars and listings
        Engine engine1("V6", 250, 3.5f, "Petrol", 6, "Automatic");
        Insurance insurance1(12345, "State Life", "Comprehensive", 5000.0f,
                           "31/12/2026", true);
        Car car1("Toyota", "Corolla", 2022, 4500000.0f, 15000, "White",
                engine1, insurance1);
        
        Listing* listing1 = new Listing(car1, seller1, "2022 Toyota Corolla - Excellent Condition",
                                       "Low mileage, single owner, all service records available",
                                       "01/02/2026");
        marketplace.addListing(listing1);
        
        Engine engine2("Inline-4", 180, 2.0f, "Petrol", 4, "Manual");
        Insurance insurance2(54321, "Jubilee Insurance", "Third Party", 3000.0f,
                           "30/06/2027", true);
        Car car2("Honda", "Civic", 2021, 5200000.0f, 22000, "Black",
                engine2, insurance2);
        
        Listing* listing2 = new Listing(car2, seller2, "2021 Honda Civic - Sporty & Reliable",
                                       "Well maintained, complete documentation",
                                       "10/02/2026");
        marketplace.addListing(listing2);
        
        isInitialized = true;
        std::cout << "Initialization complete!\n";
        std::cout << "Default Admin - Username: admin, Password: admin123\n";
        std::cout << "Total Users: " << userCount << "\n";
        std::cout << "Total Listings: " << marketplace.getListingCount() << "\n\n";
    }

    // Register a new user
    void registerUser(User* user) {
        if (!user) {
            std::cout << "Cannot register null user!\n";
            return;
        }
        
        // Check if username already exists
        for (int i = 0; i < userCount; i++) {
            if (users[i] && strcmp(users[i]->getUsername(), user->getUsername()) == 0) {
                std::cout << "Username already exists!\n";
                delete user;
                return;
            }
        }
        
        if (userCount >= userCapacity) {
            resizeUsers();
        }
        
        users[userCount++] = user;
        std::cout << "User registered successfully! Role: " << user->getRole() << "\n";
    }

    // Find user by username (const function)
    User* findUserByUsername(const char* username) const {
        if (!username) return nullptr;
        
        for (int i = 0; i < userCount; i++) {
            if (users[i] && strcmp(users[i]->getUsername(), username) == 0) {
                return users[i];
            }
        }
        return nullptr;
    }

    // Login user (const function)
    User* loginUser(const char* username, const char* password) const {
        User* user = findUserByUsername(username);
        if (user && user->authenticate(password)) {
            std::cout << "Login successful! Welcome, " << username << "\n";
            return user;
        }
        std::cout << "Invalid username or password!\n";
        return nullptr;
    }

    // Run the application
    void run();  // Defined after Menu.h is included

    // Cleanup resources
    void cleanup() {
        for (int i = 0; i < userCount; i++) {
            delete users[i];
        }
        delete[] users;
        users = nullptr;
        userCount = 0;
    }

    // Getters
    Marketplace& getMarketplace() { return marketplace; }
    const Marketplace& getMarketplace() const { return marketplace; }
    User* const* getUsers() const { return users; }
    int getUserCount() const { return userCount; }
    const char* getAppName() const { return appName; }
    bool getIsInitialized() const { return isInitialized; }
};

// Include implementations for Admin, Seller, Buyer methods that need Marketplace
#include "Marketplace.h"

// Admin method implementations
inline void Admin::approveListing(Listing* listing) {
    if (listing) {
        listing->approve();
        incrementApprovedCount();
    }
}

inline void Admin::removeListing(Marketplace* marketplace, int listingId) {
    if (marketplace) {
        marketplace->removeListing(listingId);
    }
}

inline void Admin::viewAllListings(const Marketplace* marketplace) const {
    if (marketplace) {
        std::cout << "\n=== ALL LISTINGS (Admin View) ===\n";
        const Listing* const* listings = marketplace->getListings();
        int count = marketplace->getListingCount();
        for (int i = 0; i < count; i++) {
            if (listings[i]) {
                listings[i]->display();
            }
        }
        std::cout << "Total: " << count << " listings\n";
    }
}

// Seller method implementations
inline void Seller::createListing(Marketplace* marketplace, const Car& car,
                                 const char* title, const char* description) {
    if (marketplace) {
        Listing* listing = new Listing(car, this, title, description, "13/02/2026");
        marketplace->addListing(listing);
    }
}

inline void Seller::updateListing(Marketplace* marketplace, int listingId,
                                 float newPrice, const char* newDescription) {
    if (marketplace) {
        Listing* listing = marketplace->findListingById(listingId);
        if (listing && listing->getSeller() == this) {
            listing->updateDetails(nullptr, newDescription, newPrice);
        } else {
            std::cout << "Listing not found or you're not the owner!\n";
        }
    }
}

inline void Seller::deleteListing(Marketplace* marketplace, int listingId) {
    if (marketplace) {
        Listing* listing = marketplace->findListingById(listingId);
        if (listing && listing->getSeller() == this) {
            marketplace->removeListing(listingId);
        } else {
            std::cout << "Listing not found or you're not the owner!\n";
        }
    }
}

inline void Seller::viewMyListings(const Marketplace* marketplace) const {
    if (marketplace) {
        marketplace->getListingsBySeller(getUsername());
    }
}

// Buyer method implementations
inline void Buyer::viewFavorites() const {
    std::cout << "\n=== My Favorites ===\n";
    if (favoriteCount == 0) {
        std::cout << "No favorites yet.\n";
        return;
    }
    for (int i = 0; i < favoriteCount; i++) {
        if (favorites[i]) {
            favorites[i]->display();
        }
    }
    std::cout << "Total favorites: " << favoriteCount << "\n";
}

inline void Buyer::sendMessage(Marketplace* marketplace, const char* receiverName,
                              const char* content) {
    if (marketplace && receiverName && content) {
        Message* msg = new Message(getUsername(), receiverName, content, "13:30:00");
        marketplace->addMessage(msg);
    }
}

#include "Menu.h"  // Include Menu.h for App::run() definition

