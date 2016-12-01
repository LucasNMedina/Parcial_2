#include <stdio.h>
#include <stdlib.h>
#include "Tramitente.h"

sTramitente* nuevoTramitente(int documento, int numero)
{
    sTramitente* auxTramitente=(sTramitente*)malloc(sizeof(sTramitente));

    if(auxTramitente!=NULL){
        auxTramitente->documento=documento;
        auxTramitente->numeroTurno=numero;
    }

    return auxTramitente;
}
