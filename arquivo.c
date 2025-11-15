<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>
=======

 #include <stdio.h>
>>>>>>> 5de3a2ede841800710e22cf7a02054f3deca38d4
#include <string.h>
#include <stdbool.h>
#include "arquivo.h"

int salvarContatos(Contato *agenda, int quantidade)
{
    FILE *arquivo = fopen("contatos.csv", "w");
    if (arquivo == NULL)
<<<<<<< HEAD
=======
    {
>>>>>>> 5de3a2ede841800710e22cf7a02054f3deca38d4
        return 0;

    for (int i = 0; i < quantidade; i++)
    {
        fprintf(arquivo, "%d:%s:", agenda[i].id, agenda[i].nome);
<<<<<<< HEAD

        for (int j = 0; j < agenda[i].num_telefones; j++)
        {
            fprintf(arquivo, "%s%s",
                    agenda[i].telefones[j].numero,
                    (j + 1 < agenda[i].num_telefones) ? "," : "");
        }

=======
        
        // Salvar telefones separados por vírgula
        for (int j = 0; j < agenda[i].num_telefones; j++) {
            fprintf(arquivo, "%s%s", 
                    agenda[i].telefones[j].numero,
                    j < agenda[i].num_telefones - 1 ? "," : "");
        }
        
>>>>>>> 5de3a2ede841800710e22cf7a02054f3deca38d4
        fprintf(arquivo, ":%s:%s:%s\n",
                agenda[i].cpf,
                agenda[i].email,
                agenda[i].nascimento);
    }

    fclose(arquivo);
    return 1;
}
<<<<<<< HEAD
=======

>>>>>>> 5de3a2ede841800710e22cf7a02054f3deca38d4
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
<<<<<<< HEAD

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

=======

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
        
>>>>>>> 5de3a2ede841800710e22cf7a02054f3deca38d4
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

<<<<<<< HEAD
void adicionarTelefone(Contato *contato, const char *telefone)
{
    if (telefone == NULL)
        return;

    Telefone *temp = realloc(contato->telefones,
                             (contato->num_telefones + 1) * sizeof(Telefone));
    if (temp == NULL)
    {
        printf("Erro ao alocar memória para telefone.\n");
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
=======
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
>>>>>>> 5de3a2ede841800710e22cf7a02054f3deca38d4
        free(contato->telefones);
        contato->telefones = NULL;
        contato->num_telefones = 0;
    }
<<<<<<< HEAD
}

void salvarEdicao(Contato *agenda, int quantidade, int idEditado)
{
    FILE *arquivo = fopen("contatos.csv", "r");
    FILE *temp = fopen("contatos_temp.csv", "w");

    if (arquivo == NULL || temp == NULL)
    {
        printf("Erro ao abrir arquivos para edição.\n");
        return;
    }

    // Primeiro encontra o índice correto no array
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
        printf("Contato não encontrado para edição.\n");
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
            // Usa o índice correto do array para acessar os dados atualizados
            fprintf(temp, "%d:%s:%s:%s:%s:%s\n",
                    agenda[indiceContato].id,
                    agenda[indiceContato].nome,
                    telefones, // Mantém os telefones originais
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
=======
>>>>>>> 5de3a2ede841800710e22cf7a02054f3deca38d4
}