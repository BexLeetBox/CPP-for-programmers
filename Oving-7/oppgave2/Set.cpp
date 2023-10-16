#include "Set.hpp"
#include <algorithm>

Set::Set() {}

Set Set::operator+(const Set& other) const {
    Set result = *this;
    for (int value : other.data) {
        result += value;
    }
    return result;
}

Set& Set::operator+=(int value) {
    if (std::find(data.begin(), data.end(), value) == data.end()) {
        data.push_back(value);
    }
    return *this;
}

Set& Set::operator=(const Set& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Set& set) {
    os << "{ ";
    for (size_t i = 0; i < set.data.size(); ++i) {
        os << set.data[i];
        if (i != set.data.size() - 1) {
            os << ", ";
        }
    }
    os << " }";
    return os;
}


void Set::print() const {
    std::cout << "{ ";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i != data.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}
