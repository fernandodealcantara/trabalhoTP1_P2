#include "cntrAPTimovel.h"

void CntrApresentacaoImovel::executar() {
    int campo;
    while(true) {
        CLR_SCR;

        cout << "SERVICOS - IMOVEIS" << endl;
        cout << "1 - Listar todos os imoveis." << endl;
        cout << "2 - Pesquisar um imovel pelo codigo." << endl;
        cout << "3 - Retorne para tela inicial." << endl;

        campo = getch() - 48;

        switch(campo){
            case 1:
                listarImoveis();
                break;
            case 2:
                listarImovel();
                break;
            case 3:
                return;
        }
    }
}

void CntrApresentacaoImovel::executar(Email email) {
 int campo;
    while(true) {
        CLR_SCR;

        cout << "---------SERVICOS IMOVEIS---------" << endl;
        cout << "1 - Listar todos os imoveis." << endl;              // Feito
        cout << "2 - Pesquisar um imovel pelo codigo." << endl;      // Feito
        cout << "3 - Cadastrar um imovel." << endl;                  // Feito
        cout << "4 - Editar um imovel." << endl;                     // Feito
        cout << "5 - Descadastrar um imovel." << endl;               // Feito
        cout << "6 - Listar meus imoveis. " << endl;                 // Feito
        cout << "7 - Servicos de propostas." << endl;                // Feito
        cout << "8 - Retorne para tela inicial." << endl;            // Feito

        campo = getch() - 48;

        switch(campo){
            case 1:
                listarImoveis();
                break;
            case 2:
                listarImovel();
                break;
            case 3:
                cadastrarImovel(email);
                break;
            case 4:
                editarImovel(email);
                break;
            case 5:
                descadastrarImovel(email);
                break;
            case 6:
                listarImoveis(email);
                break;
            case 7:
                telaPropostas(email);
                break;
            case 8:
                return;
        }
    }
}

