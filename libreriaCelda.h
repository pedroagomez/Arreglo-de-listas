#ifndef LIBRERIACELDA_H_INCLUDED
#define LIBRERIACELDA_H_INCLUDED
#include "libreriaListas.h"


typedef struct
{
    int idRegistro;
    int idPaciente;
    int idEspecialidad;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11]; /// formato: AAAA-mm-DD
    char especialidadMedica[30];
    char nombreDoctor[30];
} stRegistroMedico;



typedef struct
{
    int idEspecialidad;
    char especialidadMedica[30];
} stEspecialidad;


typedef struct
{
    stEspecialidad dato;
    nodoLista* listaApunta;
}stCelda;


void mostrarGral(stRegistroMedico aux);
void mostrarArchivo(char nombreArchivo[]);
int buscarPosicion(stCelda arreglo[], int validos, int idEspecialidad);
int agregarEspecialdiad(stCelda arreglo[], int validos, int dim, char nombreEspecialidad[], int idEspecialidad);
int alta(stCelda arreglo[], int validos,int dim, stRegistroMedico registro);
int deArchivoACelda(char nombreArchivo[],stCelda arreglo[], int dim);
void mostrarCeldaLista(stCelda arreglo[],int validos);
#endif // LIBRERIACELDA_H_INCLUDED
