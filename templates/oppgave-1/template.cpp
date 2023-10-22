#include <iostream>
#include <iomanip>
#include <cmath>

// Function template for generic types
template <typename Type>

bool equal(Type a, Type b) {
    std::cout << "Using generic template version." << std::endl;
    return a == b;
}

// Specialization for double
bool equal(double a, double b) {
    std::cout << "Using specialized double version." << std::endl;
    return std::fabs(a - b) < 0.00001;
}

int main() {
    int x = 5, y = 5;
    double d1 = 0.12345678, d2 = 0.12345677, d3 = 0.1234;

    // Uses the generic template for int
    std::cout << "Are " << x << " and " << y << " equal? " << (equal(x, y) ? "Yes" : "No") << std::endl;

    // Uses the specialized double version
    std::cout << std::setprecision(10) << "Are " << d1 << " and " << d2 << " equal? " << (equal(d1, d2) ? "Yes" : "No") << std::endl;

    // Uses the specialized double version
    std::cout << std::setprecision(10) << "Are " << d1 << " and " << d3 << " equal? " << (equal(d1, d3) ? "Yes" : "No") << std::endl;

    return 0;
}
