void compsubject( char pgmname[5],int sem)
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
