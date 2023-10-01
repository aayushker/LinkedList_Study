#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};

int main(){
    struct node n1, n2, n3, n4, *ptr, *start, *new;
    n1.data = 100;
    n2.data = 200;
    n3.data = 400;
    n4.data = 500;
    n1.llink = NULL;
    n1.rlink = &n2;
    n2.llink = &n1;
    n2.rlink = &n3;
    n3.llink = &n2;
    n3.rlink = &n4;
    n4.llink = &n3;
    n4.rlink = NULL;
    start = &n1;
    ptr = start;

    new = malloc(sizeof( struct node ));
    
    if (new == NULL){
        printf("Underflow, exiting...");
    }
    else{
        int ele, key;
        printf("Enter the postion after which you want to insert the node: ");
        scanf("%d", &key);
        printf("Enter the lement to be inserted: ");
        scanf("%d", &ele);

        while (ptr->data != key){
            ptr = ptr->rlink;
        }

        // ptr1 = ptr->rlink;
        new->llink = ptr;
        new->rlink = ptr->rlink;
        ptr->rlink = new;
        ptr->rlink->llink = new;
        new->data = ele;
    }

    ptr = start;
    do{
        printf("%d\n", ptr->data);
        ptr = ptr->rlink;
    }while (ptr != start);
}