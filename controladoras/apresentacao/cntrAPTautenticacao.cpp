#include "cntrAPTautenticacao.h"

bool CntrApresentacaoAutenticacao::autenticar(Email *email) {
    char texto1[]="Digite o Email  : ";
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo.";

    char campo1[80], campo2[80];

    int linha, coluna;

    getmaxyx(stdscr, linha, coluna);

    Senha senha;

    echo();

    while(true) {
        clear();
        mvprintw(linha/4, coluna/4, "%s", texto1);
        getstr(campo1);
        mvprintw(linha/4 + 2, coluna/4, "%s", texto2);
        getstr(campo2);

        try {
            email->setEmail(string(campo1));
            senha.setSenha(string(campo2));
            break;
        } catch (invalid_argument &exp) {
            clear();
            mvprintw(linha/4, coluna/4, "%s", texto3);
            noecho();
            getch();
            echo();
        }
    }
    return (cntr->autenticar(*email, senha));
}