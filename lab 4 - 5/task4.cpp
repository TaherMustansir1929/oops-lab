#include<iostream>
using namespace std;

class Engine {
public:
    int hp;
};

class Car {
public:
    string model;
    Engine eng;
};

int main() {
    Car c;
    c.model = "Toyota";
    c.eng.hp = 150;
    cout << "Model: " << c.model << ", HP: " << c.eng.hp << endl;
}
