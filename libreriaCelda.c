#include "libreriaCelda.h"



void mostrarGral(stRegistroMedico aux)
{
    printf("====================================== \n");
    printf("Id registro.............. :%d\n",aux.idRegistro);
    printf("Id Paciente.............. :%d\n",aux.idPaciente);
    printf("Id Especialidad.......... :%d\n",aux.idEspecialidad);
    printf("Nombre Paciente.......... :%s\n",aux.nombrePaciente);
    printf("Apellido Paciente........ :%s\n",aux.apellidoPaciente);
    printf("Diagnostico ............. :%s\n",aux.diagnostico);
    printf("Fecha de Atencion........ :%s\n",aux.fechaAtencion);
    printf("Especialidad Medica...... :%s\n",aux.especialidadMedica);
    printf("Nombre doctor............ :%s\n",aux.nombreDoctor);
}


void mostrarArchivo(char nombreArchivo[])
{
    stRegistroMedico aux;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&aux,sizeof(stRegistroMedico),1,archi)>0)
        {
            mostrarGral(aux);
        }
        fclose(archi);
    }
}

int buscarPosicion(stCelda arreglo[], int validos, int idEspecialidad)
{
    int pos=-1;
    int i=0;
    while(i<validos && pos==-1)
    {
        if(arreglo[i].dato.idEspecialidad==idEspecialidad)
        {
            pos=i;
        }
        i++;
    }
    return pos;
}

int agregarEspecialdiad(stCelda arreglo[], int validos, int dim, char nombreEspecialidad[], int idEspecialidad)
{
    if(validos<dim)
    {
        arreglo[validos].dato.idEspecialidad=idEspecialidad;
        strcpy(arreglo[validos].dato.especialidadMedica,nombreEspecialidad);
        arreglo[validos].listaApunta=NULL;
        validos++;
    }
    return validos;
}

int alta(stCelda arreglo[], int validos,int dim, stRegistroMedico registro)
{
    stPaciente aux;
    aux.idPaciente=registro.idPaciente;
    aux.idRegistro=registro.idRegistro;
    strcpy(aux.apellidoPaciente,registro.apellidoPaciente);
    strcpy(aux.nombrePaciente,registro.nombrePaciente);
    strcpy(aux.nombreDoctor,registro.nombreDoctor);
    strcpy(aux.fechaAtencion,registro.fechaAtencion);
    strcpy(aux.diagnostico,registro.diagnostico);

    nodoLista* nuevo=crearNodo(aux);

    int pos=buscarPosicion(arreglo,validos,registro.idEspecialidad);
    if(pos==-1)
    {
        validos=agregarEspecialdiad(arreglo,validos,dim,registro.especialidadMedica,registro.idEspecialidad);
        pos=validos-1;
    }
    arreglo[pos].listaApunta=agregarAlFinal(arreglo[pos].listaApunta,nuevo);
    return validos;
}


int deArchivoACelda(char nombreArchivo[],stCelda arreglo[],int dim)
{
    stRegistroMedico aux;
    int i=0;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&aux,sizeof(stRegistroMedico),1,archi)>0)
        {

            i=alta(arreglo,i,dim,aux);

        }
    }
    return i;
}

void mostrarCeldaLista(stCelda arreglo[],int validos)
{
    int i=0;

    while(i<validos)
    {

        printf("\N================================= \n");
        printf("Id especialidad.................. :%d\n",arreglo[i].dato.idEspecialidad);
        printf("Especialidad..................... :%s\n",arreglo[i].dato.especialidadMedica);
        printf("================================= \n");
        mostrarLista(arreglo[i].listaApunta);
        i++;
    }
}

int cargarUsuario(stCelda arreglo[], int validos, int dim)
{
    stRegistroMedico aux;
    printf("Ingrese el id paciente : ");
    scanf("%d",&aux.idPaciente);
    printf("Ingrese el id  especialidad :");
    scanf("%d",&aux.idEspecialidad);
    printf("Nombre paciente :");
    fflush(stdin);
    gets(aux.nombrePaciente);
    printf("Apellido paciente :");
    fflush(stdin);
    gets(aux.apellidoPaciente);
    printf("Diagonostico :");
    fflush(stdin);
    gets(aux.diagnostico);
    printf("Fecha de atencion :");
    fflush(stdin);
    gets(aux.fechaAtencion);
    printf("Especialidad medica :");
    fflush(stdin);
    gets(aux.especialidadMedica);
    printf("Nombre doctor :");
    fflush(stdin);
    gets(aux.nombreDoctor);

    validos=alta(arreglo,validos,dim,aux);
    return validos;
}

