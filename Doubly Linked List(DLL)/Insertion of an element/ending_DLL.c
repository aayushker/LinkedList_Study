#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};

int main(){
    struct node n1, n2, n3, *ptr, *new, *start;
    n1.data = 100;
    n2.data = 200;
    n3.data = 300;
    n1.llink = NULL;
    n1.rlink = &n2;
    n2.llink = &n1;
    n2.rlink = &n3;
    n3.llink = &n2;
    n3.rlink = NULL;
    start = &n1;
    ptr = start;

    new = malloc(sizeof( struct node ));

    if (new == NULL){
        printf("Overflow, exiting...");
    }
    else{
        while (ptr->rlink != NULL){
            ptr = ptr->rlink;
        }

        int ele;
        printf("Enter the element you want to enter");
        scanf("%d",&ele);
        ptr->rlink = new;
        new->llink = ptr;
        new->rlink = NULL;
        new->data = ele;
    }

    ptr = start;
    do{
        printf("%d\n", ptr->data);
        ptr = ptr->rlink;
    }while (ptr != start);
}