#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void create(struct node **head,int num){
    for(int i=0;i<num;i++){
        int k;
        struct node *newNode;
        printf("Enter Element%d:",i+1);
        scanf("%d",&k);
        newNode=(struct node *)malloc(sizeof(struct node));
        if(newNode==NULL){
            printf("Memory allocation Failed!\n");
            return;
        }
        newNode->data=k;
        newNode->next=NULL;
        if(i==0){
            *head=newNode;
        }
        else{
            struct node *temp=*head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        }
        printf("Created New Linked List!\n");
}
void insertFront(struct node **head,int value){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation Failed!");
        return;
    }
    newNode->data=value;
    newNode->next=*head;
    *head=newNode;
    printf("Added %d!\n",newNode->data);
}
void insertEnd(struct node **head,int value){
     struct node *newNode,*temp;
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation Failed!");
        return;
    }
    newNode->next=NULL;
    newNode->data=value;
    printf("Added %d!\n",newNode->data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void insertPos(struct node **head,int value,int pos){
    if(pos<1){
        printf("Invalid position!\n");
        return;
    }
    if(pos==1){
        insertFront(head,value);
        return;
    }
    struct node *newNode,*temp;
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation Failed!");
        return;
    }
    temp=*head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Out of Bounds!\n");
        return;
    }
    newNode->data=value;
    printf("Added %d!\n",newNode->data);
    newNode->next=temp->next;
    temp->next=newNode;
}
void display(struct node **head){
    if(*head==NULL){
        printf("list empty!");
        return;
    }
    struct node *temp=*head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int menu=0;
    int z,y;
    int choice;
    struct node *hd;
    hd=(struct node *)malloc(sizeof(struct node));
    do{
        printf("---------------\n");
        printf("1-Create\n2-Insert Front\n3-Insert Rear\n4-Insert At Position\n5-Display\n6-Exit\n");
        printf("---------------\n");
        printf("Your choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1: printf("Enter Number of Elements:");
                scanf("%d",&z);
                create(&hd,z);
                break;
        case 2: printf("Enter element:");
                scanf("%d",&z);
                insertFront(&hd,z);
                break;
        case 3: printf("Enter element:");
                scanf("%d",&z);
                insertEnd(&hd,z);
                break;
        case 4: printf("Enter element:");
                scanf("%d",&z);
                printf("enter position:");
                scanf("%d",&y);
                insertPos(&hd,z,y);
                break;
        case 5: display(&hd);
                break;
        case 6: printf("Exiting....");
                menu=1;
        }

    }while(menu!=1);
return 0;
}