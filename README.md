# Sistema de Controle de Livros

Projeto da disciplina **Programação Estruturada** — implementado em linguagem C.

## Funcionalidades

1. **Adicionar livro** — insere um novo livro na memória
2. **Buscar livro por código** — busca sequencial pelo código
3. **Imprimir livros** — exibe todos os livros cadastrados
4. **Ordenar por ano e imprimir** — ordena (bubble sort) e exibe
5. **Sair**

## Estrutura do projeto

```
projeto_livros/
├── main.c       # Código-fonte principal
├── livros.txt   # Arquivo com os 20 registros iniciais
└── README.md    # Este arquivo
```

## Como compilar

Certifique-se de ter o GCC instalado. No terminal, dentro da pasta do projeto:

```bash
gcc main.c -o livros
```

## Como executar

O arquivo `livros.txt` deve estar na **mesma pasta** do executável.

```bash
./livros
```

> No Windows, use `livros.exe` e compile com MinGW ou similar.

## Formato do arquivo livros.txt

Cada linha representa um livro com os campos separados por espaço:

```
<codigo> <titulo> <ano> <quantidade>
```

Exemplo:
```
101 Algoritmos 2020 5
102 BancoDeDados 2018 3
```

> O título não pode conter espaços (use CamelCase).

## Conceitos aplicados

- `struct` para representar cada livro
- Vetor de structs como armazenamento em memória
- Funções modularizadas para cada operação
- Leitura de arquivo texto com `fopen` / `fscanf`
- Busca sequencial por código
- Ordenação Bubble Sort por ano de publicação
