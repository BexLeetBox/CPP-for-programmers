#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 f, T2 s) : first(f), second(s) {}

    Pair operator+(const Pair &other) {
        return Pair(this->first + other.first, this->second + other.second);
    }

    bool operator>(const Pair &other) {
        return (this->first + this->second) > (other.first + other.second);
    }
};

int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 is bigger" << endl;
    else
        cout << "p2 is bigger" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;
}
