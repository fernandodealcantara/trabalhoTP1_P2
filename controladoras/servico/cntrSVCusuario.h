#ifndef CONTROLADORASVCUSUARIO_H_INCLUDED
#define CONTROLADORASVCUSUARIO_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string.h>
#include <list>
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"
#include "../../interfaces.h"

#include "../../acessoDB.h"
// 190084197 - 190129794
class CntrServicoUsuario: public IServicoUsuario {
private:
    list<Imovel> recuperarImoveis(Email);
public:
    bool cadastrar(Usuario);
    Usuario recuperar(Email);
    bool alterar(Usuario);
    bool descadastrar(Email);
};



#endif // CONTROLADORASVCUSUARIO_H_INCLUDED
