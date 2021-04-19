#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "./libs/dominios.h"
#include "./libs/entidades.h"

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
    virtual void executar() = 0;
    virtual void executar(Email) = 0;
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
    virtual recuperar(Usuario) = 0;
    virtual ~IServicoUsuario(){}
};

class IServicoImovel {
public:
    virtual bool cadastrar(Imovel) = 0;
    virtual bool descadastrar(Codigo) = 0;
    virtual bool alterar(Imovel) = 0;
    virtual bool recuperar(Imovel) = 0;
    virtual ~IServicoImovel(){}
};

#endif // INTERFACES_H_INCLUDED
