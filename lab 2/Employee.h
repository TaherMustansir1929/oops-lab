#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;
    double tax;

public:
    void getData();
    double salaryAfterTax();
    void updateTax();
};

#endif
