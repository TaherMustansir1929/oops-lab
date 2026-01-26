#include <iostream>
using namespace std;

int *allocateArray(int n) {
  int *arr = new int[n];
  return arr;
}

int main() {
  int n, i;

  cout << "Enter number of elements: ";
  cin >> n;

  int *arr = allocateArray(n);

  cout << "Enter " << n << " elements:" << endl;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "\nArray elements:" << endl;
  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  delete[] arr;

  return 0;
}