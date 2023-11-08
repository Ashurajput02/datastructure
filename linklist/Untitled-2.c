//MY GOD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void diplay();
void modify();
void search();
void elesubject(char pgmname[5],int sem);

void compsubjectct(char pgmname[5],int sem);
struct student{
    char name[30];
    int roll;
    int age;
    char add[100];
    char mail[100];
    long mob;
    char pgmname[5];
    int sem;
    char comsub1[300];
    
    char comsub2[300];
    
    char elesub1[300];
    
    char elesub2[300];

};

struct student arr[10000];
int p=0;


int main()
{
    printf("Enter 1 for registration ,2 for Search and 3 for modifying and 4 to display\n");
    int choice;
    scanf("%d",choice);

    switch(choice)
    {
        case 1:
        if(p<75)
        {
            printf("Enter Name:\n");
            scanf("%s",arr[p].name);

            
            printf("Enter roll number:\n");
            scanf("%d",&arr[p].roll);

            
            printf("Enter Age:\n");
            scanf("%d",&arr[p].age);

            
            printf("Enter Address:\n");
            scanf("%s",arr[p].add);
            
            printf("Enter Email:\n");
            scanf("%s",arr[p].mail);

            
            printf("Enter mobile number:\n");
            scanf("%ld",&arr[p].mob);

            
            printf("Enter Programme Name:\n");
            scanf("%s",arr[p].pgmname);

            printf("enter semester number\n");
            scanf("%d",&arr[p].sem);
            
            char pgmname[10]=(char*)(arr[p].pgmname);
int sem=(int *)(arr[p].sem);
             compsubject(pgmname,sem);
            
             elesubject(pgmname,sem);
            p++;
        }

        else
        printf("sorry registration full");

break;
        case 2:
        search();
        
break;
        case 3:
      
        modify();
      
break;
        case 4:
        display();
      
break;
        default:
        printf("wrong input\n");
 
    }
 return 0;     
    }


