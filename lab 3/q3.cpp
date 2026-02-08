#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
private:
    string name;
    string type;
    bool status;

public:
    SmartDevice(string n, string t, bool s) {
        name = n;
        type = t;
        status = s;
        cout << name << " (" << type << ") is now created and ";
        if (status) {
            cout << "ON" << endl;
        } else {
            cout << "OFF" << endl;
        }
    }
    
    ~SmartDevice() {
        cout << name << " (" << type << ") is powering down... Goodbye!" << endl;
    }
    
    void display() {
        cout << "Device: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Status: ";
        if (status) {
            cout << "ON" << endl;
        } else {
            cout << "OFF" << endl;
        }
    }
};

int main() {
    SmartDevice d1("Living Room Light", "Smart Light", true);
    d1.display();
    cout << endl;
    
    SmartDevice d2("Robo Cleaner", "Robot Vacuum", false);
    d2.display();
    cout << endl;
    
    SmartDevice d3("Coffee Maker", "Smart Coffee Machine", true);
    d3.display();
    cout << endl;
    
    cout << "Devices are being destroyed..." << endl;
    
    return 0;
}
