#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    struct node n1, n2, n3, n4, n5, *ptr, *start;
    n1.data = 52;
    n2.data = 26;
    n3.data = 21;
    n4.data = 50;
    n5.data = 54;
    n1.link = &n2;    
    n2.link = &n3;    
    n3.link = &n4;    
    n4.link = &n5;    
    n5.link = NULL; 
    start = &n1;
    ptr = start;

    if (start == NULL){
        printf("The given LLL has no nodes");
        exit(0);
    }
    else{
        int o=0,e=0;

        while (ptr != NULL){
            if ((ptr->data)%2 == 0){
                e++;
            }
            else if ((ptr->data)%2 != 0){
                o++;
            }
            ptr = ptr->link;
        }
        printf("There are total %d even nodes and %d odd nodes",e,o);
    }
    
    return 0;
}