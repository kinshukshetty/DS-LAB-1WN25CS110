#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;
void push(){
    int n;
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Element to insert:");
    scanf("%d",&n);
    new->data=n;
    new->next=top;
    top=new;
    printf("Added %d!\n",n);
    printf("\n");
}

void pop(){
    if(top==NULL){
        printf("Stack Empty!\n");
        return;
    }
    struct node *temp;
    temp=top;
    top=top->next;
    printf("Deleted %d!\n",temp->data);
    free(temp);
    printf("\n");
}

void display(struct node* h){
     if(h==NULL){
        printf("Stack Empty!\n");
        return;
    }
    struct node *temp;
    temp=h;
    printf("top->");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int choice;
    int menu=1;
    do{
        printf("--------------------\n");
        printf("Menu-\n");
        printf("1-push\n2-pop\n3-display\n4-exit\n");
        printf("--------------------\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display(top);
                    break;
            case 4: printf("Exiting...");
                    menu=0;
        }
    }while(menu!=0);
    return 0;
}