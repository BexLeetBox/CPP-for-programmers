//
// Created by jerry on 10/16/2023.
//

#ifndef OVING_7_FRACTION_HPP
#define OVING_7_FRACTION_HPP


#pragma once

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction();
    Fraction(int numerator, int denominator);


    void set(int numerator_, int denominator_ = 1);
    Fraction operator+(const Fraction &other) const;
    Fraction operator-(const Fraction &other) const;
    Fraction operator*(const Fraction &other) const;
    Fraction operator/(const Fraction &other) const;
    Fraction operator-() const;
    Fraction operator-(int value) const;
    friend Fraction operator-(int value, const Fraction& fraction);


    Fraction &operator++(); // Preinkrement
    Fraction &operator--(); // Predekrement
    Fraction &operator+=(const Fraction &other);
    Fraction &operator-=(const Fraction &other);
    Fraction &operator*=(const Fraction &other);
    Fraction &operator/=(const Fraction &other);
    Fraction &operator=(const Fraction &other);
    bool operator==(const Fraction &other) const;
    bool operator!=(const Fraction &other) const;
    bool operator<=(const Fraction &other) const;
    bool operator>=(const Fraction &other) const;
    bool operator<(const Fraction &other) const;
    bool operator>(const Fraction &other) const;

private:
    void reduce();
    int compare(const Fraction &other) const;
};

#endif //OVING_7_FRACTION_HPP
