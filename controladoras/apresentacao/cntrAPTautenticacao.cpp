#include "cntrAPTautenticacao.h"

bool CntrApresentacaoAutenticacao::autenticar(Email *email) {
    char texto1[]="Digite o email: ";
    char texto2[]="Digite a senha: ";

    string campo1, campo2;

    Senha senha;

    while(true) {
        CLR_SCR;

        cout << texto1;
        getline(cin, campo1);
        cout << texto2;
        getline(cin, campo2);

        try {
            email->setEmail(campo1);
            senha.setSenha(campo2);
            break;
        } catch (invalid_argument &exp) {
            CLR_SCR;
            return false;
        }
    }
    return (cntr->autenticar(*email, senha));
}
