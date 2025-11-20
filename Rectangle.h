#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    Point2D* vs;                       // array dinámico de 4 vértices

public:
    static int const N_VERTICES = 4;   // constante pública

private:
    // Comprueba si los 4 puntos forman un rectángulo válido
    static bool check(Point2D vertices[]);

public:
    // --- Constructores ---
    Rectangle();                                              // por defecto
    Rectangle(std::string color, Point2D vertices[]);         // con parámetros
    Rectangle(const Rectangle &r);                            // copia

    // --- Destructor ---
    ~Rectangle();

    // --- Consultores ---
    Point2D get_vertex(int ind) const;
    Point2D operator[](int ind) const;  // acceso tipo array

    // --- Modificadores ---
    virtual void set_vertices(Point2D vertices[]);            // VIRTUAL (lo sobrescribe Square)
    Rectangle& operator=(const Rectangle &r);                 // asignación

    // --- Métodos abstractos heredados ---
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    virtual void print() override;       // VIRTUAL (lo sobrescribe Square)

    // --- Operador de impresión ---
    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};

#endif 

