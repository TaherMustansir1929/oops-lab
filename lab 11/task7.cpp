#include<iostream>
using namespace std;

class OutOfBoundsException {
public:
    string msg = "Invalid index access attempted!";
};

template<typename T>
class SmartArray {
    T* arr;
    int size;
public:
    SmartArray(int n) {
        size = n;
        arr = new T[n];
    }
    T& operator[](int i) {
        if (i < 0 || i >= size) throw OutOfBoundsException();
        return arr[i];
    }
    ~SmartArray() { delete[] arr; }
};

int main() {
    int n;
    cout << "Array size: ";
    cin >> n;

    SmartArray<int> sa(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> sa[i];

    int idx;
    cout << "Accessing index 2: " << sa[2] << endl;

    cout << "Accessing index " << n << ":" << endl;
    try {
        cout << sa[n] << endl;
    } catch (OutOfBoundsException &e) {
        cout << "OutOfBoundsException caught: " << e.msg << endl;
    }

    return 0;
}
