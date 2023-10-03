#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start;

void main(){

    
    struct node *newnode;
    struct node *temp;
    start = NULL;
    int choice, count = 0;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (start == 0)
        {
            start = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue (0,1)?\n");
        scanf("%d", &choice);
    }
    printf("--------------------------------\n");
    temp = start;
    while (temp != 0)
    {
        printf("\n%d\n", temp->data);
        temp = temp->next;
        count++;
    }
    {
        printf("\nCount=%d", count);
    }
}