#ifndef CONTATO_H
#define CONTATO_H

typedef struct
{
    char nome[31];
    char telefone[12];
    char email[31];
    char cpf[12];
    char nascimento[11];
} Contato;

#endif