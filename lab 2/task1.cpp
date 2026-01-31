#include <iostream>
#include <string>
using namespace std;

class BoardMarker {
private:
    string company;
    string color;
    bool refillable;
    bool inkEmpty;

public:
    void setCompany(string c) { company = c; }
    void setColor(string col) { color = col; }
    void setRefillable(bool r) { refillable = r; }
    void setInkEmpty(bool e) { inkEmpty = e; }
    
    string getCompany() { return company; }
    string getColor() { return color; }
    bool getRefillable() { return refillable; }
    bool getInkEmpty() { return inkEmpty; }
    
    void write() {
        if (inkEmpty) {
            cout << "Cannot write. Ink is empty." << endl;
        } else {
            cout << "Writing with " << color << " marker." << endl;
        }
    }
    
    void refill() {
        if (refillable) {
            inkEmpty = false;
            cout << "Marker refilled." << endl;
        } else {
            cout << "This marker cannot be refilled." << endl;
        }
    }
};

int main() {
    BoardMarker m1, m2, m3;
    
    m1.setCompany("Dollar");
    m1.setColor("black");
    m1.setRefillable(true);
    m1.setInkEmpty(false);
    
    m2.setCompany("Marker");
    m2.setColor("red");
    m2.setRefillable(false);
    m2.setInkEmpty(true);
    
    m3.setCompany("Board");
    m3.setColor("blue");
    m3.setRefillable(true);
    m3.setInkEmpty(true);
    
    cout << "Marker 1:" << endl;
    m1.write();
    m1.refill();
    
    cout << "\nMarker 2:" << endl;
    m2.write();
    m2.refill();
    
    cout << "\nMarker 3:" << endl;
    m3.write();
    m3.refill();
    m3.write();
    
    return 0;
}
