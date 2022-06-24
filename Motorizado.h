#pragma once
#include <iostream>
#include "ListaDoblementeEnlazada.h"
#include <string>
#include "Persona.h"
#include "Plato.h"
using namespace std;
class Motorizado : public Persona {
protected:
    string cod_motorizado, nro_placa, marcaMoto;
public:
    string getDatosMotorizado() {
        string total = "";

        total += "Nombre: " + nombre + "\n";
        total += "Apellido:  " + apellido + "\n";
        total += "Edad: " + std::to_string(edad) + "\n";
        total += "DNI: " + dni + "\n";
        total += "Nacimiento: " + to_string(nacimiento.dia) + "/" + to_string(nacimiento.mes) + "/" + to_string(nacimiento.anio) + "\n";
        total += "Direccion: " + direccionCompleta + "\n";
        total += "Codigo de la Moto: " + cod_motorizado + "\n";
        total += "Numero de placa: " + nro_placa + "\n";
        total += "Marca de la moto: " + marcaMoto + "\n";
        return total;
    }
    Motorizado() : Persona() {}
    void imprimir()
    {
        cout << "Codigo de la Moto: " << cod_motorizado << endl;
        cout << "Numero de placa: " << nro_placa << endl;
        cout << "Marca de la moto: " << marcaMoto << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "DNI: " << dni << endl;
        cout << "Edad: " << edad << endl;
        cout << "Nacimiento: " << nacimiento.dia << "/" << nacimiento.mes << "/" << nacimiento.anio << endl;
        cout << "Direccion: " << direccionCompleta << endl;
    }
    friend void cargarMotorizado(DoubleLinkedList<Motorizado>&);
    friend Motorizado crearMotorizado();
    friend void modificacionMotorizado(DoubleLinkedList<Motorizado>&);
};

