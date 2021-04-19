#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <string>

using namespace std;

///
/// Padrão para representação do usuário
///
/// Regras de formato:
///
/// - Usuário contem nome, email, senha e telefone.
///
// Classe Usuario feita por Fernando Mat: 190125586
class Usuario {
private:
    Nome nome;
    Email email;
    Senha senha;
    Telefone telefone;
public:
    ///
    /// Armazena o nome
    ///
    // Metodos do atributo nome
    void setNome(const Nome &nome);
    ///
    /// Retorna o nome
    ///
    Nome getNome() const;
    ///
    /// Armazena o email
    ///
    // Metodos do atributo email
    void setEmail(const Email &email);
    ///
    /// Retorna o email
    ///
    Email getEmail() const;
    ///
    /// Armazena a senha
    ///
    // Metodos do atributo senha
    void setSenha(const Senha &senha);
    ///
    /// Retorna a senha
    ///
    Senha getSenha() const;
    ///
    /// Armazena o telefone
    ///
    // Metodos do atributo telefone
    void setTelefone(const Telefone &telefone);
    ///
    /// Retorna o telefone
    ///
    Telefone getTelefone() const;

};

inline void Usuario::setNome(const Nome &nome){
    this->nome = nome;
}

inline Nome Usuario::getNome() const{
    return nome;
}
inline void Usuario::setEmail(const Email &email){
    this->email = email;
}

inline Email Usuario::getEmail() const{
    return email;
}

inline void Usuario::setSenha(const Senha &senha){
    this->senha = senha;
}

inline Senha Usuario::getSenha() const{
    return senha;
}

inline void Usuario::setTelefone(const Telefone &telefone){
    this->telefone = telefone;
}

inline Telefone Usuario::getTelefone() const{
    return telefone;
}

///
/// Regras de formato:
///
/// - Imóvel contem código, classe, descrição, endereço, data inicial, data final, hóspedes e valor.
///
// Classe Imovel feita por Victor Hugo Mat: 190129794
class Imovel {
private:
    Codigo codigo;
    Classe classe;
    Descricao descricao;
    Endereco endereco;
    Data dataInicial;
    Data dataFinal;
    Numero hospedes;
    Moeda valor;
public:
    ///
    /// Armazena o código
    ///
    // Metodos do atributo código
    void setCodigo(const Codigo &codigo);
    ///
    /// Retorna o código
    ///
    Codigo getCodigo() const;
    ///
    /// Armazena a classe
    ///
    // Metodos do atributo classe
    void setClasse(const Classe &classe);
    ///
    /// Retorna a classe
    ///
    Classe getClasse() const;
    ///
    /// Armazena a descrição
    ///
    // Metodos do atributo descrição
    void setDescricao(const Descricao &descricao);
    ///
    /// Retorna a descrição
    ///
    Descricao getDescricao() const;
    ///
    /// Armazena o endereço
    ///
    // Metodos do atributo endereço
    void setEndereco(const Endereco &endereco);
    ///
    /// Retorna o endereço
    ///
    Endereco getEndereco() const;
    ///
    /// Armazena a data inicial
    ///
    // Metodos do atributo data inicial
    void setDataInicial(const Data &dataInicial);
    ///
    /// Retorna a data inicial
    ///
    Data getDataInicial() const;
    ///
    /// Armazena a data final
    ///
    // Metodos do atributo data final
    void setDataFinal(const Data &dataInicial);
    ///
    /// Retorna a data final
    ///
    Data getDataFinal() const;
    ///
    /// Armazena o numero de hospedes
    ///
    // Metodos do atributo hospedes
    void setHospedes(const Numero &hospedes);
    ///
    /// Retorna o número de hospedes
    ///
    Numero getHospedes() const;
    ///
    /// Armazena o valor
    ///
    // Metodos do atributo valor
    void setValor(const Moeda &valor);
    ///
    /// Retorna o valor
    ///
    Moeda getValor() const;
};

inline void Imovel::setCodigo(const Codigo &codigo){
    this->codigo=codigo;
}

inline Codigo Imovel::getCodigo() const{
    return codigo;
}

inline void Imovel::setClasse(const Classe &classe){
    this->classe=classe;
}

inline Classe Imovel::getClasse() const{
    return classe;
}

inline void Imovel::setDescricao(const Descricao &descricao){
    this->descricao=descricao;
}

inline Descricao Imovel::getDescricao() const{
    return descricao;
}

inline void Imovel::setEndereco(const Endereco &endereco){
    this->endereco=endereco;
}

inline Endereco Imovel::getEndereco() const{
    return endereco;
}

inline void Imovel::setDataInicial(const Data &dataInicial){
    this->dataInicial=dataInicial;
}

inline Data Imovel::getDataInicial() const{
    return dataInicial;
}

inline void Imovel::setDataFinal(const Data &dataFinal){
    this->dataFinal=dataFinal;
}

inline Data Imovel::getDataFinal() const{
    return dataFinal;
}

inline void Imovel::setHospedes(const Numero &hospedes){
    this->hospedes=hospedes;
}

inline Numero Imovel::getHospedes() const{
    return hospedes;
}

inline void Imovel::setValor(const Moeda &valor){
    this->valor=valor;
}

inline Moeda Imovel::getValor() const{
    return valor;
}

///
/// Regras de formato:
///
/// - Proposta contem código, data inicial, data final, hóspedes e valor.
///
// Classe Proposta feita por Victor Hugo Mat: 190129794
class Proposta {
private:
    Codigo codigo;
    Data dataInicial;
    Data dataFinal;
    Numero hospedes;
    Moeda valor;
public:
    ///
    /// Armazena o código
    ///
    // Metodos do atributo código
    void setCodigo(const Codigo &codigo);
    ///
    /// Retorna o código
    ///
    Codigo getCodigo() const;
    ///
    /// Armazena a data inicial
    ///
    // Metodos do atributo data inicial
    void setDataInicial(const Data &dataInicial);
    ///
    /// Retorna a data inicial
    ///
    Data getDataInicial() const;
    ///
    /// Armazena a data final
    ///
    // Metodos do atributo data final
    void setDataFinal(const Data &dataFinal);
    ///
    /// Retorna a data final
    ///
    Data getDataFinal() const;
    ///
    /// Armazena o numero de hospedes
    ///
    // Metodos do atributo hospedes
    void setHospedes(const Numero &hospedes);
    ///
    /// Retorna o numero de hospedes
    ///
    Numero getHospedes() const;
    ///
    /// Armazena o valor
    ///
    // Metodos do atributo valor
    void setValor(const Moeda &valor);
    ///
    /// Retorna o valor
    ///
    Moeda getValor() const;
};

inline void Proposta::setCodigo(const Codigo &codigo){
    this->codigo=codigo;
}

inline Codigo Proposta::getCodigo() const{
    return codigo;
}

inline void Proposta::setDataInicial(const Data &dataInicial){
    this->dataInicial = dataInicial;
}

inline Data Proposta::getDataInicial() const{
    return dataInicial;
}

inline void Proposta::setDataFinal(const Data &dataFinal){
    this->dataFinal=dataFinal;
}

inline Data Proposta::getDataFinal() const{
    return dataFinal;
}

inline void Proposta::setHospedes(const Numero &hospedes){
    this->hospedes=hospedes;
}

inline Numero Proposta::getHospedes() const{
    return hospedes;
}

inline void Proposta::setValor(const Moeda &valor){
    this->valor=valor;
}

inline Moeda Proposta::getValor() const{
    return valor;
}

#endif // ENTIDADES_H_INCLUDED
