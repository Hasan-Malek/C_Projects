/*
    Simple Guessing a Number Game in C.
    by : HM
    GitHub: https://github.com/Hasan-Malek
    Linkedin: https://linkedin.com/in/hasan-malek-125036297

    Description:
    A random number is generated between 0 and 100. 
    The user guesses the number with feedback on each attempt.
    The program tracks the number of attempts and displays the result.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int number, comp_number;
    int attempts = 0;
    char play_again;

    do {
        srand(time(0)); // Required
        comp_number = rand() % 101; // Random number between 0-100

        printf("\n\t\t\t\t |\\_$ Guess the Number! $_/| \n");
        printf("\nYou have to guess a number between 0-100.\n");
        printf("The computer has chosen a number!\n");

        do {
            printf("Enter your number: ");
            
            if (scanf("%d", &number) != 1) {
                printf("Invalid input. Please enter a valid number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue;
            }

            if (number < 0 || number > 100) {
                printf("Please enter a number between 0 and 100.\n");
                continue;
            }

            attempts++;

            if (number < comp_number) {
                printf("The number is too low. Try again.\n");
            } else if (number > comp_number) {
                printf("The number is too high. Try again.\n");
            } else {
                printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            }

        } while (number != comp_number);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    printf("\nThanks for playing! Goodbye!\n");
    return 0;
}
