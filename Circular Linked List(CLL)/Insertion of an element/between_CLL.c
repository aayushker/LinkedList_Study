#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main(){
    struct node n1, n2, n3,  *ptr, *new, *last;
    n1.data = 100;
    n2.data = 200;
    n3.data = 400;
    n1.link = &n2;
    n2.link = &n3;
    n3.link = &n1;
    last = &n3;
    ptr = last->link;

    new = malloc(sizeof( struct node ));

    int key,ele;
    printf("Enter the key after you want to enter the new node");
    scanf("%d", &key);
    printf("Enter the element to be inserted");
    scanf("%d", &ele);

    while (ptr->data != key){
        ptr = ptr->link;
    }
    new->link = ptr->link;
    ptr->link = new;
    new->data = ele;
    

    ptr = last->link;
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }while(ptr != last->link);

}