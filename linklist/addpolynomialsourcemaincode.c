
void addition(){
    struct node *temp1=head1;
struct node *temp2=head2;
while(temp1!=NULL || temp2!=NULL){

    if(temp1->data2==temp2->data2){
        int a=temp1->data1 +temp2->data1;
        int b=temp1->data2;
       inserthead3(a,b);
    }
    temp1=temp1->link;
    temp2=temp2->link;

    if(temp1!=NULL){
        while(temp1!=NULL){
            inserthead3(temp1->data1,temp1->data2);
            temp1=temp1->link;
        }
    }

    
    if(temp2!=NULL){
        while(temp2!=NULL){
            inserthead3(temp2->data1,temp2->data2);
            temp2=temp2->link;
        }
    }

    bubblesort3()
}
}
