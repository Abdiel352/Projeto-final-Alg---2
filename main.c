#include <stdio.h>
#include <stdlib.h>
#include "contato.h"
#include "arquivo.h"
#include "menu.h"

int main()
{
    Contato agenda[100];
    int quantidade = carregarContatos(agenda);
    int condicao = 1;

    do
    {
        printf("1. Cadastrar\n");
        printf("2. Editar\n");
        printf("3. Excluir\n");
        printf("4. Consultar\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &condicao);

        switch (condicao)
        {
        case 1:
            menuCadastro(agenda, &quantidade);
            break;
        case 2:
            menuEditar(agenda, &quantidade);
            break;
        case 3:
            menuExcluir(agenda, &quantidade);
            break;
        case 4:
            menuConsultar(agenda, quantidade);
            break;
        case 5:
            salvarContatos(agenda, quantidade);
            printf("Contatos salvos. Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (condicao != 5);

    return 0;
}