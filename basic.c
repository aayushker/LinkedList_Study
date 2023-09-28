// Basic Linked List Program in C construct a linked list with two nodes and display the data in the nodes.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;                           //these are the member variable
    struct node *link;                  //self referential pointer
};

int main(){
    struct node n1,n2,*start;           //these are structure variable
    n1.data=100;
    n2.data=200;
    n1.link=&n2;
    n2.link=NULL;
    start=&n1;

    // Print statement to print the data and address of the first node
    printf("%d\n",start->data);
    printf("%d\n",start->link);

    // Print statement to print the data and address of the second node
    printf("%d\n",start->link->data);
    printf("%d\n",start->link->link);
}