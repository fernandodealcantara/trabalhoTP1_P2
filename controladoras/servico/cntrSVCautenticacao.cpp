#include "cntrSVCautenticacao.h"

bool CntrServicoAutenticacao::autenticar(Email email, Senha senha) {
    ComandoLerSenha lerSenha(email);
    if (!lerSenha.executar())
        return 0;
    string senhaRecuperada;
    senhaRecuperada = lerSenha.getResultado();
    return (senha.getSenha() == senhaRecuperada);
}
