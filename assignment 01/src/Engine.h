#pragma once

#include <iostream>
#include <cstring>

class Engine {
private:
    char* type;              // e.g., "V6", "V8", "Inline-4"
    int horsepower;
    float displacement;      // in liters
    char* fuelType;          // e.g., "Petrol", "Diesel", "Hybrid"
    int cylinders;
    char* transmissionType;  // e.g., "Manual", "Automatic"

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
    Engine() : type(nullptr), horsepower(0), displacement(0.0f), 
               fuelType(nullptr), cylinders(0), transmissionType(nullptr) {
        copyString(type, "Unknown");
        copyString(fuelType, "Petrol");
        copyString(transmissionType, "Manual");
    }

    // Parameterized Constructor
    Engine(const char* t, int hp, float disp, const char* fuel, 
           int cyl, const char* trans) 
        : horsepower(hp), displacement(disp), cylinders(cyl) {
        copyString(type, t);
        copyString(fuelType, fuel);
        copyString(transmissionType, trans);
    }

    // Copy Constructor
    Engine(const Engine& other) 
        : horsepower(other.horsepower), displacement(other.displacement), 
          cylinders(other.cylinders) {
        copyString(type, other.type);
        copyString(fuelType, other.fuelType);
        copyString(transmissionType, other.transmissionType);
    }

    // Destructor
    ~Engine() {
        deleteString(type);
        deleteString(fuelType);
        deleteString(transmissionType);
    }

    // Assignment Operator
    Engine& operator=(const Engine& other) {
        if (this != &other) {
            deleteString(type);
            deleteString(fuelType);
            deleteString(transmissionType);
            
            copyString(type, other.type);
            copyString(fuelType, other.fuelType);
            copyString(transmissionType, other.transmissionType);
            horsepower = other.horsepower;
            displacement = other.displacement;
            cylinders = other.cylinders;
        }
        return *this;
    }

    // Display engine details (const function)
    void display() const {
        std::cout << "Engine Type: " << (type ? type : "N/A") << "\n";
        std::cout << "Horsepower: " << horsepower << " HP\n";
        std::cout << "Displacement: " << displacement << "L\n";
        std::cout << "Fuel Type: " << (fuelType ? fuelType : "N/A") << "\n";
        std::cout << "Cylinders: " << cylinders << "\n";
        std::cout << "Transmission: " << (transmissionType ? transmissionType : "N/A") << "\n";
    }

    // Check if high performance (const function)
    bool isHighPerformance() const {
        return horsepower >= 300;
    }

    // Get fuel efficiency rating (const function)
    int getFuelEfficiencyRating() const {
        // Simple rating: higher displacement and horsepower = lower efficiency
        float ratio = displacement / horsepower;
        if (ratio < 0.015f) return 5;  // Excellent
        if (ratio < 0.020f) return 4;  // Good
        if (ratio < 0.025f) return 3;  // Average
        if (ratio < 0.030f) return 2;  // Below Average
        return 1;  // Poor
    }

    // Compare with another engine (const function)
    int compareWith(const Engine& other) const {
        int thisScore = horsepower + (cylinders * 50);
        int otherScore = other.horsepower + (other.cylinders * 50);
        if (thisScore > otherScore) return 1;
        if (thisScore < otherScore) return -1;
        return 0;
    }

    // Getters
    const char* getType() const { return type; }
    int getHorsepower() const { return horsepower; }
    float getDisplacement() const { return displacement; }
    const char* getFuelType() const { return fuelType; }
    int getCylinders() const { return cylinders; }
    const char* getTransmissionType() const { return transmissionType; }

    // Setters
    void setType(const char* t) {
        deleteString(type);
        copyString(type, t);
    }
    void setHorsepower(int hp) { horsepower = hp; }
    void setDisplacement(float disp) { displacement = disp; }
    void setFuelType(const char* fuel) {
        deleteString(fuelType);
        copyString(fuelType, fuel);
    }
    void setCylinders(int cyl) { cylinders = cyl; }
    void setTransmissionType(const char* trans) {
        deleteString(transmissionType);
        copyString(transmissionType, trans);
    }
};

