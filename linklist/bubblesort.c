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
  bubblesort(arr,n);
  
    
    
     for(int i=0;i<n;i++)
    {
        printf("%d",*(arr+i));

    }
}

void bubblesort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {int flag=0;
        for(int j=0;j<(n-i-1);j++)
        { 
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
           
        }
         if(flag==0)
            break;
    }
  
}