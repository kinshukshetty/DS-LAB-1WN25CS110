#include <stdio.h>
#define max 3
int queue[max];
int f=-1,r=-1,chk;
void enqueue(int n){
    if(r==max-1){
        printf("QUEUE IS FULL!\n");
        chk=1;
        return;
    }
    if(f==-1){
        f=0;
    }
    r++;
    queue[r]=n;
} 
int dequeue(){
    if(f==-1||f>r){
        printf("QUEUE IS EMPTY!\n");
        chk=2;
        
    }
    return queue[f++];
    
}
void display(){
    if(f==-1||f>r){
        printf("QUEUE IS EMPTY!\n");
        return;
    }
    else{printf("Queue values are:\n");
        for(int i=f;i<=r;i++){
            printf("%d\n",queue[i]);
    }}
}
int main() {
int choice;
int menu=0;
int a;
do{
    printf("-----------------------\n");
    printf("MENU");
    printf("\n1-add\n2-remove\n3-display\n4-exit\n");
    printf("-----------------------\n");
    printf("your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("enter element to enter:");
                scanf("%d",&a);
                enqueue(a);
                if(chk!=1){
                    printf("%d added to the queue!\n",a);
                }
                break;
        case 2: a=dequeue();
                if(chk!=2){
                    printf("%d removed from the queue!\n",a);
                }
                break;
        case 3: display();
                break;
        case 4: menu=1;
                printf("EXITING PROGRAM......\n");
    }
}while(menu!=1);
    chk=0;
    return 0;
}