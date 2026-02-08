#include <iostream>
#include <string>
using namespace std;

class CricketPlayer {
private:
    string name;
    int jerseyNumber;
    double battingAverage;

public:
    CricketPlayer(string name, int jerseyNumber, double battingAverage) {
        this->name = name;
        this->jerseyNumber = jerseyNumber;
        this->battingAverage = battingAverage;
    }
    
    CricketPlayer& improveAverage(double runs) {
        this->battingAverage = this->battingAverage + runs;
        return *this;
    }
    
    void displayPlayerStats() {
        cout << "Player: " << name << endl;
        cout << "Jersey Number: " << jerseyNumber << endl;
        cout << "Batting Average: " << battingAverage << endl;
        cout << "This batting average is more consistent than Karachi's weather!" << endl;
        cout << endl;
    }
    
    void playMatch(double runsScored) {
        battingAverage = (battingAverage + runsScored) / 2;
        cout << name << " scored " << runsScored << " runs in the match!" << endl;
        cout << "Updated Batting Average: " << battingAverage << endl;
        cout << endl;
    }
};

int main() {
    CricketPlayer p1("Babar Azam", 56, 45.5);
    CricketPlayer p2("Muhammad Rizwan", 17, 42.3);
    CricketPlayer p3("Saim Ayub", 32, 38.7);
    
    cout << "Initial Stats:" << endl;
    p1.displayPlayerStats();
    p2.displayPlayerStats();
    p3.displayPlayerStats();
    
    cout << "Improving averages with method chaining:" << endl;
    p1.improveAverage(5.0).improveAverage(3.0);
    p1.displayPlayerStats();
    
    cout << "Playing matches:" << endl;
    p1.playMatch(85.0);
    p2.playMatch(92.0);
    p3.playMatch(120.0);
    
    cout << "Final Stats:" << endl;
    p1.displayPlayerStats();
    p2.displayPlayerStats();
    p3.displayPlayerStats();
    
    return 0;
}
