#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* insertathead(struct node* head, int item) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = item;
    temp->link = head;
    head=temp;}

struct node* insertatend(struct node* head, int item) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node* p = head;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = temp;
    }

    return head;
}


struct node * insert(struct node* head, int item)
{

    struct node *temp=(struct node *)malloc(sizeof( struct node));//most imp
   temp->data=item;
   temp->link=NULL;
   struct node*temp2=head;
   if(head==NULL){
   head=temp;
   return;}

   else{
    while(temp2->link!=NULL)
    temp2=temp2->link;

    temp2->link=temp;


   }
   return head;
   }

void printer(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->link;
    }
}

struct node* mergelists(struct node* head1, struct node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    struct node* mergedhead;
    if (head1->data <= head2->data) {
        mergedhead = head1;
        mergedhead->link = mergelists(head1->link, head2);
    } else {
        mergedhead = head2;
        mergedhead->link = mergelists(head1, head2->link);
    }

    return mergedhead;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    int arr1[4] = {1,3,5,7};
    int arr2[5] = {2,4,6,8,10};

    for (int i = 0; i < 4; i++) {
        head1 = insert(head1, arr1[i]);
    }
    for (int i = 0; i < 5; i++) {
        head2 = insert(head2, arr2[i]);
    }

    printf("List 1: ");
    printer(head1);
    printf("\nList 2: ");
    printer(head2);

    struct node* mergedhead = mergelists(head1, head2);
    printf("\nMerged List: ");
    printer(mergedhead);

    return 0;
}
