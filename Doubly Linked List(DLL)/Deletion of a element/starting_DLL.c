#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};

int main(){
    struct node n1, n2, n3, *ptr, *start;
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

    if (start == NULL){
        printf("Underflow, exiting...");
    }
    else{
        start = ptr->rlink;
        start->llink = NULL;
        ptr->rlink = NULL;
        free(ptr);
    }

    ptr = start;
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->rlink;
    }while (ptr != start);
}



