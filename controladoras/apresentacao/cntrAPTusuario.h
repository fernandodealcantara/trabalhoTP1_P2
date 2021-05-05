#ifndef CONTROLADORAAPTUSUARIO_H_INCLUDED
#define CONTROLADORAAPTUSUARIO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"
#include "../../interfaces.h"

#define CLR_SCR system("cls");
// 190084197 - 190129794
class CntrApresentacaoUsuario:public IApresentacaoUsuario{
private:
    IServicoUsuario *cntrServicoUsuario;
    void consultarDadosUsuario(Email);
    void editarDadosUsuario(Email);
    bool excluirUsuario(Email);
public:
    void cadastrar();
    bool executar(Email);
    void setCntrServicoUsuario(IServicoUsuario*);
};

inline void CntrApresentacaoUsuario::setCntrServicoUsuario(IServicoUsuario *cntr){
    cntrServicoUsuario = cntr;
}

#endif // CONTROLADORAAPTUSUARIO_H_INCLUDED
