#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
        int size;
        int top;
        char *arr;
};

int isEmpty(struct stack *ptr){

    if(ptr->top == -1){
         return 1; 
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,char value){

 if(isFull(ptr)){
        printf("The Stack is Full, It cannot push %d\n",value);
    }    
    else{
        
        ptr->top++;
        ptr ->arr[ptr->top] = value;
    }
}
char pop(struct stack *ptr){

    if(isEmpty(ptr)){
        printf("The Stack is Empty, It cannot pop \n");
        return -1;
    }
    else{
        char value = ptr->arr[ptr->top];
        ptr->top--;
        // printf("the value %d is poped\n", value);
        return value;
    }
}


int StackTop(struct stack *ptr){
        return ptr->arr[ptr->top];
}
int isOperator(char ch){
    if(ch== '*' || ch == '/' || ch== '+' || ch == '-'){
        return 1;
}
else 
return 0;
}
int Precedence(char ch){

            if(ch== '*' || ch == '/'){
                return 3;
            }
            else if(ch== '+' || ch == '-'){
                return 2;
            }
            else
            return 0;
}

char *InfixToPostfix(char *infix){

    struct stack sp = (struct stack)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top=-1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));

    char postfix =  (char)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;//as infix scanner
    int j=0;//as postfix filler

        while(infix[i] != '\0')
        {
            if(!isOperator(infix[i])){
                postfix[j]=infix[i];
                i++;
                j++;
            }
            else{
                if(Precedence(infix[i]) > Precedence(StackTop(sp))){
                    push(sp,infix[i]);
                    i++;
                }
                else{
                     postfix[j] = pop(sp);
                    j++;
                }
            }
        }
            while (!isEmpty(sp))
            {
                postfix[j] = pop(sp);
                j++;
            }
            postfix[j]='\0';
            return postfix;
            
}



int main(){

   char infix[80];
printf("enter the infix expression\n");
scanf("%s",infix);
    printf("The postfix expression will be %s",InfixToPostfix(infix) );
   
    return 0;

   
}