#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <stdlib.h>
#include "contato.h"

int salvarContatos(Contato *agenda, int quantidade);
int carregarContatos(Contato *agenda);

#endif