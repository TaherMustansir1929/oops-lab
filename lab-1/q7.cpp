#include <iostream>
using namespace std;

int main() {
  int u;
  float b = 0, total;

  cout << "Enter electricity units consumed: ";
  cin >> u;

  if (u <= 50) {
    b = u * 0.50;
  } else if (u <= 150) {
    b = 50 * 0.50;
    b = b + (u - 50) * 0.75;
  } else if (u <= 250) {
    b = 50 * 0.50;
    b = b + 100 * 0.75;
    b = b + (u - 150) * 1.20;
  } else {
    b = 50 * 0.50;
    b = b + 100 * 0.75;
    b = b + 100 * 1.20;
    b = b + (u - 250) * 1.50;
  }

  total = b + (b * 0.20);

  cout << "\nBase Bill: Rs. " << b << endl;
  cout << "Surcharge (20%): Rs. " << b * 0.20 << endl;
  cout << "Total Bill: Rs. " << total << endl;

  return 0;
}