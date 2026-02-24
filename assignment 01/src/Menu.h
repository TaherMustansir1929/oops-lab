#pragma once

#include "App.h"
#include <iostream>
#include <limits>
#include <cstring>

class Menu {
private:
    App* app;
    User* currentUser;
    bool isRunning;
    char* menuTitle;

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

    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void pause() {
        std::cout << "\nPress Enter to continue...";
        clearInputBuffer();
    }

public:
    // Constructor
    Menu(App* application) : app(application), currentUser(nullptr), isRunning(true) {
        copyString(menuTitle, "=== CAR MARKETPLACE SYSTEM ===");
    }

    // Destructor
    ~Menu() {
        deleteString(menuTitle);
    }

    // Show welcome screen
    void showWelcome() {
        std::cout << "\n\n";
        std::cout << "============================================\n";
        std::cout << menuTitle << "\n";
        std::cout << "============================================\n";
        std::cout << "       Welcome to PakWheels Clone!\n";
        std::cout << "============================================\n\n";
    }

    // Handle authentication
    void handleAuth() {
        while (isRunning && !currentUser) {
            std::cout << "\n=== AUTHENTICATION ===\n";
            std::cout << "1. Login\n";
            std::cout << "2. Register as Seller\n";
            std::cout << "3. Register as Buyer\n";
            std::cout << "4. Exit\n";
            std::cout << "Choose option: ";
            
            int choice;
            std::cin >> choice;
            clearInputBuffer();
            
            if (choice == 1) {
                handleLogin();
            } else if (choice == 2) {
                handleRegisterSeller();
            } else if (choice == 3) {
                handleRegisterBuyer();
            } else if (choice == 4) {
                isRunning = false;
            } else {
                std::cout << "Invalid option!\n";
            }
        }
    }

    // Handle login
    void handleLogin() {
        char username[100], password[100];
        
        std::cout << "\n=== LOGIN ===\n";
        std::cout << "Username: ";
        std::cin.getline(username, 100);
        std::cout << "Password: ";
        std::cin.getline(password, 100);
        
        currentUser = app->loginUser(username, password);
        
        if (currentUser) {
            std::cout << "Logged in as: " << currentUser->getRole() << "\n";
        }
    }

    // Handle seller registration
    void handleRegisterSeller() {
        char username[100], password[100], email[100], phone[50];
        char shopName[100], address[200];
        
        std::cout << "\n=== REGISTER AS SELLER ===\n";
        std::cout << "Username: ";
        std::cin.getline(username, 100);
        std::cout << "Password: ";
        std::cin.getline(password, 100);
        std::cout << "Email: ";
        std::cin.getline(email, 100);
        std::cout << "Phone: ";
        std::cin.getline(phone, 50);
        std::cout << "Shop Name: ";
        std::cin.getline(shopName, 100);
        std::cout << "Address: ";
        std::cin.getline(address, 200);
        
        Seller* seller = new Seller(username, password, email, phone,
                                   shopName, 0.0f, address, "13/02/2026");
        app->registerUser(seller);
    }

    // Handle buyer registration
    void handleRegisterBuyer() {
        char username[100], password[100], email[100], phone[50];
        char brand[50];
        float budget;
        
        std::cout << "\n=== REGISTER AS BUYER ===\n";
        std::cout << "Username: ";
        std::cin.getline(username, 100);
        std::cout << "Password: ";
        std::cin.getline(password, 100);
        std::cout << "Email: ";
        std::cin.getline(email, 100);
        std::cout << "Phone: ";
        std::cin.getline(phone, 50);
        std::cout << "Budget: ";
        std::cin >> budget;
        clearInputBuffer();
        std::cout << "Preferred Brand: ";
        std::cin.getline(brand, 50);
        
        Buyer* buyer = new Buyer(username, password, email, phone, budget, brand);
        app->registerUser(buyer);
    }

