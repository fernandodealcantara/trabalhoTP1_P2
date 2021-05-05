#include <string.h>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

#include "bibliotecas/dominios.h"
#include "interfaces.h"

#include "./controladoras/apresentacao/cntrAPTcontrole.h"
#include "./controladoras/apresentacao/cntrAPTautenticacao.h"
#include "./controladoras/apresentacao/cntrAPTusuario.h"
#include "./controladoras/apresentacao/cntrAPTimovel.h"

#include "./controladoras/servico/cntrSVCautenticacao.h"
#include "./controladoras/servico/cntrSVCusuario.h"
#include "./controladoras/servico/cntrSVCimovel.h"

using namespace std;

int main() {
    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoUsuario *cntrApresentacaoUsuario;
    IApresentacaoImovel *cntrApresentacaoImovel;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoUsuario = new CntrApresentacaoUsuario();
    cntrApresentacaoImovel = new CntrApresentacaoImovel();

    IServicoAutenticacao *cntrServicoAutenticacao;
    IServicoUsuario *cntrServicoUsuario;
    IServicoImovel *cntrServicoImovel;

    cntrServicoAutenticacao = new CntrServicoAutenticacao();
    cntrServicoUsuario = new CntrServicoUsuario();
    cntrServicoImovel = new CntrServicoImovel();

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoUsuario(cntrApresentacaoUsuario);
    cntrApresentacaoControle->setCntrApresentacaoImovel(cntrApresentacaoImovel);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoUsuario->setCntrServicoUsuario(cntrServicoUsuario);
    cntrApresentacaoImovel->setCntrServicoImovel(cntrServicoImovel);

    cntrApresentacaoControle->executar();

    return 0;
}
