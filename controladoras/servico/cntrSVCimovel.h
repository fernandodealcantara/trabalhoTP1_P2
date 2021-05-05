#ifndef CONTROLADORASVCIMOVEL_H_INCLUDED
#define CONTROLADORASVCIMOVEL_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string.h>
#include <list>

#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"
#include "../../interfaces.h"

#include "../../acessoDB.h"
// 190125586 - 190084197 - 190129794
class CntrServicoImovel: public IServicoImovel {
public:
    list<Imovel> recuperarImoveis();
    list<Imovel> recuperarImoveis(Email);
    bool cadastrarImovel(Imovel, Email);
    Imovel recuperarImovel(Codigo);
    Email recuperarDonoImovel(Codigo);
    bool alterar(Imovel);
    bool deletarImovel(Imovel);

    bool deletarProposta(Codigo);
    bool cadastrarProposta(Proposta, Email, Codigo);
    list<Proposta> recuperarPropostas();
    list<Proposta> recuperarPropostas(Email);
    list<Proposta> recuperarPropostas(Codigo);
    list<Codigo> recuperarCodigosPropostas(Email);
};

#endif // CONTROLADORASVCIMOVEL_H_INCLUDED
