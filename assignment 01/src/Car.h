#ifndef CAR_H
#define CAR_H

#include "Engine.h"
#include "Insurance.h"
#include <iostream>
#include <cstring>

class Car {
private:
    char* brand;
    char* model;
    int year;
    float price;
    int mileage;
    char* color;
    Engine engine;        // COMPOSITION #1: Car owns Engine
    Insurance insurance;  // COMPOSITION #2: Car owns Insurance

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
    Car() : brand(nullptr), model(nullptr), year(0), price(0.0f), 
            mileage(0), color(nullptr), engine(), insurance() {
        copyString(brand, "Unknown");
        copyString(model, "Unknown");
        copyString(color, "White");
    }

    // Parameterized Constructor
    Car(const char* b, const char* m, int y, float p, int mil, 
        const char* col, const Engine& eng, const Insurance& ins)
        : year(y), price(p), mileage(mil), engine(eng), insurance(ins) {
        copyString(brand, b);
        copyString(model, m);
        copyString(color, col);
    }

    // Copy Constructor
    Car(const Car& other)
        : year(other.year), price(other.price), mileage(other.mileage),
          engine(other.engine), insurance(other.insurance) {
        copyString(brand, other.brand);
        copyString(model, other.model);
        copyString(color, other.color);
    }

    // Destructor
    ~Car() {
        deleteString(brand);
        deleteString(model);
        deleteString(color);
        // engine and insurance are automatically destroyed (composition)
    }

    // Assignment Operator
    Car& operator=(const Car& other) {
        if (this != &other) {
            deleteString(brand);
            deleteString(model);
            deleteString(color);
            
            copyString(brand, other.brand);
            copyString(model, other.model);
            copyString(color, other.color);
            year = other.year;
            price = other.price;
            mileage = other.mileage;
            engine = other.engine;
            insurance = other.insurance;
        }
        return *this;
    }

    // Display car details (const function)
    void display() const {
        std::cout << "\n=== Car Details ===\n";
        std::cout << "Brand: " << (brand ? brand : "N/A") << "\n";
        std::cout << "Model: " << (model ? model : "N/A") << "\n";
        std::cout << "Year: " << year << "\n";
        std::cout << "Price: $" << price << "\n";
        std::cout << "Mileage: " << mileage << " km\n";
        std::cout << "Color: " << (color ? color : "N/A") << "\n";
        std::cout << "\n--- Engine ---\n";
        engine.display();
        std::cout << "\n--- Insurance ---\n";
        insurance.display();
        std::cout << "==================\n";
    }

    // Check if car matches filter criteria (const function)
    bool matchesFilter(const char* filterBrand, int minYear, int maxYear, 
                      float minPrice, float maxPrice) const {
        bool brandMatch = true;
        if (filterBrand && strlen(filterBrand) > 0) {
            brandMatch = (brand && strcmp(brand, filterBrand) == 0);
        }
        
        bool yearMatch = (year >= minYear && year <= maxYear);
        bool priceMatch = (price >= minPrice && price <= maxPrice);
        
        return brandMatch && yearMatch && priceMatch;
    }

    // Calculate depreciation (const function)
    float calculateDepreciation() const {
        int currentYear = 2026;  // Current year
        int age = currentYear - year;
        if (age <= 0) return 0.0f;
        
        float depreciationRate = 0.15f;  // 15% per year
        float totalDepreciation = price * depreciationRate * age;
        return totalDepreciation;
    }

    // Compare this car to another (const function)
    int compareTo(const Car& other) const {
        // Compare based on price
        if (price > other.price) return 1;
        if (price < other.price) return -1;
        return 0;
    }

    // Getters
    const char* getBrand() const { return brand; }
    const char* getModel() const { return model; }
    int getYear() const { return year; }
    float getPrice() const { return price; }
    int getMileage() const { return mileage; }
    const char* getColor() const { return color; }
    const Engine& getEngine() const { return engine; }
    const Insurance& getInsurance() const { return insurance; }

    // Setters
    void setBrand(const char* b) {
        deleteString(brand);
        copyString(brand, b);
    }
    void setModel(const char* m) {
        deleteString(model);
        copyString(model, m);
    }
    void setYear(int y) { year = y; }
    void setPrice(float p) { price = p; }
    void setMileage(int mil) { mileage = mil; }
    void setColor(const char* col) {
        deleteString(color);
        copyString(color, col);
    }
    void setEngine(const Engine& eng) { engine = eng; }
    void setInsurance(const Insurance& ins) { insurance = ins; }
};

#endif // CAR_H
