#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols, i, j;
    int **a;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    a = (int**) malloc(rows*sizeof(int*)); //Allocating memory for rows -- storing integer pointer
    for(i=0;i<rows;i++)
    {
        a[i] = (int*) malloc(cols*sizeof(int));
    }
    printf("Enter the elements: ");
    for(i = 0; i<rows; i++)
    {
        for(j=0;j<cols;j++)
        {
            scanf("%d",*(a+i)+j);
        }
    }
    for(i = 0; i<rows; i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%d ",*(*(a+i)+j));
            if((j+1)%cols == 0)
            {
                printf("\n");
            }
        }
    }
    free(a);
}