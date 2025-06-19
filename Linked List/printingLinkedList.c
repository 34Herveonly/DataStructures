#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct node {
    int data;              // Data part of the node
    struct node* next;     // Pointer to the next node
};

// Function to print the data of each node in the linked list
void printValues(struct node* head) {
    struct node* current = head; // Start from the head of the list
    
    // Traverse the list until we reach the end (NULL)
    while (current != NULL) {
        printf("%d ->", current->data); // Print current node's data on a new line
        current = current->next;       // Move to the next node
    }

    // Print NULL at the end to indicate end of list (optional, for visual clarity)
    printf("NULL\n");
}

int main() {
    // Allocate memory for each node in the list
    struct node* head = malloc(sizeof(struct node));
    struct node* first = malloc(sizeof(struct node));
    struct node* second = malloc(sizeof(struct node));
    struct node* third = malloc(sizeof(struct node));
    struct node* fourth = malloc(sizeof(struct node)); // Note: not used below

    // Assign data to each node and link them
    head->data = 100;
    head->next = first;

    first->data = 200;
    first->next = second;

    second->data = 300;
    second->next = third;

    third->data = 400;
    third->next = fourth;
    
    
    fourth->data=500;
    fourth->next=NULL;// Last node points to NULL (end of list)

    // Call function to print all values in the list
    printValues(head);

    return 0; // Program ends successfully
}
