#ifndef CONTROLADORASVCAUTENTICACAO_H_INCLUDED
#define CONTROLADORASVCAUTENTICACAO_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string.h>
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"
#include "../../interfaces.h"

#include "../../acessoDB.h"
// 190125586
class CntrServicoAutenticacao: public IServicoAutenticacao {
public:
    bool autenticar(Email, Senha);
};



#endif // CONTROLADORASVCAUTENTICACAO_H_INCLUDED
