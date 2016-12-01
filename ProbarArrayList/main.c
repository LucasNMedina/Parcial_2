#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "ArrayList.h"
#include "tramitente.h"
#include "validaciones.h"

//int inicializarIds(sAbonado* abonados,int cantElementos, int valorInicial);
int dar_numeros(int* numero);
void numero_urgente(ArrayList* list);
int compararDNI(void* tramitanteA,void* tramitanteB);

int main()
{
    char respuesta;
    char auxString[4096];
    int auxInt;
    int cantidad,cantidad2,i;
    int numeroUrgente=1;
    int numeroRegular=100;
    ArrayList* listaUrgente=al_newArrayList();
    ArrayList* listaRegular=al_newArrayList();
    ArrayList* listaUrgente2=al_newArrayList();
    ArrayList* listaRegular2=al_newArrayList();
    sTramitente* tramitente;
    sTramitente* auxTram;
    sTramitente* auxTram2;

    do{
         system("cls");
         respuesta=menu("Seleccione tipo de tramite\nA)Tramite urgente\nB)tramite regular\nC)Proximo cliente\nD)Listar\nE)Informar\nF)Salir\n",'A','F');
         switch(respuesta){
             case 'A':
                if(tramitente!=NULL){
                    printf("Ingrese documento:");
                    fflush(stdin);
                    scanf("%s",auxString);

                    while(!verificarDNI(auxString)){
                        printf("Ingrese un DNI correcto:");
                        fflush(stdin);
                        scanf("%s",auxString);
                    }
                    auxInt=atoi(auxString);

                    tramitente=nuevoTramitente(auxInt,numeroUrgente);
                    listaUrgente->add(listaUrgente,tramitente);

                    printf("Su turno es:%d\n",tramitente->numeroTurno);
                    dar_numeros(&numeroUrgente);
                }
                system("pause");
                break;
             case 'B':

                if(tramitente!=NULL){
                    printf("Ingrese documento:");
                    fflush(stdin);
                    scanf("%s",auxString);

                    while(!verificarDNI(auxString)){
                        printf("Ingrese un DNI correcto:");
                        fflush(stdin);
                        scanf("%s",auxString);
                    }
                    auxInt=atoi(auxString);
                    tramitente=nuevoTramitente(auxInt,numeroRegular);
                    listaRegular->add(listaRegular,tramitente);

                    printf("Su turno es:%d\n",tramitente->numeroTurno);
                    dar_numeros(&numeroRegular);
                }
                system("pause");
                break;
             case 'C':
                 if(!listaUrgente->isEmpty(listaUrgente)){
                    auxTram=(sTramitente*)listaUrgente->pop(listaUrgente,0);
                    printf("Proximo cliente a ser atendido:\nTURNO:\t TRAMITE\n:%d\t URGENTE",auxTram->numeroTurno);
                    listaUrgente2->add(listaUrgente2,auxTram);
                 }else{
                     if(listaRegular->isEmpty(listaRegular)==0){
                        auxTram=(sTramitente*)listaRegular->pop(listaRegular,0);
                        printf("Proximo cliente a ser atendido:\nTURNO:\t TRAMITE\n:%d\t REGULAR",auxTram->numeroTurno);
                        listaRegular2->add(listaRegular2,auxTram);
                     }
                     else{
                        printf("NO HAY MAS GENTE EN LA FILA");
                     }
                 }
                 system("pause");
                break;
             case 'D':
                 cantidad=listaUrgente->len(listaUrgente);
                 cantidad2=listaRegular->len(listaRegular);
                 printf("Clientes en espera Urgente:\n");

                 for(i=0;i<cantidad;i++){
                    auxTram=(sTramitente*)listaUrgente->get(listaUrgente,i);
                    printf("%d\t %d\n",auxTram->numeroTurno,auxTram->documento);
                 }

                 printf("Clientes en espera Regular:\n");
                 for(i=0;i<cantidad2;i++){
                    auxTram2=listaRegular->get(listaRegular,i);
                    printf("%d\t %d\n",auxTram2->numeroTurno,auxTram2->documento);
                 }
                system("pause");
                break;
             case 'E':
                 listaUrgente2->sort(listaUrgente2,compararDNI,1);
                 listaRegular2->sort(listaRegular2,compararDNI,1);

                 cantidad=listaUrgente2->len(listaUrgente2);
                 cantidad2=listaRegular2->len(listaRegular2);
                 printf("Clientes atendidos Urgente:\n");

                 for(i=0;i<cantidad;i++){
                    auxTram=listaUrgente2->get(listaUrgente2,i);
                    printf("%d\n",auxTram->documento);
                 }

                 printf("Clientes atendidos Regular:\n");
                 for(i=0;i<cantidad2;i++){
                    auxTram=listaRegular2->get(listaRegular2,i);
                    printf("%d\n",auxTram->documento);
                 }
                 system("pause");
                break;
             case 'F':
                 printf("Presione enter para salir");
                break;
         }
    }while(respuesta != 'F');
    return 0;
}

int dar_numeros(int* numero)
{
    *numero=*numero+1;
    return 0;
}


/*int inicializarIds(sAbonado* abonados,int cantElementos, int valorInicial)
{
    int i;
    int flag=0;

    if(abonados != NULL && cantElementos>0)
    {
        for(i=0; i<cantElementos; i++)
        {
            abonados[i].idAbonado=valorInicial+i;
            flag=1;
        }
    }
    return flag;
} */

int compararDNI(void* tramitanteA,void* tramitanteB)
{

    if(((sTramitente*)tramitanteA)->documento > ((sTramitente*)tramitanteB)->documento)
    {
        return 1;
    }
    if(((sTramitente*)tramitanteA)->documento < ((sTramitente*)tramitanteB)->documento)
    {
        return -1;
    }
    return 0;


}
