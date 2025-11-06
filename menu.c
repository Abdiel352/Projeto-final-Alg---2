#include <stdio.h>
#include <stdlib.h>
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
                    if (verificarNome(&agenda[*quantidade], quantidade))
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
                    if (verificarNome(&agenda[*quantidade], quantidade))
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
            printf("=== Casdastrar telefone ===\n");
            printf("Informe o Nome da Pessoa: \n");
            char nomeBusca[31];
            scanf("%30s", nomeBusca);
            printf("Informe o ID da Pessoa: \n");
            int idBusca;
            scanf("%d", &idBusca);
            printf("Digite o telefone: ");
            char telefone[12];
            scanf("%11s", telefone);
            Contato *contatoEncontrado = buscarContatoPorNomeEId(agenda, *quantidade, nomeBusca, idBusca);
            if (contatoEncontrado != NULL)
            {
                if (verificarTelefoneExistente(telefone))
                {
                    adicionarTelefone(contatoEncontrado, telefone);
                    printf("Telefone cadastrado com sucesso!\n");
                    salvarContatos(agenda, *quantidade);
                }
                else
                {
                    printf("Telefone inválido. Deve ter 10 ou 11 dígitos.\n");
                }
            }
            else
            {
                printf("Contato nao encontrado com o nome e ID fornecidos.\n");
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