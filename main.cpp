#include <iostream>
#include <fstream>
#include "Classes/ProductoClass/Producto.hpp"
#include "Classes/ProductoClass/Producto.cpp"
using namespace std;

int main()
{
    int opc;
    Producto producto;
    do
    {
        cout << "PRODUCTOS" << endl;
        cout << "1) Crear" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Buscar" << endl;
        cout << "4) Eliminar" << endl;
        cout << "5) Modificar" << endl;
        cout << "0) Salir" <<endl;
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            cout << "CREAR" << endl;
            producto.Crear();
            break;
        }

        case 2:
        {
            cout << "MOSTRAR" << endl;
            producto.Mostrar();
            break;
        }

        case 3:
        {
            string codigoBuscado;
            cout << "BUSCAR" << endl;
            cout << "Introduce el codigo del producto a buscar" <<endl;
            getline(cin, codigoBuscado);
            producto.Buscar(codigoBuscado);
            break;
        }

        case 4:
        {
            cout << "ELIMINAR" << endl;

            break;
        }

        case 5:
        {
            cout << "MODIFICAR" << endl;

            break;
        }

        default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }

    } while (opc != 0);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
}
void menuClientes(){
     int opc;
     Cliente cliente;
    do{
        cout << "CLIENTES" << endl;
        cout << "1)Crear" << endl;
        cout << "2)Mostrar" << endl;
        cout << "3)Buscar" << endl;
        cout << "4)Eliminar" << endl;
        cout << "5)Modificar" << endl;
        cin >> opc;
        switch(opc){
            case 1:{
                cout << "CREAR" << endl;
                cliente.Crear();
                break;
            }
            case 2:{
                cout << "MOSTRAR" << endl;
                cliente.Mostrar();
                break;
            }
            default:
            cout << "Error: Opcion no valida, intentalo de nuevo" << endl;
            break;
        }
    }while(opc != 0);
}
int main()
{
    int opc;
    do{
        cout << "AUTOMAXX" << endl;
        cout << "1)CLiente" << endl;
        cout << "2)Producto" <<endl;
        cin >> opc;
        switch(opc){
            case 1:{
                menuClientes();
                break;
            }
            case 2: {
                menuProductos();
                break;
            }
        }
    }while(opc != 0);
=======
>>>>>>> parent of 437359e (Agregando el menu de clientes, creacion de la clase clientes, metodo crear terminado)
=======
>>>>>>> parent of 437359e (Agregando el menu de clientes, creacion de la clase clientes, metodo crear terminado)
=======
>>>>>>> parent of 437359e (Agregando el menu de clientes, creacion de la clase clientes, metodo crear terminado)
=======
>>>>>>> parent of 437359e (Agregando el menu de clientes, creacion de la clase clientes, metodo crear terminado)

    return 0;
}
