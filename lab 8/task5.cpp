#include<iostream>
using namespace std;

class Student {
    string name;
    float g[3];
public:
    Student(string n, float g1, float g2, float g3) {
        name = n;
        g[0] = g1; g[1] = g2; g[2] = g3;
    }
    void display() {
        cout << "Student: " << name << endl;
        cout << "Grades: " << g[0] << ", " << g[1] << ", " << g[2] << endl;
    }
    friend class Teacher;
    friend float calculateAverageGrade(Student);
};

class Teacher {
public:
    void updateGrade(Student &s, int idx, float val) {
        s.g[idx] = val;
    }
};

float calculateAverageGrade(Student s) {
    return (s.g[0] + s.g[1] + s.g[2]) / 3;
}

int main() {
    Student s("Ali", 70, 85, 90);
    s.display();

    Teacher t;
    t.updateGrade(s, 1, 95);
    cout << "\nAfter grade update:" << endl;
    s.display();

    cout << "Average: " << calculateAverageGrade(s) << endl;
    return 0;
}
