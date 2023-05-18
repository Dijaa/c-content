#include <stdio.h>

#define TAMANHO_MAXIMO 10

struct Pilha {
    int vetor[TAMANHO_MAXIMO];
    int topo;
};

void inicializar(struct Pilha* pilha) {
    pilha->topo = -1; // Define o topo da pilha como -1 para indicar que está vazia
}

void push(struct Pilha* pilha, int elemento) {
    if (pilha->topo == TAMANHO_MAXIMO - 1) {
        printf("A pilha está cheia. Não é possível inserir mais elementos.\n");
    } else {
        pilha->topo++; // Incrementa o topo antes de adicionar um novo elemento
        pilha->vetor[pilha->topo] = elemento; // Insere o elemento na posição do topo
        printf("Elemento %d inserido na pilha.\n", elemento);
    }
}

void pop(struct Pilha* pilha) {
    if (pilha->topo == -1) {
        printf("A pilha está vazia. Não é possível remover elementos.\n");
    } else {
        int elemento = pilha->vetor[pilha->topo]; // Obtém o elemento no topo da pilha
        pilha->topo--; // Decrementa o topo para remover o elemento
        printf("Elemento %d removido da pilha.\n", elemento);
    }
}

void top(struct Pilha* pilha) {
    if (pilha->topo == -1) {
        printf("A pilha está vazia.\n");
    } else {
        int elemento = pilha->vetor[pilha->topo]; // Obtém o elemento no topo da pilha
        printf("Elemento no topo da pilha: %d\n", elemento);
    }
}

void display(struct Pilha* pilha) {
    if (pilha->topo == -1) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Elementos na pilha:\n");
        for (int i = pilha->topo; i >= 0; i--) {
            printf("%d\n", pilha->vetor[i]); // Imprime todos os elementos da pilha em ordem
        }
    }
}

int main() {
    struct Pilha pilha;
    inicializar(&pilha);

    int opcao, elemento;
    while (1) {
        printf("\n1. Inserir elemento (push)\n");
        printf("2. Remover elemento (pop)\n");
        printf("3. Consultar topo da pilha (top)\n");
        printf("4. Consultar todos os elementos da pilha\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                push(&pilha, elemento);
                break;
            case 2:
                pop(&pilha);
                break;
            case 3:
                top(&pilha);
                break;
            case 4:
                display(&pilha);
                break;
            case 5:
                return 0;
            default:
                printf("Opção inválida. Por favor, escolha novamente.\n");
                break;
        }
    }
}
