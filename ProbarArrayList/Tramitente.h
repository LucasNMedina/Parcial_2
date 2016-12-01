#ifndef TRAMITENTE_H_INCLUDED
#define TRAMITENTE_H_INCLUDED

typedef struct
{
    //int tipoTramite;
    int numeroTurno;
    int documento;

}sTramitente;

#endif // TRAMITENTE_H_INCLUDED

sTramitente* nuevoTramitente(int documento, int numero);
