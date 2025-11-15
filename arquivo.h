#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <stdlib.h>
#include "contato.h"

int salvarContatos(Contato *agenda, int quantidade);
int carregarContatos(Contato *agenda);
void buscarContatoPorId(Contato *agenda, int quantidade, int idBusca, Contato *contatoEncontrado);
void adicionarTelefone(Contato *contato, const char *telefone);
void liberarContato(Contato *contato);
void salvarEdicao(Contato *agenda, int quantidade, int idEditado);

#endif