    // Show Admin menu
    void showAdminMenu() {
        Admin* admin = dynamic_cast<Admin*>(currentUser);
        if (!admin) return;
        
        while (isRunning && currentUser) {
            std::cout << "\n=== ADMIN MENU ===\n";
            std::cout << "1. View All Listings\n";
            std::cout << "2. View Pending Listings\n";
            std::cout << "3. Approve Listing\n";
            std::cout << "4. Remove Listing\n";
            std::cout << "5. View All Users\n";
            std::cout << "6. View Statistics\n";
            std::cout << "7. Logout\n";
            std::cout << "Choose option: ";
            
            int choice;
            std::cin >> choice;
            clearInputBuffer();
            
            if (choice == 1) {
                admin->viewAllListings(&app->getMarketplace());
                pause();
            } else if (choice == 2) {
                app->getMarketplace().displayPendingListings();
                pause();
            } else if (choice == 3) {
                int listingId;
                std::cout << "Enter Listing ID to approve: ";
                std::cin >> listingId;
                clearInputBuffer();
                Listing* listing = app->getMarketplace().findListingById(listingId);
                admin->approveListing(listing);
                pause();
            } else if (choice == 4) {
                int listingId;
                std::cout << "Enter Listing ID to remove: ";
                std::cin >> listingId;
                clearInputBuffer();
                admin->removeListing(&app->getMarketplace(), listingId);
                pause();
            } else if (choice == 5) {
                admin->viewAllUsers(app->getUsers(), app->getUserCount());
                pause();
            } else if (choice == 6) {
                std::cout << "\n=== STATISTICS ===\n";
                std::cout << "Total Users: " << User::getUserCount() << "\n";
                std::cout << "Total Listings: " << Listing::getListingCount() << "\n";
                std::cout << "Approved by you: " << admin->getApprovedCount() << "\n";
                pause();
            } else if (choice == 7) {
                currentUser = nullptr;
                std::cout << "Logged out successfully!\n";
            } else {
                std::cout << "Invalid option!\n";
            }
        }
    }

    // Show Seller menu
    void showSellerMenu() {
        Seller* seller = dynamic_cast<Seller*>(currentUser);
        if (!seller) return;
        
        while (isRunning && currentUser) {
            std::cout << "\n=== SELLER MENU ===\n";
            std::cout << "1. View My Listings\n";
            std::cout << "2. Create New Listing\n";
            std::cout << "3. Update Listing\n";
            std::cout << "4. Delete Listing\n";
            std::cout << "5. View My Profile\n";
            std::cout << "6. View Messages\n";
            std::cout << "7. Logout\n";
            std::cout << "Choose option: ";
            
            int choice;
            std::cin >> choice;
            clearInputBuffer();
            
            if (choice == 1) {
                seller->viewMyListings(&app->getMarketplace());
                pause();
            } else if (choice == 2) {
                handleCreateListing(seller);
                pause();
            } else if (choice == 3) {
                int listingId;
                float newPrice;
                char newDesc[500];
                std::cout << "Enter Listing ID to update: ";
                std::cin >> listingId;
                clearInputBuffer();
                std::cout << "New Price: ";
                std::cin >> newPrice;
                clearInputBuffer();
                std::cout << "New Description: ";
                std::cin.getline(newDesc, 500);
                seller->updateListing(&app->getMarketplace(), listingId, newPrice, newDesc);
                pause();
            } else if (choice == 4) {
                int listingId;
                std::cout << "Enter Listing ID to delete: ";
                std::cin >> listingId;
                clearInputBuffer();
                seller->deleteListing(&app->getMarketplace(), listingId);
                pause();
            } else if (choice == 5) {
                seller->display();
                pause();
            } else if (choice == 6) {
                app->getMarketplace().getMessagesForUser(seller->getUsername());
                pause();
            } else if (choice == 7) {
                currentUser = nullptr;
                std::cout << "Logged out successfully!\n";
            } else {
                std::cout << "Invalid option!\n";
            }
        }
    }

