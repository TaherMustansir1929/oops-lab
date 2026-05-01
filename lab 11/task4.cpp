#include<iostream>
using namespace std;

class InsufficientFundsException {
public:
    string msg;
    InsufficientFundsException() { msg = "Insufficient funds to complete withdrawal!"; }
};

class BankAccount {
    double balance;
public:
    BankAccount(double b) { balance = b; }
    void withdraw(double amount) {
        if (amount > balance) throw InsufficientFundsException();
        balance -= amount;
        cout << "Withdrawal successful! New Balance: $" << balance << endl;
    }
    void showBalance() { cout << "Current Balance: $" << balance << endl; }
};

int main() {
    BankAccount acc(500);
    double amount;

    acc.showBalance();
    cout << "Enter withdrawal amount: $";
    cin >> amount;
    try {
        acc.withdraw(amount);
    } catch (InsufficientFundsException &e) {
        cout << "Error: " << e.msg << endl;
    }

    return 0;
}
