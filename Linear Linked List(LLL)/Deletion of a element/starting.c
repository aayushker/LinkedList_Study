#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node n1, n2, *start, *ptr;
    n1.data = 100;
    n2.data = 200;
    n1.link = &n2;
    n2.link = NULL;
    start = &n1;
    ptr = start;

    if (start == NULL){
        printf("Overflow, exiting...");
    }
    else{
        start=ptr->link;
        ptr->link=NULL;
        free(ptr);
    }

    ptr = start;

    while (ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}