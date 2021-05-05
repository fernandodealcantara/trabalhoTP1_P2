#include "cntrSVCusuario.h"

bool CntrServicoUsuario::cadastrar(Usuario usuario) {
    ComandoCadastrarUsuario cadastrarUsuario(usuario);
    return cadastrarUsuario.executar();
}

Usuario CntrServicoUsuario::recuperar(Email email) {
    ComandoPesquisarUsuario pesquisarUsuario(email);
    pesquisarUsuario.executar();
    Usuario usuario;
    usuario = pesquisarUsuario.getResultado();

    return usuario;
}

bool CntrServicoUsuario::alterar(Usuario usuario) {
    ComandoAtualizarUsuario atualizarUsuario(usuario);
    return atualizarUsuario.executar();
}

bool CntrServicoUsuario::descadastrar(Email email) {
    // Deletando as propostas do usuario
    ComandoDeletarProposta deletarMinhasPropostas(email);
    deletarMinhasPropostas.executar();
    // Coletando os imoveis do usuario
    list<Imovel> imoveis = recuperarImoveis(email);
    Imovel imovel;
    Codigo codigo;

    // Deleta todos os imoveis e propostas aos imoveis do usuario
    while (!imoveis.empty()){
        imovel = imoveis.back();
        imoveis.pop_back();
        codigo = imovel.getCodigo();
        ComandoDeletarProposta deletarProposta(imovel);
        deletarProposta.executar();
        ComandoDeletarImovel deletarImovel(codigo);
        deletarImovel.executar();
    }
    // deletando o usuario
    ComandoDeletarUsuario deletarUsuario(email);
    return deletarUsuario.executar();
}

list<Imovel> CntrServicoUsuario::recuperarImoveis(Email email) {
    ComandoPesquisarImoveis pesquisarImoveis(email);
    pesquisarImoveis.executar();
    return pesquisarImoveis.getResultado();
}
