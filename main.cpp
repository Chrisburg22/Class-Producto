#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Producto{

public:
    char codigo[11], codigoProv[11], descripcion[31], precioCompra[7], precioVenta[7];
    void Crear();
    void Mostrar();
    void Buscar();
    void Eliminar();
    void Modificar();

}p;

void Producto::Crear(){
    ofstream Archivo;
    cout << "LIMITE DE CARACTERES" << endl << endl;
    cout << "CODIGO:10  \nCODIGO PROVEEDOR:10  \nPRECIO COMPRA:6   \nPRECIO VENTA:6 \nDESCRIPCION:30" << endl;
    Archivo.open("ProductosAutomaxx.txt");

    cout << endl << "Crear codigo de 10 digitos para el producto: ";
    cin.getline(codigo,11);
    cin.getline(codigo,11);
    cout << endl << "Ingresa el Codigo del proveedor: ";
    cin.getline(codigoProv,11);
    cout << endl << "Ingresa el precio de compra: ";
    cin.getline(precioCompra,7);
    cout << endl << "Ingrese el precio de Venta: ";
    cin.getline(precioVenta,7);
    cout << endl << "Ingrese una descripcion: ";
    cin.getline(descripcion,31);
    cout << endl << endl;
    Archivo<<codigo<<'|'<<codigoProv<<'|'<<precioCompra<<'|'<<precioVenta<<'|'<<descripcion<<'|';
    Archivo.close();
    system("pause");
};

void Producto::Mostrar(){

    int i;
    ifstream Lectura("ProductosAutomaxx.txt");//abrir archivo en forma de lectura. "Lectura" es un objeto

    if(!Lectura.good()){ /* good (libreria fstream) nos verifica si hubo problema al abrir el
                            * a travez de un booleano */
        cout << "No existe el archivo" << endl;
        system("pause");

    } else {

        while(!Lectura.eof()){// eof=end of file
            // Vamos a leer la variable user
            i=0;
           do{
/*
*Leo el objeto de tipo char, lo asigno a
*la variable user en la posicion que tenga el subindice, y se lee de caracter en
*car�cter.
*/              Lectura.read((char*)&codigo[i],1);
                if(Lectura.eof()){
                    break;
                }
                i++;
           } while(codigo[i-1]!='|');

           codigo[i-1]='\0';
           i=0;

           do{
                Lectura.read((char*)&codigoProv[i],1);
                if(Lectura.eof()){
                    break;
                }
                i++;
           } while(codigoProv[i-1]!='|');

           codigoProv[i-1]='\0';
           i=0;

           do{
                Lectura.read((char*)&precioCompra[i],1);
                if(Lectura.eof()){
                    break;
                }
                i++;
           } while(precioCompra[i-1]!='|');

           precioCompra[i-1]='\0';
           i=0;

           do{
                Lectura.read((char*)&precioVenta[i],1);
                if(Lectura.eof()){
                    break;
                }
                i++;
           } while(precioVenta[i-1]!='|');

           precioVenta[i-1]='\0';
           i=0;

           do{
                Lectura.read((char*)&descripcion[i],1);
                if(Lectura.eof()){
                    break;
                }
                i++;
           } while(descripcion[i-1]!='|');

           descripcion[i-1]='\0';
           i=0;

           if(Lectura.eof())
            break;

           cout << "\nCodigo: " << codigo << endl;
           cout << "\nCodigo proveedor: " << codigoProv << endl;
           cout << "\nPrecio compra: " << precioCompra << endl;
           cout << "\nPrecio venta: " << precioVenta << endl;
           cout << "\nDescripcion: " << descripcion << endl;

           if(Lectura.eof())
            break;
        }
        cout << endl << endl;
        system("pause");
    }
    Lectura.close();
}

void Producto::Buscar(){

    int iguales, i, b=0;
    char alubus[11],caracter;
    ifstream arc("ProductosAutomaxx.txt");

    if(!arc.good()){

        cout << "No existe en archivo\n";
        system("pause");

    } else {

        cout << "\nEscribe el Codigo del producto a buscar: ";
        cin.getline(alubus,11);
        cin.getline(alubus,11);
        while(!arc.eof()){
           i=0;
           do{
             arc.read((char*)&caracter,1);
             if(caracter!='|'){
                codigo[i]=caracter;
                i++;
            }
           } while(caracter!='|');

           codigo[i]='\0';
           i=0;

           do{
                arc.read((char*)&caracter,1);
                if(caracter!='|'){
                    codigoProv[i]=caracter;
                    i++;
                }
           } while(caracter!='|');

           codigoProv[i]='\0';
           i=0;

           do{
                arc.read((char*)&caracter,1);
                if(caracter!='|'){
                    precioCompra[i]=caracter;
                    i++;
                }
           } while(caracter!='|');

           precioCompra[i]='\0';
           i=0;

           do{
                arc.read((char*)&caracter,1);
                if(caracter!='|'){
                    precioVenta[i]=caracter;
                    i++;
                }
           } while(caracter!='|');

           codigoProv[i]='\0';
           i=0;

           do{
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof()){
                    descripcion[i]=caracter;
                    i++;
                }
           } while(caracter!='|' && !arc.eof());

           codigoProv[i]='\0';

           if(arc.eof())
            break;

           iguales = strcmp(codigo,alubus);

           if(iguales==0){
           cout << "\nCodigo: " << codigo << endl;
           cout << "\nCodigo proveedor: " << codigoProv << endl;
           cout << "\nPrecio compra: " << precioCompra << endl;
           cout << "\nPrecio venta: " << precioVenta << endl;
           cout << "\nDescripcion: " << descripcion << endl;

            b=1;
            break;
           }
        }

        if(b==0){
            cout << "El archivo no existe";
        }
        arc.close();
        cout << endl << endl;
        system("pause");
    }
}
int main()
{
    int opc;


    do{

        system("cls");
        cout << "   PRODUCTOS" << endl;
        cout <<"\n 1.- CREAR \n 2.- MOSTRAR \n 3.- BUSCAR \n 4.- ELIMINAR \n 5.- MODIFICAR \n";
        cout <<" 6.- SALIR\n\n Opcion: ";
        cin >>opc;

        switch(opc){
            case 1:
                system("cls");
                p.Crear();
                break;
            case 2:
                system("cls");
                p.Mostrar();
                break;
            case 3:
                system("cls");
                p.Buscar();
                break;

            //case 4: nuevoProducto.Eliminar();
              //  break;

            //case 5: nuevoProducto.Modificar();
              //  break;
        }

    }while(opc!=3);

    return 0;
}
