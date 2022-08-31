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
    void Modificar( string RFC);   

    //GETTERS
    string getRFC();
    string getNombre();
    string getApellido();
    string getCorreo();
    string getNumeroCelular();
    string getPrecioVenta();

    //SETTERS
    void setRFC(string RFC);
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setCorreo(string correo);
    void setNumeroCelular(string numeroCelular);
    void setPrecioVenta(string precioVenta);
};

#endif // PRODUCTO_HPP