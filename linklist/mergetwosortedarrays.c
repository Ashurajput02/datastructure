#include<stdio.h>
int main()
{
    printf("enter array\n");
    int n1;
    int n2;
    scanf("%d %d",&n1,&n2);
    int arr1[n1],arr2[n2];
   
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&arr1[i]);

    }fflush(stdin);
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&arr2[i]);

    }
merge(arr1,n1,arr2,n2);
}

    void merge(int *arr1, int n1, int *arr2, int n2)
    {
        int k=0;
        int b[n1+n2];
        int index1=0;
        int index2=0;
        while(index1<n1 && index2<n2)
        {
            if(arr1[index1]<arr2[index2])
            b[k++]=arr1[index1++];
            else if(arr1[index1]>arr2[index2])
            {
                b[k++]=arr2[index2++];

            }
        }
        if(index1<n1)
        {
            while(index1<n1)
            b[k++]=arr1[index1++];
        }
else if(index2<n2)
{
    while(index2<n2)
b[k++]=arr2[index2++];
}

for(int j=0;j<(n1+n2);j++)
printf("%d",b[j]);
        }
    