#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* s1 = NULL;
struct node* s2 = NULL;

void enque(int x);
void deque();
int isempty(struct node* s);
void push(struct node** s, int x);
int pop(struct node** s);
void display();

int isempty(struct node* s)
{
    if (s == NULL)
        return 1;
    else
        return 0;
}

void push(struct node** s, int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = NULL;
    if (*s == NULL) {
        *s = temp;
    }
    else {
        temp->link = *s;
        *s = temp;
    }
}

int pop(struct node** s)
{
    struct node* temp = *s;
    int y = temp->data;
    *s = (*s)->link;
    free(temp);
    return y;
}

void display()
{
    struct node* temp = s1;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void enque(int x)
{
    push(&s1, x);
}

void deque()
{
    while (!isempty(s1)) {
        int y = pop(&s1);
        push(&s2, y);
    }
    pop(&s2);
    while (!isempty(s2)) {
        int k = pop(&s2);
        push(&s1, k);
    }
}

int main()
{
printf("enter length of string\n");
int tashu;
scanf("%d",&tashu);
    printf("enter the string\n");
    char str[tashu];
    scanf("%s", str);
for(int jiggi=0;jiggi<tashu;jiggi++){
    push(s1,str[jiggi]);
}
   for(int sim=0;sim<tashu;sim++){
    if(str[sim]==front(s1))
    pop(s1);
   }
   if(isempty(s1))
   printf("yes its palindrome\n");
   else
   printf("no its not a palindrome\n");

    }
    display();
    deque();
    deque();
    display();

    return 0;
}
