#include <iostream>
#include <fstream>
#include <iomanip>

#include "Cliente.hpp"

using namespace std;

Cliente::Cliente(){

}

Cliente::Cliente(string RFC, string nombre, string apellido, string correo, string numeroCelular, string precioVenta){
    this->RFC=RFC;
    this->nombre=nombre;
    this->apellido=apellido;
    this->correo=correo;
    this->numeroCelular=numeroCelular;
    this->precioVenta=precioVenta;
};

Cliente::~Cliente(){
}

void Cliente::Crear(){
    ofstream archivoCliente("clientes.txt", ios::app);

    if(archivoCliente.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    string RFC, nombre, apellido, correo, numeroCelular, precioVenta;
    cout << "Bienvenido a crear un cliente" << endl;
    cout << "Ingresa el RFC: ";
    getline(cin, RFC);
    getline(cin, RFC);
    
    cout  <<  "Ingrese el nombre: ";
    getline(cin, nombre);

    cout << "Ingrese el apellido: ";
    getline(cin, apellido);

    cout << "Ingrese el correo: ";
    getline(cin, correo);

    cout << "Ingrese numero de celular: ";
    getline(cin, numeroCelular);

    cout << "Ingrese el costo de venta:";
    getline(cin, precioVenta);

    archivoCliente << RFC << "," << nombre << "," << apellido << "," << correo << "," << numeroCelular << "," << precioVenta << endl;
    archivoCliente.close();
};

void Cliente::Mostrar()
{
    string RFC, nombre, apellido, correo, numeroCelular, precioVenta;
    ifstream archivo("clientes.txt");

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while(true){
        getline( archivo, RFC, ',' );
        if(archivo.eof())
           break;
        getline( archivo, nombre,',' );
        getline( archivo, apellido,',' );
        getline( archivo, correo,',' );
        getline( archivo, numeroCelular,',' );
        getline( archivo, precioVenta,',' );
        Cliente cliente(RFC, nombre, apellido, correo, numeroCelular, precioVenta);
        cout << left << endl;
        cout << setw(15) << "RFC";
        cout << setw(20) << "Nombre";
        cout << setw(20) << "Apellido";
        cout << setw(20) << "Correo";
        cout << setw(20) << "Numero Celular";
        cout << setw(20) << "Precio Venta" << endl;
        cout << setw(15) << RFC;
        cout << setw(20) << nombre;
        cout << setw(20) << apellido;
        cout << setw(20) << correo;
        cout << setw(20) << numeroCelular;
        cout << setw(20) << precioVenta << endl;
        cout << "------------------------------" << endl;
    }

    archivo.close();
}


