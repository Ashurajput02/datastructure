struct node * temp1=head1;
struct node *temp2=head2;
while(temp1!=NULL && temp2!=NULL){
    if(temp1->d2 > temp2->d2){
        head3=insert(head3,temp1->d1,temp1->d2,temp1->d3,temp1->d4);
        temp1 = temp1 -> next;
    }
    else if(temp1->d2<temp2->d2){
         head3=insert(head3,temp2->d1,temp2->d2,temp2->d3,temp2->d4);
        temp2 = temp2 -> next;
    }
    else if(temp1->d2==temp2->d2 &&temp1->d3==temp2->d3&& temp1->d4==temp2->d4)
{
     head3=insert(head3,(temp2->d1+temp1->d1),temp2->d2,temp2->d3,temp2->d4);
        temp2 = temp2 -> next;
        temp1=temp1->next;
}

}
if(temp1!=NULL){
    while(temp1!=NULL){
        head3=insert(head3,temp1->d1,temp1->d2,temp1->d3,temp1->d4);
        temp1 = temp1 -> next;
    }
}


if(temp2!=NULL){
    while(temp2!=NULL){
        head3=insert(head3,temp2->d1,temp2->d2,temp2->d3,temp2->d4);
        temp2 = temp2 -> next;
    }
}