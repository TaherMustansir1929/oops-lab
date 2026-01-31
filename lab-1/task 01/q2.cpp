#include <iostream>
using namespace std;

int main() {
  int pf, oop, dld, ict, total;
  float avg;
  char grade;

  cout << "Enter marks for PF: ";
  cin >> pf;
  cout << "Enter marks for OOP: ";
  cin >> oop;
  cout << "Enter marks for DLD: ";
  cin >> dld;
  cout << "Enter marks for ICT: ";
  cin >> ict;

  total = pf + oop + dld + ict;
  avg = total / 4.0;

  if (avg >= 90) {
    grade = 'A';
  } else if (avg >= 80) {
    grade = 'B';
  } else if (avg >= 70) {
    grade = 'C';
  } else if (avg >= 60) {
    grade = 'D';
  } else {
    grade = 'F';
  }

  cout << "\nTotal Marks: " << total << endl;
  cout << "Average Marks: " << avg << endl;
  cout << "Grade: " << grade << endl;

  return 0;
}