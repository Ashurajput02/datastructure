void add(int m1,int m2,int n1, int n2){
if(m1==m2 &&n1==n2){
    struct node *temp1=head1;
    struct node*temp2=head2;
    while(temp1!=NULL){
temp2=head2;
            
        while(temp2!=NULL){
            if(temp2->r==temp1->r && temp2->c==temp1->c){
                break;
            }
            temp2=temp2->next;

        }
        if(temp2!=NULL)
        temp1->data+=temp2->data;

        temp1=temp1->next;

    }
}
}
