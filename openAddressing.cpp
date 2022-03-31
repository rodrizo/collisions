#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

struct hash
{
    int codigo;
    char nombre[50];
} tabla[10];

string * insercion(int codigo, char nombre[50])
{

    // stores the collisions
    string * report = new string[10];

    int i = 0; // helps to go trough the array
    int valor, posicion, suma = 0;
    // calculando valor total de la cadena
    for (int i = 0; i < strlen(nombre); i++)
    {
        valor = nombre[i];
        suma = suma + valor;
    }

    posicion = suma % 10;

    //                                                              Linear Probing
    // slot is filled
    if (tabla[posicion].codigo != 0)
    {
        // generating collision report
        report[i] = "Tried to insert -> ", nombre, "in slot # -> ", posicion, "\n";
        cout <<  &report , *(&report);

        tabla[posicion + 1].codigo = codigo;
        strcpy(tabla[posicion + 1].nombre, nombre);
        i++;
    }
    // slot isn´t filled
    else
    {
        tabla[posicion].codigo = codigo;
        strcpy(tabla[posicion].nombre, nombre);
    }

    return report;
}

void listartabla()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d , %d -> %s\n", i, tabla[i].codigo, tabla[i].nombre);
    }
}

int main()
{
    //string * collisions;

    // insercion(1, "uno");
    // insercion(3, "tres");
    // insercion(4, "cuatro");
    insercion(5, "cinco");
    insercion(5, "ocnic");
    // insercion(6, "seis");
    // insercion(7, "siete");
    // insercion(8, "ocho");
    // insercion(9, "nueve");
    listartabla();

    // listing collisions
    cout << "Collisions report\n-----------------------------\n";
    // for (int i = 0; i < 10; i++)
    // {
    //     *collisions[i];
    // }

    return (0);
}
