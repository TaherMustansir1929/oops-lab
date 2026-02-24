#include<iostream>
using namespace std;

class Project {
public:
    string title;
    int duration;
};

class Employee {
public:
    string name;
    float salary;
    Project* proj;
    static float tax;

    static void changeTax(float t) { tax = t; }

    float calcNet() const { return salary - (salary * tax / 100); }

    void show() const {
        cout << name << " | Salary: " << salary
             << " | Net: " << calcNet()
             << " | Project: " << proj->title << " (" << proj->duration << " months)" << endl;
    }
};

float Employee::tax = 10.0;

int main() {
    Project p1 = {"WebApp", 6}, p2 = {"Mobile", 3}, p3 = {"AI", 12};

    Employee emps[3];
    emps[0] = {"Ali",  50000, &p1};
    emps[1] = {"Sara", 60000, &p2};
    emps[2] = {"John", 70000, &p3};

    Employee::changeTax(15);
    for (int i = 0; i < 3; i++) emps[i].show();
}
