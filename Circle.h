#ifndef CIRCLE_H
#define CIRCLE_H

#include <ostream>
#include "Shape.h"      // hereda de Shape, y ya incluye Point2D.h

class Circle : public Shape {
private:
    Point2D center;    // centro del círculo
    double radius;     // radio

public:
    // --- Constructores ---
    Circle();  // por defecto: color por defecto, centro (0,0), radio 1
    Circle(std::string color, Point2D center, double radius);

    // --- Getters ---
    Point2D get_center() const;
    double get_radius() const;

    // --- Setters ---
    void set_center(Point2D p);
    void set_radius(double r);

    // --- Métodos abstractos heredados de Shape ---
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() override;

    // --- Operador << global ---
    friend std::ostream& operator<<(std::ostream &out, const Circle &c);
};

#endif 

