#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int option;
    int auxInt;
    while(option!=13)
    {
        printf("\n1.Agregar orquesta\n2.Eliminar orquesta\n3.Imprimir orquestas\n4.Modificar orquesta\
        \n5.Agregar musico\n6.Modificar musico\n7.Eliminar musico\n8.Imprimir musicos\
        \n9.Agregar instrumento\n12.Eliminar instrumento\n11.Imprimir instrumento\n12.Modificar instrumento\n13.Salir\n");
        utn_getInt(&option,"\nSeleccione opcion: ","\nOpcion invalida",1,13,10);
        switch(option)
        {
        case 1:
            orquesta_new(orquestas,50);
            break;
        case 2:
            utn_getInt(&auxInt,"\nIngrese ID: ","\nError",1,9999,10);
            if(orquesta_searchById(orquestas,50,auxInt)<0)
            {
                printf("No existe el ID");
                break;
            }
            orquesta_delete(orquestas,50,auxInt);
            break;
        case 3:
            orquesta_printAll(orquestas,50);
            break;
        case 4:
            orquesta_modMenu(orquestas,50);
            break;
        case 5:
            musico_new(musicos,1000);
            break;
        case 6:
            musico_modMenu(musicos,1000);
            break;
        case 7:
            utn_getInt(&auxInt,"\nIngrese ID: ","\nError",1,9999,10);
            if(musico_searchById(musicos,1000,auxInt)<0)
            {
                printf("No existe el ID");
                break;
            }
            musico_delete(musicos,1000,auxInt);
            break;
        case 8:
            musico_printAll(musicos,1000);
            break;
        case 9:
            instrumento_new(instrumentos,20);
            break;
        case 10:
            utn_getInt(&auxInt,"\nIngrese ID: ","\nError",1,9999,10);
            if(instrumento_searchById(instrumentos,20,auxInt)<0)
            {
                printf("No existe el ID");
                break;
            }
            instrumento_delete(instrumentos,20,auxInt);
            break;
        case 11:
            instrumento_printAll(instrumentos,20);
            break;
        case 12:
            instrumento_modMenu(instrumentos,20);
            break;
        default:
            printf("Opcion invalida");
        }
    }



    return 0;
}
