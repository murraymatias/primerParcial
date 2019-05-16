#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"

static int autoId(void)
{
    static int id=0;
    return id++;
}

static int orquesta_freePosition(Orquesta* list,int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Orquesta* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int orquesta_init(Orquesta* list,int len)
{
    int i;
    int ret= -1;
    if(list!=NULL && len>=0)
    {
        for(i=0; i<len; i++)
        {
            list[i].id=-1;
            list[i].isEmpty=1;
            list[i].Tipo=-1;
            strcpy(list[i].Nombre,"");
        }
        ret=0;
    }
    return ret;
}

/** \brief add in a existing list of Orquesta the values received as parameters
 * in the first empty position
 * \param list Orquesta*
 * \param len int
 * \param Tipo int
 * \param Nombre char*
 * \param Lugar char*
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int orquesta_add(  Orquesta* list,
                int len,
                int Tipo,
                char* Nombre,
                char* Lugar)
{
    int i;
    int id;
    int ret=-1;
    if(list!=NULL && len>=0)
    {
        id=autoId();
        i=orquesta_freePosition(list,len);
        if(i>=0)
        {
            list[i].id=id;
            list[i].isEmpty=0;
            list[i].Tipo=Tipo;
            strcpy(list[i].Nombre,Nombre);
            strcpy(list[i].Lugar,Lugar);
            printf("\nAgregado");
            orquesta_printByIndex(list,i);
            ret=0;
        }
    }
    return ret;
}

/** \brief request to the users the information for a new Orquesta
 *
 * \param list Orquesta*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int orquesta_new(Orquesta* list,int len)
{
    int ret= -1;
    int bufferTipo;
    char bufferNombre[50];
    char bufferLugar[255];

    if(list!=NULL && len>0)
    {
        if(
        !utn_getInt(&bufferTipo,"Ingrese Tipo: ","Valor invalido",1,999,10)&&
        !utn_getName(bufferNombre,50,"Ingrese Nombre: ","Valor invalido",1,50,10)&&
        !utn_getAddress(bufferLugar,255,"Ingrese Lugar: ","Valor invalido",1,255,10))
        {
            orquesta_add(list,len,
                      bufferTipo,
                      bufferNombre,
                      bufferLugar);
            ret=0;
        }
    }
    return ret;
}

/** \brief print one position of Orquesta array
 *
 * \param list Orquesta*
 * \param length int
 * \param index int
 * \return void
 *
 */
void orquesta_printByIndex(Orquesta list[],int index)
{

    printf("\n1.Id: %d\
            \n2.Tipo: %d\
            \n3.Nombre: %s\
            \n4.Lugar: %s\n",
            list[index].id,
            list[index].Tipo,
            list[index].Nombre,
            list[index].Lugar);
    return;
}

/** \brief print the content of Orquesta array
 *
 * \param list Orquesta*
 * \param length int
 * \return void
 *
 */
void orquesta_printAll(Orquesta* list,int len)
{
    int i;
    if(list!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                orquesta_printByIndex(list,i);
            }
        }
    }
    return;
}

