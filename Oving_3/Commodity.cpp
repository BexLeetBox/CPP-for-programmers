#include "commodity.hpp"

Commodity::Commodity(std::string name_, int id_, double price_)
    : name(name_), id(id_), price(price_) {}

std::string Commodity::get_name() const {
    return name;
}

int Commodity::get_id() const {
    return id;
}

double Commodity::get_price() const {
    return price;
}

double Commodity::get_price(double quantity) const {
    return price * quantity;
}

int Commodity::set_price(double new_price) {
    price = new_price;
    return price;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
    return get_price(quantity) * (1 + SALES_TAX);
}
