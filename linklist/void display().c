void display()
{
    for(int i=0;i<75;i++)
    {
        printf("NAME: \t %s\n",arr[p].name);
        
        printf("ROLL NUMBER: \t %d\n",arr[p].roll);
        
        printf("AGE: \t %d\n",arr[p].age);
        
        printf("ADDRESS: \t %s\n",arr[p].address);
        
        printf("EMAIL: \t %s\n",arr[p].mail);
        
        printf("MOBILE NUMBER: \t %ld \n",arr[p].mob);
        
        printf("PROGRAMME NAME: \t %s \n",arr[p].pgmname);

        
        printf("COMPULSORY SUBJECT 1: \t %s  \n",arr[p].comsub1);
        
        printf("COMPULSORY SUBJECT 2: \t %s \n",arr[p].comsub2);
        
        printf("ELECTIVE SUBJECT 1: \t %s \n",arr[p].elesub1);
        printf("ELECTIVE SUBJECT 2: \t %s \n",arr[p].elesub2);

     
   
    }
}


void modify()
int roll;
printf("Enter roll number\n");
scanf("%d",&roll);
for(int i=0;i<p;i++)
{
    if(arr[p].roll==roll)
    { int change;
        printf("what do u want to modify:\n");
        
        printf("enter 1 to modify address:\n");
        
        printf("enter 2 to modify email:\n");

        printf("enter 3 to modify mobile:\n");
        scanf("%d",&change);
if(change==1)
scanf("%s",arr[p].add);


if(change==2)
scanf("%s",arr[p].mail);

if(change==3)
scanf("%ld",&arr[p].mob);
    }


else
printf("wrong input\n");
}

void search()
{
int rollno;
printf("enter roll number\n");
scanf("%d",&rollno);

for(int i=0;i<75;i++)
{
     if(arr[p].roll==rollno)
{
printf("NAME: \t %s\n",arr[p].name);
        
        printf("ROLL NUMBER: \t %d\n",arr[p].roll);
        
        printf("AGE: \t %d\n",arr[p].age);
        
        printf("ADDRESS: \t %s\n",arr[p].address);
        
        printf("EMAIL: \t %s\n",arr[p].mail);
        
        printf("MOBILE NUMBER: \t %ld \n",arr[p].mob);
        
        printf("PROGRAMME NAME: \t %s \n",arr[p].pgmname);

        
        printf("COMPULSORY SUBJECT 1: \t %s  \n",arr[p].comsub1);
        
        printf("COMPULSORY SUBJECT 2: \t %s \n",arr[p].comsub2);
        
        printf("ELECTIVE SUBJECT 1: \t %s \n",arr[p].elesub1);
        printf("ELECTIVE SUBJECT 2: \t %s \n",arr[p].elesub2);
}
else
printf("no data found\n");
}
}

     
   