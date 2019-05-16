#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"

int main()
{
    Orquesta orquestas[50];
    orquesta_init(orquestas,50);
    int option;
    int auxInt;
    while(option!=20)
    {
        printf("\n1.Agregar orquesta\n2.Eliminar orquesta\n3.Imprimir orquestas");
        utn_getInt(&option,"\nSeleccione opcion: ","\nError",1,50,10);
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
        default:
            printf("Opcion invalida");
        }
    }



    return 0;
}
