#include <iostream>
#include "Employee.h"
using namespace std;

void Employee::getData() {
    cout << "Enter employee name: ";
    cin >> name;
    cout << "Enter monthly salary: ";
    cin >> salary;
    cout << "Enter tax percentage: ";
    cin >> tax;
}

double Employee::salaryAfterTax() {
    double deduction = salary * (tax / 100);
    double remaining = salary - deduction;
    return remaining;
}

void Employee::updateTax() {
    double newTax;
    cout << "Enter new tax percentage: ";
    cin >> newTax;
    tax = newTax;
    cout << "Tax updated to " << tax << "%" << endl;
    cout << "New salary after tax: " << salaryAfterTax() << endl;
}
