#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"
#include "informes.h"

int main()
{
    Orquesta orquestas[50];
    orquesta_init(orquestas,50);
    Instrumento instrumentos[20];
    instrumento_init(instrumentos,20);
    Musico musicos[1000];
    musico_init(musicos,1000);

    //Valores hardcodeados para testing
    orquesta_add(orquestas,50,1,"Orquesta1","Lugar1");
    orquesta_add(orquestas,50,2,"Orquesta2","Lugar1");
    orquesta_add(orquestas,50,3,"Orquesta3","Lugar2");
    orquesta_add(orquestas,50,3,"Orquesta4","Lugar3");
    musico_add(musicos,1000,1,1,30,"Mus1","Amus1");
    musico_add(musicos,1000,1,1,35,"Mus2","Amus2");
    musico_add(musicos,1000,1,1,25,"Mus3","Amus3");
    musico_add(musicos,1000,1,1,25,"Mus4","Amus4");
    musico_add(musicos,1000,1,1,25,"Mus5","Amus5");
    musico_add(musicos,1000,1,1,25,"Mus6","Amus6");
    musico_add(musicos,1000,1,2,25,"Mus5","Amus5");
    musico_add(musicos,1000,1,2,25,"Mus5","Amus5");
    musico_add(musicos,1000,1,2,25,"Mus5","Amus5");
    musico_add(musicos,1000,1,2,25,"Mus5","Amus5");
    musico_add(musicos,1000,1,4,25,"Mus5","Amus5");
    musico_add(musicos,1000,1,4,25,"Mus5","Amus5");
    musico_add(musicos,1000,1,4,25,"Mus5","Amus5");
    musico_add(musicos,1000,1,4,25,"Mus5","Amus5");
    musico_add(musicos,1000,1,3,25,"Mus5","Amus5");
    instrumento_add(instrumentos,20,1,"Inst1");
    instrumento_add(instrumentos,20,2,"Inst2");
    instrumento_add(instrumentos,20,2,"Inst3");
    instrumento_add(instrumentos,20,4,"Inst4");
    instrumento_add(instrumentos,20,4,"Inst4");
    //
    //-------------------------------------------

    int option;
    int optionInf;
    int auxInt;
    while(option!=15)
    {
        clrscr();
        printf("1.Agregar orquesta\n2.Eliminar orquesta\n3.Imprimir orquestas\n4.Modificar orquesta\n\
        \n5.Agregar musico\n6.Modificar musico\n7.Eliminar musico\n8.Imprimir musicos\n\
        \n9.Agregar instrumento\n12.Eliminar instrumento\n11.Imprimir instrumento\n12.Modificar instrumento\n13.Salir\n\n14. Informes\n\n15. Salir\n");
        utn_getInt(&option,"\nSeleccione opcion: ","\nOpcion invalida",1,50,10);
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
            orquesta_delete(orquestas,50,auxInt);
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
        case 14:
            while(optionInf!=9)
            {
                clrscr();
                printf("1.Orquestas con mas de 5 musicos\n2.Musicos con edad 30 o mas\n3.Orquestas por lugar\n4.Listar orquestas completas\
                \n5.Listar musicos de una orquesta\n6.Imprimir orquesta con mas musicos\n7.Listar musicos que tocan instrumentos de cuerda\n\
                \n8.Imprimir promedio de musicos por orquesta\n\n9.Salir");
                utn_getInt(&optionInf,"\nSeleccione opcion: ","\nOpcion invalida",1,50,10);
                switch(optionInf)
                {
                case 1:
                    inf_moreThanFive(orquestas,50,musicos,1000);
                    myPause();
                    break;
                case 2:
                    inf_moreThan30Years(musicos,1000);
                    myPause();
                    break;
                case 3:
                    inf_orquestasByLugar(orquestas,50);
                    myPause();
                    break;
                case 4:
                    inf_completeOrquesta(orquestas,50,musicos,1000,instrumentos,20);
                    myPause();
                    break;
                case 5:
                    inf_musicoPorOrquesta(orquestas,50,musicos,1000,instrumentos,20);
                    myPause();
                    break;
                case 6:
                    inf_orquestaMasMusicos(orquestas,50,musicos,1000);
                    myPause();
                    break;
                case 7:
                    inf_listarMusicosCuerdas(musicos,1000,instrumentos,20);
                    myPause();
                    break;
                case 8:
                    myPause();
                    break;
                }
            }
            break;
            case 15:
            printf("Adios.");
            break;
        default:
            printf("Opcion invalida");
            myPause();
        }
    }



    return 0;
}
