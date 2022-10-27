#include <stdio.h>

void Addition(int *p)
{
    (*p)++;
    //1*(p++);
}

int main ()
{
    int a = 3;
    Addition(&a);
    printf("\n\n %d \n\n",a);
    return 0;
}