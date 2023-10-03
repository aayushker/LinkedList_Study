#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node n1, n2, n3, n4, n5, n6, *ptr, *start, *prev, *next;
    n1.data = 100;    
    n2.data = 200;    
    n3.data = 300;    
    n4.data = 400;    
    n5.data = 500;    
    n6.data = 600;
    n1.link = &n2;
    n2.link = &n3;
    n3.link = &n4;
    n4.link = &n5;
    n5.link = &n6;
    n6.link = NULL;
    start = &n1;
    ptr = start;
    prev = NULL;

    if (start == NULL){
        printf("The LLL is empty ");
    }
    else{
        while(ptr  != NULL){
            next = ptr->link;
            ptr->link = prev;
            prev = ptr;
            ptr = next;
        }
        start = prev;

        ptr = start;
        while (ptr != NULL){
            printf("%d\n",ptr->data);
            ptr = ptr->link;
        }
    }
}