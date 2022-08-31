#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include<iostream>
using namespace std;
class Cliente {
    string RFC;
    string nombre;
    string apellido;
    string correo;
    string numeroCelular;
    string precioVenta;
public:
    Cliente();
    Cliente(string RFC, string nombre, string apellido, string correo, string numeroCelular, string precioVenta);
    ~Cliente();
    void Crear();
    void Mostrar();
    void Buscar(string RFC);
    void Eliminar(string RFC);