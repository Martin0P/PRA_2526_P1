#include "Rectangle.h"

static constexpr double EPS = 1e-9;

bool Rectangle::check(Point2D* vertices) {
    if (vertices == nullptr) return false;

    double a = Point2D::distance(vertices[0], vertices[1]);
    double b = Point2D::distance(vertices[2], vertices[3]);
    double c = Point2D::distance(vertices[1], vertices[2]);
    double d = Point2D::distance(vertices[3], vertices[0]);

    return (std::abs(a - b) < EPS) && (std::abs(c - d) < EPS);
}

Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1,  0.5);
    vs[1] = Point2D( 1,  0.5);
    vs[2] = Point2D( 1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
    }

    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle& r) : Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Index out of range");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this == &r) return *this;

    color = r.color;

    delete[] vs;
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
    return *this;
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

double Rectangle::area() const {
    double base = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return base * height;
}

double Rectangle::perimeter() const {
    double base = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return 2.0 * (base + height);
}

void Rectangle::print() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    out << "[Rectangle: color = " << r.color
        << "; v0 = " << r.vs[0]
        << "; v1 = " << r.vs[1]
        << "; v2 = " << r.vs[2]
        << "; v3 = " << r.vs[3]
        << "]";
    return out;
}



