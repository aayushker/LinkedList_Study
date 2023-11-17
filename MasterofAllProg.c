#include <stdio.h>
#include <stdlib.h>

// Node structure for all types of lists
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert at the beginning of a singly linked list
void insertSingly(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

// Function to insert at the beginning of a doubly linked list
void insertDoubly(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

// Function to insert at the beginning of a circular linked list
void insertCircular(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    new_node->data  = new_data;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        while (temp->next != *head_ref) temp = temp->next;
        temp->next = new_node;
    } else {
        new_node->next = new_node;
    }

    *head_ref = new_node;
}

// Function to delete at the beginning of a singly linked list
void deleteSingly(struct Node** head_ref) {
    if (*head_ref == NULL) return;
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

// Function to delete at the beginning of a doubly linked list
void deleteDoubly(struct Node** head_ref) {
    if (*head_ref == NULL) return;
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    if (*head_ref != NULL) (*head_ref)->prev = NULL;
    free(temp);
}

// Function to delete at the beginning of a circular linked list
void deleteCircular(struct Node** head_ref) {
    if (*head_ref == NULL) return;
    struct Node* temp = *head_ref;
    if ((*head_ref)->next == *head_ref) {
        *head_ref = NULL;
    } else {
        struct Node* last = *head_ref;
        while (last->next != *head_ref) last = last->next;
        *head_ref = (*head_ref)->next;
        last->next = *head_ref;
    }
    free(temp);
}

// Function to print a singly or doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Function to print a circular linked list
void printCircularList(struct Node* head) {
    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf(" %d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

// Main function
int main() {
    struct Node* singlyHead = NULL;
    struct Node* doublyHead = NULL;
    struct Node* circularHead = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert in Singly Linked List");
        printf("\n2. Insert in Doubly Linked List");
        printf("\n3. Insert in Circular Linked List");
        printf("\n4. Delete from Singly Linked List");
        printf("\n5. Delete from Doubly Linked List");
        printf("\n6. Delete from Circular Linked List");
        printf("\n7. Display Singly Linked List");
        printf("\n8. Display Doubly Linked List");
        printf("\n9. Display Circular Linked List");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &data);
                insertSingly(&singlyHead, data);
                break;
            case 2:
                printf("\nEnter element to insert: ");
                scanf("%d", &data);
                insertDoubly(&doublyHead, data);
                break;
            case 3:
                printf("\nEnter element to insert: ");
                scanf("%d", &data);
                insertCircular(&circularHead, data);
                break;
            case 4:
                deleteSingly(&singlyHead);
                break;
            case 5:
                deleteDoubly(&doublyHead);
                break;
            case 6:
                deleteCircular(&circularHead);
                break;
            case 7:
                printList(singlyHead);
                break;
            case 8:
                printList(doublyHead);
                break;
            case 9:
                printCircularList(circularHead);
                break;
            case 10:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}