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

/*
// Going to revise about the linked lists and how the values of a linked list are printed but first and foremost we need to know how a needed space is allocated for the values in c using malloc  

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next; 
        };

    void print(struct node* head){
    struct node* current=head;
    
        while(current != NULL){
        
          printf("%d ->",current->data);

          current=current->next;
            }

            printf("NULL\n");
        }

        int main(){
        
        struct node* head=malloc(sizeof(struct node));
        struct node* first=malloc(sizeof(struct node)); 
        struct node* second=malloc(sizeof(struct node)); 
        struct node* third=malloc(sizeof(struct node));
        struct node* fourth=malloc(sizeof(struct node));
        struct node* fifth=malloc(sizeof(struct node));
        struct node* sixth=malloc(sizeof(struct node));
        struct node* seventh=malloc(sizeof(struct node));


        head->data=100;
        head->next=first;

        first->data=200;
        first->next=second;
        
        second->data=300;
        second->next=third;
        
        third->data=400;
        third->next=fourth;

        fourth->data=500;
        fourth->next=fifth;

        fifth->data=600;
        fifth->next=sixth;

        sixth->data=700;
        sixth->next=seventh;

        seventh->data=800;
        seventh->next=NULL;

        printf("These are the values from our linked list.\n");

        print(head);
        }

        // This here is a linked list,it can be defined as a box which holds the value as well as the address of the next box and this happens by using pointers to hold the adresses of those next boxes! but firstly we use malloc to allocate space in our pc that will be storing those linked lists or simply boxes and then after we call a function that will traverse through our linked list and print the valeus found there.    

*/ 