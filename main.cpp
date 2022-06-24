#include <iostream>//LIBRERIAS A USAR 
#include <stdlib.h>//DE MEMORIA DINAMICA
#include <string>//DE STRINGS Y GETLINE
#include <stdio.h>// DE PRINTF
#include <algorithm>//PARA LAMBDAS Y MAS
#include <fstream>//PARA ESCRIBIR ARCHIVOS
#include <sstream>//PARA LEER ARCHIVOS
#include <Windows.h>//PARA LA CONSOLA
#include "ListaDoblementeEnlazada.h"//NUESTRA LISTA DOBLEMENTE ENLAZADA
#include "Fecha.h"
#include "Plato.h"
#include "Persona.h"
//#include "Persona.cpp"
#include "Cliente.h"
#include "Motorizado.h"
#include "Restaurante.h"
#include "HashTable.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;

int generarAleatorio(int M, int N) {
    int tam = rand() % (N - M + 1) + M;
    return tam;
}
void cargarMotorizado(DoubleLinkedList<Motorizado>& lista_motorizado)
{
    fstream archivo_clientes("motorizados.txt", ios::in);

    while (!archivo_clientes.eof()) {
        string str;
        getline(archivo_clientes, str);

        if (str.empty())
            continue;

        stringstream abc(str);
        string token;
        DoubleLinkedList<string> separador;
        while (getline(abc, token, ',')) {
            separador.agregar(token);
        }
        Motorizado auxiliar;
        auxiliar.nombre = separador.at(0);
        auxiliar.apellido = separador.at(1);
        auxiliar.edad = stoi(separador.at(2));
        auxiliar.dni = separador.at(3);
        auxiliar.nacimiento.dia = stoi(separador.at(4));
        auxiliar.nacimiento.mes = stoi(separador.at(5));
        auxiliar.nacimiento.anio = stoi(separador.at(6));
        auxiliar.direccionCompleta = separador.at(7);
        auxiliar.cod_motorizado = separador.at(8);
        auxiliar.nro_placa = separador.at(9);
        auxiliar.marcaMoto = separador.at(10);

        lista_motorizado.agregar(auxiliar);
    }
    archivo_clientes.close();
}
//IGUAL EL PLATO
void cargarPlato(DoubleLinkedList<Plato>& lista_platos)
{
    fstream platos("platos.txt", ios::in); //abre el archivo para leerlo
    while (!platos.eof()) //mientras no sea el fin del archivo...
    {
        string str;
        getline(platos, str);

        if (str.empty())
            continue;

        stringstream ss(str);
        string token;

        DoubleLinkedList<string> separador;
        while (getline(ss, token, ',')) 
            separador.agregar(token);
        
        Plato auxiliar;
        auxiliar.nombrePlato = separador.at(0);
        auxiliar.precio = stof(separador.at(1));

        lista_platos.agregar(auxiliar);
    }
    platos.close(); //cerrar el archivo
}
//Y EL RESTAURANTE
void cargarRestaurante(DoubleLinkedList<Restaurante>& lista_restaurante, DoubleLinkedList<Plato> lista_platitos) {
    fstream archivo("restaurantes.txt", ios::in);

    while (!archivo.eof())
    {
        string str;
        getline(archivo, str);
        if (str.empty())
            continue;

        stringstream ss(str);
        string token;
        DoubleLinkedList<string> separador;
        while (getline(ss, token, ',')) {
            separador.agregar(token);
        }
        Restaurante aux;
        aux.nombreRestaurante = separador.at(0);
        aux.calificacionEstrellas = stoi(separador.at(1));

        for (int i = 0; i < 3; i++) {
            aux.carta.agregar(lista_platitos.at(generarAleatorio(0, lista_platitos.Length() - 1)));
        }
        lista_restaurante.agregar(aux);
    }
    archivo.close();
}
//MENU PRINCIPAL


