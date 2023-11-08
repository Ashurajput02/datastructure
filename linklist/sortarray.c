#include<stdio.h>
int main()
{
    printf("enter array\n");
    int n;
    scanf("%d",&n);
    int arr[n];
   
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }

   sort1(arr,n);
  //  sort2(arr);
   // sort3(arr);
   for(int i=0;i<n;i++)
    {
        print("%d",arr[i]);

    }
}

void sort1(int *arr ,int n)
{
    for(int i=0;i<(n/2);i++)
    {int temp=arr[i];
    arr[i]=arr[n-1-i];
    arr[n-1-i]=temp;


    }
    
}