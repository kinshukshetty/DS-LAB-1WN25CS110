#include<stdio.h>
#define max 3
int cq[max];
int f=-1,r=-1;
void enqueue(int n){
    if(f==(r+1)%max||(f==0 && r==max-1)){
        printf("Queue is FULL!\n");
        return;
    }
    if(f==-1){
        f=0;
    }
    r=(r+1)%max;
    cq[r]=n;
    printf("added %d!\n",n);
    return;
}
int dequeue(){
    if(f==-1 && r==-1){
        printf("Queue is EMPTY!\n");
        return -1;
    }
    int m;
    m=cq[f];
    printf("deleted %d!\n",m);
    if(f==r){
        f==-1;
        r==-1;
    }
    f=(f+1)%max;
    return m;
}
void display(){
    if(f==-1 && r==-1){
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("front\n");
    for(int i=f;i!=r;i=(i+1)%max){
        printf("%d\n",cq[i]);
    }
    printf("%d\n",cq[r]);
    printf("rear\n");
}
int main(){
    int menu=0;
    int choice,a;
    do{
        printf("------\n");
        printf("1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n");
        printf("---\n");
        printf("your choice:");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1: printf("Enter element to Add:");
                    scanf("%d",&a);
                    enqueue(a);
                    break;\
            case 2: a=dequeue();
                    break;
            case 3: display();
                    break;
            case 4: menu=1;
                    printf("Exiting Program...");
                    break;
            default: printf("Invalid Choice!");
        }
    }while(menu!=1);
    return 0;
}