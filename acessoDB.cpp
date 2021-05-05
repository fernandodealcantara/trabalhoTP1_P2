//---------------------------------------------------------------------------

#include "acessoDB.h"

//Atributo estático container List.

list<ElementoResultado> ComandoSQL::listaResultado;


//---------------------------------------------------------------------------
//Classe ElementoResultado.

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}


//---------------------------------------------------------------------------
//Classe ComandoSQL.

bool ComandoSQL::conectar() {
    rc = sqlite3_open(nomeBancoDados, &bd);
    if( rc != SQLITE_OK )
        return 0;
    return 1;
}

bool ComandoSQL::desconectar() {
    rc =  sqlite3_close(bd);
    if( rc != SQLITE_OK )
        return 0;
    return 1;
}

bool ComandoSQL::executar() {
    if(!conectar())
        return 0;

    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
    if(rc != SQLITE_OK){
            sqlite3_free(mensagem);
            desconectar();
    }
    desconectar();

    return 1;
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
    NotUsed=0;
    ElementoResultado elemento;
    int i;
    for(i=0; i<argc; i++){
    elemento.setNomeColuna(nomeColuna[i]);
    elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
    listaResultado.push_front(elemento);
    }
    return 0;
}

//---------------------------------------------------------------------------
//Classe ComandoLerSenha.

ComandoLerSenha::ComandoLerSenha(Email email) {
    comandoSQL = "SELECT senha FROM usuarios WHERE email = '";
    comandoSQL += email.getEmail();
    comandoSQL += "'";
}

