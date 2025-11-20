#include "Circle.h"
#include <cmath>        // pow, M_PI no garantizado → usamos 3.141592
#include <iostream>

// --- Constructores ---

Circle::Circle()
    : Shape(), center(0,0), radius(1) {}

Circle::Circle(std::string color, Point2D center, double radius)
    : Shape(color), center(center)
{
    if (radius <= 0)
        throw std::invalid_argument("Circle: radius must be positive");
    this->radius = radius;
}

// --- Getters ---

Point2D Circle::get_center() const {
    return center;
}

double Circle::get_radius() const {
    return radius;
}

// --- Setters ---

void Circle::set_center(Point2D p) {
    center = p;
}

void Circle::set_radius(double r) {
    if (r <= 0)
        throw std::invalid_argument("Circle::set_radius: radius must be positive");
    radius = r;
}

// --- Métodos virtuales heredados (override) ---

double Circle::area() const {
    return 3.141592 * radius * radius;     // πr²
}

double Circle::perimeter() const {
    return 2 * 3.141592 * radius;          // 2πr
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    std::cout << *this;     // reutilizamos operator<<
}

// --- Operador << global ---

std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "Circle(color=" << c.color
        << ", center=" << c.center
        << ", radius=" << c.radius
        << ")";
    return out;
}

