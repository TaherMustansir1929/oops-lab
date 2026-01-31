#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;
    double tax;

public:
    void getData() {
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter monthly salary: ";
        cin >> salary;
        cout << "Enter tax percentage: ";
        cin >> tax;
    }
    
    double salaryAfterTax() {
        double deduction = salary * (tax / 100);
        double remaining = salary - deduction;
        return remaining;
    }
    
    void updateTax() {
        double newTax;
        cout << "Enter new tax percentage: ";
        cin >> newTax;
        tax = newTax;
        cout << "Tax updated to " << tax << "%" << endl;
        cout << "New salary after tax: " << salaryAfterTax() << endl;
    }
};

int main() {
    Employee e;
    
    e.getData();
    cout << "Salary after tax: " << e.salaryAfterTax() << endl;
    e.updateTax();
    
    return 0;
}
