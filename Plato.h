#pragma once
#include <iostream>
#include "ListaDoblementeEnlazada.h"
#include <string>
using namespace std;
class Plato {
protected:
    string nombrePlato;
    float precio;
public:
    friend void cargarPlato(DoubleLinkedList<Plato>& lista_platos); //clase amiga: Lista
    friend class Restaurante;
    Plato() {
        nombrePlato = "";
        precio = 0;
    }
    void imprimirPlato() {
        cout << "Plato: " << nombrePlato << endl;
        cout << "Precio: " << precio << endl;
    }
    string devolverPlatoString() {
        string total = "";

        total += "Plato: " + nombrePlato + "\n";
        total += "Precio: " + to_string(precio);
        return total;
    }
};