void menu()
{
    printf("\n\n\t  __  __                ___     _         _            _");
    printf("\n\t |  \\/  |___ _ _ _  _  | _ \\_ _(_)_ _  __(_)_ __  __ _| |");
    printf("\n\t | |\\/| / -_) ' \\ || | |  _/ '_| | ' \\/ _| | '_ \\/ _` | |");
    printf("\n\t |_|  |_\\___|_||_\\_,_| |_| |_| |_|_||_\\__|_| .__/\\__,_|_|");
    printf("\n\t                                           |_|           ");
    printf("\n");
    printf("[1]. Opciones Clientes\n");
    printf("[2]. Opciones Motorizado\n");
    printf("[3]. Opciones Restaurante\n");
    printf("[4]. Realizar Pedido\n");
    printf("[5]. Salir\n\n[?]. Ingresa opc : ");
}

//----------------------------------CLIENTES--------------------------------------
//MENU DE CLIENTES
void clientesMenu()
{
    cout << "\n\t\t[ OPCIONES DE CLIENTES ]\n\n";
    cout << "[1]. Agregar Nuevo Cliente\n";
    cout << "[2]. Listar Todos Los Clientes\n";
    cout << "[3]. Modificar Cliente\n";
    cout << "[4]. Ordenar Nombre de Clientes (A-Z)\n";
    cout << "[5]. Ordenar Nombre de Clientes (Z-A)\n";
    cout << "[6]. Ordenar Edades de Clientes (Menor a Mayor)\n";
    cout << "[7]. Imprimir Hash Table\n";
    cout<<  "[8]. Agregar Clientes a Hash Table\n";
    cout << "[9]. Regresar\n\n[?]. Ingresa opc : ";
}
//FUNCION PARA CREAR UN CLIENTE
Cliente crearCliente()
{
    auto nuevo_lambda_gendni = []() -> string { 
        string DNI = "";
        string diccionario = "1029384756";
        for (int i = 0; i < 8; i++){
            DNI.push_back(diccionario[generarAleatorio(0, diccionario.length() - 1)]); 
        }//añadir un nuevo dato aleatorio del diccionario miestras este disminuye para no repetir
        return DNI;
    };

    cin.ignore();
    cout << "\n\t[ CREACION DE CLIENTE ]\n\n";
    Cliente nuevo;
    cout << "Nombre:  ";
    fflush(stdin);
    getline(cin, nuevo.nombre);

    cout << "Apellido:  ";
    fflush(stdin);
    getline(cin, nuevo.apellido);

    cout << "Dni:  ";
    cin >> nuevo.dni;

    nuevo.dni = nuevo_lambda_gendni();

    cout << "Nacimiento [ dia mes anio ] :  ";
    cin >> nuevo.nacimiento.dia >> nuevo.nacimiento.mes >> nuevo.nacimiento.anio;

    cin.ignore();
    cout << "Direccion  :  ";

    fflush(stdin);
    getline(cin, nuevo.direccionCompleta);

    return nuevo;
}
//FUNCION PARA IMPRIMIR UN CLIENTE
void imprimirCliente(DoubleLinkedList<Cliente> lista)
{
    if (lista.Length() == 0) cout << "\n\n\t\b[ LISTA SE ENCUENTRA VACIA ]\n\n";
    else {
        cout << "\n\t\b[ LISTADO DE CLIENTE ]\n\n";
        for (int i = 0; i < lista.Length(); i++){
            lista.at(i).imprimir();
            cout << endl;
        }
    }
}
//FUNCION PARA MODIFICAR UN CLIENTE
void modificacionCliente(DoubleLinkedList<Cliente>& lista)
{
    if (lista.Length() == 0)  cout << "\n\n\t\b[ LISTA SE ENCUENTRA VACIA ]\n\n"; 
    else {
        cin.ignore();
        string str;
        cout << "\n\t\b[ MODIFICACION DE CLIENTE ]\n\n";
        cout << "Ingresa DNI de Cliente a modificar : ";
        fflush(stdin); //limpiar buffer para evitar espacios o caracteres no deseados
        getline(cin, str);
        bool modificado = false;
        for (int i = 0; i < lista.Length(); i++)
        {
            if (str.compare(lista.at(i).dni) == 0)
            {
                cout << "\nCLIENTE ENCONTRADO\n";
                lista.at(i).imprimir(); //entra a la lista, identifica la linea del indice y la imprime

                cout << "\nMODIFICANDO\n..Presiona Enter..";
                Cliente aux = crearCliente(); //se crea un cliente como auxiliar

                aux.pedidos = lista.at(i).pedidos; 

                lista.modify_by_index(i, aux); //se modifica la linea del indice indicado y se reemplaza por el auxiliar creado
                cout << "\n\t[ MODIFICADO ]\n\n";
                modificado = true;
                break;
            }
        }
        if (!modificado)  cout << "\n\t[ NO ENCONTRADO ]\n\n"; 
    }
}
void ordenarClienteZA(DoubleLinkedList<Cliente>& lista)
{
    cout << "Nombres de clientes ordenados de la Z a la A: " << endl;
    for (int i = 0; i < lista.Length() - 1; i++)
    {
        for (int j = i+1; j < lista.Length(); j++)
        {
            if (lista.at(i).getPersonaDatosToString() < lista.at(j).getPersonaDatosToString())
            {

                Cliente aux = lista.at(i);
                aux = lista.at(i);
                lista.modify_by_index(i, lista.at(j));
                lista.modify_by_index(j, aux);
            }
        }
    }
    for (int i = 0; i < lista.Length(); i++)
    {
        lista.at(i).imprimir();
        cout << endl;
    }
}
void ordenarClienteAZ(DoubleLinkedList<Cliente>& lista)
{
    cout << "Nombres de clientes ordenados de la A a la Z: " << endl;
    for (int i = 0; i < lista.Length() - 1; i++)
    {
        for (int j = i + 1; j < lista.Length(); j++)
        {
            if (lista.at(i).getPersonaDatosToString() > lista.at(j).getPersonaDatosToString())
            {

                Cliente aux = lista.at(j);
                aux = lista.at(j);
                lista.modify_by_index(j, lista.at(i));
                lista.modify_by_index(i, aux);
            }
        }
    }
    for (int i = 0; i < lista.Length(); i++)
    {
        lista.at(i).imprimir();
        cout << endl;
    }
}
void ordenarClienteEdadMayorMenor(DoubleLinkedList<Cliente>& lista)
{
    for (int i = 0; i < lista.Length() - 1; i++)
    {
        for (int j = i + 1; j < lista.Length(); j++)
        {
            if (lista.at(i).getEdad() < lista.at(j).getEdad())
            {
                Cliente aux = lista.at(i);
                aux = lista.at(i);
                lista.modify_by_index(i, lista.at(j));
                lista.modify_by_index(j, aux);
            }
        }
    }
    for (int i = 0; i < lista.Length(); i++)
    {
        lista.at(i).imprimir();
        cout << endl;
    }
}
void ordenarClienteEdadMenorMayor(DoubleLinkedList<Cliente>& lista)
{
    for (int i = 0; i < lista.Length() - 1; i++)
    {
        for (int j = i + 1; j < lista.Length(); j++)
        {
            if (lista.at(i).getEdad() > lista.at(j).getEdad())
            {
                Cliente aux = lista.at(i);
                aux = lista.at(i);
                lista.modify_by_index(i, lista.at(j));
                lista.modify_by_index(j, aux);
            }
        }
    }
    for (int i = 0; i < lista.Length(); i++)
    {
        lista.at(i).imprimir();
        cout << endl;
    }
}
//----------------------------------MOTORIZADOS--------------------------------------
// LO MISMO QUE LOS DEMAS, TIPO UN CRUD
void clientesMotorizado()
{
    cout << "\n\t\t[ OPCIONES DE MOTORIZADOS ]\n\n";
    cout << "[1]. Agregar Nuevo Motorizado\n";
    cout << "[2]. Listar Todos Los Motorizados\n";
    cout << "[3]. Modificar Motorizado\n";
    cout << "[4]. Eliminar Motorizado\n";
    cout << "[5]: Buscar Motorizado\n";
    cout << "[6]: Mostrar Motorizados En Arbol\n";
	cout << "[7]. Regresar\n";
	cout << " Ingresa opc : ";
}
Motorizado crearMotorizado()
{
    auto nuevo_lambda_gendni = []() -> string {
        string DNI = "";
        string diccionario = "1029384756";
        for (int i = 0; i < 8; i++)
        {
            DNI.push_back(diccionario[generarAleatorio(0, diccionario.length() - 1)]);
        }
        return DNI;
    };
    cin.ignore();
    cout << "\n\t[ CREACION DE MOTORIZADO ]\n\n";
    Motorizado nuevo; //variable de tipo motorizado
    cout << "Nombre:  ";
    fflush(stdin);
    getline(cin, nuevo.nombre);

    cout << "Apellido:  ";
    fflush(stdin); //limpiar buffer para evitar datos almacenados no necesarios
    getline(cin, nuevo.apellido);

    cout << "Edad:  ";
    cin >> nuevo.edad;

    nuevo.dni = nuevo_lambda_gendni();

    cout << "Nacimiento [ dia mes anio ] (Escribir los dos nueros del dia, mes y los cuatro del año POR SEPARADO):  ";
    cin >> nuevo.nacimiento.dia >> nuevo.nacimiento.mes >> nuevo.nacimiento.anio;

    cin.ignore();
    cout << "Direccion:  ";
    fflush(stdin);
    getline(cin, nuevo.direccionCompleta);

    cout << "Cod Moto:  ";
    fflush(stdin);
    getline(cin, nuevo.cod_motorizado);

    cout << "Nro Placa:  ";
    fflush(stdin);
    getline(cin, nuevo.nro_placa);

    cout << "Marca Moto:  ";
    fflush(stdin);
    getline(cin, nuevo.marcaMoto);
    return nuevo;
}
void imprimirMotorizado(DoubleLinkedList<Motorizado> lista)
{ //Lenght es para revisar el largo/cantidad de la lista
    if (lista.Length() == 0)  cout << "\n\n\t\b[ LISTA SE ENCUENTRA VACIA ]\n\n";
    else {
        cout << "\n\t\b[ LISTADO DE MOTORIZADOS ]\n\n";
        for (int i = 0; i < lista.Length(); i++)
        {
            lista.at(i).imprimir();
            cout << endl;
        }
    }
}
void modificacionMotorizado(DoubleLinkedList<Motorizado>& lista)
{
    if (lista.Length() == 0) cout << "\n\n\t\b[ LISTA SE ENCUENTRA VACIA ]\n\n";
    else {
        cin.ignore();
        string str;
        cout << "\n\t\b[ MODIFICACION DE MOTORIZADO ]\n\n";
        cout << "Ingresa DNI de motorizado a modificar : ";
        fflush(stdin);
        getline(cin, str);
        bool modificado = false;
        for (int i = 0; i < lista.Length(); i++)
        {
            if (str.compare(lista.at(i).dni) == 0) 
            {//si al hacer la comparacion de dni en la lista y es el mismo, lo indentifica para modificaar
                cout << "\nMOTORIZADO ENCONTRADO\n";
                lista.at(i).imprimir();

                cout << "\nMODIFICANDO\n..Presiona Enter..";
                Motorizado aux = crearMotorizado();

                lista.modify_by_index(i, aux); //comando para modificar el objeto segun su indice en el arreglo
                cout << "\n\t[ MODIFICADO ]\n\n";
                modificado = true;
                break;
            }
        }
        if (!modificado) //si modificado no es TRUE...
            cout << "\n\t[ NO ENCONTRADO ]\n\n";
    }
}
//----------------------------------CREAR RESTAURANTE--------------------------------------
//Y LO MISMO QUE LOS DEMAS PERO CON RESTAURANTES
void restaurantesMenu()
{
    cout << "\n\t\t[ OPCIONES DE RESTAURANTES ]\n\n";
    cout << "[1]. Agregar Nuevo Restaurante\n";
    cout << "[2]. Listar Todos Los Restaurantes\n";
    cout << "[3]. Modificar Restaurante\n";
    cout << "[4]. Ingresa opc : ";
}

