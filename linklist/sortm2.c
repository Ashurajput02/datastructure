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
   for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);

    }
}

void sort1(int *arr ,int n)
{int b[n];
for(int i=0;i<n;i++)
{
    b[i]=arr[n-1-i];
}
for(int i=0;i<n;i++)
{
    arr[i]=b[i];
}


   }

    
    
