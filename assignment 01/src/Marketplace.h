#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include "Listing.h"
#include "Message.h"
#include <iostream>
#include <cstring>

class Marketplace {
private:
    Listing** listings;        // ARRAY OF OBJECTS: Dynamic array of Listing pointers
    int listingCount;
    int listingCapacity;
    Message** messages;        // ARRAY OF OBJECTS: Dynamic array of Message pointers
    int messageCount;
    int messageCapacity;
    const char* const name;    // CONST DATA MEMBER #4: const pointer to const char

    void copyString(char*& dest, const char* src) {
        if (src) {
            dest = new char[strlen(src) + 1];
            strcpy(dest, src);
        } else {
            dest = nullptr;
        }
    }

    void resizeListings() {
        int newCapacity = listingCapacity * 2;
        Listing** newListings = new Listing*[newCapacity];
        
        for (int i = 0; i < listingCount; i++) {
            newListings[i] = listings[i];
        }
        for (int i = listingCount; i < newCapacity; i++) {
            newListings[i] = nullptr;
        }
        
        delete[] listings;
        listings = newListings;
        listingCapacity = newCapacity;
        std::cout << "Listings capacity expanded to " << newCapacity << "\n";
    }

    void resizeMessages() {
        int newCapacity = messageCapacity * 2;
        Message** newMessages = new Message*[newCapacity];
        
        for (int i = 0; i < messageCount; i++) {
            newMessages[i] = messages[i];
        }
        for (int i = messageCount; i < newCapacity; i++) {
            newMessages[i] = nullptr;
        }
        
        delete[] messages;
        messages = newMessages;
        messageCapacity = newCapacity;
        std::cout << "Messages capacity expanded to " << newCapacity << "\n";
    }

public:
    // Default Constructor
    Marketplace() : listingCount(0), listingCapacity(10), messageCount(0),
                    messageCapacity(20), name("PakWheels Marketplace") {
        listings = new Listing*[listingCapacity];
        for (int i = 0; i < listingCapacity; i++) {
            listings[i] = nullptr;
        }
        
        messages = new Message*[messageCapacity];
        for (int i = 0; i < messageCapacity; i++) {
            messages[i] = nullptr;
        }
    }

    // Parameterized Constructor
    Marketplace(const char* marketName, int initListingCap = 10, int initMessageCap = 20)
        : listingCount(0), listingCapacity(initListingCap), 
          messageCount(0), messageCapacity(initMessageCap), name(marketName) {
        listings = new Listing*[listingCapacity];
        for (int i = 0; i < listingCapacity; i++) {
            listings[i] = nullptr;
        }
        
        messages = new Message*[messageCapacity];
        for (int i = 0; i < messageCapacity; i++) {
            messages[i] = nullptr;
        }
    }

    // Copy Constructor
    Marketplace(const Marketplace& other)
        : listingCount(other.listingCount), listingCapacity(other.listingCapacity),
          messageCount(other.messageCount), messageCapacity(other.messageCapacity),
          name(other.name) {
        listings = new Listing*[listingCapacity];
        for (int i = 0; i < listingCount; i++) {
            listings[i] = new Listing(*other.listings[i]);
        }
        for (int i = listingCount; i < listingCapacity; i++) {
            listings[i] = nullptr;
        }
        
        messages = new Message*[messageCapacity];
        for (int i = 0; i < messageCount; i++) {
            messages[i] = new Message(*other.messages[i]);
        }
        for (int i = messageCount; i < messageCapacity; i++) {
            messages[i] = nullptr;
        }
    }

    // Destructor
    ~Marketplace() {
        for (int i = 0; i < listingCount; i++) {
            delete listings[i];
        }
        delete[] listings;
        
        for (int i = 0; i < messageCount; i++) {
            delete messages[i];
        }
        delete[] messages;
    }

    // Add a listing
    void addListing(Listing* listing) {
        if (!listing) {
            std::cout << "Cannot add null listing!\n";
            return;
        }
        
        if (listingCount >= listingCapacity) {
            resizeListings();
        }
        
        listings[listingCount++] = listing;
        std::cout << "Listing added to marketplace! Total: " << listingCount << "\n";
    }

    // Remove a listing by ID
    bool removeListing(int listingId) {
        for (int i = 0; i < listingCount; i++) {
            if (listings[i] && listings[i]->getListingId() == listingId) {
                delete listings[i];
                
                // Shift remaining listings
                for (int j = i; j < listingCount - 1; j++) {
                    listings[j] = listings[j + 1];
                }
                listings[--listingCount] = nullptr;
                
                std::cout << "Listing #" << listingId << " removed!\n";
                return true;
            }
        }
        std::cout << "Listing #" << listingId << " not found!\n";
        return false;
    }

