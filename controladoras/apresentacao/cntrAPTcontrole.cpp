#include "cntrAPTcontrole.h"

void CntrApresentacaoControle::executar(){

    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Acessar o sistema.";
    char texto3[] = "2 - Cadastrar-se no sistema.";
    char texto4[] = "3 - Acessar dados sobre imoveis.";
    char texto5[] = "4 - Encerrar execucao do sistema.";

    char texto6[] = "Selecione um dos servicos : ";
    char texto7[] = "1 - Servicos de usuario.";
    char texto8[] = "2 - Servicos de imoveis.";
    char texto9[] = "3 - Encerrar sessao.";

    char texto10[] = "Dados incorretos ou falha na autenticacao. Tente novamente.";

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
                if(cntrApresentacaoAutenticacao->autenticar(&email)) {
                    bool apresentar = true;
                    while(apresentar){
                        CLR_SCR;
                        cout << texto6 << endl;
                        cout << texto7 << endl;
                        cout << texto8 << endl;
                        cout << texto9 << endl;

                        campo = getch() - 48;

                        switch(campo) {
                            case 1:
                                if(!cntrApresentacaoUsuario->executar(email)){
                                    apresentar = false;
                                    CLR_SCR;
                                    cout << "Usuario nao existe" << endl;
                                    getch();
                                }
                                break;
                            case 2:
                                cntrApresentacaoImovel->executar(email);
                                break;
                            case 3: apresentar = false;
                                break;
                        }
                    }
                } else {
                    CLR_SCR;
                    cout << texto10 << endl;
                    getch();
                }
                break;
            case 2:
                cntrApresentacaoUsuario->cadastrar();
                break;
            case 3:
                cntrApresentacaoImovel->executar();
                break;
            case 4:
                apresentar = false;
                break;
        }
    }
    return;
}
