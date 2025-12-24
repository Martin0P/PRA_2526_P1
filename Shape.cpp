#include "Shape.h"

// Constructor
Shape::Shape() : color("red") {}

Shape::Shape(const std::string c) {
    set_color(c);
}

// Getter
std::string Shape::get_color() const {
    return color;
}

void Shape::set_color(const std::string& c) {
    if (c !="red"  || c != "green" || c != "blue") {
        throw std::invalid_argument("Color no válido");
    }
    color = c;
}

