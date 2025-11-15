#ifndef MENU_H
#define MENU_H

#include "contato.h"

void menuCadastro(Contato *agenda, int *quantidade);
void menuExcluir(Contato *agenda, int *quantidade);

void menuEditar(Contato *agenda, int *quantidade);

void menuConsultar(Contato *agenda, int quantidade);

void menuCadastrarTelefonePorNome(Contato *agenda, int *quantidade);
void menuCadastrarTelefonePorID(Contato *agenda, int *quantidade);
void menuEditarPorNome(Contato *agenda, int *quantidade);
void menuEditarPorID(Contato *agenda, int *quantidade);
void excluirPessoa(Contato *agenda, int *quantidade);
void excluirTelefone(Contato *agenda, int *quantidade);

#endif