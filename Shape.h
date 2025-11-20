#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"

class Shape {
protected:
    std::string color;    // "red", "green" o "blue"

public:
    // Constructores (solo DECLARACIÓN)
    Shape();
    Shape(std::string color);

    virtual ~Shape() = default;

    // Métodos no virtuales (solo DECLARACIÓN)
    std::string get_color() const;
    void set_color(std::string c);

    // Métodos VIRTUALES PUROS
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() = 0;
};

#endif // SHAPE_H

