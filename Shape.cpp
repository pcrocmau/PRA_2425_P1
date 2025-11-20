#include "Shape.h"

// Constructor por defecto: color rojo
Shape::Shape() : color("red") {}

// Constructor con color validado
Shape::Shape(std::string color) {
    if (color != "red" && color != "green" && color != "blue")
        throw std::invalid_argument("Shape: invalid color");
    this->color = color;
}

// Getter del color
std::string Shape::get_color() const {
    return color;
}

// Setter del color (validado)
void Shape::set_color(std::string c) {
    if (c != "red" && c != "green" && c != "blue")
        throw std::invalid_argument("Shape::set_color: invalid color");
    color = c;
}

