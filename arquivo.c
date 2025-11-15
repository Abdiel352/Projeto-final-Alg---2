#include <stdlib.h>
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

        for (int j = 0; j < agenda[i].num_telefones; j++)
        {
            fprintf(arquivo, "%s%s",
                    agenda[i].telefones[j].numero,
                    (j + 1 < agenda[i].num_telefones) ? "," : "");
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

        // Separar multiplos telefones
        char *tel = strtok(telefones, ",");
        while (tel != NULL)
        {
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

void adicionarTelefone(Contato *contato, const char *telefone)
{
    if (telefone == NULL)
        return;

    Telefone *temp = realloc(contato->telefones,
                             (contato->num_telefones + 1) * sizeof(Telefone));
    if (temp == NULL)
    {
        printf("Erro ao alocar memoria para telefone.\n");
        return;
    }
    contato->telefones = temp;
    strncpy(contato->telefones[contato->num_telefones].numero,
            telefone, sizeof(contato->telefones[0].numero) - 1);
    contato->telefones[contato->num_telefones].numero[sizeof(contato->telefones[0].numero) - 1] = '\0';
    contato->num_telefones++;
}

void liberarContato(Contato *contato)
{
    if (contato->telefones != NULL)
    {
        free(contato->telefones);
        contato->telefones = NULL;
        contato->num_telefones = 0;
    }
}

void salvarEdicao(Contato *agenda, int quantidade, int idEditado)
{
    FILE *arquivo = fopen("contatos.csv", "r");
    FILE *temp = fopen("contatos_temp.csv", "w");

    if (arquivo == NULL || temp == NULL)
    {
        printf("Erro ao abrir arquivos para edicao.\n");
        return;
    }

    int indiceContato = -1;
    for (int i = 0; i < quantidade; i++)
    {
        if (agenda[i].id == idEditado)
        {
            indiceContato = i;
            break;
        }
    }

    if (indiceContato == -1)
    {
        printf("Contato nao encontrado para edicao.\n");
        fclose(arquivo);
        fclose(temp);
        return;
    }

    char linha[1024];
    while (fgets(linha, sizeof(linha), arquivo))
    {
        int id;
        char nome[31], telefones[100], cpf[12], email[31], nascimento[11];

        sscanf(linha, "%d:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]",
               &id, nome, telefones, cpf, email, nascimento);

        if (id == idEditado)
        {
            fprintf(temp, "%d:%s:%s:%s:%s:%s\n",
                    agenda[indiceContato].id,
                    agenda[indiceContato].nome,
                    telefones,
                    agenda[indiceContato].cpf,
                    agenda[indiceContato].email,
                    agenda[indiceContato].nascimento);
        }
        else
        {
            fputs(linha, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("contatos.csv");
    rename("contatos_temp.csv", "contatos.csv");
}