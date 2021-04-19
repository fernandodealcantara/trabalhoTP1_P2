#ifndef CONTROLADORAAPTAUTENTICACAO_H_INCLUDED
#define CONTROLADORAAPTAUTENTICACAO_H_INCLUDED

#include <string.h>
#include "../../bibliotecas/curses.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"
#include "../../interfaces.h"

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
private:
    IServicoAutenticacao *cntr;
public:
    bool autenticar(Email*);
    void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

#endif // CONTROLADORAAPTAUTENTICACAO_H_INCLUDED
