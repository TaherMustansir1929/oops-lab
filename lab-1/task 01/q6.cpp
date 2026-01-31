#include <iostream>
using namespace std;

void printOddAfterEven(int s, int e) {
  int i, c = 0;

  for (i = s; i <= e; i++) {
    if (i % 2 == 0) {
      cout << i << " ";
      c++;

      if (c == 5) {
        i++;
        while (i <= e && i % 2 == 0) {
          i++;
        }
        if (i <= e) {
          cout << i << " ";
        }
        c = 0;
      }
    }
  }
  cout << endl;
}

int main() {
  int s, e;

  cout << "Enter start of range: ";
  cin >> s;
  cout << "Enter end of range: ";
  cin >> e;

  printOddAfterEven(s, e);

  return 0;
}