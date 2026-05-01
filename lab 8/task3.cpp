#include<iostream>
using namespace std;

class ComplexNumber {
    float r, i;
public:
    ComplexNumber(float r = 0, float i = 0) { this->r = r; this->i = i; }

    ComplexNumber operator+(ComplexNumber c) {
        return ComplexNumber(r + c.r, i + c.i);
    }
    ComplexNumber operator-(ComplexNumber c) {
        return ComplexNumber(r - c.r, i - c.i);
    }
    ComplexNumber operator*(ComplexNumber c) {
        return ComplexNumber(r * c.r - i * c.i, r * c.i + i * c.r);
    }
    bool operator==(ComplexNumber c) {
        return r == c.r && i == c.i;
    }

    void print() {
        cout << r << " + " << i << "i" << endl;
    }
};

int main() {
    ComplexNumber a(3, 4), b(1, 2);
    ComplexNumber res = a + b;
    cout << "Addition: "; res.print();

    ComplexNumber c(8, 3), d(5, 6);
    res = c - d;
    cout << "Subtraction: "; res.print();

    ComplexNumber e(2, 3), f(1, 4);
    res = e * f;
    cout << "Multiplication: "; res.print();

    ComplexNumber g(3, 5), h(3, 5), k(4, 5);
    cout << "3+5i == 3+5i: " << (g == h ? "true" : "false") << endl;
    cout << "3+5i == 4+5i: " << (g == k ? "true" : "false") << endl;

    return 0;
}
