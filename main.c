#include <stdio.h>
#include <string.h>

#define MAX 100 

// estrutura que representa um livro
struct Livro {
    int codigo;
    char titulo[50];
    int ano;
    int quantidade;
};

struct Livro biblioteca[MAX]; 
int total = 0; 

// le os livros do arquivo livros.txt e salva no vetor
void lerArquivo() {
    FILE *f = fopen("livros.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    // le linha por linha ate acabar o arquivo
    while (fscanf(f, "%d %s %d %d", &biblioteca[total].codigo, biblioteca[total].titulo, &biblioteca[total].ano, &biblioteca[total].quantidade) == 4) {
        total++;
    }
    fclose(f);
    printf("%d livros carregados.\n", total);
}

// pede os dados ao usuario e adiciona um novo livro no vetor
void adicionarLivro() {
    printf("Codigo: ");
    scanf("%d", &biblioteca[total].codigo);
    printf("Titulo: ");
    scanf("%s", biblioteca[total].titulo);
    printf("Ano: ");
    scanf("%d", &biblioteca[total].ano);
    printf("Quantidade: ");
    scanf("%d", &biblioteca[total].quantidade);
    total++;
    printf("Livro adicionado!\n");
}

// percorre o vetor procurando o livro com o codigo digitado
void buscarLivro() {
    int cod, i, achei = 0;
    printf("Digite o codigo: ");
    scanf("%d", &cod);
    for (i = 0; i < total; i++) {
        if (biblioteca[i].codigo == cod) {
            printf("Codigo: %d | Titulo: %s | Ano: %d | Qtd: %d\n",
                biblioteca[i].codigo, biblioteca[i].titulo,
                biblioteca[i].ano, biblioteca[i].quantidade);
            achei = 1;
        }
    }
    if (!achei)
        printf("Livro nao encontrado.\n");
}

// imprime todos os livros do vetor
void imprimirLivros() {
    int i;
    printf("\n%-8s %-30s %-6s %s\n", "Codigo", "Titulo", "Ano", "Qtd");
    for (i = 0; i < total; i++) {
        printf("%-8d %-30s %-6d %d\n", biblioteca[i].codigo, biblioteca[i].titulo,
            biblioteca[i].ano, biblioteca[i].quantidade);
    }
}

// ordena os livros por ano usando bubble sort e depois imprime
void ordenarEImprimir() {
    int i, j;
    struct Livro temp;

    // compara dois livros vizinhos e troca se estiver fora de ordem
    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - 1 - i; j++) {
            if (biblioteca[j].ano > biblioteca[j+1].ano) {
                temp = biblioteca[j];
                biblioteca[j] = biblioteca[j+1];
                biblioteca[j+1] = temp;
            }
        }
    }

    printf("\nLivros ordenados por ano:\n");
    imprimirLivros();
}

int main() {
    int opcao;

    lerArquivo(); // carrega os livros antes de mostrar o menu

    do {
        printf("\n--- MENU ---\n");
        printf("1. Adicionar livro\n");
        printf("2. Buscar livro por codigo\n");
        printf("3. Imprimir livros\n");
        printf("4. Ordenar por ano e imprimir\n");
        printf("5. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        // chama a funcao correspondente a opcao escolhida
        if (opcao == 1) adicionarLivro();
        else if (opcao == 2) buscarLivro();
        else if (opcao == 3) imprimirLivros();
        else if (opcao == 4) ordenarEImprimir();
        else if (opcao != 5) printf("Opcao invalida!\n");

    } while (opcao != 5);

    printf("Saindo...\n");
    return 0;
}