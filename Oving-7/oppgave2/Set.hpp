//
// Created by jerry on 10/17/2023.
//

#ifndef OPPGAVE2_SET_H
#define OPPGAVE2_SET_H


#include <vector>
#include <iostream>

class Set {
private:
    std::vector<int> data;

public:
    // Constructor to create an empty set
    Set();

    // Overloaded operators
    Set operator+(const Set& other) const; // Union of two sets
    Set& operator+=(int value);            // Add a new value to the set
    Set& operator=(const Set& other);      // Assign one set to another
    friend std::ostream& operator<<(std::ostream& os, const Set& set);


    // Function to print the set
    void print() const;
};



#endif //OPPGAVE2_SET_H
