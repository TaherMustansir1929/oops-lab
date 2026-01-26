#include <iostream>
using namespace std;

int main() {
  int n, i;
  bool p = true;

  cout << "Enter a number: ";
  cin >> n;

  if (n <= 1) {
    p = false;
  }

  for (i = 2; i < n; i++) {
    if (n % i == 0) {
      p = false;
      break;
    }
  }

  if (p) {
    cout << n << " is a prime number" << endl;
  } else {
    cout << n << " is not a prime number" << endl;
  }

  return 0;
}