#include<iostream>
using namespace std;

template<typename T>
void swapValues(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    float x = 3.5, y = 7.8;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    char ch1 = 'A', ch2 = 'Z';
    cout << "Before swap: ch1 = '" << ch1 << "', ch2 = '" << ch2 << "'" << endl;
    swapValues(ch1, ch2);
    cout << "After swap: ch1 = '" << ch1 << "', ch2 = '" << ch2 << "'" << endl;

    return 0;
}