/** \brief Request an id and deletes the register.
 *
 * \param list Orquesta*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int orquesta_delete(Orquesta* list,int len,int id)
{
    int ret= -1;
    if(list!=NULL && len>=0)
    {
        list[id].id=-1;
        list[id].isEmpty=1;
        list[id].Tipo=-1;
        strcpy(list[id].Nombre,""),
        strcpy(list[id].Lugar,"");
        ret=0;
    }
    return ret;
}

/** \brief Request an id and permits modify his parameters.
 *
 * \param list Orquesta*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int orquesta_modMenu(Orquesta *list,int len)
{
    int ret=-1;
    int i;
    int auxId;
    int option;
    int bufferTipo;
    char bufferNombre[50];
    char bufferLugar[255];
    utn_getInt(&auxId,"\nIngrese id: ","\nValor invalido",0,999999,10);
    i=orquesta_searchById(list,len,auxId);
    if(i>=0)
    {

        while(option!=4)
        {
            orquesta_printAll(list,len);
            printf("4. Salir");
            utn_getInt(&option,"\nSeleccione campo a modificar: ","\nOpcion invalida",1,4,10);
            switch(option)
            {
            case 1:
                if(!utn_getInt(&bufferTipo,"Ingrese Tipo","Valor invalido",1,999,10))
                    list[i].Tipo=bufferTipo;
                break;
            case 2:
                if(!utn_getString(bufferNombre,"Ingrese Nombre","Valor invalido",1,50,10))
                    strcpy(list[i].Nombre,bufferNombre);
                break;
            case 3:
                if(!utn_getString(bufferLugar,"Ingrese Lugar","Valor invalido",1,255,10))
                    strcpy(list[i].Lugar,bufferLugar);
                break;

            }
        }
        ret=0;
    }
    else
    {
        printf("\nId invalido");
    }
    return ret;
}

/** \brief find an Orquesta by Id en returns the index position in array.
 *
 * \param list Orquesta*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int orquesta_searchById(Orquesta* list,int len,int id)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].id==id&&list[i].isEmpty==0)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief find an Orquesta by Tipo and returns the index position in array.
 *
 * \param list Orquesta*
 * \param len int
 * \param Tipo int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int orquesta_searchByTipo(Orquesta* list,int len,int Tipo)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].Tipo==Tipo)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief find an Orquesta by Nombre and returns the index position in array.
 *
 * \param list Orquesta*
 * \param len int
 * \param Nombre char*
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int orquesta_searchByNombre(Orquesta* list,int len,char* Nombre)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(!strcmp(list[i].Nombre,Nombre))
        {
            ret=i;
            break;
        }
    }
    return ret;
}
/** \brief find an Orquesta by Lugar and returns the index position in array.
 *
 * \param list Orquesta*
 * \param len int
 * \param Lugar char*
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int orquesta_searchByLugar(Orquesta* list,int len,char* Lugar)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(!strcmp(list[i].Lugar,Lugar))
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief swap two positions in an array of Orquesta datatype
 *
 * \param list Orquesta*
 * \param index int
 * \return void
 *
 */
void orquesta_swap(Orquesta* list,int i)
{
    Orquesta buffer1;
    Orquesta buffer2;
    buffer1=list[i];
    buffer2=list[i+1];
    list[i]=buffer2;
    list[i+1]=buffer1;
    return;
}

/** \brief Sort the elements in the array of Orquesta, the argument order indicate UP or DOWN order
 *
 * \param list Orquesta*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int orquesta_sortById(Orquesta* list, int len, int order)
{
    int i;
    int swap;
    int ret= -1;
    if(list!=NULL && len>0 && (order==0 || order==1))
    {
        do
        {
            swap=0;
            for(i=0;i<len-1;i++)
            {
                if(order==0 && list[i].id<list[i+1].id)
                {
                    orquesta_swap(list,i);
                    swap=1;
                }
                if(order==1 && list[i].id>list[i+1].id)
                {
                    orquesta_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of Orquesta, the argument order indicate UP or DOWN order
 *
 * \param list Orquesta*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int orquesta_sortByTipo(Orquesta* list, int len, int order)
{
    int i;
    int swap;
    int ret= -1;
    if(list!=NULL && len>0 && (order==0 || order==1))
    {
        do
        {
            swap=0;
            for(i=0;i<len-1;i++)
            {
                if(order==0 && list[i].Tipo<list[i+1].Tipo)
                {
                    orquesta_swap(list,i);
                    swap=1;
                }
                if(order==1 && list[i].Tipo>list[i+1].Tipo)
                {
                    orquesta_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of Orquesta, the argument order indicate UP or DOWN order
 *
 * \param list Orquesta*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int orquesta_sortByNombre(Orquesta* list, int len, int order)
{
    int i;
    int swap;
    int ret= -1;
    if(list!=NULL && len>0 && (order==0 || order==1))
    {
        do
        {
            swap=0;
            for(i=0;i<len-1;i++)
            {
                if(order==0 && strcmp(list[i].Nombre,list[i+1].Nombre)<0)
                {
                    orquesta_swap(list,i);
                    swap=1;
                }
                if(order==1 && strcmp(list[i].Nombre,list[i+1].Nombre)>0)
                {
                    orquesta_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of Orquesta, the argument order indicate UP or DOWN order
 *
 * \param list Orquesta*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int orquesta_sortByLugar(Orquesta* list, int len, int order)
{
    int i;
    int swap;
    int ret= -1;
    if(list!=NULL && len>0 && (order==0 || order==1))
    {
        do
        {
            swap=0;
            for(i=0;i<len-1;i++)
            {
                if(order==0 && strcmp(list[i].Lugar,list[i+1].Lugar)<0)
                {
                    orquesta_swap(list,i);
                    swap=1;
                }
                if(order==1 && strcmp(list[i].Lugar,list[i+1].Lugar)>0)
                {
                    orquesta_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}
