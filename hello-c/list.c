#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

void insert(const char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Allocation failed");
        exit(EXIT_FAILURE);
    }
    
    newNode->data = strdup(str); 
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Inserted: \"%s\"\n", str);
}

Node* find(const char *str) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->data, str) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteNode(Node *node) {
    if (node == NULL) return;

    printf("Deleting: \"%s\"\n", node->data);

    if (head == node) {
        head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    }

    free(node->data);
    free(node);
}

void printList(void) {
    Node *current = head;
    printf("Current List: ");
    if (current == NULL) {
        printf("[Empty]\n");
        return;
    }
    while (current != NULL) {
        printf("\"%s\" <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(void) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    head = NULL;
}

int main(void) {
    printf("Doubly Linked List\n");
    printList();

    insert("Mango");
    insert("Peach");
    insert("Lychee");
    printList();

    const char *searchTarget = "Peach";
    printf("Searching for \"%s\"...\n", searchTarget);
    Node *found = find(searchTarget);
    if (found) {
        printf("Found target: \"%s\"\n", found->data);
    } else {
        printf("Target not found.\n");
    }

    if (found) {
        deleteNode(found);
    }
    printList();

    Node *headNode = find("Lychee");
    deleteNode(headNode);
    printList();

    freeList();
    printf("List cleaned up.\n");

    return 0;
}
