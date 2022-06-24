#pragma once
#include <iostream>
#include "ListaDoblementeEnlazada.h"
#include <string>
#include "Fecha.h"
#include "Persona.h"
#include "Plato.h"
#include "Cliente.h"
#include "Motorizado.h"
using namespace std;
class Restaurante {
protected:
    string nombreRestaurante;
    int calificacionEstrellas;
    DoubleLinkedList<Plato> carta;
public:
    Restaurante() {
        nombreRestaurante = "";
        calificacionEstrellas = 0;
    }
    void imprimir() {
        cout << "Restaurante: " << nombreRestaurante << endl;
        cout << "Calificacion: " << calificacionEstrellas << endl;
        if (carta.Length() == 0)
            return;
        cout << "[CARTA]\n";
        for (int i = 0; i < carta.Length(); i++) {
            cout << "Plato: " << carta.at(i).nombrePlato << endl;
            cout << "Precio: " << carta.at(i).precio << endl;
        }
    }
    //FUNCIONES AMIGAS QUE PUEDEN ACCEDER AL CONTENIDO DE LA CLASE.
    friend void cargarRestaurante(DoubleLinkedList<Restaurante>& lista_restaurante, DoubleLinkedList<Plato> lista_platitos);
    friend Restaurante crearRestaurante(DoubleLinkedList<Plato> lista_platitos);
    friend void modificacionRestaurante(DoubleLinkedList<Restaurante>& lista, DoubleLinkedList<Plato>p);
    friend void crearPedido(DoubleLinkedList<Cliente>& LP, DoubleLinkedList<Motorizado>LM, DoubleLinkedList<Restaurante>RES);
};

