#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *a;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    a = (int*) malloc(n*sizeof(int));
    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d", a+i);
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
    free(a);
}