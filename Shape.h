#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

class Shape {
    protected:
        std::string color;


    public:
        // Constructores
        Shape();
        Shape(const std::string color);

        // Getter
        std::string get_color() const;

        // Setter: lanza std::invalid_argument
        void set_color(const std::string &c);

        // Métodos virtuales
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual void translate(double incX, double incY) = 0;
        virtual void print() const = 0;

        // Destructor 
        virtual ~Shape() = default;
};

#endif
