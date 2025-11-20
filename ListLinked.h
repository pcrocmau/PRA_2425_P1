#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first;   // primer nodo de la lista
    int n;            // número de elementos

    // Devuelve el puntero al nodo en posición pos
    Node<T>* getNode(int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("getNode: posición inválida");

        Node<T>* curr = first;
        for (int i = 0; i < pos; ++i)
            curr = curr->next;

        return curr;
    }

public:
    // Constructor: lista vacía
    ListLinked() : first(nullptr), n(0) {}

    // Destructor: libera todos los nodos (algoritmo de las diapositivas)
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;  // 1. aux apunta al siguiente
            delete first;       // 2. liberar el nodo actual
            first = aux;        // 3. avanzar first
        }
        n = 0;
    }

    // ----- Implementación de los métodos de List<T> -----

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("insert: posición inválida");

        if (pos == 0) {
            // insertar al principio
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = getNode(pos - 1);
            prev->next = new Node<T>(e, prev->next);
        }
        ++n;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("remove: posición inválida");

        Node<T>* target;
        if (pos == 0) {
            target = first;
            first = first->next;
        } else {
            Node<T>* prev = getNode(pos - 1);
            target = prev->next;
            prev->next = target->next;
        }

        T value = target->data;
        delete target;
        --n;
        return value;
    }

    T get(int pos) const override {
        return getNode(pos)->data;
    }

    int search(T e) const override {
        Node<T>* curr = first;
        int i = 0;
        while (curr != nullptr) {
            if (curr->data == e)
                return i;
            curr = curr->next;
            ++i;
        }
        return -1;
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

    // ----- Operadores extra de la práctica -----

    // operator[] con comprobación de rango
    T operator[](int pos) const {
        return get(pos);
    }

    // Operador << para imprimir la lista enlazada
    friend std::ostream& operator<<(std::ostream& out,
                                    const ListLinked<T>& list) {
        out << "[";
        Node<T>* curr = list.first;
        while (curr != nullptr) {
            out << curr->data;
            if (curr->next != nullptr)
                out << ", ";
            curr = curr->next;
        }
        out << "]";
        return out;
    }
};

#endif // LISTLINKED_H

