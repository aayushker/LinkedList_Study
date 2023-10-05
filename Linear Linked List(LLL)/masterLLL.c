#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}Node;

Node *start, *ptr;

Node *getnode(int ele){
    Node *new = (Node *)malloc(sizeof( Node));
    new->data = ele;
    new->link = NULL;
    return new;
}

int startingI(int ele){
    Node *new = getnode (ele);

    if (start == NULL){
        start = new;
    }
    else{
        new->link = start;
        start = new;
    }
}

int endingI(int ele){
    Node *new = getnode (ele);

    if (start == NULL){
        start = new;
    }
    else{
        ptr = start;

        while (ptr != NULL){
            ptr = ptr->link;
        }
        ptr->link = new;
        new->link = NULL;
    }
}

int betweenI(int ele, int key){
    Node *new = getnode(ele);

    if (start == NULL){
        start = new;
    }
    else{
        ptr = start;
        while(ptr->data == key){
            ptr = ptr->link;
        }
        ptr->link = new;
        new->link = ptr->link;
    }
}

int startingD(){
    if (start == NULL){
        printf("Underflow, no elements to delete\n");
        exit (0);
    }
    else{
        ptr = start;
        start = ptr->link;
        printf("Deleted the first node %d\n",ptr->data);
        ptr->link = NULL;
        free(ptr);
    }
}

int endingD(){
    if (start == NULL){
        printf("Underflow, no elements to delete\n");
        exit(0);
    }
    else{
        ptr = start;
        Node *ptr1;
        while (ptr->link != NULL){
            ptr1 = ptr;
            ptr = ptr->link;
        }
        ptr1 = NULL;
        printf("Deleted the last node %d\n",ptr->data);
        free(ptr);
    }
}

int betweenD(int key){
    if (start == NULL){
        printf("Underflown no element to delete\n");
        exit(0);
    }
    else{
        ptr = start;
        Node *ptr1;
        while (ptr->data != key){
            ptr1 = ptr;
            ptr = ptr->link;
        }
        ptr1->link = ptr->link;
        printf("Deleted the said node %d\n",ptr->data);
        ptr->link = NULL;
        free(ptr); 
    }
}

int reversal(){
    if (start ==  NULL){
        printf("Undeflow condition, no element in the LL to reverse\n");
        exit(0);
    }
    else{
        Node *prev, *next, *temp;
        prev = NULL;
        ptr = start;
        while (ptr != NULL){
            temp = ptr->link;
            ptr->link = prev;
            prev = ptr;
            ptr = temp;
        }
        start = prev;
        printf("The reversed the LL");
    }
}
 
void display (){
    if (start == NULL){
        printf("The given LL is empty");
    }
    else{
       ptr = start;
        printf("The elements in the LL\n");
        while(ptr != NULL){
            printf("%d\n",ptr->data);
            ptr = ptr->link;
        }
    } 
}
    

int main(){
    int ele, key, op;
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
        printf("Enter your choice\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                printf("Enter the element to push as first node");
                scanf("%d",&ele);
                startingI(ele);
                break;

            case 2:
                printf("Enter the element you want to enter as last node");
                scanf("%d",&ele);
                endingI(ele);
                break;

            case 3:
                printf("Enter the key value after which you want to enter the node");
                scanf("%d",&key);
                printf("Enter the element you want to insert");
                scanf("%d",&ele);
                betweenI(ele, key);
                break;

            case 4:
                startingD();
                break;

            case 5:
                endingD();
                break;

            case 6:
                printf("Enter the key value which you want you to delete\n");
                scanf("%d",&key);
                betweenD(key);
                break;

            case 7:
                reversal();
                display();

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid Choice");
        }
    }while(1);
}
