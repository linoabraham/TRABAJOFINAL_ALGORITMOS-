#pragma once
#include <iostream>
#include "ListaDoblementeEnlazada.h"
#include <string>
#include "Fecha.h"
using namespace std;
class Persona {
protected:
    string nombre, apellido, dni, direccionCompleta;
    int edad;
    Fecha nacimiento;
public:
    Persona() {
        nombre = "";
        apellido = "";
        edad = 18;
        dni = "";
        nacimiento = Fecha();
        direccionCompleta = "";
    }
    string getPersonaDatosToString()
    {
        string total = "";
        total += "Nombre: " + nombre + "\n";
        total += "Apellido:  " + apellido + "\n";
        total += "Edad: " + std::to_string(edad) + "\n"; //la edad connvertida a cadena
        total += "DNI: " + dni + "\n";
        total += "Nacimiento: " + to_string(nacimiento.dia) + "/" + to_string(nacimiento.mes) + "/" + to_string(nacimiento.anio) + "\n";
        total += "Direccion: " + direccionCompleta + "\n";
        return total;
    }
    string getNombre()
    {
        return nombre;
    }
    int getEdad()
    {
        return edad;
    }
};

