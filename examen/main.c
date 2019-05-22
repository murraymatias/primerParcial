#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"

int main()
{
    Orquesta orquestas[50];
    orquesta_init(orquestas,50);
    Instrumento instrumentos[20];
    instrumento_init(instrumentos,20);
    Musico musicos[1000];
    musico_init(musicos,1000);

    //Valores hardcodeados para testing
    orquesta_add(orquestas,50,1,"Orquesta1","lugarorquesta1");
    orquesta_add(orquestas,50,3,"Orquesta2","lugarorquesta2");
    orquesta_add(orquestas,50,1,"Orquesta3","lugarorquesta3");
    orquesta_add(orquestas,50,2,"Orquesta4","lugarorquesta4");
    musico_add(musicos,1000,4,1,25,"Wanda","Lewis");
    musico_add(musicos,1000,1,1,45,"Connor","Edmunds");
    musico_add(musicos,1000,2,4,18,"Ava","Ince");
    musico_add(musicos,1000,3,2,36,"Heather","Langdon");
    instrumento_add(instrumentos,20,1,"Gitarra");
    instrumento_add(instrumentos,20,4,"Piano");
    instrumento_add(instrumentos,20,2,"Bateria");
    instrumento_add(instrumentos,20,3,"Theremin");
    //
    //-------------------------------------------

    int option;
    int auxInt;
    while(option!=13)
    {
        clrscr();
        printf("1.Agregar orquesta\n2.Eliminar orquesta\n3.Imprimir orquestas\n4.Modificar orquesta\n\
        \n5.Agregar musico\n6.Modificar musico\n7.Eliminar musico\n8.Imprimir musicos\n\
        \n9.Agregar instrumento\n12.Eliminar instrumento\n11.Imprimir instrumento\n12.Modificar instrumento\n13.Salir\n");
        utn_getInt(&option,"\nSeleccione opcion: ","\nOpcion invalida",1,13,10);
        switch(option)
        {
        case 1:
            orquesta_new(orquestas,50);
            myPause();
            break;
        case 2:
            utn_getInt(&auxInt,"\nIngrese ID: ","\nError",1,9999,10);
            if(orquesta_searchById(orquestas,50,auxInt)<0)
            {
                printf("No existe el ID");
                myPause();
                break;
            }
            orquesta_delete(orquestas,50,auxInt,musicos,1000);
            printf("Eliminado.");
            myPause();
            break;
        case 3:
            orquesta_printAll(orquestas,50);
            myPause();
            break;
        case 4:
            orquesta_modMenu(orquestas,50);
            myPause();
            break;
        case 5:
            musico_new(musicos,1000,orquestas,50,instrumentos,20);
            myPause();
            break;
        case 6:
            musico_modMenu(musicos,1000,orquestas,50,instrumentos,20);
            myPause();
            break;
        case 7:
            utn_getInt(&auxInt,"\nIngrese ID: ","\nError",1,9999,10);
            if(musico_searchById(musicos,1000,auxInt)<0)
            {
                printf("No existe el ID");
                myPause();
                break;
            }
            musico_delete(musicos,1000,auxInt);
            printf("Eliminado.");
            myPause();
            break;
        case 8:
            musico_printAll(musicos,1000);
            myPause();
            break;
        case 9:
            instrumento_new(instrumentos,20);
            myPause();
            break;
        case 10:
            utn_getInt(&auxInt,"\nIngrese ID: ","\nError",1,9999,10);
            if(instrumento_searchById(instrumentos,20,auxInt)<0)
            {
                printf("No existe el ID");
                myPause();
                break;
            }
            instrumento_delete(instrumentos,20,auxInt);
            printf("Eliminado.");
            myPause();
            break;
        case 11:
            instrumento_printAll(instrumentos,20);
            myPause();
            break;
        case 12:
            instrumento_modMenu(instrumentos,20);
            myPause();
            break;
        case 13:
            printf("Adios");
            myPause();
            break;
        default:
            printf("Opcion invalida");
            myPause();
        }
    }



    return 0;
}
