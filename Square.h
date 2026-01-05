#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <ostream>
#include "Rectangle.h"
#include "Point2D.h"

class Square : public Rectangle {
private:
    static bool check(Point2D* vertices);

public:
    Square();
    Square(std::string color, Point2D* vertices);

    void set_vertices(Point2D* vertices) override;
    void print() const override;

    friend std::ostream& operator<<(std::ostream& out, const Square& square);
};

#endif

