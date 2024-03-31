#include <stdio.h>
#include <string.h>
#define MAXADDR 100

struct employee
{
    int empid;
    int age;
    char name[20];
}ht[MAXADDR];

int hash(int key)
{
    int index;
    index = key%MAXADDR;
    return index;
}

int main()
{
    int choice, key, i, count, index, age;
    count = 0;
    char name[20];

    for(i=0; i<MAXADDR; i++)
    {
        ht[i].empid = -1;
    }
    for(;;)
    {
        printf("1.Insert_Record    2.Search_Record    3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: if(count == MAXADDR)
                    {
                        printf("No space available.\n");
                    }
                    else
                    {
                        printf("Enter the empid: ");
                        scanf("%d", &key);
                        printf("Enter your name: ");
                        scanf("%s", name);
                        printf("Enter your age: ");
                        scanf("%d", &age);

                        index = hash(key);

                        if(ht[index].empid == -1)
                        {
                            ht[index].empid = key;
                            strcpy(ht[index].name, name);
                            ht[index].age = age;
                            count += 1;
                            break;
                        }
                        else
                        {
                            for(i=1;i<MAXADDR;i++)
                            {
                                index = (hash(key)+i)%MAXADDR;
                                if(ht[index].empid == -1)
                                {
                                    ht[index].empid = key;
                                    strcpy(ht[index].name, name);
                                    ht[index].age = age;
                                    count += 1;
                                    break; 
                                }
                            }
                        }
                    }
                    break;
                case 2: printf("Enter the digit for search: ");
                        scanf("%d", &key);
                        index = hash(key);
                        if(ht[index].empid == key)
                        {
                            printf("Succesful search.\n");
                            printf("Name: %s\n",ht[index].name);
                            printf("Age: %d\n",ht[index].age);
                            printf("Empid: %d\n",ht[index].empid);
                        }
                        else if(ht[index].empid == -1)
                        {
                            printf("Unsuccesful search.\n");
                            printf("Key not found.\n");
                            break;
                        }
                        else
                        {
                            for(i=1;i<MAXADDR;i++)
                            {
                                index = (hash(key)+i)%MAXADDR;
                                if(ht[index].empid==-1)
                                {
                                    printf("Unsuccesful search.\n");
                                    printf("Key not found.\n");
                                    break;
                                }
                                else if(ht[index].empid==key)
                                {
                                    printf("Succesful search.\n");
                                    printf("Name: %s\n",ht[index].name);
                                    printf("Age: %d\n",ht[index].age);
                                    printf("Empid: %d\n",ht[index].empid);
                                    break;
                                }
                            }
                        }
                        break;
                default: return 0;;
        }
    }
}