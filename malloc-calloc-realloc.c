#include <stdio.h>
#include <stdlib.h>

/*
    MALLOC      allocztes mem + doesn't touch values inside bytes
    CALLOC      allocates mem + sets all bytes to 0
    REALLOC     resize variable
    FREE        free up memory
*/



int main()
{
    int size = 5;
    int *ptr = (int*)malloc(size * sizeof(int));
    int *ptr2 = (int*)calloc(size,sizeof(int));
    ptr2 = realloc(ptr2,10 * sizeof(int));
    /*
    if (ptr == NULL)
        printf("\nMemory not allocated");
    else
        printf("\nMemory allocated succesfully");
    */

    for (int i=0;i< size;i++)
    {
        ptr[i] = i+2;
        ptr2[i] = i*2;
    }

    for (int j=0;j< size;j++)
    {
        printf("\nptr:  element %d: %d",j,ptr[j]);
    }

    for (int k=0;k<10;k++)
        printf("\nptr2: element %d: %d",k,ptr2[k]);

    free(ptr);
    free(ptr2);

    return 0;
}