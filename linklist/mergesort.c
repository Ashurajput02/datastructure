#include<stdio.h>
#include<stdlib.h>
int main()
{
   printf("enter array size and then the array\n");
    int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    
    mergesort(arr,0,n-1);
     for(int i=0;i<n;i++)
    printf("%d",(arr[i]));
   
}

void mergesort(int *arr,int lb, int ub)
{
    int mid=lb+(ub-lb)/2;
    if(lb>=ub)
    return;
    
    mergesort(arr,lb,mid);//for left part
    mergesort(arr,mid+1,ub);//for right part
merge(arr,lb,ub);//for merging the two parts together
}

void merge(int *arr,int lb,int ub)
{
    int mid=lb+((ub-lb)/2);
    int n1=mid-lb+1;
    int n2=ub-mid;
 int *arr1 = (int *)malloc(n1 * sizeof(int));
int *arr2 = (int *)malloc(n2 * sizeof(int));

int p1=lb;
for(int i=0;i<n1;i++)
arr1[i]=arr[p1++];

int p2=mid+1;
for(int i=0;i<n2;i++)
arr2[i]=arr[p2++];

int index1=0;
int index2=0;
int k=lb;


while(index1<n1 && index2<n2)
        {
            if(arr1[index1]<arr2[index2])
            arr[k++]=arr1[index1++];
            else if(arr1[index1]>arr2[index2])
            {
                arr[k++]=arr2[index2++];

            }
        }
        if(index1<n1)
        {
            while(index1<n1)
            arr[k++]=arr1[index1++];
        }
else if(index2<n2)
{
    while(index2<n2)
arr[k++]=arr2[index2++];
}
}