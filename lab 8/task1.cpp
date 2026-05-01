#include<iostream>
using namespace std;

class Time;

class Speed {
    float s;
public:
    Speed(float s) { this->s = s; }
    friend float calculateDistance(Speed, Time);
};

class Time {
    float t;
public:
    Time(float t) { this->t = t; }
    friend float calculateDistance(Speed, Time);
};

float calculateDistance(Speed sp, Time tm) {
    return sp.s * tm.t;
}

int main() {
    Speed sp(60);
    Time tm(2);
    cout << "Distance: " << calculateDistance(sp, tm) << " km" << endl;
    return 0;
}
