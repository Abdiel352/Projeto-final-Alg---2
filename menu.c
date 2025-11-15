#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "verificacao.h"
#include "arquivo.h"

void menuCadastro(Contato *agenda, int *quantidade)
{
    int condicao = 1;
    do
    {
        printf("=== Menu de Cadastro ===\n");
        printf("1. Pessoa\n");
        printf("2. Telefone\n");
        printf("3. Voltar\n");

        scanf("%d", &condicao);
        bool dadosValidos = false;
        switch (condicao)
        {
        case 1:
            printf("=== Casdastrar Pessoa ===\n");
            if (*quantidade <= 100)
            {
                while (!dadosValidos)
                {
                    printf("Digite o nome: ");
                    scanf("%30s", agenda[*quantidade].nome);
                    if (verificarNome(agenda[*quantidade].nome, agenda, *quantidade))
                    {
                        dadosValidos = true;
                    }
                    else
                    {
                        printf("Nome invalido. O nome deve ter pelo menos 2 caracteres.\n");
                    }
                }

                dadosValidos = false;
                while (!dadosValidos)
                {
                    printf("Digite a data de nascimento: ");
                    scanf("%10s", agenda[*quantidade].nascimento);
                    if (validarNascimento(&agenda[*quantidade]))
                    {
                        dadosValidos = true;
                    }
                    else
                    {
                        printf("Data de nascimento inválida! Use o formato DD/MM/AAAA\n");
                    }
                }

                dadosValidos = false;
                while (!dadosValidos)
                {
                    printf("Digite o CPF: ");
                    scanf("%11s", agenda[*quantidade].cpf);
                    if (validarCpf(&agenda[*quantidade]))
                    {
                        dadosValidos = true;
                    }
                    else
                    {
                        printf("CPF Inválido. Digite novamente.\n");
                    }
                }

                dadosValidos = false;
                while (!dadosValidos)
                {
                    printf("Digite o email: ");
                    scanf("%30s", agenda[*quantidade].email);
                    if (verificarEmailExistente(&agenda[*quantidade]))
                    {
                        dadosValidos = true;
                    }
                    else
                    {
                        printf("E-mail Inválido. Deve conter @ e ter pelo menos 10 caracteres.\n");
                    }
                }

                (*quantidade)++;
                printf("Contato cadastrado com sucesso!\n");
            }
            else if (*quantidade > 100)
            {
                Contato *temp = realloc(agenda, sizeof(Contato) * (*quantidade + 1));
                if (temp == NULL)
                {
                    printf("Erro ao alocar memória!\n");
                    return;
                }
                agenda = temp;

                while (!dadosValidos)
                {
                    printf("Digite o nome: ");
                    scanf("%30s", agenda[*quantidade].nome);
                    if (verificarNome(agenda[*quantidade].nome, agenda, *quantidade))
                    {
                        dadosValidos = true;
                    }
                    else
                    {
                        printf("Nome invalido. O nome deve ter pelo menos 2 caracteres.\n");
                    }
                }
                dadosValidos = false;
                while (!dadosValidos)
                {
                    printf("Digite a data de nascimento: ");
                    scanf("%10s", agenda[*quantidade].nascimento);
                    if (validarNascimento(&agenda[*quantidade]))
                    {
                        dadosValidos = true;
                    }
                    else
                    {
                        printf("Data de nascimento inválida! Use o formato DD/MM/AAAA\n");
                    }
                }

                dadosValidos = false;
                while (!dadosValidos)
                {
                    printf("Digite o CPF: ");
                    scanf("%11s", agenda[*quantidade].cpf);
                    if (validarCpf(&agenda[*quantidade]))
                    {
                        dadosValidos = true;
                    }
                    else
                    {
                        printf("CPF Inválido. Digite novamente.\n");
                    }
                }

                dadosValidos = false;
                while (!dadosValidos)
                {
                    printf("Digite o email: ");
                    scanf("%30s", agenda[*quantidade].email);
                    if (verificarEmailExistente(&agenda[*quantidade]))
                    {
                        dadosValidos = true;
                    }
                    else
                    {
                        printf("E-mail Inválido. Deve conter @ e ter pelo menos 10 caracteres.\n");
                    }
                }

                (*quantidade)++;
                printf("Contato cadastrado com sucesso!\n");
            }

            printf("Deseja cadastrar um telefone para esta pessoa? (S/N): ");
            char resposta;
            scanf(" %c", &resposta); // Espaço antes do %c para ignorar whitespace

            agenda[*quantidade - 1].telefones = NULL; // Inicializar como NULL
            agenda[*quantidade - 1].num_telefones = 0;

            if (resposta == 'S' || resposta == 's')
            {
                dadosValidos = false;
                char novoTelefone[12];
                while (!dadosValidos)
                {
                    printf("Digite o telefone: ");
                    scanf("%11s", novoTelefone);
                    if (verificarTelefoneExistente(novoTelefone))
                    {
                        adicionarTelefone(&agenda[*quantidade - 1], novoTelefone);
                        printf("Telefone cadastrado com sucesso!\n");
                        dadosValidos = true;
                    }
                    else
                    {
                        printf("Telefone inválido. Deve ter 10 ou 11 dígitos.\n");
                    }
                }
            }
            agenda[*quantidade - 1].id = *quantidade - 1;
            salvarContatos(agenda, *quantidade);
            break;

        case 2:
            printf("=== Cadastrar telefone ===\n");
            printf("=== Pesquisar por =====\n");
            printf("Nome(1)\n");
            printf("IDpessoa(2)\n");
            printf("Retornar(3)\n");

            {
                int opcaoTelefone;
                scanf("%d", &opcaoTelefone);

                switch (opcaoTelefone)
                {
                case 1:
                    menuCadastrarTelefonePorNome(agenda, quantidade);
                    break;
                case 2:
                    menuCadastrarTelefonePorID(agenda, quantidade);
                    break;
                case 3:
                    printf("Voltando ao menu principal...\n");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                    break;
                }
            }
            break;

        case 3:
            printf("Voltando ao menu principal...\n");
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (condicao != 3);
}

void menuCadastrarTelefonePorNome(Contato *agenda, int *quantidade)
{
    char nomeBusca[31];
    printf("Digite o nome da pessoa para adicionar o telefone: ");
    scanf("%30s", nomeBusca);

    for (int i = 0; i < *quantidade; i++)
    {
        if (strcmp(agenda[i].nome, nomeBusca) == 0)
        {
            char novoTelefone[12];
            printf("Digite o telefone: ");
            scanf("%11s", novoTelefone);

            if (!verificarTelefoneExistente(novoTelefone))
            {
                printf("Telefone inválido. Não foi cadastrado.\n");
                return;
            }

            adicionarTelefone(&agenda[i], novoTelefone);
            if (salvarContatos(agenda, *quantidade))
            {
                printf("Telefone salvo com sucesso.\n");
            }
            else
            {
                printf("Erro ao salvar no arquivo.\n");
            }
            return;
        }
    }

    printf("Pessoa nao encontrada.\n");
}

void menuCadastrarTelefonePorID(Contato *agenda, int *quantidade)
{
    int idBusca;
    printf("Digite o ID da pessoa para adicionar o telefone: ");
    scanf("%d", &idBusca);

    for (int i = 0; i < *quantidade; i++)
    {
        if (agenda[i].id == idBusca)
        {
            char novoTelefone[12];
            printf("Digite o telefone: ");
            scanf("%11s", novoTelefone);

            if (!verificarTelefoneExistente(novoTelefone))
            {
                printf("Telefone inválido. Não foi cadastrado.\n");
                return;
            }

            adicionarTelefone(&agenda[i], novoTelefone);
            if (salvarContatos(agenda, *quantidade))
            {
                printf("Telefone salvo com sucesso.\n");
            }
            else
            {
                printf("Erro ao salvar no arquivo.\n");
            }
            return;
        }
    }

    printf("Pessoa nao encontrada.\n");
}

void menuEditar(Contato *agenda, int *quantidade)
{
    int escolha;
    while (1)
    {
        printf("=== Menu de Edicao ===\n");
        printf("1.Editar Contato\n");
        printf("2.Voltar\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            printf("=== Buscar Contato para Edicao por ===\n");
            printf("1. Nome\n");
            printf("2. ID\n");
            printf("3. Voltar\n");
            {
                int opcaoBusca;
                scanf("%d", &opcaoBusca);
                switch (opcaoBusca)
                {
                case 1:
                    menuEditarPorNome(agenda, quantidade);
                    break;
                case 2:
                    menuEditarPorID(agenda, quantidade);
                    break;
                default:
                    break;
                }
            }
            break;
        case 2:
            return;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
}

// Helper function to perform the actual editing of a contact
static void editarContato(Contato *agenda, int *quantidade, int indice)
{
    printf("Que informação deseja editar de %s:\n", agenda[indice].nome);
    printf("1. Nome\n");
    printf("2. Data de Nascimento\n");
    printf("3. CPF\n");
    printf("4. Email\n");
    printf("5. Voltar\n");

    int escolhaEdicao;
    scanf("%d", &escolhaEdicao);

    switch (escolhaEdicao)
    {
    case 1:
    {
        char novoNome[31];
        bool nomeValido = false;
        while (!nomeValido)
        {
            printf("Digite o novo nome: ");
            scanf("%30s", novoNome);

            // Verificar se o nome já existe EM OUTROS contatos
            bool nomeExiste = false;
            for (int j = 0; j < *quantidade; j++)
            {
                if (j != indice && strcmp(agenda[j].nome, novoNome) == 0)
                {
                    nomeExiste = true;
                    break;
                }
            }

            if (nomeExiste)
            {
                printf("Este nome já existe na agenda!\n");
            }
            else if (strlen(novoNome) < 2)
            {
                printf("Nome inválido. O nome deve ter pelo menos 2 caracteres.\n");
            }
            else
            {
                strcpy(agenda[indice].nome, novoNome);
                nomeValido = true;
            }
        }
        break;
    }
    case 2:
        printf("Digite a nova data de nascimento: ");
        scanf("%10s", agenda[indice].nascimento);
        while (!validarNascimento(&agenda[indice]))
        {
            printf("Data inválida. Digite novamente (DD/MM/AAAA): ");
            scanf("%10s", agenda[indice].nascimento);
        }
        break;
    case 3:
        printf("Digite o novo CPF: ");
        scanf("%11s", agenda[indice].cpf);
        while (!validarCpf(&agenda[indice]))
        {
            printf("CPF inválido. Digite novamente: ");
            scanf("%11s", agenda[indice].cpf);
        }
        break;
    case 4:
        printf("Digite o novo email: ");
        scanf("%30s", agenda[indice].email);
        while (!verificarEmailExistente(&agenda[indice]))
        {
            printf("Email inválido. Digite novamente: ");
            scanf("%30s", agenda[indice].email);
        }
        break;
    case 5:
        return;
    default:
        printf("Opção inválida!\n");
        return;
    }
    salvarEdicao(agenda, *quantidade, agenda[indice].id);
    printf("Contato editado com sucesso!\n");
}

void menuEditarPorNome(Contato *agenda, int *quantidade)
{
    char nomeBusca[31];
    printf("Digite o nome do contato a ser editado: ");
    scanf("%30s", nomeBusca);
    bool encontrado = false;

    for (int i = 0; i < *quantidade; i++)
    {
        if (strcmp(agenda[i].nome, nomeBusca) == 0)
        {
            encontrado = true;
            editarContato(agenda, quantidade, i);
            return;
        }
    }

    if (!encontrado)
    {
        printf("Contato não encontrado!\n");
    }
}

void menuEditarPorID(Contato *agenda, int *quantidade)
{
    int idBusca;
    printf("Digite o id do contato a ser editado: ");
    scanf("%d", &idBusca);
    bool encontrado = false;

    for (int i = 0; i < *quantidade; i++)
    {
        if (agenda[i].id == idBusca)
        {
            encontrado = true;
            editarContato(agenda, quantidade, i);
            return;
        }
    }

    if (!encontrado)
    {
        printf("Contato não encontrado!\n");
    }
}

void menuExcluir(Contato *agenda, int *quantidade)
{
    int escolha;
    while (1)
    {
        printf("=== Menu de Exclusao ===\n");
        printf("1. Excluir Pessoa\n");
        printf("2. Excluir Telefone\n");
        printf("3. Voltar\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            excluirPessoa(agenda, quantidade);
            break;
        case 2:
            excluirTelefone(agenda, quantidade);
            break;
        case 3:
            printf("Voltando ao menu principal...\n");
            return;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    }
}

void excluirPessoa(Contato *agenda, int *quantidade)
{
    int escolha;
    while (1)
    {
        printf("=== Excluir Pessoa ===\n");
        printf("1. Excluir por Nome\n");
        printf("2. Excluir por ID\n");
        printf("3. Voltar\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
        {
            printf("=== Excluir por Nome ===\n");
            printf("Digite o nome da pessoa a ser excluida: ");
            char nomeBusca[31];
            scanf("%30s", nomeBusca);
            for (int i = 0; i < *quantidade; i++)
            {
                if (strcmp(agenda[i].nome, nomeBusca) == 0)
                {
                    for (int j = i; j < *quantidade - 1; j++)
                    {
                        agenda[j] = agenda[j + 1];
                    }

                    (*quantidade)--;

                    printf("Pessoa excluida com sucesso!\n");
                    salvarContatos(agenda, *quantidade);

                    break;
                }
            }
            break;
        }
        case 2:
        {
            printf("=== Excluir por ID ===\n");
            printf("Digite o ID da pessoa a ser excluida: ");
            int idBusca;
            scanf("%d", &idBusca);
            for (int i = 0; i < *quantidade; i++)
            {
                if (agenda[i].id == idBusca)
                {
                    for (int j = i; j < *quantidade - 1; j++)
                    {
                        agenda[j] = agenda[j + 1];
                    }

                    (*quantidade)--;

                    printf("Pessoa excluida com sucesso!\n");
                    salvarContatos(agenda, *quantidade);

                    break;
                }
            }
            break;
        }
        case 3:
            printf("Voltando...\n");
            return;
        default:
            printf("Opcao invalida.\n");
        }
    }
}

void excluirTelefone(Contato *agenda, int *quantidade)
{
    int escolha;
    while (1)
    {
        printf("=== Excluir Telefone ===\n");
        printf("1. Excluir por Nome\n");
        printf("2. Excluir por ID\n");
        printf("3. Voltar\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
        {
            printf("=== Excluir Telefone por Nome ===\n");
            printf("Digite o nome da pessoa cujo telefone deseja excluir: ");
            char nomeBusca[31];
            scanf("%30s", nomeBusca);
            for (int i = 0; i < *quantidade; i++)
            {
                if (strcmp(agenda[i].nome, nomeBusca) == 0)
                {
                    if (agenda[i].num_telefones == 0)
                    {
                        printf("Esta pessoa nao possui telefones cadastrados.\n");
                        break;
                    }

                    printf("Telefones cadastrados para %s:\n", agenda[i].nome);
                    for (int t = 0; t < agenda[i].num_telefones; t++)
                    {
                        printf("%d - %s\n", t, agenda[i].telefones[t].numero);
                    }

                    int indice;
                    printf("Digite o indice do telefone que deseja excluir: ");
                    scanf("%d", &indice);

                    if (indice < 0 || indice >= agenda[i].num_telefones)
                    {
                        printf("Indice invalido! Nenhum telefone foi excluido.\n");
                        break;
                    }

                    for (int j = indice; j < agenda[i].num_telefones - 1; j++)
                    {
                        agenda[i].telefones[j] = agenda[i].telefones[j + 1];
                    }

                    agenda[i].num_telefones--;

                    printf("Telefone excluido com sucesso!\n");

                    salvarContatos(agenda, *quantidade);

                    break;
                }
            }
            break;
        }
        case 2:
        {
            printf("=== Excluir Telefone por ID ===\n");
            printf("Digite o ID da pessoa cujo telefone deseja excluir: ");
            int idBusca;
            scanf("%d", &idBusca);
            for (int i = 0; i < *quantidade; i++)
            {
                if (agenda[i].id == idBusca)
                {
                    if (agenda[i].num_telefones == 0)
                    {
                        printf("Esta pessoa nao possui telefones cadastrados.\n");
                        break;
                    }

                    printf("Telefones cadastrados para %s:\n", agenda[i].nome);
                    for (int t = 0; t < agenda[i].num_telefones; t++)
                    {
                        printf("%d - %s\n", t, agenda[i].telefones[t].numero);
                    }

                    int indice;
                    printf("Digite o indice do telefone que deseja excluir: ");
                    scanf("%d", &indice);

                    if (indice < 0 || indice >= agenda[i].num_telefones)
                    {
                        printf("Indice invalido! Nenhum telefone foi excluido.\n");
                        break;
                    }

                    for (int j = indice; j < agenda[i].num_telefones - 1; j++)
                    {
                        agenda[i].telefones[j] = agenda[i].telefones[j + 1];
                    }

                    agenda[i].num_telefones--;

                    printf("Telefone excluido com sucesso!\n");

                    salvarContatos(agenda, *quantidade);

                    break;
                }
            }
            break;
        }
        case 3:
            printf("Voltando...\n");
            return;
        default:
            printf("Opcao invalida.\n");
        }
    }
}

void menuConsultar(Contato *agenda, int quantidade)
{
    int escolha;
    while (1)
    {
        printf("=== Consultar Contatos ===\n");
        printf("1. Consultar pessoas\n");
        printf("2. telefone\n");
        printf("3. Voltar\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
        {
            printf("1. Consultar por Nome\n");
            printf("2. Consultar por ID\n");
            printf("3. Voltar\n");
            int opcaoConsulta;
            scanf("%d", &opcaoConsulta);
            switch (opcaoConsulta)
            {
            case 1:
            {
                char nomeBusca[31];
                printf("Digite o nome do contato a ser consultado: ");
                scanf("%30s", nomeBusca);
                bool encontrado = false;

                for (int i = 0; i < quantidade; i++)
                {
                    if (strcmp(agenda[i].nome, nomeBusca) == 0)
                    {
                        encontrado = true;
                        printf("ID: %d\n", agenda[i].id);
                        printf("Nome: %s\n", agenda[i].nome);
                        printf("Data de Nascimento: %s\n", agenda[i].nascimento);
                        printf("CPF: %s\n", agenda[i].cpf);
                        printf("Email: %s\n", agenda[i].email);
                        printf("Telefones:\n");
                        for (int j = 0; j < agenda[i].num_telefones; j++)
                        {
                            printf(" - %s\n", agenda[i].telefones[j].numero);
                        }
                        break;
                    }
                }

                if (!encontrado)
                {
                    printf("Contato nao encontrado!\n");
                }
            }
            break;
            case 2:
            {
                int idBusca;
                printf("Digite o ID do contato a ser consultado: ");
                scanf("%d", &idBusca);
                bool encontrado = false;

                for (int i = 0; i < quantidade; i++)
                {
                    if (agenda[i].id == idBusca)
                    {
                        encontrado = true;
                        printf("ID: %d\n", agenda[i].id);
                        printf("Nome: %s\n", agenda[i].nome);
                        printf("Data de Nascimento: %s\n", agenda[i].nascimento);
                        printf("CPF: %s\n", agenda[i].cpf);
                        printf("Email: %s\n", agenda[i].email);
                        printf("Telefones:\n");
                        for (int j = 0; j < agenda[i].num_telefones; j++)
                        {
                            printf(" - %s\n", agenda[i].telefones[j].numero);
                        }
                        break;
                    }
                }

                if (!encontrado)
                {
                    printf("Contato nao encontrado!\n");
                }
            }
            break;
            case 3:
                break;
            default:
                printf("Opcao invalida.\n");
            }
            break;
        }
        case 2:
        {
            printf("1.Consultar telefone por nome\n");
            printf("2.Consultar telefone por ID\n");
            printf("3.Voltar\n");
            int opcaoTelConsulta;
            scanf("%d", &opcaoTelConsulta);
            switch (opcaoTelConsulta)
            {
            case 1:
            {
                char nomeBusca[31];
                printf("Digite o nome do contato para consultar telefone: ");
                scanf("%30s", nomeBusca);
                bool encontrado = false;

                for (int i = 0; i < quantidade; i++)
                {
                    if (strcmp(agenda[i].nome, nomeBusca) == 0)
                    {
                        encontrado = true;
                        printf("Telefones de %s:\n", agenda[i].nome);
                        for (int j = 0; j < agenda[i].num_telefones; j++)
                        {
                            printf(" - %s\n", agenda[i].telefones[j].numero);
                        }
                        break;
                    }
                }

                if (!encontrado)
                {
                    printf("Contato nao encontrado!\n");
                }
            }
            break;
            case 2:
            {
                int idBusca;
                printf("Digite o ID do contato para consultar telefone: ");
                scanf("%d", &idBusca);
                bool encontrado = false;

                for (int i = 0; i < quantidade; i++)
                {
                    if (agenda[i].id == idBusca)
                    {
                        encontrado = true;
                        printf("Telefones de %s:\n", agenda[i].nome);
                        for (int j = 0; j < agenda[i].num_telefones; j++)
                        {
                            printf(" - %s\n", agenda[i].telefones[j].numero);
                        }
                        break;
                    }
                }

                if (!encontrado)
                {
                    printf("Contato nao encontrado!\n");
                }
            }
            break;
            case 3:
                break;
            default:
                printf("Opcao invalida.\n");
            }
            break;
        }
        case 3:
            printf("Voltando...\n");
            return;
        default:
            printf("Opcao invalida.\n");
        }
    }
}