#include "cntrAPTusuario.h"

bool CntrApresentacaoUsuario::executar(Email email) {
    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Consultar dados pessoais.";
    char texto3[] = "2 - Editar dados pessoais.";
    char texto4[] = "3 - Excluir meu usuario.";
    char texto5[] = "4 - Retornar.";

    int campo;

    bool apresentar = true;


    while(apresentar) {

        CLR_SCR;
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        campo = getch() - 48;
         switch(campo){
            case 1:
                consultarDadosUsuario(email);
                break;
            case 2:
                editarDadosUsuario(email);
                break;
            case 3:
                if(excluirUsuario(email)){
                    cout << "Usuario excluido com sucesso. Voce nao ira conseguir logar novamente." << endl;
                    getch();
                    return false;
                }
                break;
            case 4:
                apresentar = false;
                break;
        }
    }
    return true;
}

bool CntrApresentacaoUsuario::excluirUsuario(Email email) {
    int campo;
    CLR_SCR;
    cout << "Tem certeza que deseja excluir seu usuario?" << endl;
    cout << "1 - Sim, quero excluir." << endl;
    cout << "2 - Nao tenho certeza." << endl;
    campo = getch() - 48;
    if (campo == 2){
        cout << "Processo cancelado." << endl;
        getch();
        return false;
    }
    if(cntrServicoUsuario->descadastrar(email))
        return true;

    cout << "Falha na exclusao. Tente novamente." << endl;
    getch();
    return false;
}

void CntrApresentacaoUsuario::cadastrar() {
    char texto1[] = "Preencha os seguintes campos:";
    char texto2[] = "Nome            :";
    char texto3[] = "Email           :";
    char texto4[] = "Senha           :";
    char texto5[] = "Telefone        :";
    char texto6[] = "Dados em formato incorreto. Digite algo.";
    char texto7[] = "Sucesso no cadastramento. Digite algo.";
    char texto8[] = "Falha no cadastramento. Digite algo.";
    int campo;
    string campo1, campo2, campo3, campo4;

    Nome nome;
    Email email;
    Senha senha;
    Telefone telefone;

    bool apresentar = true;

    while(apresentar){
        CLR_SCR;
        cout << "-----CADASTRO DE USUARIO-----" << endl;
        cout << texto1 << endl;
        cout << texto2 << " ";
        getline(cin, campo1);
        cout << texto3 << " ";
        getline(cin, campo2);
        cout << texto4 << " ";
        getline(cin, campo3);
        cout << texto5 << " ";
        getline(cin, campo4);

        try {
            nome.setNome(campo1);
            email.setEmail(campo2);
            senha.setSenha(campo3);
            telefone.setTelefone(campo4);

            apresentar = false;
        } catch(invalid_argument &exp) {
            cout << texto6 << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
        }
    }

    Usuario usuario;

    usuario.setNome(nome);
    usuario.setEmail(email);
    usuario.setSenha(senha);
    usuario.setTelefone(telefone);


    if(cntrServicoUsuario->cadastrar(usuario)) {
        cout << texto7 << endl;
        getch();
        return;
    }

    cout << texto8 << endl;
    getch();

    return;
}

void CntrApresentacaoUsuario::consultarDadosUsuario(Email email) {
    Usuario usuario;
    usuario = cntrServicoUsuario->recuperar(email);

    CLR_SCR;
    cout << "DADOS DO USUARIO" << endl;
    cout << "Nome    : " << usuario.getNome().getNome() << endl;
    cout << "Email   : " << usuario.getEmail().getEmail() << endl;
    cout << "Telefone: " << usuario.getTelefone().getTelefone() << endl;
    cout << "Senha   : " << usuario.getSenha().getSenha() << endl;

    cout << "Digite algo para retornar." << endl;
    getch();
}

void CntrApresentacaoUsuario::editarDadosUsuario(Email email) {
    Nome nome;
    Senha senha;
    Telefone telefone;
    Usuario usuario;
    usuario = cntrServicoUsuario->recuperar(email);

    int campo;
    string campo1, campo2, campo3;
    bool apresentar = true;

    while(apresentar){
        try {
            CLR_SCR;
            cout << "-----ATUALIZACAO DE DADOS-----" << endl;
            cout << "---------DADOS ATUAIS---------" << endl;
            cout << "Nome    : " << usuario.getNome().getNome() << endl;
            cout << "Email   : " << usuario.getEmail().getEmail() << endl;
            cout << "Telefone: " << usuario.getTelefone().getTelefone() << endl;
            cout << "Senha   : " << usuario.getSenha().getSenha() << endl;
            cout << "------------------------------" << endl;
            cout << "---------NOVOS DADOS----------" << endl;

            cout << "Alterar nome: ";
            getline(cin, campo1);

            cout << "Alterar senha: ";
            getline(cin, campo2);

            cout << "Alterar telefone: ";
            getline(cin, campo3);

            nome.setNome(campo1);
            senha.setSenha(campo2);
            telefone.setTelefone(campo3);
            usuario.setNome(nome);
            usuario.setSenha(senha);
            usuario.setTelefone(telefone);

            apresentar = false;
        } catch(invalid_argument &exp){
            cout << "Novos dados invalidos. Insira novamente." << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getch() - 48;
            if (campo == 2)
                return;
            getch();
        }
    }


    if (cntrServicoUsuario->alterar(usuario))
        cout << "Dados atualizados com sucesso!" << endl;
    else
        cout << "Falha na atualizacao dos dados!" << endl;
    cout << "Digite algo para retornar." << endl;
    getch();
}
