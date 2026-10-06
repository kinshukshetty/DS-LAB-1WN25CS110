#include<stdio.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char ch){
    stack[++top]=ch;
}
char pop(){
    return stack[top--];
}
int len(char arr[MAX]){
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }
    return i;
}
int indx(char arr1[MAX],char c,int lgth){
    int i=0;
    while(i<lgth){
        if(arr1[i]==c){
            return i;
        }
        i++;
    }
    return -1;
}
int main(){
    char array[MAX];
    char array2[MAX];
    char chr;
    printf("ENTER YOUR STRING:");
    scanf("%s",array);
    printf("ENTER YOUR CHARACTER:");
    scanf(" %c",&chr);
    int l;
    l=len(array);
    int x=-1;
    x=indx(array,chr,l);
    if(x==-1){
        printf("CHARCTER NOT FOUND!");
    }
    else{
        int i=0,j=0;
        while(i<=x){
            push(array[i]);
            i++;
           }
        while(j<l){
            if(j<=x){
                array2[j]=pop();
            }
            else{
                array2[j]=array[j];
            }
            j++;
        }
        array2[j]='\0';
        printf("FINAL EXPRESSION:%s",array2);
    }  
}