#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *llink;
    struct node *rlink;
}Node;

Node *ptr, *start;

Node *getnode(int ele){
    Node *new = (Node *)malloc(sizeof( Node ));
    new->data = ele;
    new->llink = NULL;
    new->rlink = NULL;
    return new;
}

int startingI(int ele){
    Node *new = getnode (ele);

    if (start == NULL){
        start = new;
    }
    else{
        ptr = start;
        ptr->llink = new;
        new->rlink = start;
        new->llink = NULL;
        start = new;
    }
}

display(){
    if (start == NULL){
        printf("Underflow, no elements to display\n");
        exit(0);
    }
    else{
        ptr = start;
        printf("The elements in the CLL are\n");
        do{
            printf("%d\n",ptr->data);
            ptr = ptr->rlink;
        }while(ptr != start);
    }
}

int main(){
    int ele=0, key=0, op;
    do {
        printf("//**Menu**//\n");
        printf("Press 1 for inserting as first node\n");
        printf("Press 2 for inserting as last node\n");
        printf("Press 3 for inserting after a given key value\n");
        printf("Press 4 for deleting as first node\n");
        printf("Press 5 for deleting as last node\n");
        printf("Press 6 for deleting after a given key value\n");
        printf("Press 7 for reversing the LL\n");
        printf("Press 8 to display the LL\n");
        printf("Press 9 to exit\n");
        printf("________________________________________________\n");
        printf("Enter your choice: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Enter the element to push as first node ");
                scanf("%d",&ele);
                startingI(ele);
                break;

            case 2:
                printf("Enter the element you want to enter as last node ");
                scanf("%d",&ele);
                // endingI(ele);
                break;

            case 3:
                printf("Enter the key value after which you want to enter the node ");
                scanf("%d",&key);
                printf("Enter the element you want to insert ");
                scanf("%d",&ele);
                // betweenI(ele, key);
                break;

            case 4:
                // startingD();
                break;

            case 5:
                // endingD();
                break;

            case 6:
                printf("Enter the key value which you want you to delete ");
                scanf("%d",&key);
                // betweenD(key);
                break;

            case 7:
                // reversal();

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }while(1);
}

