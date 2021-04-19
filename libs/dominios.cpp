#include <iostream>
#include <regex> // criar expressoes para validar formatos de entrada
#include "dominios.h"


using namespace std;

//Definicoes de metodos da classe Numero

void Numero::validar(int valor){
    const int minimo = 0, maximo = 20;

    if(valor < minimo || valor > maximo)
        throw invalid_argument("Valor invalido. Valores apenas de 0 a 20");
}

void Numero::setNumero(int valor){
    validar(valor);
    this->valor = valor;
}

// Definicoes de metodos da classe Moeda

void Moeda::validar(string valor){
    // expressao regular para verificar o formato da moeda
    regex moeda_modelo("1.000.000,00|[0-9]{1,3}.[0-9]{3},[0-9]{2}|[0-9]{1,3},[0-9]{2}");

    // valor no formato valido retorna true, caso contrario false
    if(!regex_match(valor, moeda_modelo))
        throw invalid_argument("Valor invalido. Valores apenas de 0,00 a 1.000.000,00");
}

void Moeda::setMoeda(string valor){
    validar(valor);
    this->valor = valor;
}

// Definicoes de metodos da classe Descricao

void Descricao::validar(string texto){
    // expressao regular para verificar o formato da descricao
    regex texto_modelo(".{5,30}\\.");

    // descricao valida retorna true, caso contrario false
    if(!regex_match(texto, texto_modelo))
        throw invalid_argument("Descricao invalida. Descricao deve conter entre 5 e 30 caracteres e terminar em ponto.");
}

void Descricao::setDescricao(string texto){
    validar(texto);
    this->texto = texto;
}

// Definicoes de metodos da classe Nome

void Nome::validar(string nome){
    //expressao regular para verificar o formato do nome
    regex nome_modelo("([A-Z][A-Za-z]*\\.? ?)+");
    const int minimo = 5, maximo = 25;
    bool tamanho_valido = (nome.length() >= minimo && nome.length() <= maximo) ? true : false;

    // valida formato do nome e tamanho, caso invalido lanca excecao
    if(!regex_match(nome, nome_modelo) || !tamanho_valido)
        throw invalid_argument("Nome invalido. Apenas 5 a 25 caracteres entre A-Z e a-z, ponto ou espaco.");
}

void Nome::setNome(string nome){
    validar(nome);
    this->nome = nome;
}

// Definicoes de metodos da classe Classe

void Classe::validar(int valor){
    if(valor != APARTAMENTO && valor != CASA && valor != QUARTO)
        throw invalid_argument("Classe invalida. Valores apenas de 1 a 3");
}

void Classe::setClasse(int valor){
    validar(valor);
    switch(valor){
        case 1:
            this->classe = valor;
            break;

        case 2:
            this->classe = valor;
            break;

        case 3:
            this->classe = valor;
            break;
    }
}

// Definicoes de metodos da classe Endereco

void Endereco::validar(string endereco){
    //expressao regular para verificar o formato do endereco
    regex endereco_modelo("([A-Za-z0-9]+\\.? ?)+");
    const int minimo = 5, maximo = 20;
    bool tamanho_valido = (endereco.length() >= minimo && endereco.length() <= maximo) ? true : false;

    // valida formato do endereco e tamanho, caso invalido lanca excecao
    if(!regex_match(endereco, endereco_modelo) || !tamanho_valido)
        throw invalid_argument("Endereco invalido. Apenas 5 a 20 caracteres entre A-Z, a-z, 0-9, ponto ou espaco.");
}

void Endereco::setEndereco(string endereco){
    validar(endereco);
    this->endereco = endereco;
}

// Definicoes de metodos da classe Data

