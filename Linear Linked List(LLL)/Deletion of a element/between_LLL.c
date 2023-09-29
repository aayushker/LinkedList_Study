#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node n1, n2,n3,n4,n5, *start, *ptr, *ptr1;
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
        printf("Underflow, exiting...");
    }
    else{
        int key;
        printf("Enter the element after which you want to delete");
        scanf("%d",&key);
        while (ptr != NULL && (ptr->data != key)){
            ptr1=ptr;
            ptr=ptr->link;
        }

        if (ptr == NULL){
            printf("Key not present, exiting...");
        }
        else{
            ptr1->link=ptr->link;
            ptr->link=NULL;
        }
        free(ptr);
    }

    ptr = start;

    while (ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}