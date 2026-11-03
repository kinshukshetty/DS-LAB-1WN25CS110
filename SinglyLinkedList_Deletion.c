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

void deleteFront(struct node **head){
    if(*head==NULL){
        printf("list is empty!");
        return;
    }
    struct node *temp=*head;
    *head=temp->next;
    printf("deleted %d!\n",temp->data);
    free(temp);
}
void deleteEnd(struct node **head)
{
    if(*head==NULL){
        printf("list is empty!");
        return;
    }
    struct node *temp=*head;
    if(temp->next==NULL){
        *head=NULL;
        free(temp);
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    printf("deleted %d!\n",temp->next->data);
    free(temp->next);
    temp->next=NULL;
}
void deletePos(struct node **head,int pos){
    if(*head==NULL){
        printf("list is empty!");
        return;
    }
    if(pos<1){
        printf("Invalid!!");
        return;
    }
    if(pos==1){
        deleteFront(head);
        return;
    }
    struct node *temp=*head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        printf("Out of Bounds!\n");
        return;
    }
    struct node *nxt=temp->next->next;
    printf("deleted %d!\n",temp->next->data);
    free(temp->next);
    temp->next=nxt;
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
    int z;
    int choice;
    struct node *hd;
    hd=(struct node *)malloc(sizeof(struct node));
    do{
        printf("---------------\n");
        printf("1-Create\n2-Delete Front\n3-Delete Rear\n4-Delete At Position\n5-Display\n6-Exit\n");
        printf("---------------\n");
        printf("Your choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1: printf("Enter Number of Elements:");
                scanf("%d",&z);
                create(&hd,z);
                break;
        case 2: deleteFront(&hd);
                break;
        case 3: deleteEnd(&hd);
                break;
        case 4: printf("enter position:");
                scanf("%d",&z);
                deletePos(&hd,z);
                break;
        case 5: display(&hd);
                break;
        case 6: printf("Exiting....");
                menu=1;
        }

    }while(menu!=1);
return 0;
}