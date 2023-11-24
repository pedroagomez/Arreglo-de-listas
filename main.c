#include <stdio.h>
#include <stdlib.h>
#include "libreriaCelda.h"
#include "libreriaListas.h"




int main()
{
    stCelda arreglo[10];
    int validos;
    char nombreArchivo[20];
    strcpy(nombreArchivo,"registroMedico.dat");


    validos=deArchivoACelda(nombreArchivo,arreglo,10);
    mostrarCeldaLista(arreglo,validos);
    printf("\n Cargue un nuevo paciente \n");
    validos=cargarUsuario(arreglo,validos,10);
    mostrarCeldaLista(arreglo,validos);
    printf("\n Busque un determinado paciente \n");
    char nombre[10];
    char apellido[10];
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese apellido :");
    fflush(stdin);
    gets(apellido);
    recorrerCelda(arreglo,validos,nombre,apellido);
    int cantidadTotal=compararEspecialidadesCelda(arreglo,validos);
    printf("\nLa cantidad de consultas fue : %d\n",cantidadTotal);

    char especialidad[20];

    printf("\nIngrese especialidad:");
    fflush(stdin);
    gets(especialidad);
    pasarAarchivoEspecialidad(arreglo,validos,especialidad);
    mostrarArchivoEspecialidad("Neumologia general");
}
