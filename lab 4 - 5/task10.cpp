#include<iostream>
using namespace std;

class Branch {
public:
    string bName, city;
};

class Account {
public:
    string holder;
    float balance;
    Branch* branch;
    static string bankName;
    static float rate;

    static void updateRate(float r) { rate = r; }

    void showBalance() const {
        cout << holder << " | Balance: " << balance
             << " | Bank: " << bankName << " | Rate: " << rate
             << " | Branch: " << branch->bName << ", " << branch->city << endl;
    }
};

string Account::bankName = "MCB";
float Account::rate = 4.0;

int main() {
    Branch b1 = {"Main Branch", "Karachi"};
    Branch b2 = {"North Branch", "Lahore"};

    Account accs[3];
    accs[0] = {"Ali",  10000, &b1};
    accs[1] = {"Sara", 20000, &b2};
    accs[2] = {"John", 15000, &b1};

    Account::updateRate(5.5);
    for (int i = 0; i < 3; i++) accs[i].showBalance();
}
