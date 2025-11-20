#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

class Point2D {
public:
    double x;   // coordenada x
    double y;   // coordenada y

    // ctor: por defecto (0,0)
    Point2D(double x = 0, double y = 0);

    // distancia euclídea entre dos puntos
    static double distance(const Point2D &a, const Point2D &b);
};

// operadores binarios globales
bool operator==(const Point2D &a, const Point2D &b);
bool operator!=(const Point2D &a, const Point2D &b);

// operador << global
std::ostream& operator<<(std::ostream &out, const Point2D &p);

#endif 