string ComandoLerSenha::getResultado() {
    ElementoResultado resultado;
    string senha;

    //Remover senha;
    if (listaResultado.empty())
        return "Erro";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha = resultado.getValorColuna();

    return senha;
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarUsuario.

ComandoPesquisarUsuario::ComandoPesquisarUsuario(Email email) {
    comandoSQL = "SELECT * FROM usuarios WHERE email = '";
    comandoSQL += email.getEmail();
    comandoSQL += "'";
}

Usuario ComandoPesquisarUsuario::getResultado() {
    ElementoResultado resultado;
    Nome nome;
    Email email;
    Senha senha;
    Telefone telefone;
    Usuario usuario;

    // Remover nome;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    nome.setNome(resultado.getValorColuna());

    // Remover email;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    email.setEmail(resultado.getValorColuna());

    // Remover senha;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha.setSenha(resultado.getValorColuna());

    // Remover telefone;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    telefone.setTelefone(resultado.getValorColuna());

    usuario.setNome(nome);
    usuario.setEmail(email);
    usuario.setSenha(senha);
    usuario.setTelefone(telefone);

    return usuario;
}

//---------------------------------------------------------------------------
//Classe ComandoCadastrarUsuario.

ComandoCadastrarUsuario::ComandoCadastrarUsuario(Usuario usuario) {
    comandoSQL = "INSERT INTO usuarios VALUES (";
    comandoSQL += "'";
    comandoSQL += usuario.getNome().getNome();
    comandoSQL += "', '";
    comandoSQL += usuario.getEmail().getEmail();
    comandoSQL += "', '";
    comandoSQL += usuario.getSenha().getSenha();
    comandoSQL += "', '";
    comandoSQL += usuario.getTelefone().getTelefone();
    comandoSQL += "')";
}


//---------------------------------------------------------------------------
//Classe ComandoAtualizarUsuario.

ComandoAtualizarUsuario::ComandoAtualizarUsuario(Usuario usuario) {
    comandoSQL = "UPDATE usuarios ";
    comandoSQL += "SET nome = '" + usuario.getNome().getNome();
    comandoSQL += "', senha = '" + usuario.getSenha().getSenha();
    comandoSQL += "', telefone = '" + usuario.getTelefone().getTelefone();
    comandoSQL += "' WHERE email = '" + usuario.getEmail().getEmail() + "'";
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarImoveis.
ComandoPesquisarImoveis::ComandoPesquisarImoveis() {
    comandoSQL = "SELECT * FROM IMOVEIS";
}

ComandoPesquisarImoveis::ComandoPesquisarImoveis(Email email) {
    comandoSQL = "SELECT * FROM imoveis WHERE email = '";
    comandoSQL += email.getEmail();
    comandoSQL += "'";
}

list<Imovel> ComandoPesquisarImoveis::getResultado() {
    ElementoResultado resultado;
    list<Imovel> imoveis;
    Codigo codigo;
    Classe classe;
    Descricao descricao;
    Endereco endereco;
    Data dataInicial;
    Data dataFinal;
    Numero hospedes;
    Moeda moeda;
    Email email;
    Imovel imovel;

    while(!listaResultado.empty()){
        resultado = listaResultado.back();
        listaResultado.pop_back();

        codigo.setCodigo(resultado.getValorColuna());

        resultado = listaResultado.back();
        listaResultado.pop_back();
        classe.setClasse(stoi(resultado.getValorColuna()));

        resultado = listaResultado.back();
        listaResultado.pop_back();
        descricao.setDescricao(resultado.getValorColuna());

        resultado = listaResultado.back();
        listaResultado.pop_back();
        endereco.setEndereco(resultado.getValorColuna());

        resultado = listaResultado.back();
        listaResultado.pop_back();
        dataInicial.setData(resultado.getValorColuna());

        resultado = listaResultado.back();
        listaResultado.pop_back();
        dataFinal.setData(resultado.getValorColuna());

        resultado = listaResultado.back();
        listaResultado.pop_back();
        hospedes.setNumero(stoi(resultado.getValorColuna()));

        resultado = listaResultado.back();
        listaResultado.pop_back();
        moeda.setMoeda(resultado.getValorColuna());

        resultado = listaResultado.back();
        listaResultado.pop_back();
        email.setEmail(resultado.getValorColuna());

        imovel.setCodigo(codigo);
        imovel.setClasse(classe);
        imovel.setDescricao(descricao);
        imovel.setEndereco(endereco);
        imovel.setDataInicial(dataInicial);
        imovel.setDataFinal(dataFinal);
        imovel.setHospedes(hospedes);
        imovel.setValor(moeda);

        imoveis.push_back(imovel);
    }
    return imoveis;
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarImovel.
ComandoPesquisarImovel::ComandoPesquisarImovel(Codigo codigo) {
    comandoSQL = "SELECT * FROM imoveis WHERE codigo = '";
    comandoSQL += codigo.getCodigo();
    comandoSQL += "'";
}

Imovel ComandoPesquisarImovel::getResultado() {
    ElementoResultado resultado;

    Codigo codigo;
    Classe classe;
    Descricao descricao;
    Endereco endereco;
    Data dataInicial, dataFinal;
    Numero hospedes;
    Moeda valor;
    Email email;

    Imovel imovel;

    // Remover codigo;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo.setCodigo(resultado.getValorColuna());

    // Remover classe;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    classe.setClasse(stoi(resultado.getValorColuna()));

    // Remover descricao;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    descricao.setDescricao(resultado.getValorColuna());

    // Remover endereco;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    endereco.setEndereco(resultado.getValorColuna());

    // Remover data inicial;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    dataInicial.setData(resultado.getValorColuna());

    // Remover data final;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    dataFinal.setData(resultado.getValorColuna());

    // Remover hospedes;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    hospedes.setNumero(stoi(resultado.getValorColuna()));

    // Remover valor;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    valor.setMoeda(resultado.getValorColuna());

    // Remover email;
    if (listaResultado.empty())
            throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    email.setEmail(resultado.getValorColuna());

    imovel.setCodigo(codigo);
    imovel.setClasse(classe);
    imovel.setDescricao(descricao);
    imovel.setEndereco(endereco);
    imovel.setDataInicial(dataInicial);
    imovel.setDataFinal(dataFinal);
    imovel.setHospedes(hospedes);
    imovel.setValor(valor);

    return imovel;
}

//Classe ComandoPesquisarDonoImovel.
ComandoPesquisarDonoImovel::ComandoPesquisarDonoImovel(Codigo codigo) {
    comandoSQL = "SELECT email FROM imoveis WHERE codigo = '";
    comandoSQL += codigo.getCodigo();
    comandoSQL += "'";
}

Email ComandoPesquisarDonoImovel::getResultado() {
    ElementoResultado resultado;
    Email email;

    //Remover email;
    if (listaResultado.empty())
        throw "not found";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    email.setEmail(resultado.getValorColuna());

    return email;
}

//Classe ComandoCadastrarImovel.
ComandoCadastrarImovel::ComandoCadastrarImovel(Imovel imovel, Email email) {
    comandoSQL = "INSERT INTO imoveis VALUES (";
    comandoSQL += "'";
    comandoSQL += imovel.getCodigo().getCodigo();
    comandoSQL += "', '";
    comandoSQL += to_string(imovel.getClasse().getClasse());
    comandoSQL += "', '";
    comandoSQL += imovel.getDescricao().getDescricao();
    comandoSQL += "', '";
    comandoSQL += imovel.getEndereco().getEndereco();
    comandoSQL += "', '";
    comandoSQL += imovel.getDataInicial().getData();
    comandoSQL += "', '";
    comandoSQL += imovel.getDataFinal().getData();
    comandoSQL += "', '";
    comandoSQL += to_string(imovel.getHospedes().getNumero());
    comandoSQL += "', '";
    comandoSQL += imovel.getValor().getMoeda();
    comandoSQL += "', '";
    comandoSQL += email.getEmail();
    comandoSQL += "')";
}

//Classe ComandoAtualizarImovel.
ComandoAtualizarImovel::ComandoAtualizarImovel(Imovel imovel) {
    comandoSQL = "UPDATE imoveis ";
    comandoSQL += "SET classe = '" + to_string(imovel.getClasse().getClasse());
    comandoSQL += "', descricao = '" + imovel.getDescricao().getDescricao();
    comandoSQL += "', endereco = '" + imovel.getEndereco().getEndereco();
    comandoSQL += "', data_inicial = '" + imovel.getDataInicial().getData();
    comandoSQL += "', data_final = '" + imovel.getDataFinal().getData();
    comandoSQL += "', hospedes = '" + to_string(imovel.getHospedes().getNumero());
    comandoSQL += "', valor = '" + imovel.getValor().getMoeda();
    comandoSQL += "' WHERE codigo = '" + imovel.getCodigo().getCodigo() + "'";
}

//Classe ComandoCadastrarImovel.
ComandoCadastrarProposta::ComandoCadastrarProposta(Proposta proposta, Email email, Codigo codigo) {
    comandoSQL = "INSERT INTO propostas VALUES (";
    comandoSQL += "'";
    comandoSQL += proposta.getCodigo().getCodigo();
    comandoSQL += "', '";
    comandoSQL += proposta.getDataInicial().getData();
    comandoSQL += "', '";
    comandoSQL += proposta.getDataFinal().getData();
    comandoSQL += "', '";
    comandoSQL += to_string(proposta.getHospedes().getNumero());
    comandoSQL += "', '";
    comandoSQL += proposta.getValor().getMoeda();
    comandoSQL += "', '";
    comandoSQL += email.getEmail();
    comandoSQL += "', '";
    comandoSQL += codigo.getCodigo();
    comandoSQL += "')";
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarPropostas.
ComandoPesquisarPropostas::ComandoPesquisarPropostas() {
    comandoSQL = "SELECT * FROM PROPOSTAS";
}

ComandoPesquisarPropostas::ComandoPesquisarPropostas(Email email) {
    comandoSQL = "SELECT * FROM propostas WHERE email = '";
    comandoSQL += email.getEmail();
    comandoSQL += "'";
}

ComandoPesquisarPropostas::ComandoPesquisarPropostas(Codigo codigo) {
    comandoSQL = "SELECT * FROM propostas WHERE codigo_imovel = '";
    comandoSQL += codigo.getCodigo();
    comandoSQL += "'";
}

list<Proposta> ComandoPesquisarPropostas::getResultado() {
    ElementoResultado resultado;
    list<Proposta> propostas;

    Codigo codigo;
    Data dataInicial;
    Data dataFinal;
    Numero hospedes;
    Moeda moeda;
    Proposta proposta;

    while(!listaResultado.empty()){
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo.setCodigo(resultado.getValorColuna());


        resultado = listaResultado.back();
        listaResultado.pop_back();
        dataInicial.setData(resultado.getValorColuna());

        resultado = listaResultado.back();
        listaResultado.pop_back();
        dataFinal.setData(resultado.getValorColuna());

        resultado = listaResultado.back();
        listaResultado.pop_back();
        hospedes.setNumero(stoi(resultado.getValorColuna()));

        resultado = listaResultado.back();
        listaResultado.pop_back();
        moeda.setMoeda(resultado.getValorColuna());

        listaResultado.pop_back(); // Remove email
        listaResultado.pop_back(); // Remove codigo imovel

        proposta.setCodigo(codigo);
        proposta.setDataInicial(dataInicial);
        proposta.setDataFinal(dataFinal);
        proposta.setHospedes(hospedes);
        proposta.setValor(moeda);

        propostas.push_back(proposta);
    }
    return propostas;
}

list<Codigo> ComandoPesquisarCodigosImoveisPropostos::getResultado() {
    ElementoResultado resultado;
    list<Codigo> codigos;

    Codigo codigo;

    while(!listaResultado.empty()){
        resultado = listaResultado.back(); // Armazena codigo imovel
        listaResultado.pop_back(); // Tira codigo imovel
        codigo.setCodigo(resultado.getValorColuna());

        codigos.push_back(codigo);
    }
    return codigos;
}


//---------------------------------------------------------------------------
//Classe ComandoPesquisarCodigosImoveisPropostos.
ComandoPesquisarCodigosImoveisPropostos::ComandoPesquisarCodigosImoveisPropostos(Email email) {
    comandoSQL = "SELECT codigo_imovel FROM propostas WHERE email = '";
    comandoSQL += email.getEmail();
    comandoSQL += "'";
}

//---------------------------------------------------------------------------
//Classe ComandoDeletarProposta.

ComandoDeletarProposta::ComandoDeletarProposta(Codigo codigo) {
        comandoSQL = "DELETE FROM propostas WHERE codigo = '";
        comandoSQL += codigo.getCodigo();
        comandoSQL += "'";
}

ComandoDeletarProposta::ComandoDeletarProposta(Imovel imovel) {
        comandoSQL = "DELETE FROM propostas WHERE codigo_imovel = '";
        comandoSQL += imovel.getCodigo().getCodigo();
        comandoSQL += "'";
}
ComandoDeletarProposta::ComandoDeletarProposta(Email email) {
        comandoSQL = "DELETE FROM propostas WHERE email = '";
        comandoSQL += email.getEmail();
        comandoSQL += "'";
}

//---------------------------------------------------------------------------
// ComandoDeletarImovel
ComandoDeletarImovel::ComandoDeletarImovel(Codigo codigo) {
    comandoSQL = "DELETE FROM imoveis WHERE codigo = '";
    comandoSQL += codigo.getCodigo();
    comandoSQL += "'";
}

//---------------------------------------------------------------------------
// ComandoDeletarUsuario
ComandoDeletarUsuario::ComandoDeletarUsuario(Email email) {
    comandoSQL = "DELETE FROM usuarios WHERE email = '";
    comandoSQL += email.getEmail();
    comandoSQL += "'";
}
