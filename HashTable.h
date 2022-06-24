#pragma once
#include "Libreria.h"
template<typename T1, typename T2>
class HashEntidad1 {
private:
	T1 key;
	T2 value;
public:
	HashEntidad1(T1 key, T2 value) : key(key), value(value) {}
	T1 getKey() { return key; }
	T2& getValue() { return value; }
};

template<typename T1, typename T2>
class HashTable1 {
	int capacidad;
	HashEntidad1<T1, T2>** ht;
public:
	HashTable1(int capacidad = 100)
	{
		this->capacidad = capacidad;
		ht = new HashEntidad1<T1, T2>*[capacidad];
		for (int i = 0; i < capacidad; ++i) {
			ht[i] = nullptr;
		}

	}
	// TRANFORMAR NOMBRE BINARIO PARA BUSCAR EN HASH TABLE
	long long Key_Name(string word) {
		long long key = 0;
		for (int i = 0; i < word.size(); i++) {
			key += int(word.at(i));
		}
		return key;
	}
	// GUARDAR EN HASH TABLE Y EN TXT
	void insertar(T1 key, T2 value)
	{
		ofstream Esc;
		int base, step, hash;
		base = Key_Name(key) % capacidad;
		hash = base;
		step = 0;
		while (ht[hash] != nullptr)
		{
			hash = (base + step) % capacidad;
		}
		ht[hash] = new HashEntidad1<T1, T2>(key, value);
		cout << ht[hash]->getValue();
		insertarUsuario(Esc, ht[hash]->getValue().GetNombre(), ht[hash]->getValue().GetApellido(), ht[hash]->getValue().GetMonto());
	}
	// BUSCAR EN EL HASH
	void buscarUsuario(string key) {
		int base, step, hash;
		base = Key_Name(key) % capacidad;
		hash = base;
		step = 0;

		while (ht[hash] != nullptr)
		{
			cout << base;
			hash = (base + step) % capacidad;
		}

		cout << hash;
		HashEntidad1<T1, T2>* elemento = ht[hash];
		cout << elemento->getValue();
	}


	// USUARIO REGISTRADO
	bool usuario_registrado(string nombre, string apellido) {
		ifstream leer("Personas.txt", ios::in);
		string nombreU, apellidoU;
		leer >> nombreU;
		while (!leer.eof()) {
			leer >> apellidoU;
			if (nombreU == nombre && apellidoU == apellido) {
				leer.close();
				cout << "SE REGISTRO CORRECTAMENTE" << endl;
				return false;
			}
			leer >> nombreU;
		}
		return true;
	}
	// REGISTRO DE USUARIO EN UN TXT
	void insertarUsuario(ofstream& es, string nombre, string apellido, int monto) {
		es.open("Personas.txt", ios::out | ios::app);
		if (usuario_registrado(nombre, apellido) == 1)
			es << nombre << " " << apellido << " " << monto << " " << endl;
		es.close();
	}
	// LECTURA DE USUARIOS DEL TXT
	void registro_usuarios(ifstream& lec) {
		system("cls");
		string nombre, apellido;
		string monto;
		lec.open("Personas.txt", ios::in);
		cout << endl;
		cout << endl;
		cout << "Usuarios Insertados en HASH TABLE";
		cout << endl;
				//lec >> nombre;
		while (!lec.eof()) {
			lec >> nombre;
			lec >> apellido;
			lec >> monto;
			cout << "Nombre----------->" << nombre << endl;
			cout << "Apellido--------->" << apellido << endl;
			cout << "Monto a pagar: -->" << monto << endl;
			lec >> nombre;
			lec >> apellido;
			lec >> monto;
			cout << endl;

		}
		lec.close();
	}
	void imprimirUsuarios()
	{
		ifstream Lec;
		registro_usuarios(Lec);

	}

	void Transaccion(int modificacion) {
		int monto;
		char v;
		cout << "Desea hacer una transaccion: (s/n) ";
		cin >> v;
		if (v == 's') {
			monto = ht->getValue().GetMonto();
			monto -= modificacion;
			cout << ht->getValue().SetMonto();
		}
	}
};
