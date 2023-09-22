#ifndef COMMODITY_HPP  // Include guard to prevent double inclusion
#define COMMODITY_HPP

#include <string>

const double SALES_TAX = 0.25;  // Assuming a 25% sales tax for simplicity.

class Commodity {
public:
    Commodity(std::string name_, int id_, double price_);
    
    std::string get_name() const;
    int get_id() const;
    double get_price() const;
    double get_price(double quantity) const;
    int set_price(double new_price);
    double get_price_with_sales_tax(double quantity) const;

private:
    std::string name;
    int id;
    double price;
};

#endif  // COMMODITY_HPP
