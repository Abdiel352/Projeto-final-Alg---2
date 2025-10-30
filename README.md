# 📒 Projeto Final – Algoritmos 2

![Status](https://img.shields.io/badge/status-em%20desenvolvimento-yellow)
![Linguagem](https://img.shields.io/badge/language-C-blue)

## 📖 Descrição
Este projeto implementa uma **agenda telefônica** que armazena informações de pessoas, incluindo **múltiplos telefones**, e permite operações de:

- Cadastrar
- Editar
- Excluir
- Consultar

---

## 📂 Estrutura da Agenda

Cada pessoa possui os seguintes campos:

| Campo | Tipo | Limite | Validação |
|-------|------|--------|-----------|
| Nome | Texto | 30 caracteres | > 2 caracteres, único |
| Telefone | Texto | 11 caracteres | 10 ou 11 dígitos |
| E-mail | Texto | 30 caracteres | > 10 caracteres, válido |
| CPF | Texto | 11 caracteres | CPF válido, único |
| Data de Nascimento | Texto | 10 caracteres | dd/mm/YYYY, ≤ data atual |

> Uma pessoa pode ter **mais de um telefone** cadastrado.

---

## 🛠 Funcionalidades

- **Validações**: todos os campos só avançam quando informados corretamente.
- **Menus numéricos**: navegação através de números inteiros.
- **Cadastro de múltiplos telefones**.
- **Pesquisa por Nome ou IDPessoa** para edição, exclusão ou consulta.

---

## 📑 Estrutura de Menus

### Menu Principal
1. Cadastrar  
2. Editar  
3. Excluir  
4. Consultar  
5. Sair  

### Menu Cadastrar
1. Pessoa → Cadastro de Nome, Data de Nascimento, CPF, E-mail e Telefones  
2. Telefone → Adição de telefones para pessoa existente  
3. Retornar → Volta ao Menu Principal  

### Menu Editar
- Edita pessoa ou telefone por **Nome** ou **IDPessoa**  
- Alteração de campos individuais  
- Retorno ao Menu Principal disponível  

### Menu Excluir
- Exclui pessoa ou telefone por **Nome** ou **IDPessoa**  
- Confirmação obrigatória para exclusão  

### Menu Consultar
- Consulta pessoa ou telefone por **Nome** ou **IDPessoa**  
- Exibe todas as informações cadastradas  

---

## 🌳 Estrutura Resumida dos Menus

