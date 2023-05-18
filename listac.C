#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* criarNo(int dado) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(1);
    }
    novoNo->data = dado;
    novoNo->next = NULL;
    return novoNo;
}

// Função para inserir um elemento no início da lista
void inserirInicio(struct Node** head, int dado) {
    struct Node* novoNo = criarNo(dado);
    novoNo->next = *head; // O próximo do novo nó aponta para o antigo nó inicial
    *head = novoNo; // O novo nó se torna o novo nó inicial
    printf("Elemento %d inserido no início da lista.\n", dado);
}

// Função para inserir um elemento no final da lista
void inserirFinal(struct Node** head, int dado) {
    struct Node* novoNo = criarNo(dado);
    if (*head == NULL) {
        *head = novoNo; // Se a lista estiver vazia, o novo nó se torna o nó inicial
    } else {
        struct Node* atual = *head;
        while (atual->next != NULL) {
            atual = atual->next; // Percorre a lista até encontrar o último nó
        }
        atual->next = novoNo; // O próximo do último nó passa a ser o novo nó
    }
    printf("Elemento %d inserido no final da lista.\n", dado);
}

// Função para exibir os elementos da lista
void exibir(struct Node* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
    } else {
        printf("Elementos da lista: ");
        while (head != NULL) {
            printf("%d ", head->data); // Imprime o dado do nó atual
            head = head->next; // Avança para o próximo nó
        }
        printf("\n");
    }
}

// Função para remover o elemento do início da lista
void removerInicio(struct Node** head) {
    if (*head == NULL) {
        printf("A lista está vazia. Não é possível remover elementos.\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next; // O próximo nó se torna o novo nó inicial
        printf("Elemento %d removido do início da lista.\n", temp->data);
        free(temp); // Libera a memória do nó removido
    }
}

// Função para remover o elemento do final da lista
void removerFinal(struct Node** head) {
    if (*head == NULL) {
        printf("A lista está vazia. Não é possível remover elementos.\n");
    } else if ((*head)->next == NULL) {
        struct Node* temp = *head;
        *head = NULL; // Se a lista possuir apenas um nó, a lista fica vazia
        printf("Elemento %d removido do final da lista.\n", temp->data);
        free(temp); // Libera a memória do nó removido
    } else {
        struct Node* atual = *head;
        struct Node* anterior = NULL;
        while (atual->next != NULL) {
            anterior = atual;
            atual = atual->next; // Percorre a lista até encontrar o último nó
        }
        anterior->next = NULL; // O próximo do penúltimo nó passa a ser NULL
        printf("Elemento %d removido do final da lista.\n", atual->data);
        free(atual); // Libera a memória do nó removido
    }
}

// Função para liberar a memória ocupada pela lista
void liberarLista(struct Node** head) {
    struct Node* atual = *head;
    struct Node* proximo = NULL;
    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    int opcao, elemento;

    while (1) {
        printf("\n1. Inserir no início da lista\n");
        printf("2. Inserir no final da lista\n");
        printf("3. Exibir lista\n");
        printf("4. Remover do início da lista\n");
        printf("5. Remover do final da lista\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido no início: ");
                scanf("%d", &elemento);
                inserirInicio(&head, elemento);
                break;
            case 2:
                printf("Digite o elemento a ser inserido no final: ");
                scanf("%d", &elemento);
                inserirFinal(&head, elemento);
                break;
            case 3:
                exibir(head);
                break;
            case 4:
                removerInicio(&head);
                break;
            case 5:
                removerFinal(&head);
                break;
            case 6:
                liberarLista(&head);
                return 0;
            default:
                printf("Opção inválida. Por favor, escolha novamente.\n");
                break;
        }
    }
}
