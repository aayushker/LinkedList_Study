#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}Node;

Node *start;

Node *getnode(int ele){
    Node *new = (Node *)malloc(sizeof( Node ));
    new->data = ele;
    new->link = NULL;
    return new;
}

insertatfront(int ele){
    Node *new = getnode (ele);

    if (start == NULL){
        start = new;
    }
    else{
        new->link = start;
        start = new;
    }
}

display(){
    Node *ptr;
    ptr = start;

    while (ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
}

int main(){ 
    int m,n;
    printf("How many elements you want to enter\n");
    scanf ("%d",&n);
    printf("Enter the elements\n");
    for (int i=0; i<n; i++){
        scanf("%d",&m);
        insertatfront(m);
    }
    printf("The elements are:\n");
    display();
}