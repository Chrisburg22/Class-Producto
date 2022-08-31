#include <iostream>
#include <fstream>
#include <iomanip>
#include "Producto.hpp"
using namespace std;

Producto::Producto()
{
}

Producto::Producto(string codigo, string codigoProvedor, string precioVenta, string precioCompra, string descripcion)
{
    this->codigo = codigo;
    this->codigoProvedor = codigoProvedor;
    this->precioVenta = precioVenta;
    this->precioCompra = precioCompra;
    this->descripcion = descripcion;
}

Producto::~Producto()
{
}

void Producto::Crear()
{
    ofstream archivoProductos;
    string codigo, codigoProvedor, precioVenta, precioCompra, descripcion;
    cout << "Bienvenido a crear producto" << endl;
    archivoProductos.open("productos.txt");

    cout << "Ingrese el codigo de 10 digitos para el producto" << endl;
    getline(cin, codigo);

    cout << "Ingresa el Codigo del proveedor" << endl;
    getline(cin, codigoProvedor);

    cout << "Ingresa el precio de compra: ";
    getline(cin, precioCompra);

    cout << "Ingrese el precio de Venta: ";
    getline(cin, precioVenta);

    cout << "Ingrese una descripcion: ";
    getline(cin, descripcion);

    archivoProductos << codigo << ',' << codigoProvedor << ',' << precioCompra << ',' << precioVenta << ',' << descripcion << endl;
    archivoProductos.close();
};

void Producto::Mostrar()
{
    string codigo, codigoProvedor, precioVenta, precioCompra, descripcion;
    ifstream archivo("productos.txt");

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while (true)
    {
        getline(archivo, codigo, ',');
        if (archivo.eof())
            break;
        getline(archivo, codigoProvedor, ',');
        getline(archivo, precioVenta, ',');
        getline(archivo, precioCompra, ',');
        getline(archivo, descripcion);
        Producto producto(codigo, codigoProvedor, precioVenta, precioCompra, descripcion);
        cout << left << endl;
        cout << setw(15) << "Codigo";
        cout << setw(20) << "Codigo Provedor";
        cout << setw(15) << "Precio Venta";
        cout << setw(15) << "Precio Compra";
        cout << setw(15) << "Descripcion" << endl;
        cout << setw(15) << codigo;
        cout << setw(20) << codigoProvedor;
        cout << setw(15) << precioVenta;
        cout << setw(15) << precioCompra;
        cout << setw(15) << descripcion << endl;
        cout << "------------------------" << endl;
    }

    archivo.close();
}

void Producto::Buscar(string productoBuscado)
{
    ifstream archivo("productos.txt");
    string codigo;
    int cont = 0;
    Producto producto;

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    cout << "Resultados para: " << productoBuscado;

    while (true)
    {
        getline(archivo, codigo, ',');
        if (archivo.eof())
            break;
        getline(archivo, codigoProvedor, ',');
        getline(archivo, precioVenta, ',');
        getline(archivo, precioCompra, ',');
        getline(archivo, descripcion);
        if (codigo == productoBuscado)
        {
            cont++;
        }

        if (cont > 0)
        {
            Producto producto(codigo, codigoProvedor, precioVenta, precioCompra, descripcion);
            cout << left << endl;
            cout << "-----------------------------------------------------------------" <<endl;
            cout << setw(15) << "Codigo";
            cout << setw(20) << "Codigo Provedor";
            cout << setw(15) << "Precio Venta";
            cout << setw(15) << "Precio Compra";
            cout << setw(15) << "Descripcion" << endl;
            cout << setw(15) << codigo;
            cout << setw(20) << codigoProvedor;
            cout << setw(15) << precioVenta;
            cout << setw(15) << precioCompra;
            cout << setw(15) << descripcion;
        }
        else
        {
            cout<<endl;
            cout << "Busqueda fallida, intente de nuevo" << endl;
            return;
        }
    }

    archivo.close();
}
