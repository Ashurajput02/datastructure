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
  quicksort(arr,0,n-1);
 fflush(stdin); 
    
    
     for(int i=0;i<n;i++)
    {
        printf("%d\t",*(arr+i));

    }
}

void quicksort(int *arr,int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
        
    }
}

int partition(int *arr,int lb,int ub)
{
    int pivot=arr[ub];
    int start=lb;
    int end=ub;
while(start<end)
{
    while(arr[start]<=pivot)
    start++;

    while(arr[end]>pivot)
    end--;

    if(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
    }
}
int temp2=arr[lb];
        arr[lb]=arr[end];
        arr[end]=temp2;

        return end;

}