#include <stdio.h>
#include <string.h>
#include "arquivo.h"


int salvarContatos(Contato *agenda, int quantidade) 
{
    FILE *arquivo = fopen("contatos.csv", "w");
    if (arquivo == NULL) {
        return 0;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s:%s:%s:%s:%s\n",
            agenda[i].nome,
            agenda[i].telefone,
            agenda[i].cpf,
            agenda[i].email,
            agenda[i].nascimento);
    }

    fclose(arquivo);
    return 1;
}

int carregarContatos(Contato *agenda) 
{
    FILE *arquivo = fopen("contatos.csv", "r");
    if (arquivo == NULL) {
        return 0;
    }

    int quantidade = 0;
    char linha[1024];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]",
            agenda[quantidade].nome,
            agenda[quantidade].telefone,
            agenda[quantidade].cpf,
            agenda[quantidade].email,
            agenda[quantidade].nascimento);
        quantidade++;
    }

    fclose(arquivo);
    return quantidade;
}