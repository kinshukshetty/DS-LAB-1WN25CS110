#include<stdio.h>
#define max 10
int top=-1;
int stack[max];
void push(int data){
    if(top==max-1){
        printf("\nSTACK OVERFLOW!\n");
        return;
    }
    top++;
    stack[top]=data;
}
int pop(){
    if(top==-1){
        printf("\nSTACK UNDERFLOW!\n");
        return -1;
    }
    return stack[top--];
}
void display(){
    if(top==-1){
        printf("EMPTY STACK!\n");
    }
    else{
    printf("STACK elements are:\n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
    }
}
int main(){
    int choice;
    int menu=0;
    do{
        
        printf("\n1-PUSh\n2-POP\n3-DISPLAY\n4-EXIT\n");
         printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: 
                {int dat;
                printf("Enter your insertion element:");
                scanf(" %d",&dat);
                push(dat);
                break;}
        case 2: 
                {int last;
                last=pop();
                if(last!=-1){
                    printf("POPED Successfully!\n");
                }
                break;}
        case 3: display();
                break;
        case 4: printf("EXITING Program!\n");
                menu=1;
                break;
        
        default:printf("INVALID CHOICE!\n");
                break;
        }
    }while(menu==0);
return 0;
}