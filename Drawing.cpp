#include "Drawing.h"
#include <iostream>

Drawing::Drawing() {
    // Elige la implementación que quieras:
    shapes = new ListLinked<Shape*>();
    // shapes = new ListArray<Shape*>();  // si la tienes OK
}

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);     // tu List ya lo tiene
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);      // tu List ya lo tiene
}

void Drawing::print_all() const {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);
        s->print();
        std::cout << std::endl;
    }
}

double Drawing::get_area_all_circles() const {
    double total = 0.0;

    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);

        if (auto c = dynamic_cast<Circle*>(s)) {
            total += c->area();
        }
    }

    return total;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* s = shapes->get(i);

        if (auto sq = dynamic_cast<Square*>(s)) {
            sq->translate(incX, incY);
        }
    }
}
