#include <iostream>
using namespace std;

void add(int *a, int *b, int *r) { *r = *a + *b; }

void subtract(int *a, int *b, int *r) { *r = *a - *b; }

void multiply(int *a, int *b, int *r) { *r = *a * *b; }

void divide(int *a, int *b, int *r) {
  if (*b != 0) {
    *r = *a / *b;
  } else {
    cout << "Error: Division by zero" << endl;
    *r = 0;
  }
}

int main() {
  int a, b, r;
  char op;

  cout << "Enter first number: ";
  cin >> a;
  cout << "Enter operator (+, -, *, /): ";
  cin >> op;
  cout << "Enter second number: ";
  cin >> b;

  int *p1 = &a;
  int *p2 = &b;
  int *p3 = &r;

  if (op == '+') {
    add(p1, p2, p3);
    cout << "Result: " << *p3 << endl;
  } else if (op == '-') {
    subtract(p1, p2, p3);
    cout << "Result: " << *p3 << endl;
  } else if (op == '*') {
    multiply(p1, p2, p3);
    cout << "Result: " << *p3 << endl;
  } else if (op == '/') {
    divide(p1, p2, p3);
    if (b != 0) {
      cout << "Result: " << *p3 << endl;
    }
  } else {
    cout << "Invalid operator" << endl;
  }

  return 0;
}