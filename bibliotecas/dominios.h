#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;


///
/// Padrão para representação do número
///
/// Regras de formato:
///
/// - Número valido apenas inteiro de 0 a 20
///
// Classe Numero feita por Victor Hugo Mat: 190129794
class Numero {
private:
    int valor;
    void validar(int valor);

public:

    ///
    /// Armazena o numero informado caso o mesmo seja valido
    ///
    /// Lança exceção caso o número informado seja invalido
    ///
    /// @param valor numero
    ///
    /// @throw invalid_argument
    ///

    void setNumero(int valor);

    ///
    /// Retorna valor
    ///
    /// @return valor
    ///
        int getNumero();
};

inline int Numero::getNumero(){
    return valor;
}

///
/// Padrao para representacao de moeda
///
/// Regras de formato:
///
/// - Moeda valida apenas de 0,00 a 1.000.000,00
///
// Classe Moeda feita por Fernando Mat: 190125586
class Moeda {
private:
    string valor;
    void validar(string valor);

public:

    ///
    /// Armazena o valor informado caso o mesmo seja valido
    ///
    /// Lança exceção caso o valor informado seja invalido
    ///
    /// @param valor da moeda
    ///
    /// @throw invalid_argument
    ///

    void setMoeda(string valor);

    ///
    /// Retorna valor da moeda
    ///
    /// @return valor
    ///

    string getMoeda();

};

inline string Moeda::getMoeda(){
    return valor;
}

///
/// Padrão para representação da descrição
///
/// Regras de formato:
///
/// - Descrições aceitam 5 a 30 caracteres e são terminadas por ponto.
///
// Classe Descricao feita por Fernando Mat: 190125586
class Descricao{
private:
    string texto;
    void validar(string texto);

public:

    ///
    /// Armazena o texto da descrição
    ///
    /// Lança exceção caso o texto da descrição informado seja invalido.
    ///
    /// @param texto descricao
    ///
    /// @throw invalid_argument
    ///

    void setDescricao(string texto);

    ///
    /// Retorna o texto da descrição
    ///
    /// @return string
    ///

    string getDescricao();

};

inline string Descricao::getDescricao(){
    return texto;
}

///
/// Padrão para representação do nome
///
/// Regras de formato:
///
/// - Nome de 5 a 25 caracteres podendo ser letras de A-Z maiúsculas e minúsculas, ponto ou espaço.
/// Pontos precedem letra, não há espaços em sequência e a primeira letra de cada termo é maiúscula.
///
// Classe Nome feita por Fernando Mat: 190125586
class Nome{
private:
    string nome;
    void validar(string nome);

public:

    ///
    /// Armazena o nome
    ///
    /// Lança exceção caso o nome informado seja invalido.
    ///
    /// @param string nome
    ///
    /// @throw invalid_argument
    ///

    void setNome(string nome);

    ///
    /// Retorna o nome
    ///
    /// @return string
    ///

    string getNome();
};

inline string Nome::getNome(){
    return nome;
}

///
/// Padrão para representação de classe
///
/// Regras de formato:
///
/// - 1 para apartamento, 2 para casa e 3 para quarto.
///
// Classe Classe feita por Andre Mat: 190084197
class Classe{
private:
    const static int APARTAMENTO = 1;
    const static int CASA = 2;
    const static int QUARTO = 3;
    int classe;
    void validar(int valor);

public:

    ///
    /// Armazena o número informado e caso o mesmo seja valido atribui uma classe
    ///
    /// Lança exceção caso o valor informado seja invalido
    ///
    /// @param valor classe
    ///
    /// @throw invalid_argument
    ///

    void setClasse(int valor);

    ///
    /// Retorna classe
    ///
    /// @return classe
    ///

    int getClasse();

};

inline int Classe::getClasse(){
    return classe;
}

///
/// Padrão para representação do endereço
///
/// Regras de formato:
///
/// - Texto de 5 a 20 caracteres podendo ser letras (A-Z e a-z), digito (0-9), ponto ou espaço.
///
// Classe Endereco feita por Andre Mat: 190084197
class Endereco {
private:
    string endereco;
    void validar(string endereco);

public:

    ///
    /// Armazena o endereço
    ///
    /// Lança exceção caso o endereço informado seja invalido
    ///
    /// @param string endereco
    ///
    /// @throw invalid_argument
    ///

