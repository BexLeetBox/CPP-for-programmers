#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec);

int main() {
    // 1. Create a vector of double
    std::vector<double> v = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Vector: " << v << std::endl;

    // 2. Use the front() and back() member functions
    std::cout << "Front of vector: " << v.front() << std::endl;
    std::cout << "Back of vector: " << v.back() << std::endl;

    // 3. Use emplace() to insert a value after the first element
    v.emplace(v.begin() + 1, 9.9);
    std::cout << "Vector after emplace: " << v << std::endl;
    // Display the result of front() after the emplace()
    std::cout << "Front of vector after emplace: " << v.front() << std::endl;

    // 4. Try out the STL find() algorithm
    double searchValue = 9.9;
    auto it = std::find(v.begin(), v.end(), searchValue);

    // Check if the result of find() was successful
    if(it != v.end()) {
        std::cout << "Value " << *it << " found in the vector!" << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the vector." << std::endl;
    }

    return 0;
}


//Template used for printing vectors
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

