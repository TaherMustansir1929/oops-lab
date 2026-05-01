#include<iostream>
using namespace std;

class TrafficSystem {
    int n;
public:
    TrafficSystem(int n) { this->n = n; }

    TrafficSystem operator+(TrafficSystem t) { return TrafficSystem(n + t.n); }
    TrafficSystem operator-(TrafficSystem t) { return TrafficSystem(n - t.n); }
    TrafficSystem operator*(TrafficSystem t) { return TrafficSystem(n * t.n); }
    bool operator==(TrafficSystem t) { return n == t.n; }

    void print() { cout << n << endl; }
};

int main() {
    TrafficSystem a(50), b(20);
    TrafficSystem res = a + b;
    cout << "Addition: "; res.print();

    TrafficSystem c(70), d(15);
    res = c - d;
    cout << "Subtraction: "; res.print();

    TrafficSystem e(5), f(2);
    res = e * f;
    cout << "Multiplication: "; res.print();

    TrafficSystem g(100), h(100), k(80);
    cout << "100 == 100: " << (g == h ? "true" : "false") << endl;
    cout << "100 == 80: " << (g == k ? "true" : "false") << endl;

    return 0;
}
