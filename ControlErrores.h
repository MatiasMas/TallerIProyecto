#ifndef TALLERIPROYECTO_CONTROLERRORES_H
#define TALLERIPROYECTO_CONTROLERRORES_H

#include "ABBSecuencias.h"
#include "ListaStrings.h"
#include "Comando.h"

//En funcion del comando recibido realiza las validaciones requeridas por el programa
boolean validarComando(Comando comando, ListaStrings listaStrings, ABBSecuencias abbSecuencias);

#endif //TALLERIPROYECTO_CONTROLERRORES_H
