#ifndef VERIFICACAO_H
#define VERIFICACAO_H

#include <stdbool.h>
#include "contato.h"
#include "menu.h"

bool verificarTelefoneExistente(Contato *agenda);
bool validarCpf(Contato *agenda);
bool verificarEmailExistente(Contato *agenda);
bool validarNascimento(Contato *agenda);
bool verificarNome(Contato *agenda, int *quantidade);

#endif