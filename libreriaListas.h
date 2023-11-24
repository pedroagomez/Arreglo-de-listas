#ifndef LIBRERIALISTAS_H_INCLUDED
#define LIBRERIALISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int idRegistro;
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    char nombreDoctor[30];
} stPaciente;


typedef struct
{
    stPaciente persona;
    struct nodoLista* siguiente;
}nodoLista;

nodoLista* inicLista();
nodoLista* crearNodo(stPaciente nuevo);
nodoLista* agregarAlFinal(nodoLista* lista, nodoLista* nuevo);
void mostrarUnNodo(nodoLista* lista);
void mostrarLista(nodoLista* lista);



#endif // LIBRERIALISTAS_H_INCLUDED
