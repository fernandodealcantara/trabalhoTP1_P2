#ifndef ACESSODB_H_INCLUDED
#define ACESSODB_H_INCLUDED
//---------------------------------------------------------------------------
#include "./bibliotecas/dominios.h"
#include "./bibliotecas/entidades.h"
#include <list>

// Posteriomente remover.

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>

#include "./bibliotecas/sqlite3.h"

using namespace std;


//Classe ElementoResultado.

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};
//---------------------------------------------------------------------------
//Classe ElementoResultado.

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}

//---------------------------------------------------------------------------
//Classe ComandoSQL.

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        bool conectar();
        bool desconectar();
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
             nomeBancoDados = "db.db";
        }
        bool executar();
};


//---------------------------------------------------------------------------
//Classe ComandoLerSenha.

class ComandoLerSenha:public ComandoSQL {
public:
        ComandoLerSenha(Email);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarUsuario.

class ComandoPesquisarUsuario:public ComandoSQL {
public:
        ComandoPesquisarUsuario(Email);
        Usuario getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarUsuario.

class ComandoCadastrarUsuario:public ComandoSQL {
public:
        ComandoCadastrarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarUsuario.

class ComandoAtualizarUsuario:public ComandoSQL {
public:
        ComandoAtualizarUsuario(Usuario);
};
/*
//---------------------------------------------------------------------------
//Classe ComandoRemoverAluno.

class ComandoRemoverAluno:public ComandoSQL {
public:
        ComandoRemoverAluno(Matricula);
};*/

//---------------------------------------------------------------------------
//Classe ComandoPesquisarImoveis.

class ComandoPesquisarImoveis:public ComandoSQL {
public:
        ComandoPesquisarImoveis();
        ComandoPesquisarImoveis(Email);
        list<Imovel> getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarImovel.
class ComandoPesquisarImovel:public ComandoSQL {
public:
    ComandoPesquisarImovel(Codigo);
    Imovel getResultado();
};
//---------------------------------------------------------------------------
//Classe ComandoPesquisarDonoImovel.
class ComandoPesquisarDonoImovel:public ComandoSQL {
public:
    ComandoPesquisarDonoImovel(Codigo);
    Email getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarImovel.
class ComandoCadastrarImovel:public ComandoSQL {
public:
    ComandoCadastrarImovel(Imovel, Email);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarImovel.
class ComandoAtualizarImovel:public ComandoSQL {
public:
    ComandoAtualizarImovel(Imovel);
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarImovel.
class ComandoCadastrarProposta:public ComandoSQL {
public:
    ComandoCadastrarProposta(Proposta, Email, Codigo);
};

//Classe ComandoPesquisarPropostas.

class ComandoPesquisarPropostas:public ComandoSQL {
public:
    ComandoPesquisarPropostas();
    ComandoPesquisarPropostas(Email);
    ComandoPesquisarPropostas(Codigo);
    list<Proposta> getResultado();
};

// ComandoPesquisarCodigosImoveisPropostos
class ComandoPesquisarCodigosImoveisPropostos: public ComandoSQL {
public:
    ComandoPesquisarCodigosImoveisPropostos(Email);
    list<Codigo> getResultado();
};

//Classe ComandoDeletarProposta
class ComandoDeletarProposta: public ComandoSQL {
public:
    ComandoDeletarProposta(Codigo);
    ComandoDeletarProposta(Imovel);
    ComandoDeletarProposta(Email);
};

class ComandoDeletarImovel: public ComandoSQL {
public:
    ComandoDeletarImovel(Codigo);
};

//Classe ComandoDeletarUsuario
class ComandoDeletarUsuario: public ComandoSQL {
public:
    ComandoDeletarUsuario(Email);
};


#endif // ACESSODB_H_INCLUDED
