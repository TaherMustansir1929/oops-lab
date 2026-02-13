#ifndef INSURANCE_H
#define INSURANCE_H

#include <iostream>
#include <cstring>
#include <ctime>

class Insurance {
private:
    const int policyNumber;  // CONST DATA MEMBER #1
    char* provider;
    char* coverageType;      // e.g., "Comprehensive", "Third Party"
    float premium;           // monthly premium
    char* expiryDate;        // format: "DD/MM/YYYY"
    bool isActive;

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
    Insurance() : policyNumber(0), provider(nullptr), coverageType(nullptr), 
                  premium(0.0f), expiryDate(nullptr), isActive(false) {
        copyString(provider, "Unknown");
        copyString(coverageType, "None");
        copyString(expiryDate, "01/01/2025");
    }

    // Parameterized Constructor
    Insurance(int policyNum, const char* prov, const char* coverage, 
              float prem, const char* expiry, bool active)
        : policyNumber(policyNum), premium(prem), isActive(active) {
        copyString(provider, prov);
        copyString(coverageType, coverage);
        copyString(expiryDate, expiry);
    }

    // Copy Constructor
    Insurance(const Insurance& other)
        : policyNumber(other.policyNumber), premium(other.premium), 
          isActive(other.isActive) {
        copyString(provider, other.provider);
        copyString(coverageType, other.coverageType);
        copyString(expiryDate, other.expiryDate);
    }

    // Destructor
    ~Insurance() {
        deleteString(provider);
        deleteString(coverageType);
        deleteString(expiryDate);
    }

    // Assignment Operator
    Insurance& operator=(const Insurance& other) {
        if (this != &other) {
            // Note: policyNumber is const, cannot be reassigned
            deleteString(provider);
            deleteString(coverageType);
            deleteString(expiryDate);
            
            copyString(provider, other.provider);
            copyString(coverageType, other.coverageType);
            copyString(expiryDate, other.expiryDate);
            premium = other.premium;
            isActive = other.isActive;
        }
        return *this;
    }

    // Display insurance details (const function)
    void display() const {
        std::cout << "Policy Number: " << policyNumber << "\n";
        std::cout << "Provider: " << (provider ? provider : "N/A") << "\n";
        std::cout << "Coverage Type: " << (coverageType ? coverageType : "N/A") << "\n";
        std::cout << "Premium: $" << premium << "/month\n";
        std::cout << "Expiry Date: " << (expiryDate ? expiryDate : "N/A") << "\n";
        std::cout << "Status: " << (isActive ? "Active" : "Expired") << "\n";
    }

    // Check if insurance is expired (const function)
    bool isExpired() const {
        // Simple check based on active status
        return !isActive;
    }

    // Renew insurance
    void renew(const char* newExpiry) {
        deleteString(expiryDate);
        copyString(expiryDate, newExpiry);
        isActive = true;
        std::cout << "Insurance renewed successfully until " << newExpiry << "\n";
    }

    // Calculate premium based on coverage type (const function)
    float calculatePremium() const {
        if (!coverageType) return 0.0f;
        
        if (strcmp(coverageType, "Comprehensive") == 0) {
            return premium * 1.5f;  // Higher premium for comprehensive
        } else if (strcmp(coverageType, "Third Party") == 0) {
            return premium * 0.8f;  // Lower premium for third party
        }
        return premium;
    }

    // Getters
    int getPolicyNumber() const { return policyNumber; }
    const char* getProvider() const { return provider; }
    const char* getCoverageType() const { return coverageType; }
    float getPremium() const { return premium; }
    const char* getExpiryDate() const { return expiryDate; }
    bool getIsActive() const { return isActive; }

    // Setters
    void setProvider(const char* prov) {
        deleteString(provider);
        copyString(provider, prov);
    }
    void setCoverageType(const char* coverage) {
        deleteString(coverageType);
        copyString(coverageType, coverage);
    }
    void setPremium(float prem) { premium = prem; }
    void setExpiryDate(const char* expiry) {
        deleteString(expiryDate);
        copyString(expiryDate, expiry);
    }
    void setIsActive(bool active) { isActive = active; }
};

#endif // INSURANCE_H
