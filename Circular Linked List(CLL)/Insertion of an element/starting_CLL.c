#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};


int main(){
    struct node n1, n2, n3, *new, *ptr, *last, *start;
    n1.data = 200;
    n2.data = 300;
    n3.data = 400;
    n1.link = &n2;
    n2.link = &n3;
    n3.link = &n1;
    last = &n3;
    start= &n1;

    new = malloc(sizeof(struct node));

    if (last == NULL){
        new->data=100;
        new->link=new;
        last=new;
    }
    else{
        new->data=100;
        new->link = last->link;
        last->link = new;
        last = new;
    }

    ptr= start;

    do {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    } while (ptr != start);

}