Restaurante crearRestaurante(DoubleLinkedList<Plato> lista_platitos)
{
    cout << "\n\t[ CREACION DE RESTAURANTE ]\n";
    cin.ignore();
    Restaurante nuevo;

    cout << "Ingresa Nombre de Restaurante : ";
    getline(cin, nuevo.nombreRestaurante);

    cout << "Calificacion de Restaurante [1 - 5 ] : ";
    cin >> nuevo.calificacionEstrellas;

    int cant;
    cout << "Cuantos Platos Anadira?: ";
    cin >> cant;
    for (int i = 0; i < lista_platitos.Length(); i++){
        cout << i << ".";
        lista_platitos.at(i).imprimirPlato();
    }

    int aux;
    for (int i = 0; i < cant; i++){
        cin >> aux;
        nuevo.carta.agregar(lista_platitos.at(aux));
    }
    return nuevo;
}
void imprimirRestaurantes(DoubleLinkedList<Restaurante> lista)
{
    if (lista.Length() == 0)  cout << "\n\n\t\b[ LISTA SE ENCUENTRA VACIA ]\n\n";
    else {
        cout << "\n\t\b[ LISTADO DE RESTAURANTES ]\n\n";
        for (int i = 0; i < lista.Length(); i++)
        {
            lista.at(i).imprimir();
            cout << endl;
        }
    }
}