void recorrerCelda(stCelda arreglo[], int validos, char nombre[], char apellido[])
{
    int i=0;
    int flag=0;
    while(i<validos && flag ==0)
    {
        flag=recorrerListaPaciente(arreglo[i].listaApunta,nombre,apellido);
        if(flag==1)
        {
            printf("Se encontro el paciente en la especialidad :%s\n",arreglo[i].dato.especialidadMedica);
        }
        else
        {
            printf("No se encntro el paciente en la especialidad :%s\n",arreglo[i].dato.especialidadMedica);
        }
        i++;
    }
}

int especialidadRecorrerLista(nodoLista* lista)
{
    int cantidad=0;
    while(lista)
    {
        cantidad++;
        lista=lista->siguiente;
    }
    return cantidad;
}

int compararEspecialidadesCelda(stCelda arreglo[],int validos)
{
    int i=0;
    int cantidadEspecialidad=0;
    int cantidadTotal=0;
    char especialidadMaxima[30];

    while(i<validos)
    {
        cantidadEspecialidad=especialidadRecorrerLista(arreglo[i].listaApunta);
        if(cantidadEspecialidad>cantidadTotal)
        {
            cantidadTotal=cantidadEspecialidad;
            strcpy(especialidadMaxima,arreglo[i].dato.especialidadMedica);
        }
        i++;
    }
    printf("La especialidad medica con mas consulta fue : %s",especialidadMaxima);
    return cantidadTotal;
}

void recorrerListaSecundaria(nodoLista* lista, FILE* archi,int idEspecialidad,char especlaidad[])
{
    stRegistroMedico aux;
    if(archi)
    {
        while(lista)
        {
            aux.idPaciente=lista->persona.idPaciente;
            aux.idRegistro=lista->persona.idRegistro;
            strcpy(aux.apellidoPaciente,lista->persona.apellidoPaciente);
            strcpy(aux.nombrePaciente,lista->persona.nombrePaciente);
            strcpy(aux.diagnostico,lista->persona.diagnostico);
            strcpy(aux.fechaAtencion,lista->persona.fechaAtencion);
            strcpy(aux.nombreDoctor,lista->persona.nombreDoctor);
            fwrite(&aux,sizeof(stRegistroMedico),1,archi);
            lista=lista->siguiente;
        }
    }
}

void pasarAarchivoEspecialidad(stCelda arreglo[], int validos, char especialidad[])
{
    int i = 0;
    while (i < validos)
    {
        if (strcmp(arreglo[i].dato.especialidadMedica, especialidad) == 0)
        {
            char nombreArchivo[50]; // Tamaño suficiente para el nombre del archivo
            sprintf(nombreArchivo, "%s_datos.bin", arreglo[i].dato.especialidadMedica); // Nombre del archivo basado en la especialidad

            FILE *archi = fopen(nombreArchivo, "wb");
            if (archi)
            {
                recorrerListaSecundaria(arreglo[i].listaApunta, archi, arreglo[i].dato.idEspecialidad, especialidad);
                fclose(archi);
                return; // Terminar la función después de escribir el archivo
            }
        }
        i++;
    }
}
void mostrarArchivoEspecialidad(char nombreArchivo[])
{
    stRegistroMedico aux;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&aux,sizeof(stRegistroMedico),1,archi)>0)
        {
            printf("====================================== \n");
            printf("Id registro.............. :%d\n",aux.idRegistro);
            printf("Id Paciente.............. :%d\n",aux.idPaciente);

            printf("Nombre Paciente.......... :%s\n",aux.nombrePaciente);
            printf("Apellido Paciente........ :%s\n",aux.apellidoPaciente);
            printf("Diagnostico ............. :%s\n",aux.diagnostico);
            printf("Fecha de Atencion........ :%s\n",aux.fechaAtencion);

            printf("Nombre doctor............ :%s\n",aux.nombreDoctor);
        }
    }
}
