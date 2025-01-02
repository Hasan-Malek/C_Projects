/*
    Creating simple and basic ATM Machine in C
    by : HM
    GitHub: https://github.com/Hasan-Malek
    Linkedin: https://linkedin.com/in/hasan-malek-125036297
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* Here I'm also demonstrating you the work of preprocessor directives & macros in C */

// Cross-platform compatibility for sleep
#ifdef _WIN32
#include <windows.h>               // Windows-specific header
#define sleep(x) Sleep(1000 * (x)) // Sleep in milliseconds
#else
#include <unistd.h> // Linux/Unix-specific header
#endif

#define MAX_PIN_LENGTH 4 // Length of ATM PIN in our code

// Function for Printing Statement
void printBox(const char *name, double balance, int history)
{
    time_t now;
    time(&now);
    char *dateTime = ctime(&now);

    // Remove the newline character from dateTime
    dateTime[strcspn(dateTime, "\n")] = '\0';

    printf("\n");
    printf("*********************************\n");
    printf("*                               *\n");
    printf("*     Mini Statement of Your    *\n");
    printf("*           Account             *\n");
    printf("*                               *\n");
    printf("*********************************\n");

    printf(" ---------------------------------------\n");
    printf("| User's Name: %-17s \t|\n", name);
    printf("| Account Balance: %-10.2f \t\t|\n", balance);
    printf("| Accessed On: %-10s |\n", dateTime);
    printf("|---------------------------------------|\n");
    printf("| Withdraw History:             \t|\n");
    printf("| %d \t\t\t\t\t|\n", history);
    printf("|---------------------------------------|\n");
}

