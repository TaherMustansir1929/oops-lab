#include <iostream>
using namespace std;

int factorial(int n) {
  int f = 1, i;

  for (i = 1; i <= n; i++) {
    f = f * i;
  }

  return f;
}

int main() {
  int n, r;

  cout << "Enter a number: ";
  cin >> n;

  r = factorial(n);

  cout << "Factorial of " << n << " is: " << r << endl;

  return 0;
}