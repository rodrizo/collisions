#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

// string *report = new string[10]; // stores the collisions

void listarTabla();

struct hash
{
    int codigo;
    char nombre[20];
} tabla[10];

/*
    Stores the collisions in the array
*/
// string *collisions(int index, char data[20], int position)
// {
//     report[index] = "Tried to insert -> ", data, "in slot # -> ", position, "\n";

//     return report;
// }

void insercion(int codigo, char nombre[20])
{

    int counter = 0; // helps to go trough the array
    int valor, posicion, suma = 0;
    for (int i = 0; i < strlen(nombre); i++) // sum of array
    {
        valor = nombre[i];
        suma = suma + valor;
    }
    posicion = suma % 10; // generating key

    // LINEAR PROBING
    while (tabla[posicion].codigo != 0) // slot is full, it will stop until there's an empty one
    {
        // Generating collision report
        // collisions(counter, nombre, posicion);
        counter++;
        posicion++; // skips one slot to check for availability
    }

    tabla[posicion].codigo = codigo;
    strcpy(tabla[posicion].nombre, nombre);

    if (tabla[posicion].codigo == 0) // slot is empty
    {
        tabla[posicion].codigo = codigo;
        strcpy(tabla[posicion].nombre, nombre);
    }
}

void deleting()
{

    int option, index;

    do
    {
        cout << "-----------------------------------------------------------\n";
        cout << "¿Quiere eliminar un elemento de la tabla?\n1- Si\n2- No\n";
        cin >> option;
        if (option == 1)
        {
            cout << "-----------------------------------------------------------\n";
            cout << "\n\nIngrese el indice del elemento que desea borrar -> ";
            cin >> index;

            //deleting
            tabla[index].codigo = 0;
            memset(tabla[index].nombre, ' ', 10);
            listarTabla();
        }

    } while (option != 2);
}

void listarTabla()
{
    for (int i = 0; i < 10; i++)
    {
        printf("\t\t\t\t[%d] : %d -> %s\n", i, tabla[i].codigo, tabla[i].nombre);
    }
}

int main()
{
    /*
    string *collisions;
    collisions = collisions();
    */

    insercion(1, "uno");
    insercion(3, "tres");
    insercion(4, "cuatro");
    insercion(5, "cinco");
    insercion(55, "ocnic");
    insercion(6, "seis");
    insercion(7, "hola");
    insercion(77, "aloh");
    insercion(65, "trece");
    listarTabla();
    deleting();

    return (0);
}
