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

 
void display (){
    if (start == NULL){
        printf("The given LL is empty");
    }
    else{
       ptr = start;
        printf("The elements in the LL");
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
        // printf("Press 1 for deleting as first node\n");
        // printf("Press 2 for deleting as last node\n");
        // printf("Press 3 for deleting after a given key value\n");
        printf("Press 4 to display the LL\n");
        printf("Press 5 to exit\n");
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
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice");
        }
    }while(1);
}
