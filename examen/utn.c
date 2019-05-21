#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

int utn_getString(  char *pResult,
                    char *pMsg,
                    char *pMsgError,
                    int min,
                    int max,
                    int attemps)
{
    int ret=-1;
    char bufferStr[4096];
    while(attemps>0)
    {
        printf("%s",pMsg);
        fgets(bufferStr,sizeof(bufferStr),stdin);
        bufferStr[strlen(bufferStr)-1] = '\0';
        if( pResult != NULL &&
            strlen(bufferStr) >= min &&
            strlen(bufferStr) <= max)
        {
            strncpy(pResult,bufferStr,max);
            ret=0;
            break;
        }
        else
        {
            printf("%s",pMsgError);
        }
        attemps--;
    }

    return ret;
}

int utn_isValidInt (char* string)
{
    int ret = 1;
    int i=0;
    if(string!=NULL)
    {
        if(string[i] == '-')
        {
            i++;
        }
        for(;string[i] != '\0';i++)
        {
            if(string[i] < '0' || string[i] > '9')
            {
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int utn_isValidFloat(char* string)
{
    int dotCounter=0;
    int singCounter=0;
    int ret=1;
    int i=0;
    if(string!=NULL)
    {
        for(;string[i] != '\0';i++)
        {
            if(string[i] == '-')
            {
                i++;
            }
            if(string[i]=='.')
            {
                if(singCounter>0&&i==1)
                {
                    ret=0;
                    break;
                }
                dotCounter++;
                i++;
            }
            if(((string[i]<'0' || string[i]>'9') && string[i]!='.') || dotCounter>1)
            {
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int utn_isValidName (char* string)
{
    int ret=1;
    int i=0;
    for(;string[i] != '\0';i++)
    {
        if(!isalpha(string[i]))
        {
            ret=0;
            break;
        }
    }
    return ret;
}

int utn_isValidAddress (char* string)
{
    int ret=1;
    int i=0;
    for(;string[i] != '\0';i++)
    {
        if(!isalnum(string[i])/* || string[i]!=' '*/)
        {
            ret=0;
            break;
        }
    }
    return ret;
}

int utn_isValidGender (char string)
{
    int ret=1;
    if(string!='m' && string!='f' && string!='M' && string!='F')
    {
        ret=0;
    }
    return ret;
}

int utn_getInt( int *pResult,
                char *pMsg,
                char *pMsgError,
                int min,
                int max,
                int attempts)
{
    int ret = -1;
    char bufferStr[4096];
    int bufferInt;
    while(attempts>0)
    {
        if(pResult != NULL)
        {
            if(!utn_getString(bufferStr,pMsg,pMsgError,1,7,10) &&
                utn_isValidInt(bufferStr))
            {
                bufferInt = atoi(bufferStr);
                if(bufferInt >= min && bufferInt <= max)
                {
                    ret = 0;
                    *pResult = bufferInt;
                    break;
                }
                else
                {
                    printf("%s",pMsgError);
                }
            }
        }
    }
    return ret;
}

int utn_getFloat(   float *pResult,
                    char *pMsg,
                    char *pMsgError,
                    int min,
                    int max,
                    int attempts)
{
    int ret = -1;
    char bufferStr[4096];
    float bufferFloat;
    while(attempts>0)
    {
        if(pResult != NULL)
        {
            if(!utn_getString(bufferStr,pMsg,pMsgError,1,7,10) &&
                utn_isValidFloat(bufferStr))
            {
                bufferFloat = atoi(bufferStr);
                if(bufferFloat >= min && bufferFloat <= max)
                {
                    ret = 0;
                    *pResult = bufferFloat;
                    break;
                }
                else
                {
                    printf("%s",pMsgError);
                }
            }
        }
    }
    return ret;
}

int utn_getName(    char *pResult,
                    int len,
                    char *pMsg,
                    char *pMsgError,
                    int minChars,
                    int maxChars,
                    int attempts)
{
    int ret = -1;
    char bufferStr[4096];
    while(attempts>0)
    {
        if(pResult != NULL)
        {
            if(!utn_getString(bufferStr,pMsg,pMsgError,minChars,maxChars,1) &&
                utn_isValidName(bufferStr)&&strlen(bufferStr)<=len)
            {
                strncpy(pResult,bufferStr,len);
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int utn_getAddress( char *pResult,
                    int len,
                    char *pMsg,
                    char *pMsgError,
                    int minChars,
                    int maxChars,
                    int attempts)
{
    int ret = -1;
    char bufferStr[4096];
    while(attempts>0)
    {
        if(pResult != NULL)
        {
            if(!utn_getString(bufferStr,pMsg,pMsgError,minChars,maxChars,1) &&
                utn_isValidAddress(bufferStr)&&strlen(bufferStr)<=len)
            {
                strncpy(pResult,bufferStr,len);
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int utn_getGender( char *pResult,
                    char *pMsg,
                    char *pMsgError,
                    int attempts)
{
    int ret = -1;
    char bufferChar;
    while(attempts>0)
    {
        if(pResult != NULL)
        {
            if(!utn_getString(&bufferChar,pMsg,pMsgError,1,1,1) &&
                utn_isValidGender(bufferChar))
            {
                *pResult=bufferChar;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

void clrscr(void)
{
    system("@cls||clear");
}
