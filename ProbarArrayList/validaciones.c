#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

char menu(char* message,char minChar, char maxChar)
{
    char auxChar;

    printf("%s",message);
    fflush(stdin);
    scanf("%c",&auxChar);

    auxChar=toupper(auxChar);

    while(auxChar<minChar || auxChar>maxChar)
    {
        printf("Coloco una letra no valida. REINGRESE:");
        fflush(stdin);
        scanf("%c",&auxChar);

        auxChar=toupper(auxChar);
    }

    return auxChar;
}

int esNumerico(char* str)
{
    int i=0;
    int esNumero=1;

    while(str[i]!='\0')
    {
        if(str[i]<'0' || str[i]>'9')
        {
            esNumero=0;
            break;
        }
        i++;
    }
    return esNumero;
}

int verificarLargo(char* str,int largoCadena)
{
    int isOk=0;
    if(strlen(str)>0 && strlen(str)<=largoCadena)
    {
        isOk=1;
    }
    return isOk;
}

int verificarLargoDNI(char* str)
{
    int isOk=0;
    if(strlen(str)>0 && strlen(str)==8)
    {
        isOk=1;
    }
    return isOk;
}

int verificarDNI(char* str)
{
    int isOk=0;

    if(esNumerico(str) && verificarLargoDNI(str))
    {
        isOk=1;
    }
    return isOk;
}

int validarDNI(char* str)
{
    int isOk=0;
    if(esNumerico(str) && verificarLargoDNI(str))
    {
        isOk=1;
    }
    return isOk;
}

int esSoloLetras(char* str)
{
    int i=0;
    int esLetras=1;

    while(str[i]!='\0')
    {
        if((str[i]<'A' || str[i]>'Z') && (str[i]<'a' || str[i]>'z') && str[i]!=' ')
        {
            esLetras=0;
        }
        i++;
    }
    return esLetras;
}

int validarNombre(char* str,int largo)
{
    int isOk=0;

    if(esSoloLetras(str) && verificarLargo(str,largo))
       {
           isOk=1;
       }

    return isOk;
}

int validarEdad(char* str)
{
    int auxInt;
    int isOk=0;

    if(esNumerico(str))
    {
        auxInt=atoi(str);
        if(auxInt>0 && auxInt<99)
        {
            isOk=1;
        }
    }
    return isOk;
}

void estiloNombres(char* str)
{
    int i=1;

    str[0]=toupper(str[0]);

    while(str[i]!='\0')
    {
        if((str[i]>='A' && str[i]<='Z'))
        {
            str[i]=tolower(str[i]);
        }
        else
        {
            if(str[i]==' ')
            {
                str[i+1]=toupper(str[i+1]);
                i=i+1;
            }
        }
        i++;
    }
}