    void setEndereco(string endereco);

    ///
    /// Retorna o endereço
    ///
    /// @return string endereco
    ///

    string getEndereco();

};

inline string Endereco::getEndereco(){
    return endereco;
}

///
/// Padrão para representação da data
///
/// Regras de formato:
///
/// - Data formato DD-MM-AA onde DD de 01 a 31, MM de 01 a 12 e AA de 21 a 99
/// Data considera anos bissextos e meses com 30 e 31 dias.
///
// Classe Data feita por Fernando Mat: 190125586
class Data {
private:
    string data;
    bool bissexto;
    void validar(string data);

public:

    ///
    /// Armazena a data
    ///
    /// Lança exceção caso a data informada seja invalida.
    ///
    /// @param string data
    ///
    /// @throw invalid_argument
    ///

    void setData(string data);

    ///
    /// Retorna a data
    ///
    /// @return string data
    ///

    string getData();

    ///
    /// Retorna se o ano é bissexto
    ///
    /// @return bool
    ///

    bool isBissexto();
};

inline string Data::getData(){
    return data;
}

inline bool Data::isBissexto(){
    return bissexto;
}

///
/// Padrão para representação do código
///
/// Regras de formato:
///
/// - Formato XXXXX, X é letra maiúscula A-Z ou digito 0-9. Note que 00000 é um código invalido.
///
// Classe Codigo feita por Victor Hugo Mat: 190129794
class Codigo {
private:
    string codigo;
    void validar(string codigo);

public:

    ///
    /// Armazena o código
    ///
    /// Lança exceção caso o código esteja em formato invalido
    ///
    /// @param string codigo
    ///
    /// @throw invalid_argument
    ///

    void setCodigo(string codigo);

    ///
    /// Retorna o codigo
    ///
    /// @return string codigo
    ///

    string getCodigo();
};

inline string Codigo::getCodigo(){
    return codigo;
}

///
/// Padrão para representação da senha
///
/// Regras de formato:
///
/// - Formato XXXXXX, X é letra maiúscula ou minúscula de A-Z, a-z ou digito 0-9.
/// Não pode haver caractere repetido, deve ter pelo menos uma letra maiúscula, uma minúscula e um digito.
///
// Classe Senha feita por Fernando Mat: 190125586
class Senha {
private:
    string senha;
    void validar(string senha);

public:

    ///
    /// Armazena a senha
    ///
    /// Lança exceção caso a senha esteja em formato invalido
    ///
    /// @param string senha
    ///
    /// @throw invalid_argument
    ///

    void setSenha(string senha);

    ///
    /// Retorna a senha
    ///
    /// @return string senha
    ///

    string getSenha();
};

inline string Senha::getSenha(){
    return senha;
}

///
/// Padrão para representação do email
///
/// Regras de formato:
///
/// - Formato nome@dominio, onde o nome é composto por até 10 caracteres e dominio é composto por até 20 caracteres.
/// Valido apenas caracteres de A-Z, a-z, 0-9 ou ponto. Nao há pontos em sequência.
///
// Classe Email feita por Fernando Mat: 190125586
class Email {
private:
    string email;
    void validar(string email);

public:

    ///
    /// Armazena o email
    ///
    /// Lança exceção caso o email esteja em formato invalido.
    ///
    /// @param string email
    ///
    /// @throw invalid_argument
    ///

    void setEmail(string email);

    ///
    /// Retorna o email
    ///
    /// @return string email
    ///

    string getEmail();
};

inline string Email::getEmail(){
    return email;
}

///
/// Padrão para representação do telefone
///
/// Regras de formato:
///
/// - Formato (XXX)-XXXXXXXXX, onde cada X eh digito de 0-9. Note que número não é (000)-000000000.
///
// Classe Telefone feita por Fernando Mat: 190125586
class Telefone {
private:
    string telefone;
    void validar(string telefone);

public:

    ///
    /// Armazena o telefone
    ///
    /// Lança exceção caso o telefone esteja em formato invalido.
    ///
    /// @param string telefone
    ///
    /// @throw invalid_argument
    ///

    void setTelefone(string telefone);

    ///
    /// Retorna o telefone
    ///
    /// @return string telefone
    ///

    string getTelefone();
};

inline string Telefone::getTelefone(){
    return telefone;
}

#endif // DOMINIOS_H_INCLUDED
