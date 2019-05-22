#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
typedef struct
{
    int id;
    int isEmpty;
    //-------------
    int Tipo;
    char Nombre[51];
    char Lugar[255];
}Orquesta;
#endif // ORQUESTA_H_INCLUDED

int orquesta_init(Orquesta* list,int len);
int orquesta_add(Orquesta* list,
                int len,
                int Tipo,
                char* Nombre,
                char* Lugar);
int orquesta_new(Orquesta* list,int len);
void orquesta_printByIndex(Orquesta* list,int index);
void orquesta_printAll(Orquesta* list,int len);
int orquesta_delete(Orquesta* list,int len,int id);
int orquesta_modMenu(Orquesta *list,int len);
int orquesta_searchById(Orquesta* list,int len,int id);
int orquesta_searchByTipo(Orquesta* list,int len,int Tipo);
int orquesta_searchByNombre(Orquesta* list,int len,char* Nombre);
int orquesta_searchByLugar(Orquesta* list,int len,char* Nombre);
void orquesta_swap(Orquesta* list,int i);
int orquesta_sortById(Orquesta* list, int len, int order);
int orquesta_sortByTipo(Orquesta* list, int len, int order);
int orquesta_sortByNombre(Orquesta* list, int len, int order);
int orquesta_sortByLugar(Orquesta* list, int len, int order);
int orquesta_getOrquesta(int*pId,Orquesta* list, int len);

