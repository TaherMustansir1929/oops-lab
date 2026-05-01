#include<iostream>
using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
    string cardNumber;
public:
    CreditCard(string num) { cardNumber = num; }
    void processPayment(double amount) {
        if (cardNumber.length() == 16)
            cout << "CreditCard payment of " << amount << " successful." << endl;
        else
            cout << "CreditCard payment failed: invalid card." << endl;
    }
};

class DigitalWallet : public PaymentMethod {
    double balance;
public:
    DigitalWallet(double b) { balance = b; }
    void processPayment(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Wallet payment of " << amount << " successful. Remaining: " << balance << endl;
        } else {
            cout << "Wallet payment failed: insufficient balance." << endl;
        }
    }
};

int main() {
    PaymentMethod* p1 = new CreditCard("1234567812345678");
    PaymentMethod* p2 = new DigitalWallet(100.0);

    p1->processPayment(49.99);
    p2->processPayment(60.0);
    p2->processPayment(60.0);

    delete p1;
    delete p2;
    return 0;
}
