#include<iostream>
using namespace std;

int main() {
    int n, d;
    cout << "Enter numerator: ";
    cin >> n;
    cout << "Enter denominator: ";
    cin >> d;

    try {
        if (d == 0) throw "Division by zero is not allowed!";
        cout << "Result: " << n / d << endl;
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }

    return 0;
}
