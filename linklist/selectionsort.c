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
  selectionsort(arr,n);
  
    
    
     for(int i=0;i<n;i++)
    {
        printf("%d\t",*(arr+i));

    }
}

void selectionsort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {int min=i;
        for(int j=i+1;j<(n);j++)
        { 
            if(arr[j]<arr[min])
            {
                min=j; }
           
        }
         if(min!=i){
          int temp=arr[i];
          arr[i]=arr[min];
          arr[min]=temp;
         }
     }
  
}