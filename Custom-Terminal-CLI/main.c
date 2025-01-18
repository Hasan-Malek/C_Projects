/*
    Creating simple and basic Terminal in C
    by : HM
    GitHub: https://github.com/Hasan-Malek
    Linkedin: https://linkedin.com/in/hasan-malek-125036297
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define WELCOME "OhMyHM"
#define version 1.0
#define BUFFER 1020

// Cross-platform compatibility for sleep
#ifdef _WIN32
#include <windows.h>               // Windows-specific header
#define sleep(x) Sleep(1000 * (x)) // Sleep in milliseconds
#else
#include <unistd.h> // Linux/Unix-specific header
#endif

void help()
{
    printf("\nCommand:  \t\tUsage:  \n");
    printf("- help\t\t\tDisplay the Help Manu\n- ls\t\t\tList Directories\n- clear\t\t\tClear the Screen\n- cat <filename>\tDisplay file content\n- exit\t\t\tExit the OhMyHM\n");
}

// Creating LS command customly
void myls(char *path)
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    char buf[512];
    mydir = opendir(path);
    if (mydir == NULL)
    {
        perror("Unable to open directory");
        return;
    }
    while ((myfile = readdir(mydir)) != NULL)
    {
        sprintf(buf, "%s/%s", path, myfile->d_name);
        stat(buf, &mystat);
        printf("%zu", mystat.st_size);
        printf(" %s\n", myfile->d_name);
    }
    closedir(mydir);
}

// for `cat` command
void ReadAFile(const char *filename)
{
    char file[BUFFER];

    int isEmpty = 1;

    FILE *fptr = NULL;

    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        perror("\nError: ");
        return; // Returning instead of calling exit(1) to avoid abrupt termination
    }

    printf("\nContent of File: \n");

    printf("-----------------------------------------------\n");

    while (fgets(file, BUFFER, fptr) != NULL) // Reading a File
    {
        isEmpty = 0;
        printf("%s", file);
    }

    if (isEmpty)
    {
        printf("File is empty or could not be read.\n");
    }

    printf("-----------------------------------------------\n");

    fclose(fptr);
}

int main(int argc, char *argv[])
{
    char name[20];
    char *command = NULL;
    char *filename = NULL;

    // ANSI escape codes for colors
    const char *red = "\033[31m";
    const char *green = "\033[32m";
    const char *yellow = "\033[33m";
    const char *blue = "\033[34m";
    const char *cyan = "\033[36m";
    const char *reset = "\033[0m"; // Reset to default color

    printf("Welcome to ~ %s\n", WELCOME);

    printf("Enter your name: ");
    scanf(" %19[^\n]", name); // Take a name including spaces
    getchar();
    printf("\033[H\033[J"); // Clear the screen using ANSI escape code

    command = (char *)malloc(100 * sizeof(char));
    if (command == NULL)
    {
        perror("Memory allocation failed");
        return 1;
    }

    while (1)
    {
        printf("\n%s$@%s%s%s %s>%s ", green, cyan, name, reset, red, reset);
        if (fgets(command, 100, stdin) == NULL)
        {
            perror("Error reading input");
            free(command); // Free memory before exiting
            break;
        }

        command[strcspn(command, "\n")] = '\0'; // Remove the newline

        // Tokenize the input command
        char *cmd = strtok(command, " "); // Command like "cat"
        char *arg = strtok(NULL, " ");    // Argument like "file.txt"

        /*
            I'm adding simple and basic commands to showcase,
            You can create more as you want
        */
        if (strcmp(cmd, "help") == 0)
        {
            help();
        }

        else if (strcmp(cmd, "exit") == 0)
        {
            printf("GoodBye!\n");
            break;
        }

        else if (strcmp(cmd, "clear") == 0)
        {
            printf("\033[H\033[J"); // Clear the screen using ANSI escape code
        }

        else if (strcmp(cmd, "ls") == 0)
        {
            myls("."); // List current directory
        }

        else if (strcmp(cmd, "cat") == 0)
        {
            if (arg == NULL)
            {
                printf("Please provide a filename\n");
            }
            else
            {
                ReadAFile(arg);
            }
        }
        else
        {
            printf("Command '%s' not recognized.\n", cmd);
        }
    }

    free(command); // It's very important to free the memory...
    return 0;
}