    // Show Buyer menu
    void showBuyerMenu() {
        Buyer* buyer = dynamic_cast<Buyer*>(currentUser);
        if (!buyer) return;
        
        while (isRunning && currentUser) {
            std::cout << "\n=== BUYER MENU ===\n";
            std::cout << "1. View All Listings\n";
            std::cout << "2. Search by Brand\n";
            std::cout << "3. Search by Price Range\n";
            std::cout << "4. Filter by Year\n";
            std::cout << "5. Add to Favorites\n";
            std::cout << "6. View Favorites\n";
            std::cout << "7. Remove from Favorites\n";
            std::cout << "8. Send Message to Seller\n";
            std::cout << "9. View My Profile\n";
            std::cout << "10. Logout\n";
            std::cout << "Choose option: ";
            
            int choice;
            std::cin >> choice;
            clearInputBuffer();
            
            if (choice == 1) {
                app->getMarketplace().displayAllListings();
                pause();
            } else if (choice == 2) {
                char brand[50];
                std::cout << "Enter Brand: ";
                std::cin.getline(brand, 50);
                app->getMarketplace().searchByBrand(brand);
                pause();
            } else if (choice == 3) {
                float minPrice, maxPrice;
                std::cout << "Min Price: ";
                std::cin >> minPrice;
                std::cout << "Max Price: ";
                std::cin >> maxPrice;
                clearInputBuffer();
                app->getMarketplace().searchByPriceRange(minPrice, maxPrice);
                pause();
            } else if (choice == 4) {
                int minYear, maxYear;
                std::cout << "Min Year: ";
                std::cin >> minYear;
                std::cout << "Max Year: ";
                std::cin >> maxYear;
                clearInputBuffer();
                app->getMarketplace().filterByYear(minYear, maxYear);
                pause();
            } else if (choice == 5) {
                int listingId;
                std::cout << "Enter Listing ID to add to favorites: ";
                std::cin >> listingId;
                clearInputBuffer();
                Listing* listing = app->getMarketplace().findListingById(listingId);
                buyer->addFavorite(listing);
                pause();
            } else if (choice == 6) {
                buyer->viewFavorites();
                pause();
            } else if (choice == 7) {
                int listingId;
                std::cout << "Enter Listing ID to remove from favorites: ";
                std::cin >> listingId;
                clearInputBuffer();
                Listing* listing = app->getMarketplace().findListingById(listingId);
                buyer->removeFavorite(listing);
                pause();
            } else if (choice == 8) {
                char receiver[100], content[500];
                std::cout << "Seller Username: ";
                std::cin.getline(receiver, 100);
                std::cout << "Message: ";
                std::cin.getline(content, 500);
                buyer->sendMessage(&app->getMarketplace(), receiver, content);
                pause();
            } else if (choice == 9) {
                buyer->display();
                pause();
            } else if (choice == 10) {
                currentUser = nullptr;
                std::cout << "Logged out successfully!\n";
            } else {
                std::cout << "Invalid option!\n";
            }
        }
    }

    // Helper: Create listing for seller
    void handleCreateListing(Seller* seller) {
        char brand[50], model[50], color[50];
        int year, mileage;
        float price;
        char title[200], description[500];
        
        std::cout << "\n=== CREATE NEW LISTING ===\n";
        std::cout << "Car Brand: ";
        std::cin.getline(brand, 50);
        std::cout << "Car Model: ";
        std::cin.getline(model, 50);
        std::cout << "Year: ";
        std::cin >> year;
        std::cout << "Price: ";
        std::cin >> price;
        std::cout << "Mileage (km): ";
        std::cin >> mileage;
        clearInputBuffer();
        std::cout << "Color: ";
        std::cin.getline(color, 50);
        std::cout << "Listing Title: ";
        std::cin.getline(title, 200);
        std::cout << "Description: ";
        std::cin.getline(description, 500);
        
        // Create simple engine and insurance
        Engine engine("Standard", 150, 2.0f, "Petrol", 4, "Manual");
        Insurance insurance(10000 + year, "General Insurance", "Third Party", 
                          2000.0f, "31/12/2027", true);
        Car car(brand, model, year, price, mileage, color, engine, insurance);
        
        seller->createListing(&app->getMarketplace(), car, title, description);
    }

    // Main run loop
    void run() {
        showWelcome();
        
        while (isRunning) {
            if (!currentUser) {
                handleAuth();
            } else {
                const char* role = currentUser->getRole();
                if (strcmp(role, "Admin") == 0) {
                    showAdminMenu();
                } else if (strcmp(role, "Seller") == 0) {
                    showSellerMenu();
                } else if (strcmp(role, "Buyer") == 0) {
                    showBuyerMenu();
                } else {
                    std::cout << "Unknown role!\n";
                    currentUser = nullptr;
                }
            }
        }
        
        std::cout << "\nThank you for using " << app->getAppName() << "!\n";
    }
};

// Implement App::run() now that Menu is defined
inline void App::run() {
    initialize();
    Menu menu(this);
    menu.run();
}

