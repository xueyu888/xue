/*************************************************************************
	> File Name: binary_add.c
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Sep 2015 09:08:53 AM CST
 ************************************************************************/

#include <stdio.h>

#define GET_ARRAY_LEN(arr, len)     {len = (sizeof(arr) / sizeof(arr[0]));}

int c[11];
int a[10] = {1, 0, 1, 1, 1, 1, 0, 1, 1, 0};
int b[10] = { 0, 0, 1, 1, 1, 0, 0, 0, 0, 1};

void *binary_add(int *arr1, int *arr2, int len)
{
    int *a = arr1;
    int *b = arr2;
    int i;

    c[len] = a[len - 1] + b[len - 1];
    for (i = len - 1; i > 0; i--)
    {

        if ( c[i + 1] == 2)
        {
            c[i + 1] = 0;
            c[i] = a[i - 1] + b[i - 1] + 1;
        }
        else if (c[i + 1] == 3)
        {
            c[i + 1] = 1;
            c[i] = a[i - 1] + b[i - 1] + 1;
        }
        else
        {
            c[i] = a[i - 1] + b[i - 1];
        }
    }
    
    if (c[1] == 2)
    {
        c[1] = 0;
        c[0] = 1;
    }
    else if (c[1] == 3)
    {
        c[1] = 1;
        c[0] = 1;
    }
    else
    {
        c[1] = a[0] + b[0];
        c[0] = 0;
    }
}
                       
void print_array_c(int len)
{
    int i;

    if (c[0] == 1)
        for (i = 0; i <= len; i++)
            printf("%d", c[i]);
        
    
    if (c[0] == 0)
        for (i = 1; i <=len; i++)
            printf("%d", c[i]);
        
    printf("\n");
}   

void main()
{
    int len;
    
    GET_ARRAY_LEN(a, len);
    binary_add(a, b, len);
    print_array_c(len);
}
