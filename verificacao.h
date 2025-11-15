#ifndef VERIFICACAO_H
#define VERIFICACAO_H

#include <stdbool.h>
#include "contato.h"
#include "menu.h"

bool verificarTelefoneExistente(const char *telefone);
bool validarCpf(Contato *agenda);
bool verificarEmailExistente(Contato *agenda);
bool validarNascimento(Contato *agenda);
bool verificarNome(const char *nome, Contato *agenda, int quantidade);

#endif