#include<stdio.h>
#include<stdlib.h>
 struct node {
    int data;
    struct node *link;
 };

 int main(){
    struct node n1, n2, n3, *ptr, *last, *new;
    n1.data = 100;
    n2.data = 200;
    n3.data = 300;
    n1.link = &n2;
    n2.link = &n3;
    n3.link = &n1;
    last = &n3;

    new = malloc(sizeof( struct node));

    if (new == NULL){
        printf("Overflow, exiting...");
    }
    else{
        int ele;
        printf("Enter the element you want to enter");
        scanf("%d",&ele);
        new->link = last->link;
        last->link = new;
        last = new;
        new->data=ele;
    }

    ptr = last->link;
    do{
        printf("%d\n", ptr->data);
        ptr=ptr->link;
    }while(ptr != last->link);
    
 }