void modificacionRestaurante(DoubleLinkedList<Restaurante>& lista, DoubleLinkedList<Plato>p)
{
    if (lista.Length() == 0) {
        cout << "\n\n\t\b[ LISTA SE ENCUENTRA VACIA ]\n\n";
    }
    else {
        cin.ignore();
        string str;
        cout << "\n\t\b[ MODIFICACION DE RESTAURANTE ]\n\n";
        cout << "Ingresa Nombre de Restaurante a modificar : ";
        fflush(stdin);
        getline(cin, str);
        bool modificado = false;
        for (int i = 0; i < lista.Length(); i++)
        {
            if (str.compare(lista.at(i).nombreRestaurante) == 0)
            {
                cout << "\nRESTAURANTE ENCONTRADO\n";
                lista.at(i).imprimir();

                cout << "\nMODIFICANDO\n..Presiona Enter..";
                Restaurante aux = crearRestaurante(p);


                lista.modify_by_index(i, aux);
                cout << "\n\t[ MODIFICADO ]\n\n";
                modificado = true;
                break;
            }
        }
        if (!modificado) {
            cout << "\n\t[ NO ENCONTRADO ]\n\n";
        }
    }
}
//---------------------------------CREACION DE PEDIDO----------------------------------------
//ELEGIMOS UN CLIENTE, UN LAMBDA ELEGIRA UN MOTORIZADO, Y EL RESTAURANTE LO ELIGIREMOS NOSOTROS
void crearPedido(DoubleLinkedList<Cliente>& LP, DoubleLinkedList<Motorizado>LM, DoubleLinkedList<Restaurante>RES)
{
    cout << "\n\n\t[ CREACION DE PEDIDO ]\n\n";

    cout << "\n\tELIGIENDO CLIENTE\n";
    for (int i = 0; i < LP.Length(); i++) //largo de la lista de personas
    {
        cout << "[" << i << "].";
        LP.at(i).imprimir();
        cout << endl;
    }

    int index_LP;
    while (1) {
        cout << "\nIngresa Cliente[i]: ";  cin >> index_LP;

        if (index_LP >= 0 && index_LP < LP.Length())
            break;
    }
    auto escogerMotorizado = [&]() -> Motorizado {
        return LM.at(generarAleatorio(0, LM.Length() - 1)); 
    };//retorna los datos del motorizado elegido aleatoriamente y la lista se reduce en uno para no repetirlo

    cout << "\n\t[ SE TE ASIGNO EL SIGUIENTE MOTORIZADO :) ]\n";
    Motorizado motoEscogida = escogerMotorizado();
    motoEscogida.imprimir();
    cout << endl;

    cout << "\n\tELIGIENDO RESTAURANTE\n";
    for (int i = 0; i < RES.Length(); i++) {
        cout << "[" << i << "].";
        RES.at(i).imprimir();
        cout << endl;
    }

    int index_RES;
    while (1) {
        cout << "\nIngresa Restaurante[i]: ";
        cin >> index_RES;

        if (index_RES >= 0 && index_RES < RES.Length())
            break;
    }

    DoubleLinkedList<Plato> carta;
    carta = RES.at(index_RES).carta;

    cout << "\n\tELIGIENDO PLATOS DE RESTAURANT ( " << RES.at(index_RES).nombreRestaurante << " )\n";
    for (int i = 0; i < carta.Length(); i++) {
        cout << "[" << i << "].";
        carta.at(i).imprimirPlato();
        cout << endl;
    }

    int totalPlatos;
    cout << "-1 o 0 Para Cancelar PEDIDO\n";
    cout << "Cuantos Platos Elegira? "; cin >> totalPlatos;

    if (totalPlatos == -1 || totalPlatos == 0) {
        cout << "\n\t[ OPERACION CANCELADA ]\n";
        return;
    }

    DoubleLinkedList<Plato> platosApedir;
    for (int i = 0; i < totalPlatos; i++)
    {
        int index;
        cout << "Ingresa indice de  Plato [" << i << "] : "; cin >> index;

        platosApedir.agregar(carta.at(index));
    }
    carta = platosApedir;
    Cliente despachar = LP.at(index_LP);
    cout << "\n\n\t\[ CONFIRMACION DE PEDIDO ]\n\n";
    cout << "\nCLIENTE\n";
    despachar.imprimir();

    cout << "\nMOTORIZADO\n";
    motoEscogida.imprimir();

    cout << "\nRestaurante  : " << RES.at(index_RES).nombreRestaurante << endl;
    cout << "Calificacion : " << RES.at(index_RES).calificacionEstrellas << endl;
    for (int i = 0; i < carta.Length(); i++)
        carta.at(i).imprimirPlato();

    int opc;
    cout << "\nConfirmar ? [1]. SI | [0]. No : ";
    cin >> opc;

    if (opc == 0) {
        cout << "\n\n\t\t[ OPERACION CANCELADA ]\n";
        return;
    }
    despachar.pedidos = carta;

    LP.modify_by_index(index_LP, despachar);
    cout << "\n\n\t\t[ PEDIDO DESPACHADO ]\n\n";
    system("pause");

    fstream archivo("pedidosHECHOS.txt", ios::app); //ios::app agregara el pedido realizado al final del archivo

    archivo << despachar.getPersonaDatosToString() << endl;
    archivo << motoEscogida.getDatosMotorizado() << endl;
    for (int i = 0; i < carta.Length(); i++)
        archivo << carta.at(i).devolverPlatoString() << endl;
    
    archivo.close(); //cerrar el archivo de pedidos
}
int main() {
    srand(time(NULL));//CREACION  DE ALEATORIOS 
    //LISTAS QUE USAREMOS
    DoubleLinkedList<Cliente> lista_clientes;
    
    DoubleLinkedList<Motorizado> lista_motorizados;
    DoubleLinkedList<Restaurante> lista_Restaurantes;
    DoubleLinkedList<Plato> lista_platos;

    //CARGANDO LAS PERSONAS
    cargarPersona(lista_clientes);
    cargarPlato(lista_platos);
    cargarMotorizado(lista_motorizados);
    cargarRestaurante(lista_Restaurantes, lista_platos);

    bool salir = false;
    int opc;
    //MENU PRINICPAL
    do {
        do {
            system("cls");
            menu();
            cin >> opc;
        } while (opc > 5);
        switch (opc)
        {
        case 1://CASO 1 DE CLIENTES
            do {
                system("cls");
                clientesMenu();
                cin >> opc;
                HashTable1<string, Usuario1>* ht = new HashTable1<string, Usuario1>(100);
                switch (opc)
                {
                case 1:
                    lista_clientes.agregar(crearCliente());
                    cout << "\n\t\b[ CLIENTE AGREGADO CORRECTAMENTE ]\n";
                    break;
                case 2:
                    imprimirCliente(lista_clientes);
                    break;
                case 3:
                    modificacionCliente(lista_clientes);
                    break;
                case 4:
                    ordenarClienteAZ(lista_clientes);
                    break;
                case 5: 
                    ordenarClienteZA(lista_clientes);
                    break;
                case 6:
                    ordenarClienteEdadMenorMayor(lista_clientes);
                    break;
                case 7:
                  
                    ht->imprimirUsuarios();
                    break;
                case 8:
                 
                    string nombre, apellido;
                    int monto;
                    cout << "Ingrese Nombre y Apellido: " << endl;
                    getline(cin, nombre);
                    getline(cin, apellido);
                    cout << "Ingrese su Numero: " << endl;
                    cin >> monto;
                    int cont = 0;
                    ht->insertar(nombre, Usuario1(nombre, apellido, monto));
                    cont++;
                   
                    break;
                }
                cout << endl;
                system("pause");
            } while (opc != 9);
            break;
        case 2://CASO DOS DE MOTORIZADOS
            do{
                system("cls");
                clientesMotorizado();
                cin >> opc;
                if(opc==1){
                	lista_motorizados.agregar(crearMotorizado());
                    cout << "\n\t\b[ MOTORIZADO AGREGADO CORRECTAMENTE ]\n";
				}
                if(opc==2) imprimirMotorizado(lista_motorizados);
                if(opc==3) modificacionMotorizado(lista_motorizados);
                if(opc==5){
                	string nombre;
					system("cls");
                	cout<<endl;
                	cout<<"[ BUSCAR MOTORIZADO ]"<<endl;
                	cout<<endl;
                	node *root=leerArchivo();
  					cout<<"Digite nombre del motorizado: ";
  					cin>>nombre;
  					cout<<endl;
  					buscarMotorizado(root,nombre);
				}	
				if(opc==6){
					system("cls");
                	cout<<endl;
                	cout<<"[ MOSTRAR MOTORIZADOS - EN ORDEN BST ]"<<endl;
                	cout<<endl;
                	node *root=leerArchivo();
  					inorder(root);
				}
                cout << endl;
                system("pause");
            }while(opc!=7);
        break;
        case 3://CASO DE RESTAURANTES
            do {
                system("cls");
                restaurantesMenu();
                cin >> opc;
                switch (opc)
                {
                case 1:
                    lista_Restaurantes.agregar(crearRestaurante(lista_platos));
                    cout << "\n\t\b[ RESTAURANTE AGREGADO CORRECTAMENTE ]\n";
                    break;
                case 2:
                    imprimirRestaurantes(lista_Restaurantes);
                    break;
                case 3:
                    modificacionRestaurante(lista_Restaurantes, lista_platos);
                    break;
                }
                cout << endl;
                system("pause");
            } while (opc != 4);
            break;
        case 4://CREAMOS PEDIDO
            crearPedido(lista_clientes, lista_motorizados, lista_Restaurantes);
            break;
        case 5://Y FINALEMNTE SALIMOS
            cout << "\n\n\t\t[ GRACIAS POR USAR EL PROGRAMA DE PEDIDOS YAAA!!]\n\n";
            salir = true;
            break;
        }
    } while (!salir);
    return 0;
}
