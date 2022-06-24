#pragma once
#include <iostream>
#include "ListaDoblementeEnlazada.h"
#include <string>
#include "Persona.h"
#include "Plato.h"
using namespace std;
class Cliente : public Persona {
public:
    DoubleLinkedList<Plato> pedidos;

    Cliente() : Persona() {}
    void imprimir()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "DNI: " << dni << endl;
        cout << "Edad: " << edad << endl;
        cout << "Nacimiento: " << nacimiento.dia << "/" << nacimiento.mes << "/" << nacimiento.anio << endl;
        cout << "Direccion : " << direccionCompleta;

        if (pedidos.Length() == 0)
            return;
        cout << "\n[PEDIDOS DE ESTE CLIENTE]\n";
        for (int i = 0; i < pedidos.Length(); i++)
            pedidos.at(i).imprimirPlato();
    }
    friend void cargarPersona(DoubleLinkedList<Cliente>&);
    friend Cliente crearCliente();
    friend void modificacionCliente(DoubleLinkedList<Cliente>&);
    friend void ordenarClienteAZ(DoubleLinkedList<Cliente>&);
    friend void ordenarClienteZA(DoubleLinkedList<Cliente>&);
    friend void ordenarClienteMenorMayor(DoubleLinkedList<Cliente>&);
    friend void ordenarClienteMayorMenor(DoubleLinkedList<Cliente>&);
};

class Usuario1
{
    string nombre, apellido;
    int monto;

public:
    Usuario1(string nombre = "", string apellido = "", int monto = 0) :nombre(nombre), apellido(apellido), monto(monto) {}

    friend ostream& operator << (ostream& s, const Usuario1& u) {
        s << u.nombre << " " << u.apellido << " " << u.monto << endl;
        return s;
    }
    bool operator<(const Usuario1& u) {
        return this->monto < u.monto;
    }
    bool operator>=(const Usuario1& u) {
        return this->monto >= u.monto;
    }
    bool operator>(const Usuario1& u) {
        return this->monto > u.monto;
    }
    bool operator==(const Usuario1& u) {
        return this->monto == u.monto;
    }

    string GetNombre() { return nombre; }
    string GetApellido() { return apellido; }
    int GetMonto() { return monto; }

    string SetNombre(string nombre) { return this->nombre = nombre; }
    string SetApellido(string apellido) { return this->apellido = apellido; }
    int SetMonto(int monto) { return this->monto = monto; }

};

