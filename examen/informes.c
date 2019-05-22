#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"

int inf_moreThanFive(Orquesta* listOrquesta,int lenOrquesta,Musico* listMusico,int lenMusico)
{
    int ret= -1;
    int countMusico;
    int auxIdOrquesta=0;
    int auxIdMusico=0;
    if(listMusico!=NULL && listOrquesta!=NULL && lenMusico>=0 && lenOrquesta>=0)
    {
        for(auxIdOrquesta=0;auxIdOrquesta<lenOrquesta;auxIdOrquesta++)
        {
            if(listOrquesta[auxIdOrquesta].isEmpty==0)
            {
                countMusico=0;
                for(auxIdMusico=0;auxIdMusico<lenMusico;auxIdMusico++)
                {
                    if(listMusico[auxIdMusico].fkOrquesta==listOrquesta[auxIdOrquesta].id)
                    {
                        countMusico++;
                    }
                }
                if(countMusico>5)
                {
                    orquesta_printByIndex(listOrquesta,auxIdOrquesta);
                }
            }

        }
        ret=0;
    }
    return ret;
}

int inf_moreThan30Years(Musico* list,int len)
{
    int i;
    int ret= -1;
    if(list!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].Edad>=30)
            {
                musico_printByIndex(list,i);
            }
        }
        ret=0;
    }
    return ret;
}

int inf_orquestasByLugar(Orquesta* list,int len)
{
    int i;
    int ret= -1;
    char auxLugar[100];
    if(list!=NULL && len>=0)
    {
        utn_getString(auxLugar,"Ingrese lugar: ","Error",1,100,10);
        for(i=0;i<len;i++)
        {
            if(!strcmp(list[i].Lugar,auxLugar))
            {
                orquesta_printByIndex(list,i);
            }
        }
        ret=0;
    }
    return ret;
}

int inf_completeOrquesta(Orquesta* listOrquesta,int lenOrquesta,Musico* listMusico,int lenMusico,Instrumento* listInstrumento,int lenInstrumento)
{
    int ret= -1;
    int countCuerdas;
    int countViento;
    int countPercusion;
    int auxIdOrquesta=0;
    int auxIdMusico=0;
    int auxIdInstrumento=0;
    int auxInBusqueda;
    if(listMusico!=NULL && listOrquesta!=NULL && lenMusico>=0 && lenOrquesta>=0)
    {
        for(auxIdOrquesta=0;auxIdOrquesta<lenOrquesta;auxIdOrquesta++)
        {
            countCuerdas=0;
            countPercusion=0;
            countViento=0;
            if(listOrquesta[auxIdOrquesta].isEmpty==0)
            {
                for(auxIdMusico=0;auxIdMusico<lenMusico;auxIdMusico++)
                {
                    auxInBusqueda=listMusico[auxIdMusico].fkInstrumento;
                    auxIdInstrumento=instrumento_searchById(listInstrumento,lenInstrumento,auxInBusqueda);

                    if(listMusico[auxIdMusico].fkOrquesta==listOrquesta[auxIdOrquesta].id&&listInstrumento[auxIdInstrumento].Tipo==1)
                    {
                        countCuerdas++;
                    }
                    else if(listMusico[auxIdMusico].fkOrquesta==listOrquesta[auxIdOrquesta].id&&(listInstrumento[auxIdInstrumento].Tipo==2||listInstrumento[auxIdInstrumento].Tipo==3))
                    {
                        countViento++;
                    }
                    else if(listMusico[auxIdMusico].fkOrquesta==listOrquesta[auxIdOrquesta].id&&listInstrumento[auxIdInstrumento].Tipo==4)
                    {
                        countPercusion++;
                    }
                }
                if(countCuerdas>=5&&countViento>=3&&countPercusion>=2)
                {
                    orquesta_printByIndex(listOrquesta,auxIdOrquesta);
                }
            }

        }
        ret=0;
    }
    return ret;
}

int inf_musicoPorOrquesta(Orquesta* listOrquesta,int lenOrquesta,Musico* listMusico,int lenMusico,Instrumento* listInstrumento,int lenInstrumento)
{
    int indiceMusico;
    int indiceOrquesta;
    int indiceInstrumento;
    int idIngresado;
    utn_getInt(&idIngresado,"Ingrese id de la orquesta: ","Error",0,99999,10);
    indiceOrquesta=orquesta_searchById(listOrquesta,lenOrquesta,idIngresado);
    if(indiceOrquesta>=0)
    {
        for(indiceMusico=0;indiceMusico<lenMusico;indiceMusico++)
        {
            if(listMusico[indiceMusico].fkOrquesta==idIngresado)
            {
                musico_printByIndex(listMusico,indiceMusico);
                indiceInstrumento=instrumento_searchById(listInstrumento,lenInstrumento,(listMusico[indiceMusico].fkInstrumento));
                instrumento_printByIndex(listInstrumento,indiceInstrumento);
            }
        }
    }
    return 0;
}

int inf_orquestaMasMusicos(Orquesta* listOrquesta,int lenOrquesta,Musico* listMusico,int lenMusico)
{
    int ret= -1;
    int countMusico;
    int countMusicoMax=-1;
    int idOrquestaMax;
    int auxIdOrquesta=0;
    int auxIdMusico=0;
    if(listMusico!=NULL && listOrquesta!=NULL && lenMusico>=0 && lenOrquesta>=0)
    {
        for(auxIdOrquesta=0;auxIdOrquesta<lenOrquesta;auxIdOrquesta++)
        {
            if(listOrquesta[auxIdOrquesta].isEmpty==0)
            {
                countMusico=0;
                for(auxIdMusico=0;auxIdMusico<lenMusico;auxIdMusico++)
                {
                    if(listMusico[auxIdMusico].fkOrquesta==listOrquesta[auxIdOrquesta].id)
                    {
                        countMusico++;
                    }
                }
                if(countMusico>countMusicoMax)
                {
                    countMusicoMax=countMusico;
                    idOrquestaMax=auxIdOrquesta;
                }
            }

        }
        orquesta_printByIndex(listOrquesta,idOrquestaMax);
        printf("Cantidad de musicos %d/n",countMusicoMax);
        ret=0;
    }
    return ret;
}
