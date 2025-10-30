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
        switch (condicao)
        {
        case 1:
            if (*quantidade <= 100)
            {
                bool dadosValidos = false;
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

                printf("Deseja cadastrar um telefone? (S ou s para sim / N ou n para não): ");
                char resposta;
                scanf(" %c", &resposta);
                if (resposta == 'S' || resposta == 's')
                {
                    dadosValidos = false;
                    while (!dadosValidos)
                    {
                        printf("Digite o telefone: ");
                        scanf("%11s", agenda[*quantidade - 1].telefone);
                        if (verificarTelefoneExistente(&agenda[*quantidade - 1]))
                        {
                            dadosValidos = true;
                            printf("Telefone cadastrado com sucesso!\n");
                        }
                        else
                        {
                            printf("Telefone inválido. Deve ter 10 ou 11 dígitos.\n");
                        }
                    }
                }
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

                bool dadosValidos = false;
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

                printf("Deseja cadastrar um telefone? (S ou s para sim / N ou n para não): ");
                char resposta;
                scanf(" %c", &resposta);
                if (resposta == 'S' || resposta == 's')
                {
                    dadosValidos = false;
                    while (!dadosValidos)
                    {
                        printf("Digite o telefone: ");
                        scanf("%11s", agenda[*quantidade - 1].telefone);
                        if (verificarTelefoneExistente(&agenda[*quantidade - 1]))
                        {
                            dadosValidos = true;
                            printf("Telefone cadastrado com sucesso!\n");
                        }
                        else
                        {
                            printf("Telefone inválido. Deve ter 10 ou 11 dígitos.\n");
                        }
                    }
                }
            }
            salvarContatos(agenda, *quantidade);
            break;

        case 2:
           
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