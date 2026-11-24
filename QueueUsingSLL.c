#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
void enqueue(){
    int n;
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Element to insert:");
    scanf("%d",&n);
    new->next=NULL;
    new->data=n;
    if(rear==NULL){
        front=new;
        rear=new;
    }
    else{
        rear->next=new;
        rear=new;
    }
    printf("Added %d!\n",n);
    printf("\n");
}

void dequeue(){
    if(rear==NULL){
        printf("Queue Empty!\n");
        return;
    }
    struct node *temp;
    temp=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    printf("Deleted %d!\n",temp->data);
    free(temp);
    printf("\n");
}

void display(struct node* h){
     if(h==NULL){
        printf("Queue Empty!\n");
        return;
    }
    struct node *temp;
    temp=h;
    printf("Front->");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("Rear\n");
}
int main(){
    int choice;
    int menu=1;
    do{
        printf("--------------------\n");
        printf("Menu-\n");
        printf("1-enqueue\n2-dequeue\n3-display\n4-exit\n");
        printf("--------------------\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display(front);
                    break;
            case 4: printf("Exiting...");
                    menu=0;
        }
    }while(menu!=0);
    return 0;
}