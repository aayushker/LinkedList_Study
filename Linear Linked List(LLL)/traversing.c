#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node n1,n2,n3,n4,*start,*ptr;
    n1.data=100;
    n2.data=200;
    n3.data=300;
    n4.data=400;
    n1.link=&n2;
    n2.link=&n3;
    n3.link=&n4;
    n4.link=NULL;
    start=&n1;
    ptr=start;
    while (ptr->link!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }

    struct node *p = (struct node *)malloc(sizeof(struct node));
}
