#include <stdio.h>

void Multiply(int *p);

int main()
{
    int a;
    scanf("%d",&a);
    Multiply(&a);
    printf("val a: %d",a);

return 0;
}

void Multiply(int *p)
{
    *p = *p * 2;
}