void display()
{
    for(int i=0;i<75;i++)
    {
        printf("NAME: \t %s\n",arr[p].name);
        
        printf("ROLL NUMBER: \t %d\n",arr[p].roll);
        
        printf("AGE: \t %d\n",arr[p].age);
        
        printf("ADDRESS: \t %s\n",arr[p].add);
        
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
{
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
        
        printf("ADDRESS: \t %s\n",arr[p].add);
        
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

     

     void compsubject( char pgmname[],int sem)
{
if(strcmp(pgmname,"btech")==0)
{
if(sem==1){
arr[p].comsub1="computer programming";

arr[p].comsub2="calculus for engineers";
return;}

if(sem==2){
arr[p].comsub1="applied programming";

arr[p].comsub2="Data Structures in C";
return;}

if(sem==3){
arr[p].comsub1="Operating Systems";

arr[p].comsub2="oop";
return;}


if(sem==4){
arr[p].comsub1="Microprocessors";

arr[p].comsub2="System programming";
return;}


if(sem==4){
arr[p].comsub1="programming language principles";

arr[p].comsub2="computer organization";
return;}


if(sem==5){
arr[p].comsub1="DBMS";

arr[p].comsub2="computer network";
return;}


if(sem==6){
arr[p].comsub1="Artificial intelligence";

arr[p].comsub2="wireless netwok";
return;}


if(sem==7){
arr[p].comsub1="java programming";

arr[p].comsub2="neural networks";
return;}


if(sem==8){
arr[p].comsub1="mobile computing";

arr[p].comsub2="simulation and modeling";
return;}

}

else if(strcmp(pgmname,"mtech")==0)
{
if(sem==1){
arr[p].comsub1="Data structures";

arr[p].comsub2="software engineering";
return;}

if(sem==2){
arr[p].comsub1="web design";

arr[p].comsub2="applied physics";
return;}

if(sem==3){
arr[p].comsub1="computer graphics";

arr[p].comsub2="operating systems";
return;}


if(sem==4){
arr[p].comsub1="engineering mechanics";

arr[p].comsub2="analog electronics";
return;}

else
printf("incorrect input\n");
}
}




//elective subjects

int edc=0;
int eee=0;
int evs=0;
int as=0;
int ai=0;
int dge=0;
int mg=0;
int mttd=0;
int comskills=0;
int gaming=0;
int android=0;
int logictheory=0;
int pas=0;           
int dm=0;
int sam=0;
int vp=0; 
int nora=0;          
            void elesubject( char pgmname, int sem)
        
{
    int c1,c2;
if(strcmp(pgmname,"btech")==0)
{
    while(nora!=2){
if(sem==1){

    printf("Elective subjects available are:\n");
    printf("1.electronic devices and circuits(001):\n");
    printf("2.Elements of electrical engineering(002):\n");
    printf("3.applied science:(003)\n");
    
    printf("4.environmental studies(004):\n");
    printf("enter your choices\n");
   // scanf("%s %s",arr[p].elesub1,arr[p].elesub2);
    printf("enter their respective serial number\n");
    scanf("%d %d",&c1,&c2);
    switch(c1)
    {
        case 1:
        if(edc<75){
        arr[p].elesub1="electronic devices and circuits"; 
        edc++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case2:
        if(eee<75){
        arr[p].elesub1="elements of electrical engineering"; 
        eee++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(as<75){
        arr[p].elesub1="applied science\n"; 
        as++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
        case 4:
        if(evs<75){
        arr[p].elesub1="environmental studies"; 
        evs++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }

switch(c2)
    {
        case 1:
        if(edc<75){
        arr[p].elesub1="electronic devices and circuits"; 
        edc++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(eee<75){
        arr[p].elesub1="elements of electrical engineering"; 
        eee++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(as<75){
        arr[p].elesub1="applied science"; 
        as++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(evs<75){
        arr[p].elesub1="environmental studies"; 
        evs++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
}


if(sem==2){

    printf("Elective subjects available are:\n");
    printf("1.MTTD(005):\n");
    printf("2.engineering drawings(006):\n");
    printf("3.communication skills:(003)\n");
    
    printf("4.digital electronics(007):\n");
    printf("enter your choices\n");
   // scanf("%s %s",arr[p].elesub1,arr[p].elesub2);
    printf("enter their respective serial number\n");
    scanf("%d %d",&c1,&c2);
    switch(c1)
    {
        case 1:
        if(mttd<75){
        arr[p].elesub1="mttd"; 
        mttd++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(mg<75){
        arr[p].elesub1="engineering drawings"; 
        mg++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(comskills<75){
        arr[p].elesub1="communication skills\n"; 
        comskills++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(dge<75){
        arr[p].elesub1="digital electronics"; 
        dge++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
switch(c2)
    {
        case 1:
        if(mttd<75){
        arr[p].elesub1="mttd"; 
        mttd++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(mg<75){
        arr[p].elesub1="engineering drawings"; 
        mg++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(comskills<75){
        arr[p].elesub1="communication skills"; 
        comskills++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(dge<75){
        arr[p].elesub1="digital electronics"; 
        dge++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
}


if(sem==3){

    printf("Elective subjects available are:\n");
    printf("1.electronic devices and circuits(001):\n");
    printf("2.Elements of electrical engineering(002):\n");
    printf("3.applied science:(003)\n");
    
    printf("4.environmental studies(004):\n");
    printf("enter your choices\n");
   // scanf("%s %s",arr[p].elesub1,arr[p].elesub2);
    printf("enter their respective serial number\n");
    scanf("%d %d",&c1,&c2);
    switch(c1)
    {
        case 1:
        if(edc<75){
        arr[p].elesub1="electronic devices and circuits"; 
        edc++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(eee<75){
        arr[p].elesub1="elements of electrical engineering"; 
        eee++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(as<75){
        arr[p].elesub1="applied science"; 
        as++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(evs<75){
        arr[p].elesub1="environmental studies"; 
        evs++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }

switch(c2)
    {
        case 1:
        if(edc<75){
        arr[p].elesub1="electronic devices and circuits"; 
        edc++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(eee<75){
        arr[p].elesub1="elements of electrical engineering"; 
        eee++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(as<75){
        arr[p].elesub1="applied science"; 
        as++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(evs<75){
        arr[p].elesub1="environmental studies"; 
        evs++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
}




if(sem==4){

    printf("Elective subjects available are:\n");
    printf("1.MTTD(005):\n");
    printf("2.engineering drawings(006):\n");
    printf("3.communication skills:(003)\n");
    
    printf("4.digital electronics(007):\n");
    printf("enter your choices\n");
   // scanf("%s %s",arr[p].elesub1,arr[p].elesub2);
    printf("enter their respective serial number\n");
    scanf("%d %d",&c1,&c2);
    switch(c1)
    {
        case 1:
        if(mttd<75){
        arr[p].elesub1="mttd"; 
        mttd++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(mg<75){
        arr[p].elesub1="engineering drawings"; 
        mg++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(comskills<75){
        arr[p].elesub1="communication skills"; 
        comskills++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(dge<75){
        arr[p].elesub1="digital electronics"; 
        dge++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
switch(c2)
    {
        case 1:
        if(mttd<75){
        arr[p].elesub1="mttd"; 
        mttd++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(mg<75){
        arr[p].elesub1="engineering drawings"; 
        mg++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(comskills<75){
        arr[p].elesub1="communication skills"; 
        comskills++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(dge<75){
        arr[p].elesub1="digital electronics"; 
        dge++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
}




if(sem==5){

    printf("Elective subjects available are:\n");
    printf("1.electronic devices and circuits(001):\n");
    printf("2.Elements of electrical engineering(002):\n");
    printf("3.applied science:(003)\n");
    
    printf("4.environmental studies(004):\n");
    printf("enter your choices\n");
   // scanf("%s %s",arr[p].elesub1,arr[p].elesub2);
    printf("enter their respective serial number\n");
    scanf("%d %d",&c1,&c2);
    switch(c1)
    {
        case 1:
        if(edc<75){
        arr[p].elesub1="electronic devices and circuits"; 
        edc++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(eee<75){
        arr[p].elesub1="elements of electrical engineering"; 
        eee++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(as<75){
        arr[p].elesub1="applied science\n"; 
        as++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(evs<75){
        arr[p].elesub1="environmental studies"; 
        evs++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }

switch(c2)
    {
        case 1:
        if(edc<75){
        arr[p].elesub1="electronic devices and circuits"; 
        edc++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(eee<75){
        arr[p].elesub1="elements of electrical engineering"; 
        eee++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(as<75){
        arr[p].elesub1="applied science\n"; 
        as++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(evs<75){
        arr[p].elesub1="environmental studies"; 
        evs++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
}




if(sem==6){

    printf("Elective subjects available are:\n");
    printf("1.gaming(008):\n");
    printf("2.engineering drawings(006):\n");
    printf("3.logictheory:(009)\n");
    
    printf("4.applied physics(010):\n");
    printf("enter your choices\n");
   // scanf("%s %s",arr[p].elesub1,arr[p].elesub2);
    printf("enter their respective serial number\n");
    scanf("%d %d",&c1,&c2);
    switch(c1)
    {
        case 1:
        if(gaming<75){
        arr[p].elesub1="gaming"; 
        gaming++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(mg<75){
        arr[p].elesub1="engineering drawings"; 
        mg++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(logictheory<75){
        arr[p].elesub1="logic theory"; 
        logictheory++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(ap<75){
        arr[p].elesub1="applied physics"; 
        ap++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }




  switch(c2)
    {
        case 1:
        if(gaming<75){
        arr[p].elesub1="gaming"; 
        gaming++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(mg<75){
        arr[p].elesub1="engineering drawings"; 
        mg++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(logictheory<75){
        arr[p].elesub1="logic theory"; 
        logictheory++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(ap<75){
        arr[p].elesub1="applied physics"; 
        ap++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }

}


if(sem==7){

    printf("Elective subjects available are:\n");
    printf("1.android(011):\n");
    printf("2.data mining(012):\n");
    printf("3.logictheory:(009)\n");
    
    printf("4.simulation and modelling(013):\n");
    printf("enter your choices\n");
   // scanf("%s %s",arr[p].elesub1,arr[p].elesub2);
    printf("enter their respective serial number\n");
    scanf("%d %d",&c1,&c2);
    switch(c1)
    {
        case 1:
        if(android<75){
        arr[p].elesub1="android development"; 
        android++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(dm<75){
        arr[p].elesub1="data mining"; 
        dm++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(logictheory<75){
        arr[p].elesub1="logic theory"; 
        logictheory++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(sam<75){
        arr[p].elesub1="simulation and modelling"; 
        sam++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }

        switch(c1)
    {
        case 1:
        if(android<75){
        arr[p].elesub1="android development"; 
        android++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(dm<75){
        arr[p].elesub1="data mining"; 
        dm++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(logictheory<75){
        arr[p].elesub1="logic theory"; 
        logictheory++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(sam<75){
        arr[p].elesub1="simulation and modelling"; 
        sam++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }

}

if(sem==2){

    printf("Elective subjects available are:\n");
    printf("1.visual programming(014):\n");
    printf("2.engineering drawings(006):\n");
    printf("3.communication skills:(003)\n");
    
    printf("4.digital electronics(007):\n");
    printf("enter your choices\n");
   // scanf("%s %s",arr[p].elesub1,arr[p].elesub2);
    printf("enter their respective serial number\n");
    scanf("%d %d",&c1,&c2);
    switch(c1)
    {
        case 1:
        if(vp<75){
        arr[p].elesub1="visual programming"; 
        vp++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(mg<75){
        arr[p].elesub1="engineering drawings"; 
        mg++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(comskills<75){
        arr[p].elesub1="communication skills\n"; 
        comskills++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(dge<75){
        arr[p].elesub1="digital electronics"; 
        dge++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
switch(c2)
    {
        case 1:
        if(vp<75){
        arr[p].elesub1="visual programming"; 
        vp++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(mg<75){
        arr[p].elesub1="engineering drawings"; 
        mg++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(comskills<75){
        arr[p].elesub1="communication skills"; 
        comskills++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(dge<75){
        arr[p].elesub1="digital electronics"; 
        dge++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
}
    }
}


else if(strcmp(pgmname,"mtech")==0)
{
while(nora!=2){
if(sem==1){

    printf("Elective subjects available are:\n");
    printf("1.electronic devices and circuits(001):\n");
    printf("2.Elements of electrical engineering(002):\n");
    printf("3.applied science:(003)\n");
    
    printf("4.environmental studies(004):\n");
    printf("enter your choices\n");
   // scanf("%s %s",arr[p].elesub1,arr[p].elesub2);
    printf("enter their respective serial number\n");
    scanf("%d %d",&c1,&c2);
    switch(c1)
    {
        case 1:
        if(edc<75){
        arr[p].elesub1="electronic devices and circuits"; 
        edc++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(eee<75){
        arr[p].elesub1="elements of electrical engineering"; 
        eee++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(as<75){
        arr[p].elesub1="applied science\n"; 
        as++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(evs<75){
        arr[p].elesub1="environmental studies"; 
        evs++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }

switch(c2)
    {
        case 1:
        if(edc<75){
        arr[p].elesub1="electronic devices and circuits"; 
        edc++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(eee<75){
        arr[p].elesub1="elements of electrical engineering"; 
        eee++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(as<75){
        arr[p].elesub1="applied science\n"; 
        as++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(evs<75){
        arr[p].elesub1="environmental studies"; 
        evs++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
}


if(sem==2){

    printf("Elective subjects available are:\n");
    printf("1.MTTD(005):\n");
    printf("2.engineering drawings(006):\n");
    printf("3.communication skills:(003)\n");
    
    printf("4.digital electronics(007):\n");
    printf("enter your choices\n");
   // scanf("%s %s",arr[p].elesub1,arr[p].elesub2);
    printf("enter their respective serial number\n");
    scanf("%d %d",&c1,&c2);
    switch(c1)
    {
        case 1:
        if(mttd<75){
        arr[p].elesub1="mttd"; 
        mttd++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(mg<75){
        arr[p].elesub1="engineering drawings"; 
        mg++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(comskills<75){
        arr[p].elesub1="communication skills\n"; 
        comskills++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(dge<75){
        arr[p].elesub1="digital electronics"; 
        dge++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }
switch(c2)
    {
        case 1:
        if(mttd<75){
        arr[p].elesub1="mttd"; 
        mttd++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 2:

        
        if(mg<75){
        arr[p].elesub1="engineering drawings"; 
        mg++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;


        case 3:
        if(comskills<75){
        arr[p].elesub1="communication skills"; 
        comskills++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;

        case 4:
        
        if(dge<75){
        arr[p].elesub1="digital electronics"; 
        dge++;
        nora++;}
        else
        {
            printf("sorry,registration full\n");
        }
        break;
default:
printf("wrong input\n");
    }

}


}
}
}//

   