#include <stdio.h>

int count = 0;

void hanoi(int n, char source, char destination, char temp)
{
    if(n==1)
    {
        printf("Move disk from %c to %c\n", source, destination);
        count++;
        return;
    }
    hanoi(n-1,source,temp,destination);
    printf("Move disk from %c to %c\n", source, destination);
    hanoi(n-1, temp, destination, source);
    count++;
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n,'S', 'D', 'T');
    printf("The total number of moves is %d\n", count);
    return 0; 
}