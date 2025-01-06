/*
    Creating Library Management System in C
    by : HM
    GitHub: https://github.com/Hasan-Malek
    Linkedin: https://linkedin.com/in/hasan-malek-125036297
*/

/*
    You can store the books data in file using FILE I/O
    in C.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOK 100
#define MAX_SIZE 100

typedef struct
{
    char book_name[MAX_SIZE];
    char author_name[MAX_SIZE];
} Books;

Books books[MAX_BOOK];
int book_count = 0;

void AddBook()
{
    if (book_count >= MAX_BOOK)
    {
        printf("Book list is full! Cannot add more books.\n");
    }

    printf("\nEnter the Book's Name: ");
    if (fgets(books[book_count].book_name, sizeof(books[book_count].book_name), stdin))
    {
        size_t len = strlen(books[book_count].book_name);
        if (len > 0 && books[book_count].book_name[len - 1] == '\n')
        {
            books[book_count].book_name[len - 1] = '\0'; // Removing the trailling new line
        }
    }

    printf("\nEnter the Author's Name: ");
    if (fgets(books[book_count].author_name, sizeof(books[book_count].author_name), stdin))
    {
        size_t len = strlen(books[book_count].author_name);
        if (len > 0 && books[book_count].author_name[len - 1] == '\n')
        {
            books[book_count].author_name[len - 1] = '\0'; // Removing the trailling new line
        }
    }

    printf("\nBook Added in Library!\n");
    printf("- Book's Name: '%s'\n- Author's Name: '%s'\n\n", books[book_count].book_name, books[book_count].author_name);
    book_count++;
}

void ShowBooks()
{
    if (book_count == 0)
    {
        printf("\nNo Books Available in Library!\n");
    }

    else
    {

        printf("\n------------------------------------------------------\n");

        printf("\n\t\tAvailbale Books :- \n\n");

        for (int i = 0; i < book_count; i++)
        {
            printf("Book %d: '%s'\nAuthor : '%s'\n\n", i + 1, books[i].book_name, books[i].author_name);
        }

        printf("------------------------------------------------------\n");
    }
}

void RemoveBook()
{
    if (book_count == 0)
    {
        printf("\nNo Books to Remove!\n");
        return;
    }

    ShowBooks();

    int index;
    printf("\nEnter the Book Number to Remove: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > book_count)
    {
        printf("\nInvalid Book Number. Try Again.\n");
        return;
    }

    // Adjust index to match array (0-based indexing)
    index--;

    // Shift books down to overwrite the removed book
    for (int i = index; i < book_count - 1; i++)
    {
        books[i] = books[i + 1];
    }

    book_count--;
    printf("\nBook Removed Successfully!\n");
}

int main()
{
    char name[50];
    int choice;

    printf("\t\t\t\t\t [- Library Management System -]\n");

    printf("Enter your name: ");
    scanf(" %49[^\n]", name); // Read up to 49 characters (+1 for the null terminator)

    printf("Welcome %s to the library!\n\n", name);

    while (1)
    {
        printf("\n1. Add a Book\n2. Show Available Books\n3. Remove a Book\n4. To Exit: ");
        scanf("%d", &choice);
        getchar(); // Get Newline (when we press ENTER) from buffer

        switch (choice)
        {
        case 1:
            AddBook();
            break;

        case 2:
            ShowBooks();
            break;

        case 3:
            RemoveBook();
            break;

        case 4:
            printf("\nExiting...\nGoodBye!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid Choice. Try Again\n\n");
        }
    }

    return 0;
}
