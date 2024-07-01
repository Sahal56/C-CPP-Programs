/**************************************************** HEADER FILES *****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n_records;
int counter = 0;

typedef struct
{
    int sr;
    char name[50];
    long landline, mobile;
} contact;

/******************************************** FUNCTION DECLARATIONS *****************************************************/

void clearMemoryData(contact *);
void displayContacts(contact *);
void updateContact(contact *);
void addContact(contact *);

/********************************************** DRIVER PROGRAM ***************************************************/

int main(void)
{
    printf("SIZE of Record Book : ");
    scanf("%ld", &n_records);

    contact *List = calloc(n_records, sizeof(*List));

    if (List == NULL)
        exit(1);

    while (1)
    {
        int option;
        printf("1  ADD");
        printf("2  UPDATE");
        printf("3  DELETE");
        printf("4  DISPLAY");
        printf("-1 EXIT");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            addContact(List);
            break;

        case 2:
            updateContact(List);
            break;

        case 3:

            break;

        case 4:
            displayContacts(List);
            break;

        case -1:
            clearMemoryData(List);
            exit(0);
            break;

        default:
            printf("\nWRONG CHOICE\n");
            break;
        }
    }

    clearMemoryData(List);

    return 0;
}

/******************************************** FUNCTION DEFINITIONS *****************************************************/

void clearMemoryData(contact *List)
{
    if (List != NULL)
        free(List);
}

void displayContacts(contact *List)
{
    printf("\n-------- PHONE BOOK --------\n");
    for (int i = 0; i < n_records; i++)
    {
        printf(" Name: %s\nLandline: %ld\nMobile: %ld\n", List[i].name, List[i].landline, List[i].mobile);
    }
    printf("\n--------------------------\n");
}

void addContact(contact *List)
{
    printf("\n Enter name, landline number, phone number:(with spaces in between)\n");
    scanf("%s %ld %ld", List[counter].name, List[counter].landline, List[counter].mobile);

    counter = counter + 1;
}

void updateContact(contact *List)
{
    char query[50];
    printf("Enter name to modify details: ");
    scanf("%s", query);

    int flag = 1;

    for (int i = 0; i < n_records; i++)
    {
        if (strcmp(List[i].name, query) == 0)
        {
            printf("\n----RECORD FOUND----\n");
            printf("Enter new landline number and phone number : (with spaces in between)\n");
            scanf("%ld %ld", &List[i].landline, &List[i].mobile);

            flag = 0;
            break;
        }
    }

    if (flag)
        printf("\n----RECORD NOT FOUND----\n");
}

/************************************************* END ***********************************************************/