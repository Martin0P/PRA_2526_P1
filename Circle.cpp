#include "Circle.h"
#include <iostream>
#include <cmath>

static constexpr double PI = 3.141592;

Circle::Circle() : Shape(), center(0, 0), radius(1) {}
Circle::Circle(const std::string &color, const Point2D &center, double radius): Shape(color), center(center), radius(1){
    set_radius(radius);
}

// Get de las variables
Point2D Circle::get_center() const{
    return center;
}
double Circle::get_radius() const{
    return radius;
}
double Circle::area() const {
    return PI * std::pow(radius, 2.0);
}
double Circle::perimeter() const {
    return 2.0 * PI * radius;
}

// Set de las variables
void Circle::set_center(const Point2D& p){
    center = p;
}
void Circle::set_radius(double r){
    if(r <= 0){
      throw std::invalid_argument("Radio invalido menor a 0");
    }
    radius = r;
}
void Circle::translate(double incX, double incY){
    center.x += incX;
    center.y += incY;
}

void Circle::print() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
    out << "[Circle: color = " << c.color << "; center = " << c.center << "; radius = " << c.radius << "]";
    return out;
}

