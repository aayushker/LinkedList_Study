#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node n1, n2, n3, n4, n5, n6, *ptr, *start1, *start2;
    n1.data = 68;
    n2.data = 56;
    n3.data = 37;
    n4.data = 20;
    n5.data = 53;
    n6.data = 31;
    n1.link = &n2;
    n2.link = &n3;
    n3.link = &n4;
    n4.link = &n5;
    n5.link = &n6;
    n6.link = NULL;
    start1 = &n1;
    ptr = start1;

    if (start1 == NULL){
        printf("The given LLL is empty\n");
        exit(0);
    }
    else{
        int c;

        while(ptr != NULL){
            c++;
            ptr = ptr->link;
        }

        printf("Total number of nodes %d and no. of nodes in each LL is  %d\n",c,c/2);

        if (c%2 != 0){
            printf("Enter even number of nodes to split form middle\n");
            exit(0);
        }
        else{
            ptr = start1;

            for (int i=1; i<(c/2); i++){
                ptr = ptr->link;
            }

            start2 = ptr->link;
            ptr->link = NULL;
        }

        ptr = start1;
        printf("Elements of node 1\n");
        while (ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->link;
        }

        ptr = start2;
        printf("Elements of node 2\n");
        while (ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->link;
        }

    }
}