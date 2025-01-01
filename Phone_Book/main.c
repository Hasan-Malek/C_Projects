/*
    Create a Phone Book in C
    by : HM
    GitHub: https://github.com/Hasan-Malek
    Linkedin: https://linkedin.com/in/hasan-malek-125036297
*/

/*
    This program will hold data temporary,
    You can create a Phone Book Which stores the data Permenantly using
    FILE I/O
*/

/* You can Update this code*/

#include <stdio.h>
#include <stdlib.h>

// Will Save Details with Structures
typedef struct 
{
    char name[100];
    char number[20];
}Contacts;

int main()
{
    int ask;

    printf("How many contacts do you want to save? (e.g., 1, 2) : ");
    if (scanf("%d", &ask) != 1 || ask <= 0)
    {
        printf("Input Invalid. Try Again.\n");
        return 1;
    }
    
    // Allocating memory for an array of structures.
    Contacts *contacts = malloc(ask * sizeof(Contacts));

    // If error in giving a memory
    if (!contacts)
    {
        printf("Unable to Give Memory!\n");
        return 1;   // Will Exit the Program
    }
    
    for (int i = 0; i < ask; i++)
    {
        while (getchar() != '\n');

        printf("\nEnter the name of contact %d : ", i+1);
        scanf(" %[^\n]", contacts[i].name); // Take Input Including Spaces

        printf("Enter the Contact Number : ");
        scanf(" %[^\n]", contacts[i].number); // Take a Number as String
    }

    // Display the Saved Contacts on Screen
    printf("\nSaved Contacts :");
    for (int j = 0; j < ask; j++)
    {
        printf("\n----------------\n");
        printf("Contact %d Name : %s\n", j+1, contacts[j].name);
        printf("Contact %d Number : %s", j+1, contacts[j].number);
        printf("\n----------------\n");
    }
    
    free(contacts);  // Do not forget to FREE the Memory

    return 0;
}
