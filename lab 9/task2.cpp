#include<iostream>
using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
    bool isOn;
    int brightness;
public:
    LightBulb(int b) { isOn = false; brightness = b; }
    void turnOn() { isOn = true; }
    void turnOff() { isOn = false; }
    void getStatus() {
        cout << "LightBulb - On: " << (isOn ? "Yes" : "No") << ", Brightness: " << brightness << "%" << endl;
    }
};

class Thermostat : public SmartDevice {
    bool isOn;
    double temperature;
public:
    Thermostat(double t) { isOn = false; temperature = t; }
    void turnOn() { isOn = true; }
    void turnOff() { isOn = false; }
    void getStatus() {
        cout << "Thermostat - On: " << (isOn ? "Yes" : "No") << ", Temp: " << temperature << "C" << endl;
    }
};

int main() {
    SmartDevice* d1 = new LightBulb(75);
    SmartDevice* d2 = new Thermostat(22.5);

    d1->turnOn();
    d1->getStatus();
    d1->turnOff();
    d1->getStatus();

    d2->turnOn();
    d2->getStatus();
    d2->turnOff();
    d2->getStatus();

    delete d1;
    delete d2;
    return 0;
}
