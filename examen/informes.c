#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "instrumento.h"
#include "orquesta.h"
#include "musico.h"

/** \brief Imprime por consola las orquestas que poseen mas de 5 musicos
 * \param listOrquesta Orquesta* Puntero al array de orquestas
 * \param lenOrquesta int Tamaño array de orquestas
 * \param listMusico Musico* Puntero al array de musicos
 * \param lenOrquesta int Tamaño array de musicos
 * \return int Return (-1) si Error [Largo invalido o puntero NULL] - (0) si Ok
 *
 */
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

/** \brief Imprime por consola los musicos mayores a 30 años
 * \param list Musico* Puntero al array de musicos
 * \param len int Tamaño array de musicos
 * \return int Return (-1) si Error [Largo invalido o puntero NULL] - (0) si Ok
 *
 */
int inf_moreThan30Years(Musico* list,int len)
{
    int i;
    int ret= -1;
    if(list!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].Edad>30)
            {
                musico_printByIndex(list,i);
            }
        }
        ret=0;
    }
    return ret;
}

/** \brief Imprime por consola las orquestas que correspondan a un lugar ingresado por el usuario
 * \param list Orquesta* Puntero al array de orquestas
 * \param len int Tamaño array de orquestas
 * \return int Return (-1) si Error [Largo invalido o puntero NULL] - (0) si Ok
 *
 */
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

/** \brief Imprime por consola las orquestas que esten completas
 * \param listOrquesta Orquesta* Puntero al array de orquestas
 * \param lenOrquesta int Tamaño array de orquestas
 * \param listMusico Musico* Puntero al array de musicos
 * \param lenOrquesta int Tamaño array de musicos
 * \param listInstrumento Instrumento* Puntero al array de instrumentos
 * \param lenInstrumento int Tamaño array de instrumentos
 * \return int Return (-1) si Error [Largo invalido o puntero NULL] - (0) si Ok
 *
 */
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

/** \brief Imprime por consola los musicos y el instrumento que tocan insgresando la orquesta a la que pertenecen
 * \param listOrquesta Orquesta* Puntero al array de orquestas
 * \param lenOrquesta int Tamaño array de orquestas
 * \param listMusico Musico* Puntero al array de musicos
 * \param lenOrquesta int Tamaño array de musicos
 * \param listInstrumento Instrumento* Puntero al array de instrumentos
 * \param lenInstrumento int Tamaño array de instrumentos
 * \return int Return (-1) si Error [Largo invalido o puntero NULL] - (0) si Ok
 *
 */
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
                instrumento_printByIndexNoId(listInstrumento,indiceInstrumento);
            }
        }
    }
    return 0;
}

/** \brief Imprime por consola la orquesta con mayor cantidad de musicos
 * \param listOrquesta Orquesta* Puntero al array de orquestas
 * \param lenOrquesta int Tamaño array de orquestas
 * \param listMusico Musico* Puntero al array de musicos
 * \param lenMusico int Tamaño array de musicos
 * \return int Return (-1) si Error [Largo invalido o puntero NULL] - (0) si Ok
 *
 */
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

/** \brief Imprime por consola los musicos que tocan instrumentos de cuerda
 * \param listMusico Musico* Puntero al array de musicos
 * \param lenMusico int Tamaño array de musicos
 * \param listInstrumento Instrumento* Puntero al array de instrumentos
 * \param lenInstrumentos int Tamaño array de instrumentos
 * \return int Return (-1) si Error [Largo invalido o puntero NULL] - (0) si Ok
 *
 */
int inf_listarMusicosCuerdas(Musico* listMusico,int lenMusico,Instrumento* listInstrumento, int lenInstrumento)
{
    int i;
    int ret= -1;
    int indiceInstrumento;
    musico_sortByApellido(listMusico,lenMusico,1);
    if(listMusico!=NULL && lenMusico>=0 && listInstrumento!=NULL && lenInstrumento>=0)
    {
        for(i=0;i<lenMusico;i++)
        {
            indiceInstrumento=instrumento_searchById(listInstrumento,lenInstrumento,listMusico[i].fkInstrumento);
            if(listInstrumento[indiceInstrumento].Tipo==1)
            {
                musico_printByIndex(listMusico,i);
                instrumento_printByIndexTipo(listInstrumento,indiceInstrumento);
            }
        }
        ret=0;
    }
    return ret;
}

