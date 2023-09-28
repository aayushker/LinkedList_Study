#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node n1, n2, *start, *New, *ptr;
    New = malloc(sizeof(struct node));
    n1.data = 100;
    n2.data = 200;
    n1.link = &n2;
    n2.link = NULL;
    start = &n1;
    ptr = start;

    if (New == NULL){
        printf("Overflow, exiting...");
    }
    else{
        int ele,key;
        printf("Enter element you want to enter:");
        scanf("%d", &ele);
        printf("Enter after which key value you want to add");
        scanf("%d", &key);
        while (ptr->data != key){
        ptr = ptr->link;
        }
        New->link=ptr->link;
        ptr->link=New;
        New->data=ele;
    }

    ptr = start;

    while (ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}