#include <stdio.h>
#include <stdlib.h>
struct Node{
    char data;
    struct Node *next;
};
typedef struct Node Node;
void push(Node ** head,char value){
    Node * temp=(Node *) malloc(sizeof(Node));
    if(temp==NULL){
        printf("error in malloc!\n");
        exit(1);
    }
    temp->data=value;
    temp->next=(*head);
    (*head)=temp;
}
int empty(Node *head){
    return head==NULL;
}
void pop(Node **head){
    if(head==NULL) return;
    Node * temp=(*head);
    *head =temp->next;
    free(temp);
}
char top(Node *head){
    if(head!=NULL){
        return head->data;
    }
}
int main(){
    FILE *fptr;
    fptr=fopen("test.txt","r");
    if(!fptr){
        printf("Error opening file!");
        exit(1);
    }
    Node *stack=NULL;
    char ch;
    while(!feof(fptr)){
        ch=fgetc(fptr);
        int br=0;
        if(ch=='('|| ch=='{'||ch=='['){
            push(&stack,ch);
        }
        else if(ch==')'||ch=='}'||ch==']'){
            if(empty(stack)) br=1;
            if(ch==')'){
                if(top(stack)=='(') pop(&stack);
                else br=1;
            }
            if(ch=='}'){
                if(top(stack)=='{') pop(&stack);
                else br=1;
            }
            if(ch==']'){
                if(top(stack)=='[') pop(&stack);
                else br=1;
            }
        }
        if(br){
            printf("Not balanced\n");
            return 0;
        }
    }
    if(empty(stack)) printf("perfectly balanced.\n");
    else printf("Not balanced.\n");
    return 0;
}