    // Search listings by brand (const function)
    void searchByBrand(const char* brand) const {
        if (!brand) return;
        
        std::cout << "\n=== Search Results for Brand: " << brand << " ===\n";
        int found = 0;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i] && listings[i]->getIsApproved()) {
                const Car& car = listings[i]->getCar();
                if (car.getBrand() && strcmp(car.getBrand(), brand) == 0) {
                    listings[i]->display();
                    found++;
                }
            }
        }
        if (found == 0) {
            std::cout << "No listings found for brand: " << brand << "\n";
        } else {
            std::cout << "Found " << found << " listing(s).\n";
        }
    }

    // Search listings by price range (const function)
    void searchByPriceRange(float minPrice, float maxPrice) const {
        std::cout << "\n=== Listings in Price Range: $" << minPrice 
                  << " - $" << maxPrice << " ===\n";
        int found = 0;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i] && listings[i]->getIsApproved()) {
                const Car& car = listings[i]->getCar();
                float price = car.getPrice();
                if (price >= minPrice && price <= maxPrice) {
                    listings[i]->display();
                    found++;
                }
            }
        }
        if (found == 0) {
            std::cout << "No listings found in this price range.\n";
        } else {
            std::cout << "Found " << found << " listing(s).\n";
        }
    }

    // Filter listings by year (const function)
    void filterByYear(int minYear, int maxYear) const {
        std::cout << "\n=== Listings from Year " << minYear 
                  << " to " << maxYear << " ===\n";
        int found = 0;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i] && listings[i]->getIsApproved()) {
                const Car& car = listings[i]->getCar();
                int year = car.getYear();
                if (year >= minYear && year <= maxYear) {
                    listings[i]->display();
                    found++;
                }
            }
        }
        if (found == 0) {
            std::cout << "No listings found for these years.\n";
        } else {
            std::cout << "Found " << found << " listing(s).\n";
        }
    }

    // Display all approved listings (const function)
    void displayAllListings() const {
        std::cout << "\n=== All Approved Listings ===\n";
        int approvedCount = 0;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i] && listings[i]->getIsApproved()) {
                listings[i]->display();
                approvedCount++;
            }
        }
        if (approvedCount == 0) {
            std::cout << "No approved listings available.\n";
        } else {
            std::cout << "Total approved listings: " << approvedCount << "\n";
        }
    }

    // Display all pending listings (const function)
    void displayPendingListings() const {
        std::cout << "\n=== Pending Listings (Admin Review) ===\n";
        int pendingCount = 0;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i] && !listings[i]->getIsApproved()) {
                listings[i]->display();
                pendingCount++;
            }
        }
        if (pendingCount == 0) {
            std::cout << "No pending listings.\n";
        } else {
            std::cout << "Total pending listings: " << pendingCount << "\n";
        }
    }

    // Add a message
    void addMessage(Message* message) {
        if (!message) {
            std::cout << "Cannot add null message!\n";
            return;
        }
        
        if (messageCount >= messageCapacity) {
            resizeMessages();
        }
        
        messages[messageCount++] = message;
        std::cout << "Message sent successfully!\n";
    }

    // Get messages for a specific user (const function)
    void getMessagesForUser(const char* username) const {
        if (!username) return;
        
        std::cout << "\n=== Messages for " << username << " ===\n";
        int found = 0;
        for (int i = 0; i < messageCount; i++) {
            if (messages[i]) {
                const char* receiver = messages[i]->getReceiverName();
                if (receiver && strcmp(receiver, username) == 0) {
                    messages[i]->display();
                    found++;
                }
            }
        }
        if (found == 0) {
            std::cout << "No messages for " << username << "\n";
        } else {
            std::cout << "Total messages: " << found << "\n";
        }
    }

    // Find listing by ID
    Listing* findListingById(int listingId) const {
        for (int i = 0; i < listingCount; i++) {
            if (listings[i] && listings[i]->getListingId() == listingId) {
                return listings[i];
            }
        }
        return nullptr;
    }

    // Get listings by seller (const function)
    void getListingsBySeller(const char* sellerUsername) const {
        if (!sellerUsername) return;
        
        std::cout << "\n=== Listings by " << sellerUsername << " ===\n";
        int found = 0;
        for (int i = 0; i < listingCount; i++) {
            if (listings[i]) {
                Seller* seller = listings[i]->getSeller();
                if (seller && strcmp(seller->getUsername(), sellerUsername) == 0) {
                    listings[i]->display();
                    found++;
                }
            }
        }
        if (found == 0) {
            std::cout << "No listings found for seller: " << sellerUsername << "\n";
        } else {
            std::cout << "Total listings: " << found << "\n";
        }
    }

    // Getters
    Listing* const* getListings() const { return listings; }
    int getListingCount() const { return listingCount; }
    int getListingCapacity() const { return listingCapacity; }
    Message* const* getMessages() const { return messages; }
    int getMessageCount() const { return messageCount; }
    int getMessageCapacity() const { return messageCapacity; }
    const char* getName() const { return name; }
};

#endif // MARKETPLACE_H
