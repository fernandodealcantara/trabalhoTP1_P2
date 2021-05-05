#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include <list>

#include "./bibliotecas/dominios.h"
#include "./bibliotecas/entidades.h"

class IServicoAutenticacao;
class IServicoUsuario;
class IServicoImovel;

class IApresentacaoAutenticacao {
public:
    virtual bool autenticar(Email*) = 0;
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
    virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoUsuario {
public:
    virtual void cadastrar() = 0;
    virtual bool executar(Email) = 0;
    virtual void setCntrServicoUsuario(IServicoUsuario*) = 0;
    virtual ~IApresentacaoUsuario(){}
};

class IApresentacaoImovel {
public:
    virtual void executar() = 0;
    virtual void executar(Email) = 0;
    virtual void setCntrServicoImovel(IServicoImovel*) = 0;
    virtual ~IApresentacaoImovel(){}
};

class IServicoAutenticacao {
public:
    virtual bool autenticar(Email, Senha) = 0;
    virtual ~IServicoAutenticacao(){}
};

class IServicoUsuario {
public:
    virtual bool cadastrar(Usuario) = 0;
    virtual bool descadastrar(Email) = 0;
    virtual bool alterar(Usuario) = 0;
    virtual Usuario recuperar(Email) = 0;
    virtual ~IServicoUsuario(){}
};

class IServicoImovel {
public:
    virtual bool cadastrarImovel(Imovel, Email) = 0;
    virtual bool alterar(Imovel) = 0;
    virtual Imovel recuperarImovel(Codigo) = 0;
    virtual list<Imovel> recuperarImoveis() = 0;
    virtual list<Imovel> recuperarImoveis(Email) = 0;
    virtual Email recuperarDonoImovel(Codigo) = 0;
    virtual bool deletarImovel(Imovel) = 0;

    virtual bool deletarProposta(Codigo) = 0;
    virtual bool cadastrarProposta(Proposta, Email, Codigo) = 0;
    virtual list<Proposta> recuperarPropostas() = 0;
    virtual list<Proposta> recuperarPropostas(Email) = 0;
    virtual list<Proposta> recuperarPropostas(Codigo) = 0;
    virtual list<Codigo> recuperarCodigosPropostas(Email) = 0;
    virtual ~IServicoImovel(){}
};

#endif // INTERFACES_H_INCLUDED
