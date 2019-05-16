#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

typedef struct
{
    int id;
    int isEmpty;
    //-------------
    int Tipo;
    char Nombre[51];
}Instrumento;

int instrumento_init(Instrumento* list,int len);
int instrumento_add(Instrumento* list,
                int len,
                int Tipo,
                char* Nombre,
                char* Lugar);
int instrumento_new(Instrumento* list,int len);
void instrumento_printByIndex(Instrumento list[],int index);
void instrumento_printAll(Instrumento* list,int len);
int instrumento_delete(Instrumento* list,int len,int id);
int instrumento_modMenu(Instrumento *list,int len);
int instrumento_searchById(Instrumento* list,int len,int id);
int instrumento_searchByTipo(Instrumento* list,int len,int Tipo);
int instrumento_searchByNombre(Instrumento* list,int len,char* Nombre);
void instrumento_swap(Instrumento* list,int i);
int instrumento_sortById(Instrumento* list, int len, int order);
int instrumento_sortByTipo(Instrumento* list, int len, int order);
int instrumento_sortByNombre(Instrumento* list, int len, int order);

#endif // ORQUESTA_H_INCLUDED