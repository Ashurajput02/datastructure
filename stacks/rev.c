#include<stdio.h>
#include<string.h>
int main(){
    char a[5]="ashur";
    // char b[5]=strrev(a);
    // printf("%s",b);
for(int i=0;i<5/2;i++){

    char temp=a[i];
    a[i]=a[5-i-1];
    a[5-i-1]=temp;
}
printf("%s",a);


}