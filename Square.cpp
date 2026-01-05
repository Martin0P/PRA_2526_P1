#include "Square.h"
#include <iostream>
#include <cmath>

static constexpr double EPS = 1e-9;

bool Square::check(Point2D* vertices) {
    if (vertices == nullptr) return false;

    double a = Point2D::distance(vertices[0], vertices[1]);
    double b = Point2D::distance(vertices[1], vertices[2]);
    double c = Point2D::distance(vertices[2], vertices[3]);
    double d = Point2D::distance(vertices[3], vertices[0]);

    return (std::abs(a - b) < EPS) && (std::abs(b - c) < EPS) && (std::abs(c - d) < EPS);
}

Square::Square() : Rectangle() {
    // Sobrescribe los vértices 
    Point2D tmp[N_VERTICES] = {Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)};
    set_vertices(tmp);
}

Square::Square(std::string color, Point2D* vertices) : Rectangle() {
    set_color(color);       
    set_vertices(vertices); 
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }

    // Guarda los vértices en el array
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

void Square::print() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& out, const Square& square) {
    out << "[Square: color = " << square.color << "; v0 = " << square.vs[0] << "; v1 = " << square.vs[1] << "; v2 = " << square.vs[2] << "; v3 = " << square.vs[3] << "]";
    return out;
}
