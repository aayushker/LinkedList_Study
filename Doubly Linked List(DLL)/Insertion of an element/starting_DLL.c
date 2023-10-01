#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};

int main(){
    struct node n1, n2, n3, *ptr, *new, *start;
    n1.data = 200;
    n2.data = 300;
    n3.data = 400;
    n1.llink = NULL;
    n1.rlink = &n2;
    n2.llink = &n1;
    n2.rlink = &n3;
    n3.llink = &n2;
    n3.rlink = NULL;
    start = &n1;
    ptr = start;

    new = malloc(sizeof( struct node ));

    if (new ==  NULL){
        printf("Overflow, exiting...");
    }
    else{
        int ele;
        printf("Enter the element you want to enter");
        scanf("%d",&ele);
        new->llink = NULL;
        new->rlink = start;
        new->llink = new;
        new->data = ele;
        start = new;
    }

    ptr = start;
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->rlink;
    }while (ptr != start);
}