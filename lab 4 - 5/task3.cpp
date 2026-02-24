#include<iostream>
using namespace std;

class BankAccount {
public:
    static float interestRate;
    static void changeRate(float r) { interestRate = r; }
    void showRate() { cout << "Rate: " << interestRate << endl; }
};

float BankAccount::interestRate = 5.0;

int main() {
    BankAccount a, b, c;
    BankAccount::changeRate(8.5);
    a.showRate();
    b.showRate();
    c.showRate();
}