void CntrApresentacaoImovel::descadastrarImovel(Email email) {
    list<Imovel> imoveis = cntr->recuperarImoveis(email);
    list<Imovel> :: iterator imovel;
    Codigo codigo;
    string entrada;
    int campo;
    bool apresentar = true;

    while(apresentar) {
        CLR_SCR;
        cout << "Digite o codigo do imovel que deseja deletar: ";
        try {
            getline(cin, entrada);
            codigo.setCodigo(entrada);
            for(imovel = imoveis.begin(); imovel!= imoveis.end(); ++imovel) {
                if((*imovel).getCodigo().getCodigo() == codigo.getCodigo()){
                    cntr->deletarImovel(*imovel);
                    apresentar = false;
                    cout << "Imovel deletado com sucesso." << endl;
                    cout << "Digite algo para retornar." << endl;
                    getch();
                    return;
                }
            }
            if(imovel == imoveis.end()){
                cout << "Imovel nao encontrado." << endl;
                cout << "Digite algo para retornar." << endl;
                getch();
                return;
            }

        } catch(...) {
            cout << "Codigo invalido ou imovel inexistente." << endl;
            cout << "Pressione:" << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }
}

void CntrApresentacaoImovel::listarImoveis(Email email) {
    list<Imovel> imoveis = cntr->recuperarImoveis(email);
    list<Imovel> :: iterator imovel;
    CLR_SCR;
    cout << "-------------------------LISTA DE IMOVEIS-------------------------" << endl;
    for(imovel = imoveis.begin(); imovel!= imoveis.end(); ++imovel) {
        mostrarImovel(*imovel);
    }
    cout << "Digite algo para retornar." << endl;
    getch();
}

void CntrApresentacaoImovel::descadastrarProposta(Email email) {
    list<Proposta> propostas = cntr->recuperarPropostas(email);
    list<Proposta> :: iterator proposta;
    Codigo codigo;
    string entrada;
    int campo;
    bool apresentar = true;

    while(apresentar) {
        CLR_SCR;
        cout << "Digite o codigo da proposta que deseja deletar: ";
        try {
            getline(cin, entrada);
            codigo.setCodigo(entrada);
            for(proposta = propostas.begin(); proposta!= propostas.end(); ++proposta) {
                if((*proposta).getCodigo().getCodigo() == codigo.getCodigo()){
                    cntr->deletarProposta(codigo);
                    apresentar = false;
                    cout << "Proposta deletada com sucesso." << endl;
                    cout << "Digite algo para retornar." << endl;
                    getch();
                    return;
                }
            }
            if(proposta == propostas.end()){
                cout << "Proposta nao encontrada." << endl;
                cout << "Digite algo para retornar." << endl;
                getch();
                return;
            }

        } catch(...) {
            cout << "Codigo invalido ou proposta inexistente." << endl;
            cout << "Pressione:" << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }
}

void CntrApresentacaoImovel::listarProposta(Email email){
    list<Proposta> propostas = cntr->recuperarPropostas(email);
    list<Proposta> :: iterator proposta;
    Codigo codigo;
    string entrada;
    int campo;
    bool apresentar = true;

    while(apresentar) {
        CLR_SCR;
        cout << "Digite o codigo da proposta que deseja visualizar: ";
        try {
            getline(cin, entrada);
            codigo.setCodigo(entrada);
            for(proposta = propostas.begin(); proposta!= propostas.end(); ++proposta) {
                if((*proposta).getCodigo().getCodigo() == codigo.getCodigo()){
                    cout << "-------------------------PROPOSTA ENCONTRADA-------------------------" << endl;
                    mostrarProposta(*proposta);
                    apresentar = false;
                    cout << "Digite algo para retornar" << endl;
                    getch();
                    return;
                }
            }
            if(proposta == propostas.end()){
                cout << "Proposta nao encontrada" << endl;
                cout << "Digite algo para retornar" << endl;
                getch();
                return;
            }

        } catch(...) {
            cout << "Codigo invalido ou proposta inexistente." << endl;
            cout << "Pressione:" << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }
}


void CntrApresentacaoImovel::listarPropostas(Email email) {
    list<Proposta> propostas = cntr->recuperarPropostas(email);
    list<Proposta> :: iterator proposta;
    CLR_SCR;
    cout << "-------------------------LISTA DE MINHAS PROPOSTAS-------------------------" << endl;
    for(proposta = propostas.begin(); proposta!= propostas.end(); ++proposta) {
        mostrarProposta(*proposta);
    }
    cout << "Digite algo para retornar." << endl;
    getch();
}

void CntrApresentacaoImovel::mostrarProposta(Proposta proposta) {
    cout << "Codigo            : " << proposta.getCodigo().getCodigo() << endl;
    cout << "Data Inicial      : " << proposta.getDataInicial().getData() << endl;
    cout << "Data Final        : " << proposta.getDataFinal().getData() << endl;
    cout << "Numero de Hospedes: " << proposta.getHospedes().getNumero() << endl;
    cout << "Valor R$          : " << proposta.getValor().getMoeda() << endl;
    cout << "---------------------------------------------------------------------"<< endl;
}

void CntrApresentacaoImovel::cadastrarProposta(Email email) {
    int campo;
    string campo1, campo2, campo3, campo4, campo5;
    Data dataInicial, dataFinal;
    Numero hospedes;
    Moeda valor;
    Codigo codigoImovel, codigoProposta;
    Proposta proposta;
    Imovel imovel;

    list<Codigo> codigos = cntr->recuperarCodigosPropostas(email);
    list<Codigo> :: iterator codigo;

    bool apresentar = true;

    while(apresentar) {
        CLR_SCR;
        cout << "----------CADASTRO DE PROPOSTA----------" << endl;
        cout << "Codigo do imovel: ";
        getline(cin, campo2);
        cout << "Data inicial: ";
        getline(cin, campo3);
        cout << "Data final: ";
        getline(cin, campo4);
        cout << "Numero de hospedes: ";
        getline(cin, campo1);
        cout << "Valor proposto: ";
        getline(cin, campo5);


        try {
            codigoImovel.setCodigo(campo2);
            imovel = cntr->recuperarImovel(codigoImovel);

            for(codigo = codigos.begin(); codigo!= codigos.end(); ++codigo) {
                if((*codigo).getCodigo() == codigoImovel.getCodigo()){
                    cout << "Voce ja tem uma proposta cadastrada para esse imovel." << endl;
                    apresentar = false;
                    cout << "Digite algo para retornar" << endl;
                    getch();
                    return;
                }
            }

            dataInicial.setData(campo3);
            dataFinal.setData(campo4);

            int anoFp = stoi(dataFinal.getData().substr(6,2))*365;
            int mesFp = stoi(dataFinal.getData().substr(3,2))*30;
            int diaFp = stoi(dataFinal.getData().substr(0,2));
            int anoIp = stoi(dataInicial.getData().substr(6,2))*365;
            int mesIp = stoi(dataInicial.getData().substr(3,2))*30;
            int diaIp = stoi(dataInicial.getData().substr(0,2));
            int data = (anoFp+mesFp+diaFp) - (anoIp+mesIp+diaIp);
            if(data <= 0){
                throw "Data invalida.";
            }

            int anoFi = stoi(imovel.getDataFinal().getData().substr(6,2))*365;
            int mesFi = stoi(imovel.getDataFinal().getData().substr(3,2))*30;
            int diaFi = stoi(imovel.getDataFinal().getData().substr(0,2));
            int anoIi = stoi(imovel.getDataInicial().getData().substr(6,2))*365;
            int mesIi = stoi(imovel.getDataInicial().getData().substr(3,2))*30;
            int diaIi = stoi(imovel.getDataInicial().getData().substr(0,2));
            if((anoFi+mesFi+diaFi) < (anoFp+mesFp+diaFp))
                throw "Data invalida.";
            if((anoIi+mesIi+diaIi) > (anoIp+mesIp+diaIp))
                throw "Data invalida.";

            hospedes.setNumero(stoi(campo1));
            if(hospedes.getNumero() > imovel.getHospedes().getNumero())
                throw "Quantidade de hospedes invalida.";

            valor.setMoeda(campo5);
            string valorString = valor.getMoeda();
            valorString.erase(remove(valorString.begin(), valorString.end(), '.'), valorString.end());
            int valorCentavos = (stoi(valorString.substr(0, valorString.length()-3))*100);
            valorCentavos += stoi(valorString.substr(valorString.length()-2, 2));

            string valorImovelString = imovel.getValor().getMoeda();
            valorImovelString.erase(remove(valorImovelString.begin(), valorImovelString.end(), '.'), valorImovelString.end());
            int valorImovelCentavos = (stoi(valorImovelString.substr(0, valorImovelString.length()-3))*100);
            valorImovelCentavos += stoi(valorImovelString.substr(valorImovelString.length()-2, 2));

            if(valorImovelCentavos > valorCentavos)
                throw "Valor informado insuficiente.";

            apresentar = false;

            codigoProposta.setCodigo(propostaGeradorCodigo().getCodigo());
        } catch(...) {
            cout << "Algum dado esta em formato invalido ou imovel nao existe." << endl;
            cout << "Atente-se para os requisitos do imovel." << endl;
            cout << "Pressione:" << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar" << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }

    proposta.setCodigo(codigoProposta);
    proposta.setDataInicial(dataInicial);
    proposta.setDataFinal(dataFinal);
    proposta.setHospedes(hospedes);
    proposta.setValor(valor);

    if (cntr->cadastrarProposta(proposta, email, codigoImovel)){
        cout << "Proposta cadastrado com sucesso." << endl;
        cout << "Codigo da proposta: " << proposta.getCodigo().getCodigo() << endl;
        getch();
        return;
    }
    cout << "Falha no cadastramento da proposta. Tente novamente." << endl;
    cout << "Digite para retornar." << endl;
    getch();
}

Codigo CntrApresentacaoImovel::propostaGeradorCodigo() {
    list<Proposta> propostas = cntr->recuperarPropostas();
    Codigo codigo;
    string novo_codigo = "P0000", id;
    id = to_string(stoi(propostas.back().getCodigo().getCodigo().substr(1, 4)) + 1);
    int tam1 = id.length(), tam2 = novo_codigo.length();
    novo_codigo = novo_codigo.substr(0, tam2-tam1)+id;
    codigo.setCodigo(novo_codigo);

    return codigo;
}

void CntrApresentacaoImovel::telaPropostas(Email email) {
    bool apresentar = true;
    int campo_proposta;
    while(apresentar){
        CLR_SCR;
        cout << "---------SERVICOS PROPOSTAS---------" << endl;
        cout << "1 - Listar minhas propostas." << endl;                  // Feito
        cout << "2 - Visualizar proposta." << endl;                      // Feito
        cout << "3 - Efetuar proposta." << endl;                         // Feito
        cout << "4 - Descadastrar proposta." << endl;                    // Feito
        cout << "5 - Propostas a todos os meus imoveis." << endl;        // Feito
        cout << "6 - Visualizar propostas de apenas um imovel." << endl; // Feito
        cout << "7 - Retorne para tela de imoveis." << endl;             // Feito
        campo_proposta = getch() - 48;

        switch(campo_proposta) {
            case 1:
                listarPropostas(email);
                break;
            case 2:
                listarProposta(email);
                break;
            case 3:
                cadastrarProposta(email);
                break;
            case 4:
                descadastrarProposta(email);
                break;
            case 5:
                imoveisPropostas(email);
                break;
            case 6:
                imovelPropostas(email);
                break;
            case 7:
                apresentar = false;
                break;
        }
    }
}

void CntrApresentacaoImovel::imoveisPropostas(Email email) {
    list<Imovel> imoveis = cntr->recuperarImoveis(email);
    list<Imovel> :: iterator imovel;
    Codigo codigo;

    CLR_SCR;
    cout << "-------------------------TODAS AS PROPOSTAS ENCONTRADAS-------------------------" << endl;
    try {
        for(imovel = imoveis.begin(); imovel!= imoveis.end(); ++imovel) {
            codigo = (*imovel).getCodigo();
            cout << "Propostas para o imovel: " << codigo.getCodigo() << endl;
            list<Proposta> propostas = cntr->recuperarPropostas(codigo);
            list<Proposta> :: iterator proposta;
            for(proposta = propostas.begin(); proposta!= propostas.end(); ++proposta) {
                mostrarProposta(*proposta);
            }
        }
    } catch(...) {
        cout << "Codigo invalido ou imovel inexistente." << endl;
    }
    cout << "Digite algo para retornar" << endl;
    getch();
}

void CntrApresentacaoImovel::imovelPropostas(Email email) {
    list<Imovel> imoveis = cntr->recuperarImoveis(email);
    list<Imovel> :: iterator imovel;
    Codigo codigo;
    string entrada;
    int campo;
    bool apresentar = true;

    while(apresentar) {
        CLR_SCR;
        cout << "Digite o codigo do imovel que deseja visualizar as propostas: ";
        try {
            getline(cin, entrada);
            codigo.setCodigo(entrada);
            for(imovel = imoveis.begin(); imovel!= imoveis.end(); ++imovel) {
                if((*imovel).getCodigo().getCodigo() == codigo.getCodigo()){
                    list<Proposta> propostas = cntr->recuperarPropostas(codigo);
                    list<Proposta> :: iterator proposta;
                    for(proposta = propostas.begin(); proposta!= propostas.end(); ++proposta) {
                        cout << "-------------------------PROPOSTAS ENCONTRADAS-------------------------" << endl;
                        mostrarProposta(*proposta);
                    }
                    apresentar = false;
                    cout << "Digite algo para retornar" << endl;
                    getch();
                    return;
                }
            }
            if(imovel == imoveis.end()){
                cout << "Imovel nao encontrado" << endl;
                cout << "Digite algo para retornar" << endl;
                getch();
                return;
            }

        } catch(...) {
            cout << "Codigo invalido ou imovel inexistente." << endl;
            cout << "Pressione:" << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }
}

void CntrApresentacaoImovel::editarImovel(Email email) {
    Codigo codigo;
    Classe classe;
    Descricao descricao;
    Endereco endereco;
    Data dataInicial, dataFinal;
    Numero hospedes;
    Moeda valor;
    Imovel imovel;
    Email email_autenticacao;

    int campo;
    string campo1;
    bool apresentar = true;

    while(apresentar){
        try {
            CLR_SCR;
            cout << "-----ATUALIZACAO DE DADOS DE IMOVEL-----" << endl;
            cout << " Codigo do imovel a ser alterado:" << endl;
            getline(cin, campo1);
            codigo.setCodigo(campo1);
            imovel = cntr->recuperarImovel(codigo);
            email_autenticacao = cntr->recuperarDonoImovel(codigo);
            if (email.getEmail() != email_autenticacao.getEmail()){
                cout << "Voce nao tem permissao para editar esse imovel." << endl;
                getch();
                return;
            }

            cout << "-----IMOVEL A SER EDITADO-----" << endl;
            mostrarImovel(imovel);

            string campo2, campo3, campo4, campo5, campo6, campo7, campo8, campo9;

            cout << "Alterar classe: ";
            getline(cin, campo2);

            cout << "Alterar descricao: ";
            getline(cin, campo3);

            cout << "Alterar endereco: ";
            getline(cin, campo4);

            cout << "Alterar data inicial: ";
            getline(cin, campo5);

            cout << "Alterar data final: ";
            getline(cin, campo6);

            cout << "Alterar hospedes: ";
            getline(cin, campo7);

            cout << "Alterar valor: ";
            getline(cin, campo8);

            classe.setClasse(stoi(campo2));
            descricao.setDescricao(campo3);
            endereco.setEndereco(campo4);
            dataInicial.setData(campo5);
            dataFinal.setData(campo6);
            hospedes.setNumero(stoi(campo7));
            valor.setMoeda(campo8);

            imovel.setClasse(classe);
            imovel.setDescricao(descricao);
            imovel.setEndereco(endereco);
            imovel.setDataInicial(dataInicial);
            imovel.setDataFinal(dataFinal);
            imovel.setHospedes(hospedes);
            imovel.setValor(valor);

            apresentar = false;
        } catch(...){
            cout << "Imovel nao existe ou dados invalidos. Insira novamente." << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }

    if (cntr->alterar(imovel))
        cout << "Dados atualizados com sucesso!" << endl;
    else
        cout << "Falha na atualizacao dos dados!" << endl;
    cout << "Digite algo para retornar." << endl;
    getch();
}

void CntrApresentacaoImovel::cadastrarImovel(Email email) {
    int campo;
    string campo1, campo2, campo3, campo4, campo5, campo6, campo7;
    Codigo codigo;
    Classe classe;
    Descricao descricao;
    Endereco endereco;
    Data dataInicial, dataFinal;
    Numero hospedes;
    Moeda valor;
    Imovel imovel;

    list<Imovel> imoveis = cntr->recuperarImoveis(email);

    if(imoveis.size() > 5){
        cout << "Ja existe 5 imoveis cadastrados no seu email." << endl;
        getch();
        return;
    }

    bool apresentar = true;
    while(apresentar) {
        CLR_SCR;
        cout << "----------CADASTRO DE IMOVEL----------" << endl;
        cout << "Classe do imovel:" << endl;
        cout << "1 - Apartamento." << endl;
        cout << "2 - Casa." << endl;
        cout << "3 - Quarto." << endl;
        getline(cin, campo1);
        cout << "Descricao do imovel: ";
        getline(cin, campo2);
        cout << "Endereco do imovel: ";
        getline(cin, campo3);
        cout << "Numero maximo de hospedes: ";
        getline(cin, campo4);
        cout << "Data inicial de disponibilidade: ";
        getline(cin, campo5);
        cout << "Data final de disponibilidade: ";
        getline(cin, campo6);
        cout << "Valor minimo de diaria: ";
        getline(cin, campo7);
        try {
            classe.setClasse(stoi(campo1));
            descricao.setDescricao(campo2);
            endereco.setEndereco(campo3);
            hospedes.setNumero(stoi(campo4));
            dataInicial.setData(campo5);
            dataFinal.setData(campo6);
            valor.setMoeda(campo7);

            int anoF = stoi(dataFinal.getData().substr(6,2))*365;
            int mesF = stoi(dataFinal.getData().substr(3,2))*30;
            int diaF = stoi(dataFinal.getData().substr(0,2));
            int anoI = stoi(dataInicial.getData().substr(6,2))*365;
            int mesI = stoi(dataInicial.getData().substr(3,2))*30;
            int diaI = stoi(dataInicial.getData().substr(0,2));
            int data = (anoF+mesF+diaF) - (anoI+mesI+diaI);
            if(data <= 0){
                throw "Data invalida";
            }

            apresentar = false;

            codigo.setCodigo(imovelGeradorCodigo().getCodigo());
        } catch(...) {
            cout << "Algum dado esta em formato invalido." << endl;
            cout << "Pressione:" << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar" << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }

    imovel.setCodigo(codigo);
    imovel.setClasse(classe);
    imovel.setDescricao(descricao);
    imovel.setEndereco(endereco);
    imovel.setDataInicial(dataInicial);
    imovel.setDataFinal(dataFinal);
    imovel.setHospedes(hospedes);
    imovel.setValor(valor);
    if (cntr->cadastrarImovel(imovel, email)){
        cout << "Imovel cadastrado com sucesso." << endl;
        cout << "Codigo do imovel: " <<imovel.getCodigo().getCodigo() << endl;
        getch();
        return;
    }
    cout << "Falha no cadastramento do imovel. Tente novamente." << endl;
    cout << "Digite para retornar." << endl;
    getch();
}

Codigo CntrApresentacaoImovel::imovelGeradorCodigo(){
    list<Imovel> imoveis = cntr->recuperarImoveis();
    Codigo codigo;
    string novo_codigo = "I0000", id;
    id = to_string(stoi(imoveis.back().getCodigo().getCodigo().substr(1, 4)) + 1);
    int tam1 = id.length(), tam2 = novo_codigo.length();
    novo_codigo = novo_codigo.substr(0, tam2-tam1)+id;
    codigo.setCodigo(novo_codigo);

    return codigo;
}

void CntrApresentacaoImovel::listarImoveis() {
    list<Imovel> imoveis = cntr->recuperarImoveis();
    list<Imovel> :: iterator imovel;
    CLR_SCR;
    cout << "-------------------------LISTA DE IMOVEIS-------------------------" << endl;
    for(imovel = imoveis.begin(); imovel!= imoveis.end(); ++imovel) {
        mostrarImovel(*imovel);
    }
    cout << "Digite algo para retornar." << endl;
    getch();
}

void CntrApresentacaoImovel::listarImovel(){
    Imovel imovel;
    Codigo codigo;
    string entrada;
    int campo;
    bool apresentar = true;

    while(apresentar) {
        CLR_SCR;
        cout << "Digite o codigo do imovel que deseja visualizar: ";
        try {
            getline(cin, entrada);
            codigo.setCodigo(entrada);
            imovel = cntr->recuperarImovel(codigo);
            apresentar = false;

        } catch(...) {
            cout << "Codigo invalido ou imovel nao registrado." << endl;
            cout << "Pressione:" << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }
    cout << "-------------------------IMOVEL ENCONTRADO-------------------------" << endl;
    mostrarImovel(imovel);
    cout << "Digite algo para retornar" << endl;
    getch();
}

void CntrApresentacaoImovel::mostrarImovel(Imovel imovel) {
    cout << "Codigo            : " <<imovel.getCodigo().getCodigo() << endl;
    cout << "Classe            : ";
    switch(imovel.getClasse().getClasse()){
        case 1:
            cout << "Apartamento." << endl;
            break;
        case 2:
            cout << "Casa." << endl;
            break;
        case 3:
            cout << "Quarto." << endl;
            break;
    }
    cout << "Descricao         : " << imovel.getDescricao().getDescricao() << endl;
    cout << "Endereco          : " << imovel.getEndereco().getEndereco() << endl;
    cout << "Data Inicial      : " << imovel.getDataInicial().getData() << endl;
    cout << "Data Final        : " << imovel.getDataFinal().getData() << endl;
    cout << "Numero de Hospedes: " << imovel.getHospedes().getNumero() << endl;
    cout << "Valor R$          : " << imovel.getValor().getMoeda() << endl;
    cout << "---------------------------------------------------------------------"<< endl;
}