void Data::validar(string data){
    //Expressoes regulares para validar dia(DD), mes(MM) e ano(AA)
    string DD = "(0[1-9]|[1-2][0-9]|3[0-1])";
    string MM = "(0[1-9]|[1][0-2])";
    string AA = "(2[1-9]|[3-9][0-9])";
    regex data_modelo(DD+"-"+MM+"-"+AA);
    bool data_valida = regex_match(data, data_modelo);

    // se o formato da data for valido, verifica se o dia informado eh maior do que a quantidade de dias do mes
    if(data_valida){
        int dia = stoi(data.substr(0, 2)); // dia valor inteiro
        int mes = stoi(data.substr(3, 2)); // mes valor inteiro
        int ano = stoi(data.substr(6, 2)); // ano valor inteiro
        int maximo = 30; // maximo de dias no mes (assumindo 30 dias)
        int meses31[] = {1, 3, 5, 7, 8, 10, 12}; // meses com 31 dias

        if(mes == 2) // se fevereiro
            maximo = (ano % 4 == 0)? 29 : 28; //caso ano bissexto o ultimo dia do mes eh 29 se nao, 28
        else{
            for(auto &mes31 : meses31){ // verifica se o mes eh de 31 dias
                if(mes == mes31)
                    maximo = 31;
            }
        }

        if(dia > maximo)
            data_valida = false;
    }

    if(!data_valida)
        throw invalid_argument("Data invalida. Apenas datas no formato DD-MM-AA");
}

void Data::setData(string data){
    validar(data);
    //ano em formato inteiro para verificar se eh bissexto
    int ano = stoi(data.substr(6, 2));

    this->bissexto = (ano % 4 == 0)? true: false;
    this->data = data;
}

// Definicoes de metodos da classe Codigo

void Codigo::validar(string codigo){
    //expressao regular para validar codigo
    regex codigo_modelo("[A-Z0-9]{5}");
    string codigo_invalido = "00000";

    if(!regex_match(codigo, codigo_modelo) || codigo == codigo_invalido)
        throw invalid_argument("Codigo invalido. Apenas codigo no formato XXXXX, X eh caractere de A-Z ou 0-9");
}

void Codigo::setCodigo(string codigo){
    validar(codigo);
    this->codigo = codigo;
}

// Definicoes de metodos da classe Senha

void Senha::validar(string senha){
    // expressao regular para validar se a senha contem apenas valores de A-Za-z0-9
    // e se contem letra maiuscula, letra minuscula, digito e tamanho 6
    regex senha_modelo("^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z]{6}$");
    // assume que a senha eh valida ate falhar em uma ou todas das condicoes
    bool senha_valida = regex_match(senha, senha_modelo);

    if(senha_valida){
        // verifica ocorrencia de caracteres repetidos
        for(auto &ch : senha){
            int count_char = count(senha.begin(), senha.end(), ch);
            // se count_char for maior que 1, significa que ha repeticoes de caractere
            if (count_char > 1) senha_valida = false;
        }
    }

    if(!senha_valida)
        throw invalid_argument("Senha invalida. Senha deve conter 6 caracteres alfanumericos maiusculos e minusculos nao repetidos.");
}

void Senha::setSenha(string senha){
    validar(senha);
    this->senha = senha;
}

// Definicoes de metodos da classe Email

void Email::validar(string email){
    // expressao regular para validar formato do email
    regex email_modelo("([A-Za-z0-9]\\.?){1,10}@([A-Za-z0-9]\\.?){1,20}");

    if(!regex_match(email, email_modelo))
        throw invalid_argument("Email invalido. Apenas caracteres alfunumericos ou ponto no formato nome@dominio");
}

void Email::setEmail(string email){
    validar(email);
    this->email = email;
}

// Definicoes de metodos da classe Telefone

void Telefone::validar(string telefone){
    // expressao regular para validar formato do telefone
    regex telefone_modelo("\\([0-9]{3}\\)-[0-9]{9}");
    string telefone_invalido = "(000)-000000000";

    if(!regex_match(telefone, telefone_modelo) || telefone == telefone_invalido)
        throw invalid_argument("Telefone invalido. Apenas digitos de 0-9 no formato (XXX)-XXXXXXXXX");

}

void Telefone::setTelefone(string telefone){
    validar(telefone);
    this->telefone = telefone;
}
