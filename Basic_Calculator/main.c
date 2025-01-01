// Simple Calculator in C
// By: HM
// GitHub:   https://github.com/Hasan-Malek
// Linkedin: https://linkedin.com/in/hasan-malek-125036297

#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;

    while (1) {

        printf("\n===== Calculator =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("=============================\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Exiting...
        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        // Validating the Input
        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("Enter the first number: ");
        scanf("%f", &num1);

        printf("Enter the second number: ");
        scanf("%f", &num2);

        switch (choice) {
            case 1: // Addition
                result = num1 + num2;
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2: // Subtraction
                result = num1 - num2;
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3: // Multiplication
                result = num1 * num2;
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4: // Division
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
            default:
                printf("Something went wrong. Please try again.\n");
        }
    }

    return 0;
}
