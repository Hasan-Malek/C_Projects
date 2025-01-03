/*
    Creating simple Text Editor in C
    by : HM
    GitHub: https://github.com/Hasan-Malek
    Linkedin: https://linkedin.com/in/hasan-malek-125036297
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER 1024 // Defining Buffer Size

void ReadAFile(const char *filename)
{
    char file[BUFFER];

    int isEmpty = 1;

    FILE *fptr = NULL;

    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        perror("\nError: ");
        exit(1);
    }

    printf("\nContent of File: \n");

    printf("-----------------------------------------------\n");

    while (fgets(file, BUFFER, fptr) != NULL)   // Reading a File
    {
        isEmpty = 0;
        printf("%s", file);
    }

    printf("-----------------------------------------------\n");

    fclose(fptr);
}

void WriteFile(const char *filename)
{
    char file[BUFFER];

    FILE *fptr = NULL;

    fptr = fopen(filename, "w");

    if (fptr == NULL)
    {
        perror("\nError: ");
        exit(1);
    }

    printf("Write to File (type EXIT to finish): \n");

    while (1)
    {
        printf("> ");
        fgets(file, BUFFER, stdin);     // Writing into File

        if (strncmp(file, "EXIT", 4) == 0)     // EXIT Condition
        {
            break;
        }

        if (fputs(file, fptr) == EOF)     // Optional
        {
            perror("\nError: ");
            break;
        }
    }

    fclose(fptr);
    printf("\nFile Written Successfully.\n");
}


/*
You can create the append function for appending text to file
Without losing the existing data
*/
void AppendToFile(const char *filename)
{

    printf("User Will Create the Function.\n");

}

int main()
{
    char filename[50];
    int choice;

    printf("\t\t\t\t *** Simple Text Editor *** \n");

    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);

    filename[strcspn(filename, "\n")] = '\0';   // Remove New Line from filename and replace it with null character 

    printf("File = %s\n", filename);

    while (1)
    {
        printf("\n1. For Read\n2. For Write\n3. To Append\n4. To Exit : ");
        scanf("%d", &choice);

        getchar();

        switch (choice)
        {
        case 1:
            ReadAFile(filename);
            break;
        
        case 2:
            WriteFile(filename);
            break;

        case 3:
            AppendToFile(filename);
            break;

        case 4:
            printf("\nExiting...\nGood Bye!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid Choice. Try Again.\n");
        }
    }

    return 0;
}
