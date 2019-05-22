#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

void clrscr(void);
int utn_getString(  char *pResult,
                char *pMsg,
                char *pMsgError,
                int min,
                int max,
                int attemps);
int utn_isValidInt (char* string);
int utn_isValidFloat(char* string);
int utn_isValidName (char* string);
int utn_isValidName (char* string);
int utn_isValidAddress (char* string);
int utn_isValidGender (char string);
int utn_getInt(  int *pResult,
                char *pMsg,
                char *pMsgError,
                int min,
                int max,
                int attempts);
int utn_getFloat(   float *pResult,
                    char *pMsg,
                    char *pMsgError,
                    int min,
                    int max,
                    int attempts);
int utn_getName(    char *pResult,
                    int len,
                    char *pMsg,
                    char *pMsgError,
                    int minChars,
                    int maxChars,
                    int attempts);
int utn_getAddress( char *pResult,
                    int len,
                    char *pMsg,
                    char *pMsgError,
                    int minChars,
                    int maxChars,
                    int attempts);
int utn_getGender( char *pResult,
                    char *pMsg,
                    char *pMsgError,
                    int attempts);

void myPause(void);
void clrscr(void);

#endif // UTN_H_INCLUDED
