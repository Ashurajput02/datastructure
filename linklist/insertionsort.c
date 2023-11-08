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
  insertionsort(arr,n);
  
    
    
     for(int i=0;i<n;i++)
    {
        printf("%d",*(arr+i));

    }
}

void insertionsort(int *arr,int n)
{
    for(int i=1;i<n-1;i++)
    {int temp=arr[i];
    int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
    arr[j+1]=arr[j];
    j--;
        }
    arr[j+1]=temp;
    }

}