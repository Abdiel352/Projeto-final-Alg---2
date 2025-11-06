#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <stdlib.h>
#include "contato.h"

int salvarContatos(Contato *agenda, int quantidade);
int carregarContatos(Contato *agenda);
void buscarContatoPorId(Contato *agenda, int quantidade, int idBusca, Contato *contatoEncontrado);
Contato *buscarContatoPorNomeEId(Contato *agenda, int quantidade, const char *nome, int id);
void adicionarTelefone(Contato *contato, const char *telefone);
void liberarContato(Contato *contato);

#endif