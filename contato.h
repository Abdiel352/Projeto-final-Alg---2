#ifndef CONTATO_H
#define CONTATO_H

typedef struct {
    char numero[12];
} Telefone;

typedef struct {
    char nome[31];
    char email[31];
    char cpf[12];
    char nascimento[11];
    int id;
    Telefone *telefones;  
    int num_telefones;    
} Contato;


#endif