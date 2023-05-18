#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

void inserirInicio(struct Node** head, int dado) {
    struct Node* novoNo = criarNo(dado);
    novoNo->next = *head;
    *head = novoNo;
    printf("Elemento %d inserido no início da lista.\n", dado);
}

void inserirFinal(struct Node** head, int dado) {
    struct Node* novoNo = criarNo(dado);
    if (*head == NULL) {
        *head = novoNo;
    } else {
        struct Node* atual = *head;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novoNo;
    }
    printf("Elemento %d inserido no final da lista.\n", dado);
}

void exibir(struct Node* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
    } else {
        printf("Elementos da lista: ");
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

void removerInicio(struct Node** head) {
    if (*head == NULL) {
        printf("A lista está vazia. Não é possível remover elementos.\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        printf("Elemento %d removido do início da lista.\n", temp->data);
        free(temp);
    }
}

void removerFinal(struct Node** head) {
    if (*head == NULL) {
        printf("A lista está vazia. Não é possível remover elementos.\n");
    } else if ((*head)->next == NULL) {
        struct Node* temp = *head;
        *head = NULL;
        printf("Elemento %d removido do final da lista.\n", temp->data);
        free(temp);
    } else {
        struct Node* atual = *head;
        struct Node* anterior = NULL;
        while (atual->next != NULL) {
            anterior = atual;
            atual = atual->next;
        }
        anterior->next = NULL;
        printf("Elemento %d removido do final da lista.\n", atual->data);
        free(atual);
    }
}

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
