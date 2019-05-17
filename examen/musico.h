#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

typedef struct
{
    int id;
    int isEmpty;
    //-------------
    int Edad;
    char Nombre[255];
    char Apellido[255];
    int fkOrquesta;
    int fkInstrumento;

}Musico;

int musico_init(Musico* list,int len);
int musico_add(  Musico* list,
                int len,
                int fkOrquesta,
                int fkInstrumento,
                int Edad,
                char* Nombre,
                char* Apellido);
int musico_new(Musico* list,int len);
void musico_printByIndex(Musico list[],int index);
void musico_printAll(Musico* list,int len);
int musico_delete(Musico* list,int len,int id);
int musico_modMenu(Musico *list,int len);
int musico_searchById(Musico* list,int len,int id);
int musico_searchByfkOrquesta(Musico* list,int len,int fkOrquesta);
int musico_searchByEdad(Musico* list,int len,int Edad);
int musico_searchByNombre(Musico* list,int len,char* Nombre);
int musico_searchByApellido(Musico* list,int len,char* Apellido);
void musico_swap(Musico* list,int i);
int musico_sortById(Musico* list, int len, int order);
int musico_sortByfkOrquesta(Musico* list, int len, int order);
int musico_sortByfkInstrumento(Musico* list, int len, int order);
int musico_sortByEdad(Musico* list, int len, int order);
int musico_sortByNombre(Musico* list, int len, int order);
int musico_sortByApellido(Musico* list, int len, int order);

#endif // MUSICO_H_INCLUDED
