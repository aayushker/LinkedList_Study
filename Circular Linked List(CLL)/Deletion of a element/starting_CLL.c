#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node n1, n2, n3, *ptr, *last;
    n1.data = 100;
    n2.data = 200;
    n3.data = 300;
    n1.link = &n2;
    n2.link = &n3;
    n3.link = &n1;
    last = &n3;
    ptr = last->link;

    if (ptr == NULL){
        printf("Underflow, exitng...");
    }
    else{
        last->link = ptr->link;
        ptr->link = NULL;
        free (ptr);
    }

    ptr = last->link;
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }while(ptr != last->link);
}
