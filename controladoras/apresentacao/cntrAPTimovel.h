#ifndef CONTROLADORAAPTIMOVEL_H_INCLUDED
#define CONTROLADORAAPTIMOVEL_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#include <iterator>

#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"
#include "../../interfaces.h"

#define CLR_SCR system("cls");
// 190125586 - 190084197 - 190129794
class CntrApresentacaoImovel:public IApresentacaoImovel {
private:
    IServicoImovel *cntr;
    Codigo imovelGeradorCodigo();
    Codigo propostaGeradorCodigo();

    void mostrarImovel(Imovel);
    void listarImoveis();
    void listarImoveis(Email);
    void listarImovel();
    void cadastrarImovel(Email);
    void editarImovel(Email);
    void descadastrarImovel(Email);

    void imoveisPropostas(Email);
    void imovelPropostas(Email);

    void cadastrarProposta(Email);
    void descadastrarProposta(Email);
    void listarPropostas(Email);
    void listarProposta(Email);
    void mostrarProposta(Proposta);
    void telaPropostas(Email email);
public:
    void executar();
    void executar(Email);
    void setCntrServicoImovel(IServicoImovel*);
};

inline void CntrApresentacaoImovel::setCntrServicoImovel(IServicoImovel *cntr) {
    this->cntr = cntr;
}

#endif // CONTROLADORAAPTIMOVEL_H_INCLUDED
