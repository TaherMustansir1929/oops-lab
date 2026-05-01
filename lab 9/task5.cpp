#include<iostream>
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() = 0;
    virtual ~Activity() {}
};

class Running : public Activity {
    double distance, time;
public:
    Running(double d, double t) { distance = d; time = t; }
    double calculateCaloriesBurned() {
        return distance * time * 0.75;
    }
};

class Cycling : public Activity {
    double speed, time;
public:
    Cycling(double s, double t) { speed = s; time = t; }
    double calculateCaloriesBurned() {
        return speed * time * 0.5;
    }
};

int main() {
    Activity* a1 = new Running(5.0, 30.0);
    Activity* a2 = new Cycling(20.0, 1.5);

    cout << "Running calories burned: " << a1->calculateCaloriesBurned() << endl;
    cout << "Cycling calories burned: " << a2->calculateCaloriesBurned() << endl;

    delete a1;
    delete a2;
    return 0;
}
