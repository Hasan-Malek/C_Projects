/*
    Rock-Paper-Scissor Game in C
    by : HM
    GitHub: https://github.com/Hasan-Malek
    Linkedin: https://linkedin.com/in/hasan-malek-125036297
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to Return the Rock-Paper-Scissor According to Number
int PrintScene(int choice)
{

    switch (choice)
    {
    case 1:
        printf("Rock (%d)\n", choice);
        break;

    case 2:
        printf("Paper (%d)\n", choice);
        break;

    case 3:
        printf("Scissor (%d)\n", choice);
        break;
    }
}

int main()
{
    char name[30];

    int user_input, compo_input;
    int user_score = 0, compo_score = 0;

    printf("Welcome to Rock-Paper-Scissor\n");
    printf("Enter your name : ");
    fgets(name, sizeof(name), stdin);   // Take a Input from user for String

    printf("Welcome to the game, %s\n", name);

    // Playing 3 Rounds
    for (int round = 1; round <= 3; round++)
    {
        printf("Your Score : %d, Compo Score : %d\n\n", user_score, compo_score);
        printf("Round %d -\n", round);
        printf("Enter 1 for Rock\nEnter 2 for Paper\nEnter 3 for Scissor\n(0 to Exit) :");
        scanf("%d", &user_input);
        printf("\n");

        if (user_input < 1)
        {
            printf("Exiting...\nGood Bye!\n");
            return 0;
        }

        else if (user_input > 3)
        {
            printf("Invalid Choice\nTry Again.\n");
            return 1;
        }

        else
        {
            printf("You Choose : ");
            PrintScene(user_input);

            srand(time(0));  // The functional will generate random value using current time

            compo_input = rand() % 3 + 1;   // Generates a random integer between 1 and 3 (inclusive)

            printf("Compo Choose : ");
            PrintScene(compo_input);
            printf("\n");

            if (user_input == compo_input)
            {
                printf("It's a Draw!\n");
            }
            else if (user_input == 1 && compo_input == 3 ||
                     user_input == 2 && compo_input == 1 ||
                     user_input == 3 && compo_input == 2)
            {
                printf("You Win this Round!\n");
                user_score++;
            }

            else
            {
                printf("Compo Win this Round!\n");
                compo_score++;
            }
        }

    }

    // Scoring Conditions

    if (user_score > compo_score)
    {
        printf("Congratulation, You won the Game!\n");
    }

    else if (compo_score > user_score)
    {
        printf("Compo Win, Better Luck!\n");
    }

    else
    {
        printf("The game is Draw!\n");
    }

    return 0;
}
