#include<stdio.h>

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5};
    int* ptr1 = (int*)(&arr + 0x1);
    int* ptr2 = (int*)((int)arr + 0x1);
    printf("%x,%x", ptr1[-1], *ptr2);
    return 0;
}