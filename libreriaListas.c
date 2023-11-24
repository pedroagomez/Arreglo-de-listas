#include "libreriaListas.h"

nodoLista* inicLista()
{
    return NULL;
}

nodoLista* crearNodo(stPaciente nuevo)
{
    nodoLista* lista=(nodoLista*)malloc(sizeof(nodoLista));
    lista->persona=nuevo;
    lista->siguiente=NULL;
    return lista;
}

nodoLista* agregarAlFinal(nodoLista* lista, nodoLista* nuevo)
{
    nodoLista* seguidora=lista;
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        while(seguidora->siguiente!=NULL)
        {
            seguidora=seguidora->siguiente;
        }
        seguidora->siguiente=nuevo;
    }
    return lista;
}


void mostrarUnNodo(nodoLista* lista)
{
    if(lista)
    {
        printf("=================================================== \n");
        printf("IdPaciente..................... :%d\n",lista->persona.idPaciente);
        printf("Id registro.................... :%d\n",lista->persona.idRegistro);
        printf("Apellido paciente.............. :%s\n",lista->persona.apellidoPaciente);
        printf("Nombre paciente................ :%s\n",lista->persona.nombrePaciente);
        printf("Fecha de atencion ............. :%s\n",lista->persona.fechaAtencion);
        printf("Nombre doctor.................. :%s\n",lista->persona.nombreDoctor);
        printf("Diagnostico.................... :%s\n",lista->persona.diagnostico);
    }
}

void mostrarLista(nodoLista* lista)
{
    while(lista)
    {
        mostrarUnNodo(lista);
        lista=lista->siguiente;
    }
}


int recorrerListaPaciente(nodoLista* lista, char nombre[], char apellido[])
{
    int flag=0;
    while(lista && flag==0)
    {
        if(strcmp(lista->persona.nombrePaciente,nombre)==0 && strcmp(lista->persona.apellidoPaciente,apellido)==0)
        {
            flag=1;
        }
        lista=lista->siguiente;
    }
    return flag;
}



