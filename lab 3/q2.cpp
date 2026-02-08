#include <iostream>
#include <string>
using namespace std;

class WeekDays {
private:
    string Days[7];
    int CurrentDay;

public:
    WeekDays() {
        Days[0] = "Sunday";
        Days[1] = "Monday";
        Days[2] = "Tuesday";
        Days[3] = "Wednesday";
        Days[4] = "Thursday";
        Days[5] = "Friday";
        Days[6] = "Saturday";
        CurrentDay = 0;
    }
    
    WeekDays(int day) {
        Days[0] = "Sunday";
        Days[1] = "Monday";
        Days[2] = "Tuesday";
        Days[3] = "Wednesday";
        Days[4] = "Thursday";
        Days[5] = "Friday";
        Days[6] = "Saturday";
        
        if (day > 6) {
            CurrentDay = day % 7;
        } else {
            CurrentDay = day;
        }
    }
    
    string getCurrentDay() {
        return Days[CurrentDay];
    }
    
    string getNextDay() {
        int next = (CurrentDay + 1) % 7;
        return Days[next];
    }
    
    string getPreviousDay() {
        int prev = (CurrentDay - 1);
        if (prev < 0) {
            prev = 6;
        }
        return Days[prev];
    }
    
    string getNthDayFromToday(int n) {
        int day = (CurrentDay + n) % 7;
        return Days[day];
    }
};

int main() {
    WeekDays w1;
    cout << "Current Day: " << w1.getCurrentDay() << endl;
    cout << "Next Day: " << w1.getNextDay() << endl;
    cout << "Previous Day: " << w1.getPreviousDay() << endl;
    
    cout << endl;
    
    WeekDays w2(1);
    cout << "Current Day: " << w2.getCurrentDay() << endl;
    cout << "Next Day: " << w2.getNextDay() << endl;
    cout << "20 days from today: " << w2.getNthDayFromToday(20) << endl;
    
    cout << endl;
    
    WeekDays w3(8);
    cout << "Current Day (input 8): " << w3.getCurrentDay() << endl;
    cout << "Next Day: " << w3.getNextDay() << endl;
    
    return 0;
}
