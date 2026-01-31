#include <iostream>
using namespace std;

int main() {
  int n, i, e = 0, o = 0;

  cout << "Enter the size of array: ";
  cin >> n;

  int arr[n];

  cout << "Enter " << n << " numbers:" << endl;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      e++;
    } else {
      o++;
    }
  }

  cout << "\nEven numbers count: " << e << endl;
  cout << "Odd numbers count: " << o << endl;

  return 0;
}