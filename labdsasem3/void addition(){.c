void addition(){
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data2 >temp2->data2){
            temp3=insert(temp3,temp1->data1,temp1->data2);
            temp1=temp1->next;
        }

        
        else if(temp1->data2 < temp2->data2){
            temp3=insert(temp3,temp2->data1,temp2->data2);
            temp2=temp2->next;
        }
        
        else{
            temp3=insert(temp3,(temp1->data1 +temp2->data1),temp2->data2);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
}

if(temp1!=NULL){
    while(temp1!=NULL){
        temp3=insert(temp3,temp1->data1,temp1->data2);
    temp1=temp1->next;
    }
}

    
if(temp2!=NULL){
    while(temp2!=NULL){
        temp3=insert(temp3,temp2->data1,temp2->data2);
    temp2=temp2->next;
    }

}