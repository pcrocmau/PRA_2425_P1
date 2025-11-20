#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
public:
    T data;          // elemento almacenado
    Node<T>* next;   // puntero al siguiente nodo (o nullptr)

    // Constructor: next será nullptr si no se indica
    Node(T data, Node<T>* next = nullptr)
        : data(data), next(next) {}

    // Operador << global para imprimir el nodo 
    friend std::ostream& operator<<(std::ostream& out,
                                    const Node<T>& node) {
        out << node.data;
        return out;
    }
};

#endif // NODE_H

