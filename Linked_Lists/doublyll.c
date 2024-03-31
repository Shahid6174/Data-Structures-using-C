#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char ssn[20];
    char name[30];
    char dept[20];
    char desg[20];
    int salary;
    char phno[20];
    struct node* llink;
    struct node* rlink;
};
typedef struct node* NODE;

NODE insert_front(char ssn[20], char name[30], char dept[20], char desg[20], int salary, char phno[20], NODE first)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    strcpy(temp->ssn,ssn);
    strcpy(temp->name,name);
    strcpy(temp->dept,dept);
    strcpy(temp->desg, desg);
    temp->salary = salary;
    strcpy(temp->phno, phno);
    temp->rlink = NULL;
    temp->llink = NULL;
    if (first != NULL)
        first->llink = temp;
    temp->rlink = first;
    return temp;
}

NODE insert_rear(char ssn[20], char name[30], char dept[20], char desg[20], int salary, char phno[20], NODE first)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    strcpy(temp->ssn,ssn);
    strcpy(temp->name,name);
    strcpy(temp->dept,dept);
    strcpy(temp->desg, desg);
    temp->salary = salary;
    strcpy(temp->phno, phno);
    temp->rlink = NULL;
    temp->llink = NULL;
    if(first == NULL)
        return temp;
    cur = first;
    while(cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

NODE delete_front(NODE first)
{
    NODE cur;
    if(first == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    if(first->rlink == NULL)
    {
        printf("Employee with following details is deleted: \n");
        printf("SSN: %s\n", first->ssn);
        printf("Name: %s\n", first->name);
        printf("Dept: %s\n", first->dept);
        printf("Desg: %s\n", first->desg);
        printf("Salary: %d\n", first->salary);
        printf("Phno: %s\n", first->phno);
        free(first);
        return NULL;
    }
    cur = first;
    first = first->rlink;
    printf("Employee with following details is deleted: \n");
    printf("SSN: %s\n", cur->ssn);
    printf("Name: %s\n", cur->name);
    printf("Dept: %s\n", cur->dept);
    printf("Desg: %s\n", cur->desg);
    printf("Salary: %d\n", cur->salary);
    printf("Phno: %s\n", cur->phno);
    free(cur);
    first->llink = NULL;
    return first;
}

NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if(first==NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    if(first->rlink == NULL)
    {
            printf("Employee with following details is deleted: \n");
            printf("SSN: %s\n", first->ssn);
            printf("Name: %s\n", first->name);
            printf("Dept: %s\n", first->dept);
            printf("Desg: %s\n", first->desg);
            printf("Salary: %d\n", first->salary);
            printf("Phno: %s\n", first->phno);
            free(first);
            return NULL;
    }
    cur = first;
    while(cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    prev = cur->llink;
    printf("Employee with following details is deleted: \n");
    printf("SSN: %s\n", cur->ssn);
    printf("Name: %s\n", cur->name);
    printf("Dept: %s\n", cur->dept);
    printf("Desg: %s\n", cur->desg);
    printf("Salary: %d\n", cur->salary);
    printf("Phno: %s\n", cur->phno);
    free(cur);
    prev->rlink=NULL;
    return first;
}

void display(NODE first)
{
    NODE cur;
    if(first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    cur = first;
    printf("The contents of the list are: \n");
    while(cur != NULL)
    {
        
            printf("SSN: %s\n", cur->ssn);
            printf("Name: %s\n", cur->name);
            printf("Dept: %s\n", cur->dept);
            printf("Desg: %s\n", cur->desg);
            printf("Salary: %d\n", cur->salary);
            printf("Phno: %s\n", cur->phno);
            printf("\n");
            cur  = cur->rlink;
    }
}

int main()
{
    char ssn[20];
    char name[30];
    char dept[20];
    char desg[20];
    int salary;
    char phno[20];
    int choice;
    NODE first = NULL;

    for(;;)
    {
        printf("Enter 1.Insert_front 2.Insert_rear 3.Delete_front 4.Delete_rear 5.Display: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: printf("Enter the ssn: ");
                    scanf("%s", ssn);
                    printf("Enter the name: ");
                    scanf("%s", name);
                    printf("Enter the dept: ");
                    scanf("%s",dept);
                    printf("Enter the designation: ");
                    scanf("%s",desg);
                    printf("Enter the salary: ");
                    scanf("%d",&salary);
                    printf("Enter the phno: ");
                    scanf("%s",phno);
                    first = insert_front(ssn,name,dept,desg,salary,phno,first);
                    break;
            case 2: printf("Enter the ssn: ");
                    scanf("%s", ssn);
                    printf("Enter the name: ");
                    scanf("%s", name);
                    printf("Enter the dept: ");
                    scanf("%s",dept);
                    printf("Enter the designation: ");
                    scanf("%s",desg);
                    printf("Enter the salary: ");
                    scanf("%d",&salary);
                    printf("Enter the phno: ");
                    scanf("%s",phno);
                    first = insert_rear(ssn,name,dept,desg,salary,phno,first);;
                    break;
            case 3: first = delete_front(first);
                    break;
            case 4: first = delete_rear(first);
                    break;
            case 5: display(first);
                    break;
            default: return 0;
        }
    }
}
