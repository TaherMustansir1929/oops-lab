#include<iostream>
using namespace std;

class Account {
public:
    string holder;
    float balance;
    static string bankName;
    static float rate;

    void deposit(float amt) { balance += amt; }
    void showBalance() const {
        cout << holder << " | Balance: " << balance
             << " | Bank: " << bankName << " | Rate: " << rate << endl;
    }
};

string Account::bankName = "HBL";
float Account::rate = 3.5;

int main() {
    Account a1, a2, a3;
    a1.holder = "Ali";   a1.balance = 1000;
    a2.holder = "Sara";  a2.balance = 2000;
    a3.holder = "John";  a3.balance = 3000;

    a1.deposit(500);
    a2.deposit(200);

    a1.showBalance();
    a2.showBalance();
    a3.showBalance();
}
