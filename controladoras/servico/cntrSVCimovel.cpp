#include "cntrSVCimovel.h"

list<Imovel> CntrServicoImovel::recuperarImoveis() {
    ComandoPesquisarImoveis pesquisarImoveis;
    pesquisarImoveis.executar();
    return pesquisarImoveis.getResultado();
}

list<Imovel> CntrServicoImovel::recuperarImoveis(Email email) {
    ComandoPesquisarImoveis pesquisarImoveis(email);
    pesquisarImoveis.executar();
    return pesquisarImoveis.getResultado();
}

Imovel CntrServicoImovel::recuperarImovel(Codigo codigo) {
    ComandoPesquisarImovel pesquisarImovel(codigo);
    pesquisarImovel.executar();
    return pesquisarImovel.getResultado();
}

bool CntrServicoImovel::cadastrarImovel(Imovel imovel, Email email){
    ComandoCadastrarImovel cadastrarImovel(imovel, email);
    return cadastrarImovel.executar();
}

Email CntrServicoImovel::recuperarDonoImovel(Codigo codigo) {
    ComandoPesquisarDonoImovel pesquisarDonoImovel(codigo);
    pesquisarDonoImovel.executar();
    return pesquisarDonoImovel.getResultado();
}

bool CntrServicoImovel::alterar(Imovel imovel) {
    ComandoAtualizarImovel atualizarImovel(imovel);
    return atualizarImovel.executar();
}

bool CntrServicoImovel::cadastrarProposta(Proposta proposta, Email email, Codigo codigo) {
    ComandoCadastrarProposta cadastrarProposta(proposta, email, codigo);
    return cadastrarProposta.executar();
}

list<Proposta> CntrServicoImovel::recuperarPropostas() {
    ComandoPesquisarPropostas pesquisarPropostas;
    pesquisarPropostas.executar();
    return pesquisarPropostas.getResultado();
}

list<Proposta> CntrServicoImovel::recuperarPropostas(Email email) {
    ComandoPesquisarPropostas pesquisarPropostas(email);
    pesquisarPropostas.executar();
    return pesquisarPropostas.getResultado();
}

list<Proposta> CntrServicoImovel::recuperarPropostas(Codigo codigo) {
    ComandoPesquisarPropostas pesquisarPropostas(codigo);
    pesquisarPropostas.executar();
    return pesquisarPropostas.getResultado();
}

list<Codigo> CntrServicoImovel::recuperarCodigosPropostas(Email email) {
    ComandoPesquisarCodigosImoveisPropostos codigosImoveis(email);
    codigosImoveis.executar();
    return codigosImoveis.getResultado();
}

bool CntrServicoImovel::deletarProposta(Codigo codigo) {
    ComandoDeletarProposta deletarProposta(codigo);
    return deletarProposta.executar();
}

bool CntrServicoImovel::deletarImovel(Imovel imovel) {
    Codigo codigo;
    codigo = imovel.getCodigo();
    ComandoDeletarImovel deletarImovel(codigo);
    ComandoDeletarProposta deletarProposta(imovel);
    deletarProposta.executar();
    return deletarImovel.executar();
}
