#include <iostream>
using namespace std;

int main() {
  int cap = 5, count = 0, val;
  int *arr = new int[cap];

  cout << "Enter integers (enter -1 to stop):" << endl;

  while (true) {
    cin >> val;
    if (val == -1) {
      break;
    }

    if (count == cap) {
      cap = cap * 2;
      int *temp = new int[cap];
      for (int i = 0; i < count; i++) {
        temp[i] = arr[i];
      }
      delete[] arr;
      arr = temp;
      cout << "Array doubled! New capacity: " << cap << endl;
    }

    arr[count] = val;
    count++;
  }

  int *final = new int[count];
  for (int i = 0; i < count; i++) {
    final[i] = arr[i];
  }
  delete[] arr;

  cout << "\nFinal array with " << count << " elements:" << endl;
  for (int i = 0; i < count; i++) {
    cout << final[i] << " ";
  }
  cout << endl;

  delete[] final;

  return 0;
}