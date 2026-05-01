#include<iostream>
using namespace std;

class Balls;

class Runs {
    int r;
public:
    Runs(int r) { this->r = r; }
    friend float calculateStrikeRate(Runs, Balls);
};

class Balls {
    int b;
public:
    Balls(int b) { this->b = b; }
    friend float calculateStrikeRate(Runs, Balls);
};

float calculateStrikeRate(Runs rn, Balls bl) {
    return ((float)rn.r / bl.b) * 100;
}

int main() {
    Runs rn(85);
    Balls bl(60);
    cout << "Strike Rate: " << calculateStrikeRate(rn, bl) << endl;
    return 0;
}
