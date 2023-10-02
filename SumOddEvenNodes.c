#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node n1, n2, n3, n4, n5, *ptr, *start;
    n1.data = 78; 
    n2.data = 10; 
    n3.data = 61; 
    n4.data = 89; 
    n5.data = 52; 
    n1.link = &n2;
    n2.link = &n3;
    n3.link = &n4;
    n4.link = &n5;
    n5.link = NULL;
    start = &n1;
    ptr = start;

    if (start == NULL){
        printf("The given LLL is empty");
        exit(0);
    }
    else{
        int e=0,o=0;
        while (ptr != NULL){
            if ((ptr->data)%2 == 0){
                e+=(ptr->data);
            }
            else if((ptr->data)%2 != 0){
                o+=(ptr->data);
            }
            ptr = ptr->link;
        }
        printf("The sum of all the even elements is %d and that of odd is %d",e,o);
    }
    return 0;
}