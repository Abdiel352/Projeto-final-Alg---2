# 📘 Projeto Final – Algoritmos 2  
## Exemplo de Código — Especificação da Agenda Telefônica

## 📌 Informações

Implementar uma **agenda telefônica** contendo os seguintes dados:

- **Nome**
- **Telefone** (mais de um por pessoa)
- **E-mail**
- **CPF**
- **Data de Nascimento**

## 📂 Estrutura de Armazenamento

| Campo              | Tipo / Tamanho           |
|-------------------|---------------------------|
| Nome              | Texto, 30 caracteres      |
| Telefone          | Texto, 11 caracteres      |
| E-mail            | Texto, 30 caracteres      |
| CPF               | Texto, 11 caracteres      |
| Data de Nasc.     | Texto, 10 caracteres      |

## ✅ Validações

- **Nome:** Mais que 2 caracteres.  
- **Telefone:** 10 ou 11 caracteres numéricos (DDD incluso).  
- **E-mail:** Mais que 10 caracteres + formato válido.  
- **CPF:** Deve ser válido.  
- **Data de Nascimento:**  
  - Data válida (dd/mm/YYYY)  
  - Menor ou igual à data atual  

O usuário deve repetir a entrada até que o valor seja validado.

# 📋 Menus

Os menus recebem **somente números inteiros (int)**.  
Entradas inválidas devem ser solicitadas novamente.

## 🔷 Estrutura Resumida dos Menus

1. Cadastrar  
   - Pessoa  
     - Nome  
     - IDPessoa  
     - Retornar  
   - Telefone  
     - Nome  
     - IDPessoa  
     - Retornar  

2. Editar  
   - Pessoa  
     - Nome  
       - Nome  
       - Data de Nascimento  
       - CPF  
       - E-mail  
       - Retornar  
     - IDPessoa  
       - Nome  
       - Data de Nascimento  
       - CPF  
       - E-mail  
       - Retornar  
   - Retornar  

3. Excluir  
   - Pessoa  
     - Nome  
     - IDPessoa  
     - Retornar  
   - Telefone  
     - Nome  
     - IDPessoa  
     - Retornar  
   - Retornar  

4. Consultar  
   - Pessoa  
     - Nome  
     - IDPessoa  
     - Retornar  
   - Telefone  
     - Nome  
     - IDPessoa  
     - Retornar  

5. Sair

# 🏠 Menu Principal

Entrada válida: **1 a 5**  
- **1 a 4** → abre menus  
- **5** → encerra  
Outros valores → solicitar novamente.

# 📁 Menu Cadastrar (1)

Opções válidas: **1 a 3**

1. Pessoa  
2. Telefone  
3. Retornar  

## 🧍 Menu Cadastrar / Pessoa (1 → 1)

O usuário deve inserir:

1. Nome  
2. Data de Nascimento  
3. CPF  
4. E-mail  

Regras:

- Nome não pode existir na lista.  
- Após os dados, cadastrar Telefones.  
- Permitir inserir vários telefones (S/N).

## ☎️ Menu Cadastrar / Telefone (1 → 2)

Pesquisar pessoa por:

1. Nome  
2. IDPessoa  
3. Retornar  

### Telefone / Nome (1 → 2 → 1)

- Informar nome  
- Se encontrado → cadastrar telefones  
- Perguntar (S/N) para adicionar mais

### Telefone / IDPessoa (1 → 2 → 2)

- Informar ID  
- Se encontrado → cadastrar telefones  
- Perguntar (S/N) para adicionar mais  

# ✏️ Menu Editar (2)

Opções válidas: **1 a 3**

1. Pessoa  
2. Telefone  
3. Retornar  

## Editar / Pessoa (2 → 1)

Pesquisar por:

1. Nome  
2. IDPessoa  
3. Retornar  

Ao localizar a pessoa, pode editar:

- Nome  
- Data de Nascimento  
- CPF  
- E-mail  

# 🗑️ Menu Excluir (3)

Opções válidas: **1 a 3**

1. Pessoa  
2. Telefone  
3. Retornar  

## Excluir / Pessoa

Buscar por nome ou IDPessoa  
Após encontrar → confirmar exclusão

## Excluir / Telefone

Buscar por nome ou IDPessoa  
Selecionar telefone a excluir

# 🔍 Menu Consultar (4)

Opções válidas: **1 a 3**

1. Pessoa  
2. Telefone  
3. Retornar  

## Consultar / Pessoa

Buscar por nome ou IDPessoa  
Exibir informações completas

## Consultar / Telefone

Buscar por nome ou IDPessoa  
Exibir telefones cadastrados
