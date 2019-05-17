#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"

static int autoId(void)
{
    static int id=0;
    return id++;
}

static int musico_freePosition(Musico* list,int len)
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
 * \param list Musico* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int musico_init(Musico* list,int len)
{
    int i;
    int ret= -1;
    if(list!=NULL && len>=0)
    {
        for(i=0; i<len; i++)
        {
            list[i].id=-1;
            list[i].isEmpty=1;
            list[i].Edad=-1;
            strcpy(list[i].Nombre,"");
            strcpy(list[i].Apellido,"");
            list[i].fkOrquesta=-1;
            list[i].fkInstrumento=-1;
        }
        ret=0;
    }
    return ret;
}

/** \brief add in a existing list of Musico the values received as parameters
 * in the first empty position
 * \param list Musico*
 * \param len int
 * \param fkOrquesta int
 * \param fkInstrumento int
 * \param FKeyField3 int
 * \param Edad int
 * \param IntField2 int
 * \param IntField3 int
 * \param FloatField1 float
 * \param FloatField2 float
 * \param FloatField3 float
 * \param CharField1 char
 * \param CharField2 char
 * \param CharField3 char
 * \param Nombre char*
 * \param Apellido char*
 * \param StringField3 char*
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int musico_add(  Musico* list,
                int len,
                int fkOrquesta,
                int fkInstrumento,
                int Edad,
                char* Nombre,
                char* Apellido)
{
    int i;
    int id;
    int ret=-1;
    if(list!=NULL && len>=0)
    {
        id=autoId();
        i=musico_freePosition(list,len);
        if(i>=0)
        {
            list[i].id=id;
            list[i].fkOrquesta=fkOrquesta;
            list[i].fkInstrumento=fkInstrumento;
            list[i].Edad=Edad;
            strcpy(list[i].Nombre,Nombre);
            strcpy(list[i].Apellido,Apellido);
            ret=0;
        }
    }
    return ret;
}

/** \brief request to the users the information for a new Musico
 *
 * \param list Musico*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int musico_new(Musico* list,int len)
{
    int ret= -1;
    int bufferfkOrquesta;
    int bufferfkInstrumento;
    int bufferEdad;
    char bufferNombre[255];
    char bufferApellido[255];

    if(list!=NULL && len>0)
    {
        if(
        !utn_getInt(&bufferfkOrquesta,"Ingrese fkOrquesta","Valor invalido",1,50,10)&&
        !utn_getInt(&bufferfkInstrumento,"Ingrese fkInstrumento","Valor invalido",1,50,10)&&
        !utn_getInt(&bufferEdad,"Ingrese Edad","Valor invalido",1,50,10)&&
        !utn_getString(bufferNombre,"Ingrese Nombre","Valor invalido",1,255,10)&&
        !utn_getString(bufferApellido,"Ingrese Apellido","Valor invalido",1,255,10))
        {
            musico_add(list,len,
                      bufferfkOrquesta,
                      bufferfkInstrumento,
                      bufferEdad,
                      bufferNombre,
                      bufferApellido);
            ret=0;
        }
    }
    return ret;
}

/** \brief print one position of Musico array
 *
 * \param list Musico*
 * \param length int
 * \param index int
 * \return void
 *
 */
void musico_printByIndex(Musico list[],int index)
{

    printf("\nId: %d\
            \nfkOrquesta: %d\
            \nfkInstrumento: %d\
            \nEdad: %d\
            \nNombre: %s\
            \nApellido: %s",
            list[index].id,
            list[index].fkOrquesta,
            list[index].fkInstrumento,
            list[index].Edad,
            list[index].Nombre,
            list[index].Apellido);
    return;
}

/** \brief print the content of Musico array
 *
 * \param list Musico*
 * \param length int
 * \return void
 *
 */
void musico_printAll(Musico* list,int len)
{
    int i;
    if(list!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(!list[i].isEmpty)
            {
                musico_printByIndex(list,i);
            }
        }
    }
    return;
}

