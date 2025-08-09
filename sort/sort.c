#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int n;
    printf("please enter the number of real numbers:");
    scanf("%d",&n);
    float arr[n];
    printf("please enter the numbers:");
    for(int i=0;i<n;i++)
    scanf("%f",arr+i);
    qsort(arr,n,sizeof(float),cmp);
    printf("the sorted array(ascending):");
    for(int i=0;i<n;i++)
    printf("%f ",arr[i]);
    return 0;
}