#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "verificacao.h"

bool verificarTelefoneExistente(const char *telefone)
{
    if (strlen(telefone) != 10 && strlen(telefone) != 11)
    {
        return false;
    }
    for (int i = 0; telefone[i] != '\0'; i++)
    {
        if (!isdigit(telefone[i]))
        {
            return false;
        }
    }

    return true;
}

bool validarCpf(Contato *agenda)
{
    // Verificar se todos os dígitos são iguais
    bool todosIguais = true;
    for (int i = 1; i < 11; i++)
    {
        if (agenda->cpf[i] != agenda->cpf[0])
        {
            todosIguais = false;
            break;
        }
    }
    if (todosIguais)
        return false;

    int j = 0, k = 0;

    for (int i = 0; i < 9; i++)
    {
        j += (agenda->cpf[i] - 48) * (10 - i);
    }
    j = (j * 10) % 11;
    if (j == 10)
        j = 0;

    for (int i = 0; i < 10; i++)
    {
        k += (agenda->cpf[i] - 48) * (11 - i);
    }
    k = (k * 10) % 11;
    if (k == 10)
        k = 0;

    return (j == (agenda->cpf[9] - 48) && k == (agenda->cpf[10] - 48));
}

bool verificarEmailExistente(Contato *agenda)
{
    const char *aroba = "@";
    if (strstr(agenda->email, aroba) != NULL && strlen(agenda->email) >= 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validarNascimento(Contato *agenda)
{
    if (strlen(agenda->nascimento) != 10)
    {
        return false;
    }

    int dia, mes, ano;
    if (sscanf(agenda->nascimento, "%2d/%2d/%4d", &dia, &mes, &ano) != 3)
    {
        return false;
    }

    if (ano < 1900 || ano > 2024)
    {
        return false;
    }
    if (mes < 1 || mes > 12)
    {
        return false;
    }
    if (dia < 1 || dia > 31)
    {
        return false;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
    {
        return false;
    }
    if (mes == 2)
    {
        bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        if (dia > (bissexto ? 29 : 28))
        {
            return false;
        }
    }

    return true;
}

bool verificarNome(const char *nome, Contato *agenda, int quantidade)
{
    if (strlen(nome) < 2)
    {
        return false;
    }

    for (int i = 0; i < quantidade; i++)
    {
        if (strcmp(agenda[i].nome, nome) == 0)
        {
            printf("Este nome já existe na agenda!\n");
            return false;
        }
    }

    return true;
}