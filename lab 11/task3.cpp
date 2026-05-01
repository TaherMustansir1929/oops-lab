#include<iostream>
using namespace std;

template<typename A, typename B>
class Pair {
    A first;
    B second;
public:
    Pair(A a, B b) { first = a; second = b; }
    void display() {
        cout << "Pair: (" << first << ", " << second << ")" << endl;
    }
};

int main() {
    Pair<int, string> p1(5, "Hello");
    p1.display();

    Pair<double, int> p2(3.14, 42);
    p2.display();

    return 0;
}
