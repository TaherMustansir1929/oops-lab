#include <iostream>
#include <string>
using namespace std;

class WaterBottle {
private:
    string company;
    string color;
    double liters;
    double ml;

public:
    void setCompany(string c) { company = c; }
    void setColor(string col) { color = col; }
    
    void setCapacity(double l) {
        liters = l;
        ml = l * 1000;
    }
    
    string getCompany() { return company; }
    string getColor() { return color; }
    double getLiters() { return liters; }
    double getMl() { return ml; }
    
    void drink() {
        double amount;
        cout << "How much water did you drink (in ml)? ";
        cin >> amount;
        
        ml = ml - amount;
        liters = ml / 1000;
        
        cout << "Remaining water: " << liters << " liters (" << ml << " ml)" << endl;
    }
};

int main() {
    WaterBottle w;
    
    w.setCompany("Aqua");
    w.setColor("blue");
    w.setCapacity(1.5);
    
    cout << "Company: " << w.getCompany() << endl;
    cout << "Color: " << w.getColor() << endl;
    cout << "Initial capacity: " << w.getLiters() << " liters (" << w.getMl() << " ml)" << endl;
    
    w.drink();
    w.drink();
    
    return 0;
}