// "Every great journey starts with int main()."
int main()
{
    printf("\n\t\t\t\t\t========= Welcome to ATM Machine ========= \n");

    const char name[30];
    const char acc_type;

    printf("Enter your name: ");
    scanf(" %[^\n]", name); // Take a name including spaces
    getchar();              // Consume the \n(a new line) From buffer

    printf("Welcome %s!\n", name);

    while (1) // Run until a exit found!
    {
        printf("\nSelect Your Account Type: \n");
        printf("D/d For Domenstic, I/i For International (enter e to exit): ");
        scanf("%c", &acc_type);
        getchar();

        int acc_balance = 0, withdraw = 0; // Initializing with 0 by default
        int default_pin = 1001;            // The Default PIN is : 1001
        int new_pin, confirm_pin;
        int atm_pin, choice;
        int attempts = 0; // Counting the pin entered attempts;
        int deposit;
        char pin_input[10]; // Temp Buffer to verify user entering only 4 digits while changing the PIN
        bool is_with = false;

        if (acc_type == 'D' || acc_type == 'd')
        {
            // Working with Domenstic Account Logic...
            printf("Account type = Domenstic\n");

        // User will redirect again to authentication, If he changes the PIN
        start: // Using goto statement     (Generally it's not recommended to use this)

            while (attempts < 3) // Give 3 Attempts to enter a correct PIN
            {
                printf("\nCheck Code's Comments for Default PIN\n");
                printf("Enter your PIN: ");
                scanf("%d", &atm_pin);
                getchar();

                if (atm_pin == default_pin)
                {
                    while (1) // Give options to user.. until EXIT
                    {
                        printf("\nATM Machine Options:\n");
                        printf("1. Check Your Balance\n");
                        printf("2. Deposit Money\n");
                        printf("3. Withdraw Money\n");
                        printf("4. Change PIN\n");
                        printf("5. View Mini Statement\n");
                        printf("6. Exit\n");
                        printf("Select an option (1-6): ");
                        scanf("%d", &choice);

                        printf("Choice = %d\n", choice);

                        switch (choice)
                        {
                        case 1:
                            printf("\nChecking current account balance...\n");
                            sleep(1);
                            printf("Your Current Balance: %d\n", acc_balance);
                            sleep(1);
                            break;

                        case 2:
                            printf("\nDeposit Money in Your Account...\n");
                            sleep(1);
                            printf("Enter the Amout: ");
                            if (scanf("%d", &deposit) != 1 || deposit < 100) // Check condition
                            {
                                printf("Invalid input. You can't deposit an amount less than 100.\n");
                            }
                            else
                            {
                                acc_balance += deposit; // Add the deposit to the account balance
                                sleep(1);
                                printf("\nYour account balance is now: %d\n", acc_balance);
                                sleep(1);
                            }

                            break;

                        case 3:
                            if (acc_balance > 0)
                            {
                                printf("\nWithdraw Money from Your Account...\n");
                                sleep(1);
                                printf("Your Current Account Balance: %d\n", acc_balance);
                                sleep(1);
                                printf("Enter the amount to withdraw: ");
                                scanf("%d", &withdraw);

                                if (withdraw > acc_balance)
                                {
                                    printf("\nInsufficient Balance, Try Again.\n");
                                    continue;
                                }

                                else
                                {
                                    printf("Take the amount - %d\n", withdraw);
                                    printf("Remaining amount in your balance...\n");
                                    sleep(1);
                                    acc_balance -= withdraw;
                                    printf("Your Current Balance is now: %d\n", acc_balance);

                                    sleep(1);
                                }
                            }

                            else
                            {
                                printf("\nSorry, You can't withdraw money...\n");
                                printf("Your Current Account Balance: %d\n", acc_balance);
                                is_with = true;
                                is_with = withdraw;
                                sleep(1);
                                continue;
                            }

                            break;

                        case 4:
                            printf("\nChange your PIN\n");
                            sleep(1);
                            printf("Enter your current PIN: ");
                            scanf("%d", &atm_pin);

                            if (atm_pin == default_pin)
                            {
                                printf("Enter a new 4-digit PIN: ");

                                // Loop until valid input is received
                                while (1)
                                {
                                    scanf("%s", pin_input);

                                    // Check if input length is 4
                                    if (strlen(pin_input) != MAX_PIN_LENGTH)
                                    {
                                        printf("Error: PIN must be exactly 4 digits. Try again: ");
                                        continue;
                                    }

                                    // Check if all characters are digits
                                    int is_valid = 1;
                                    for (int i = 0; i < MAX_PIN_LENGTH; i++)
                                    {
                                        if (!isdigit(pin_input[i]))
                                        {
                                            is_valid = 0;
                                            break;
                                        }
                                    }

                                    if (!is_valid)
                                    {
                                        printf("Error: PIN must contain only digits. Try again: ");
                                        continue;
                                    }

                                    // Convert valid string to integer
                                    int new_pin = atoi(pin_input);
                                    printf("Your new PIN is: %d\n", new_pin);
                                    sleep(1);
                                    printf("\nYou have to do verification once again...\n");
                                    sleep(1);
                                    default_pin = new_pin;
                                    goto start;
                                    break;
                                }
                            }
                            else
                            {
                                printf("Incorrect current PIN!\n");
                            }

                            break;

                        case 5:
                            printf("\nMini Statement of Your Account\n");
                            printBox(name, acc_balance, withdraw);
                            break;

                        case 6:
                            printf("\nExiting Program...\n");
                            sleep(1); // Delay 1 Second
                            printf("Goodbye!\n");
                            exit(0);
                            break;

                        default:
                            printf("\nInvalid Option. Try Again\n");
                        }
                    }

                    break;
                }
                else
                {
                    printf("Wrong PIN. Please try again\n");
                    attempts++; // Increasing Attempts after wrong entered PIN
                }

                if (attempts == 3) // Exit after 3 wrong attempts.
                {
                    printf("Too many wrong attempts. Exiting...\n");
                    exit(0);
                }
            }

            break;
        }

        else if (acc_type == 'I' || acc_type == 'i')
        {
            printf("\nAccount type = International\n");

            /* You can create this functionality with same logic
            as Domenstic.
            I'm leaving this blank for you.
            */

            printf("User will create this functionality\n");
            continue;
        }

        else if (acc_type == 'e' || acc_type == 'E')
        {
            printf("\nExiting Program. Good Bye!\n");
            exit(0); // A function to terminate the program with no errors. Available In : <stdlib.h>
        }

        else
        {
            printf("\nError: Invalid Choice, Try again.\n\n");
            // Will continue the loop
        }
    }

    return 0;
}
