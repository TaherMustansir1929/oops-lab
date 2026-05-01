#include<iostream>
using namespace std;

template<typename T>
T findMax(T arr[], int size) {
    T mx = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

int main() {
    int nums[] = {10, 20, 5, 30, 25};
    cout << "Array: [10, 20, 5, 30, 25]" << endl;
    cout << "Maximum: " << findMax(nums, 5) << endl;

    string words[] = {"Apple", "Mango", "Banana", "Peach"};
    cout << "Array: [Apple, Mango, Banana, Peach]" << endl;
    cout << "Maximum: " << findMax(words, 4) << endl;

    return 0;
}
