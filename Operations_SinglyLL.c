#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* create(){
    struct node* last;
    struct node* head=NULL;
    int n,i;
    printf("Enter number of Elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        struct node *new;
        new=(struct node*)malloc(sizeof(struct node));
        if(new==NULL){
            printf("Memory Allocation Failed!\n");
            return NULL;
        }
        int k;
        printf("Enter Value%d:",i+1);
        scanf("%d",&k);
        new->next=NULL;
        new->data=k;
        if(head==NULL){
            head=new;
            last=new;
            continue;
        }
        last->next=new;
        last=new;
    }
    return head;
};

void display(struct node* h){
     if(h==NULL){
        printf("Stack Empty!\n");
        return;
    }
    struct node *temp;
    temp=h;
    printf("Head->");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void sort(struct node* h){
    int swap;
    if(h==NULL){
        printf("List empty!\n");
        return;
    }
    struct node* temp;
    struct node* curr;
    for(temp=h;temp->next!=NULL;temp=temp->next){
        for(curr=temp->next;curr!=NULL;curr=curr->next){
            if(temp->data>curr->data){
                swap=temp->data;
                temp->data=curr->data;
                curr->data=swap;
            }
        }
    }
}

struct node* conc(struct node * h1,struct node * h2){
    struct node *temp;
    temp=h1;
    if(h1==NULL){
        return h2;
    }
    if(h2==NULL){
        return h1;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=h2;
    return h1;
}

struct node* rev(struct node *h){
    struct node *prev=NULL;
    struct node *curr;
    struct node *nxt;
    curr=h;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}


int main(){
    int choice;
    int menu=1;
    struct node* head1=NULL;
    struct node* head2=NULL;
    do{
        printf("--------------------\n");
        printf("Menu-\n");
        printf("1-Create\n2-Display\n3-Sort\n4-Reverse\n5-Concatenate\n6-Exit\n");
        printf("--------------------\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: head1=create();
                    break;
            case 2: display(head1);
                    break;
            case 3: sort(head1);
                    printf("Sorted list-\n");
                    display(head1);
                    break;
            case 4: head1=rev(head1);
                    printf("Reversed List-\n");
                    display(head1);
                    break;
            case 5: printf("Enter new List to concatenate:\n");
                    head2=create();
                    head1=conc(head1,head2);
                    printf("After concatenation-\n");
                    display(head1);
                    break;
            case 6: printf("Exiting...");
                    menu=0;
        }
    }while(menu!=0);
    return 0;
}