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
            void elesubject(arr[p].pgmname,arr[p].sem)
        
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

        case2:

        
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

        case2:

        
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

        case2:

        
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

        case2:

        
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

        case2:

        
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

        case2:

        
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

        case2:

        
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

        case2:

        
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

        case2:

        
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

        case2:

        
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

        case2:

        
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

        case2:

        
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
