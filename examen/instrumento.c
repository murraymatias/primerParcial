#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "instrumento.h"

static int autoId(void)
{
    static int id=0;
    return id++;
}

static int instrumento_freePosition(Instrumento* list,int len)
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
 * \param list Instrumento* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int instrumento_init(Instrumento* list,int len)
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

/** \brief add in a existing list of Instrumento the values received as parameters
 * in the first empty position
 * \param list Instrumento*
 * \param len int
 * \param Tipo int
 * \param Nombre char*
 * \param Lugar char*
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int instrumento_add(  Instrumento* list,
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
        i=instrumento_freePosition(list,len);
        if(i>=0)
        {
            list[i].id=id;
            list[i].isEmpty=0;
            list[i].Tipo=Tipo;
            strcpy(list[i].Nombre,Nombre);
            printf("\nAgregado");
            instrumento_printByIndex(list,i);
            ret=0;
        }
    }
    return ret;
}

/** \brief request to the users the information for a new Instrumento
 *
 * \param list Instrumento*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int instrumento_new(Instrumento* list,int len)
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
            instrumento_add(list,len,
                      bufferTipo,
                      bufferNombre,
                      bufferLugar);
            ret=0;
        }
    }
    return ret;
}

/** \brief print one position of Instrumento array
 *
 * \param list Instrumento*
 * \param length int
 * \param index int
 * \return void
 *
 */
void instrumento_printByIndex(Instrumento list[],int index)
{

    printf("\nId: %d\
            \n1.Tipo: %d\
            \n2.Nombre: %s\n",
            list[index].id,
            list[index].Tipo,
            list[index].Nombre);
    return;
}

/** \brief print the content of Instrumento array
 *
 * \param list Instrumento*
 * \param length int
 * \return void
 *
 */
void instrumento_printAll(Instrumento* list,int len)
{
    int i;
    if(list!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                instrumento_printByIndex(list,i);
            }
        }
    }
    return;
}

/** \brief Request an id and deletes the register.
 *
 * \param list Instrumento*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int instrumento_delete(Instrumento* list,int len,int id)
{
    int ret= -1;
    if(list!=NULL && len>=0)
    {
        list[id].id=-1;
        list[id].isEmpty=1;
        list[id].Tipo=-1;
        strcpy(list[id].Nombre,"");
        ret=0;
    }
    return ret;
}

/** \brief Request an id and permits modify his parameters.
 *
 * \param list Instrumento*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int instrumento_modMenu(Instrumento *list,int len)
{
    int ret=-1;
    int i;
    int auxId;
    int option;
    int bufferTipo;
    char bufferNombre[50];
    utn_getInt(&auxId,"\nIngrese id: ","\nValor invalido",0,999999,10);
    i=instrumento_searchById(list,len,auxId);
    if(i>=0)
    {

        while(option!=4)
        {
            instrumento_printByIndex(list,i);
            printf("3. Salir");
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

/** \brief find an Instrumento by Id en returns the index position in array.
 *
 * \param list Instrumento*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int instrumento_searchById(Instrumento* list,int len,int id)
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

/** \brief find an Instrumento by Tipo and returns the index position in array.
 *
 * \param list Instrumento*
 * \param len int
 * \param Tipo int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int instrumento_searchByTipo(Instrumento* list,int len,int Tipo)
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

/** \brief find an Instrumento by Nombre and returns the index position in array.
 *
 * \param list Instrumento*
 * \param len int
 * \param Nombre char*
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int instrumento_searchByNombre(Instrumento* list,int len,char* Nombre)
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

/** \brief swap two positions in an array of Instrumento datatype
 *
 * \param list Instrumento*
 * \param index int
 * \return void
 *
 */
void instrumento_swap(Instrumento* list,int i)
{
    Instrumento buffer1;
    Instrumento buffer2;
    buffer1=list[i];
    buffer2=list[i+1];
    list[i]=buffer2;
    list[i+1]=buffer1;
    return;
}

/** \brief Sort the elements in the array of Instrumento, the argument order indicate UP or DOWN order
 *
 * \param list Instrumento*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int instrumento_sortById(Instrumento* list, int len, int order)
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
                    instrumento_swap(list,i);
                    swap=1;
                }
                if(order==1 && list[i].id>list[i+1].id)
                {
                    instrumento_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of Instrumento, the argument order indicate UP or DOWN order
 *
 * \param list Instrumento*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int instrumento_sortByTipo(Instrumento* list, int len, int order)
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
                    instrumento_swap(list,i);
                    swap=1;
                }
                if(order==1 && list[i].Tipo>list[i+1].Tipo)
                {
                    instrumento_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of Instrumento, the argument order indicate UP or DOWN order
 *
 * \param list Instrumento*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int instrumento_sortByNombre(Instrumento* list, int len, int order)
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
                    instrumento_swap(list,i);
                    swap=1;
                }
                if(order==1 && strcmp(list[i].Nombre,list[i+1].Nombre)>0)
                {
                    instrumento_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}
