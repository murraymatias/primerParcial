#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int inf_moreThanFive(Orquesta* listOrquesta,int lenOrquesta,Musico* listMusico,int lenMusico);
int inf_moreThan30Years(Musico* list,int len);
int inf_orquestasByLugar(Orquesta* list,int len);
int inf_completeOrquesta(Orquesta* listOrquesta,int lenOrquesta,Musico* listMusico,int lenMusico,Instrumento* listInstrumento,int lenInstrumento);
int inf_musicoPorOrquesta(Orquesta* listOrquesta,int lenOrquesta,Musico* listMusico,int lenMusico,Instrumento* listInstrumento,int lenInstrumento);


#endif // INFORMES_H_INCLUDED
