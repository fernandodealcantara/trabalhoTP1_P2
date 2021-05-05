#ifndef CONTROLADORAAPTCONTROLE_H_INCLUDED
#define CONTROLADORAAPTCONTROLE_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"
#include "../../interfaces.h"

#define CLR_SCR system("cls");
// 190125586
class CntrApresentacaoControle {
private:
    Email email;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoUsuario *cntrApresentacaoUsuario;
    IApresentacaoImovel *cntrApresentacaoImovel;
public:
    void executar();
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
    void setCntrApresentacaoUsuario(IApresentacaoUsuario*);
    void setCntrApresentacaoImovel(IApresentacaoImovel*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr) {
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoUsuario(IApresentacaoUsuario *cntr) {
    cntrApresentacaoUsuario = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoImovel(IApresentacaoImovel *cntr) {
    cntrApresentacaoImovel = cntr;
}

#endif // CONTROLADORAAPTCONTROLE_H_INCLUDED