/** \brief Request an id and deletes the register.
 *
 * \param list Musico*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int musico_delete(Musico* list,int len,int id)
{
    int ret= -1;
    if(list!=NULL && len>=0)
    {
        list[id].id=-1;
        list[id].isEmpty=1;
        list[id].Edad=-1;
        strcpy(list[id].Nombre,"");
        strcpy(list[id].Apellido,"");
        list[id].fkOrquesta=-1;
        list[id].fkInstrumento=-1;
        ret=0;
    }
    return ret;
}

/** \brief Request an id and permits modify his parameters.
 *
 * \param list Musico*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int musico_modMenu(Musico *list,int len)
{
    int ret=-1;
    int i;
    int auxId;
    int option;
    int bufferfkOrquesta;
    int bufferfkInstrumento;
    int bufferEdad;
    char bufferNombre[255];
    char bufferApellido[255];
    utn_getInt(&auxId,"\nIngrese id: ","\nValor invalido",0,999999,10);
    i=musico_searchById(list,len,auxId);
    if(i>=0)
    {

        while(option!=16)
        {
            musico_printAll(list,len);
            printf("16. Salir");
            utn_getInt(&option,"\nSeleccione campo a modificar: ","\nOpcion invalida",1,16,10);
            switch(option)
            {
            case 1:
                if(!utn_getInt(&bufferfkOrquesta,"Ingrese fkOrquesta","Valor invalido",1,50,10))
                    list[i].fkOrquesta=bufferfkOrquesta;
                break;
            case 2:
                if(!utn_getInt(&bufferfkInstrumento,"Ingrese fkInstrumento","Valor invalido",1,50,10))
                    list[i].fkInstrumento=bufferfkInstrumento;
                break;
            case 4:
                if(!utn_getInt(&bufferEdad,"Ingrese Edad","Valor invalido",1,50,10))
                    list[i].Edad=bufferEdad;
                break;
            case 13:
                if(!utn_getString(bufferNombre,"Ingrese Nombre","Valor invalido",1,255,10))
                    strcpy(list[i].Nombre,bufferNombre);
                break;
            case 14:
                if(!utn_getString(bufferApellido,"Ingrese Apellido","Valor invalido",1,255,10))
                    strcpy(list[i].Apellido,bufferApellido);
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

/** \brief find an Musico by Id en returns the index position in array.
 *
 * \param list Musico*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int musico_searchById(Musico* list,int len,int id)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].id==id)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief find an Musico by fkOrquesta and returns the index position in array.
 *
 * \param list Musico*
 * \param len int
 * \param fkOrquesta int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int musico_searchByfkOrquesta(Musico* list,int len,int fkOrquesta)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].fkOrquesta==fkOrquesta)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief find an Musico by fkInstrumento and returns the index position in array.
 *
 * \param list Musico*
 * \param len int
 * \param fkInstrumento int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int musico_searchByfkInstrumento(Musico* list,int len,int fkInstrumento)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].fkInstrumento==fkInstrumento)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief find an Musico by Edad and returns the index position in array.
 *
 * \param list Musico*
 * \param len int
 * \param Edad int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int musico_searchByEdad(Musico* list,int len,int Edad)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].Edad==Edad)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief find an Musico by Nombre and returns the index position in array.
 *
 * \param list Musico*
 * \param len int
 * \param Nombre char*
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int musico_searchByNombre(Musico* list,int len,char* Nombre)
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

/** \brief find an Musico by Apellido and returns the index position in array.
 *
 * \param list Musico*
 * \param len int
 * \param Apellido char*
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int musico_searchByApellido(Musico* list,int len,char* Apellido)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(!strcmp(list[i].Apellido,Apellido))
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief swap two positions in an array of Musico datatype
 *
 * \param list Musico*
 * \param index int
 * \return void
 *
 */
void musico_swap(Musico* list,int i)
{
    Musico buffer1;
    Musico buffer2;
    buffer1=list[i];
    buffer2=list[i+1];
    list[i]=buffer2;
    list[i+1]=buffer1;
    return;
}

/** \brief Sort the elements in the array of Musico, the argument order indicate UP or DOWN order
 *
 * \param list Musico*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int musico_sortById(Musico* list, int len, int order)
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
                    musico_swap(list,i);
                    swap=1;
                }
                if(order==1 && list[i].id>list[i+1].id)
                {
                    musico_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of Musico, the argument order indicate UP or DOWN order
 *
 * \param list Musico*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int musico_sortByfkOrquesta(Musico* list, int len, int order)
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
                if(order==0 && list[i].fkOrquesta<list[i+1].fkOrquesta)
                {
                    musico_swap(list,i);
                    swap=1;
                }
                if(order==1 && list[i].fkOrquesta>list[i+1].fkOrquesta)
                {
                    musico_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of Musico, the argument order indicate UP or DOWN order
 *
 * \param list Musico*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int musico_sortByfkInstrumento(Musico* list, int len, int order)
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
                if(order==0 && list[i].fkInstrumento<list[i+1].fkInstrumento)
                {
                    musico_swap(list,i);
                    swap=1;
                }
                if(order==1 && list[i].fkInstrumento>list[i+1].fkInstrumento)
                {
                    musico_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of Musico, the argument order indicate UP or DOWN order
 *
 * \param list Musico*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int musico_sortByEdad(Musico* list, int len, int order)
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
                if(order==0 && list[i].Edad<list[i+1].Edad)
                {
                    musico_swap(list,i);
                    swap=1;
                }
                if(order==1 && list[i].Edad>list[i+1].Edad)
                {
                    musico_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of Musico, the argument order indicate UP or DOWN order
 *
 * \param list Musico*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int musico_sortByNombre(Musico* list, int len, int order)
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
                    musico_swap(list,i);
                    swap=1;
                }
                if(order==1 && strcmp(list[i].Nombre,list[i+1].Nombre)>0)
                {
                    musico_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of Musico, the argument order indicate UP or DOWN order
 *
 * \param list Musico*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int musico_sortByApellido(Musico* list, int len, int order)
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
                if(order==0 && strcmp(list[i].Apellido,list[i+1].Apellido)<0)
                {
                    musico_swap(list,i);
                    swap=1;
                }
                if(order==1 && strcmp(list[i].Apellido,list[i+1].Apellido)>0)
                {
                    musico_swap(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}
