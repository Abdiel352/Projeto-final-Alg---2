
 #include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "arquivo.h"

int salvarContatos(Contato *agenda, int quantidade)
{
    FILE *arquivo = fopen("contatos.csv", "w");
    if (arquivo == NULL)
    {
        return 0;
    }

    for (int i = 0; i < quantidade; i++)
    {
        fprintf(arquivo, "%d:%s:", agenda[i].id, agenda[i].nome);
        
        // Salvar telefones separados por vírgula
        for (int j = 0; j < agenda[i].num_telefones; j++) {
            fprintf(arquivo, "%s%s", 
                    agenda[i].telefones[j].numero,
                    j < agenda[i].num_telefones - 1 ? "," : "");
        }
        
        fprintf(arquivo, ":%s:%s:%s\n",
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
    if (arquivo == NULL)
    {
        return 0;
    }

    int quantidade = 0;
    char linha[1024];
    char telefones[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        agenda[quantidade].telefones = NULL;
        agenda[quantidade].num_telefones = 0;

        char *token;
        char *rest = linha;
        
        // Ler ID
        token = strtok_r(rest, ":", &rest);
        agenda[quantidade].id = atoi(token);
        
        // Ler nome
        token = strtok_r(NULL, ":", &rest);
        strcpy(agenda[quantidade].nome, token);
        
        // Ler telefones
        token = strtok_r(NULL, ":", &rest);
        strcpy(telefones, token);
        
        // Separar múltiplos telefones
        char *tel = strtok(telefones, ",");
        while (tel != NULL) {
            adicionarTelefone(&agenda[quantidade], tel);
            tel = strtok(NULL, ",");
        }
        
        // Ler demais campos
        token = strtok_r(NULL, ":", &rest);
        strcpy(agenda[quantidade].cpf, token);
        
        token = strtok_r(NULL, ":", &rest);
        strcpy(agenda[quantidade].email, token);
        
        token = strtok_r(NULL, "\n", &rest);
        strcpy(agenda[quantidade].nascimento, token);
        
        quantidade++;
    }

    fclose(arquivo);
    return quantidade;
}

void buscarContatoPorId(Contato *agenda, int quantidade, int idBusca, Contato *contatoEncontrado)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (agenda[i].id == idBusca)
        {
            *contatoEncontrado = agenda[i];
            return;
        }
    }
    memset(contatoEncontrado, 0, sizeof(Contato));
}

Contato* buscarContatoPorNomeEId(Contato *agenda, int quantidade, const char *nome, int id)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (agenda[i].id == id && strcmp(agenda[i].nome, nome) == 0)
        {
            return &agenda[i];
        }
    }
    return NULL;
}

void adicionarTelefone(Contato *contato, const char *telefone) {
    contato->num_telefones++;
    Telefone *temp = (Telefone*)realloc(contato->telefones, 
                                     contato->num_telefones * sizeof(Telefone));
    if (temp != NULL) {
        contato->telefones = temp;
        strcpy(contato->telefones[contato->num_telefones - 1].numero, telefone);
    } else {
        contato->num_telefones--;
        printf("Erro ao alocar memória para o telefone!\n");
    }
}

void liberarContato(Contato *contato) {
    if (contato->telefones != NULL) {
        free(contato->telefones);
        contato->telefones = NULL;
        contato->num_telefones = 0;
    }
}