#include "Set.hpp"

int main() {
    Set set1;
    set1 += 1;
    set1 += 1;
    set1 += 4;
    set1 += 3;

    Set set2;
    set2 += 4;
    set2 += 4;
    set2 += 7;

    Set unionSet = set1 + set2;

    std::cout << "Set 1: " << set1 << std::endl;
    std::cout << "Set 2: " << set2 << std::endl;
    std::cout << "Union of Set 1 and Set 2: " << unionSet << std::endl;

    set1 = set2;
    std::cout << "Setting Set 1 to equal Set 2: " << set1 << std::endl;

    return 0;
}
