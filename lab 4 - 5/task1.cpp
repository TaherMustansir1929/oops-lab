#include<iostream>
using namespace std;

class Car {
    int speed;
public:
    void setSpeed(int s) { speed = s; }
    void showSpeed() const { cout << "Speed: " << speed << endl; }
};

int main() {
    Car c;
    c.setSpeed(100);
    c.showSpeed();
}
