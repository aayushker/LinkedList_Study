#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node n1, n2, n3, n4, n5, *ptr, *start;
    int c=0;
    n1.data = 100;
    n2.data = 200;
    n3.data = 300;
    n4.data = 400;
    n5.data = 500;
    n1.link = &n2;
    n2.link = &n3;
    n3.link = &n4;
    n4.link = &n5;
    n5.link = NULL;
    start = &n1;
    ptr = start;

    if (start == NULL){
        printf("This Single Linked List has %d nodes", c);
    }
    else{
        c=1;
        while (ptr->link != NULL){
        c=c+1;
        ptr = ptr->link;
        }
    }
    
    printf("This Single Linked List has %d nodes",c);

    return 0;
}