#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    Employee e1, e2, e3;
    
    cout << "=== Employee 1 ===" << endl;
    e1.getData();
    cout << "Salary after tax: " << e1.salaryAfterTax() << endl;
    e1.updateTax();
    
    cout << "\n=== Employee 2 ===" << endl;
    e2.getData();
    cout << "Salary after tax: " << e2.salaryAfterTax() << endl;
    e2.updateTax();
    
    cout << "\n=== Employee 3 ===" << endl;
    e3.getData();
    cout << "Salary after tax: " << e3.salaryAfterTax() << endl;
    e3.updateTax();
    
    return 0;
}
