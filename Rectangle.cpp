#include "Rectangle.h"
#include <cmath>        // std::fabs

// ---------- Método estático privado ----------

bool Rectangle::check(Point2D vertices[])
{
    // Lados: v0-v1, v1-v2, v2-v3, v3-v0
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    const double EPS = 1e-6;

    // No se permiten lados degenerados
    if (d01 <= EPS || d12 <= EPS || d23 <= EPS || d30 <= EPS)
        return false;

    // Rectángulo válido si lados opuestos tienen misma longitud
    return std::fabs(d01 - d23) < EPS && std::fabs(d12 - d30) < EPS;
}

// ---------- Constructores / destructor ----------

Rectangle::Rectangle()
    : Shape()
{
    vs = new Point2D[N_VERTICES];

    // Rectángulo unitario centrado en el origen
    vs[0] = Point2D(-0.5, -0.5);
    vs[1] = Point2D( 0.5, -0.5);
    vs[2] = Point2D( 0.5,  0.5);
    vs[3] = Point2D(-0.5,  0.5);
}

Rectangle::Rectangle(std::string color, Point2D vertices[])
    : Shape(color)
{
    if (!check(vertices))
        throw std::invalid_argument("Rectangle: invalid vertices");

    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = vertices[i];
}

Rectangle::Rectangle(const Rectangle &r)
    : Shape(r.color)     // copiamos el color de la figura base
{
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = r.vs[i];
}

Rectangle::~Rectangle()
{
    delete[] vs;
}

// ---------- Consultores ----------

Point2D Rectangle::get_vertex(int ind) const
{
    if (ind < 0 || ind >= N_VERTICES)
        throw std::out_of_range("Rectangle::get_vertex: index out of range");
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const
{
    return get_vertex(ind);
}

// ---------- Modificadores ----------

void Rectangle::set_vertices(Point2D vertices[])
{
    if (!check(vertices))
        throw std::invalid_argument("Rectangle::set_vertices: invalid vertices");

    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = vertices[i];
}

Rectangle& Rectangle::operator=(const Rectangle &r)
{
    if (this != &r) {
        // copiar parte base
        color = r.color;

        // copiar vértices
        for (int i = 0; i < N_VERTICES; ++i)
            vs[i] = r.vs[i];
    }
    return *this;
}

// ---------- Métodos heredados de Shape ----------

double Rectangle::area() const
{
    double d01 = Point2D::distance(vs[0], vs[1]);
    double d12 = Point2D::distance(vs[1], vs[2]);
    return d01 * d12;
}

double Rectangle::perimeter() const
{
    double d01 = Point2D::distance(vs[0], vs[1]);
    double d12 = Point2D::distance(vs[1], vs[2]);
    return 2 * (d01 + d12);
}

void Rectangle::translate(double incX, double incY)
{
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print()
{
    std::cout << *this;     // reutilizamos operator<<
}

// ---------- Operador << ----------

std::ostream& operator<<(std::ostream &out, const Rectangle &r)
{
    out << "Rectangle(color=" << r.color << ", vertices=[";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        out << r.vs[i];
        if (i + 1 < Rectangle::N_VERTICES)
            out << ", ";
    }
    out << "])";
    return out;
}

