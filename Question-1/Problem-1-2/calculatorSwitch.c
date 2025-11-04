/*
Jay Marquez Febles
November 3, 2025
Problem Description:
    Write a C calculator program that:
    1. Accepts two numbers and an operator (+,-,*,/,%,^) 
    2. Uses a switch statement to perform the operation
    3. Handles division by 0
    4. Implements power operation (^) using loops
    5. Supports both integer and floating-point operations
    6. Includes a menu system that allows multiple calculations until the user chooses to exit
*/

#include <stdio.h>

int main() {
    
    //Declare three double variables for number a and number b, and ans which can handle both integer and decimal inputs
    double a, b, ans;
    /*The char "operation" can be one of the following:
    1. plus (+)
    2. minus (-)
    3. mult (*)
    4. div (/)
    5. mod (%) 
    6. exp (^)*/
    char operation, contCalc;

    do {
        //input validation for all as explained in gradeCalculator.c
        printf("Select an operation:\n[ + - * / %% ^ ]\n");
        /* Use a leading space to skip any leftover whitespace/newline */
        while(scanf(" %c", &operation) != 1){
            printf("Invalid input. Please select an operation:\n[ + - * / %% ^ ]\n");
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
        
        printf("Enter your first number:\n");
        while(scanf("%lf", &a) != 1){
            printf("Invalid input. Enter your first number:\n");
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }

        printf("Enter your second number:\n");
        while(scanf("%lf", &b) != 1){
            printf("Invalid Input. Enter your second number:\n");
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }

        /*
        Example 
            "Select an operation:\n[ + - * / %% ^ ]"
            Input  :  +
            "Enter your first number:"
            Input  :  5
            "Enter your second number:"
            Input  :  5
            Output :  10
        */

        switch (operation) {
            case '+':
                ans = a + b;
                printf("\n%.2lf %c %.2lf = %.2lf\n", a, operation, b, ans);
                break;

            case '-':
                ans = a - b;
                printf("\n%.2lf %c %.2lf = %.2lf\n", a, operation, b, ans);
                break;

            case '*':
                ans = a * b;
                printf("\n%.2lf %c %.2lf = %.2lf\n", a, operation, b, ans);
                break;

            case '/':
                if (b != 0) {
                    ans = a / b;
                    printf("\n%.2lf %c %.2lf = %.2lf\n", a, operation, b, ans);
                } else {
                    printf("Undefined: Division by 0\n");
                }
                break;

            case '%':
                if ((int)b != 0) {
                    ans = (int)a % (int)b;
                    printf("\n%.2lf %c %.2lf = %.2lf\n", a, operation, b, ans);
                } else {
                    printf("Undefined: Division by 0\n");
                }
                break;

            case '^': 
                ans = 1.0;
                //check for nagetive exponent
                if (b < 0){
                    b = -b; //if b is negative, make it positive and run normal exponentiation
                    for (int i = 0; i < b; i++){    
                        ans *= a;
                    }
                    //print the reciprocal of ans (1/ans), as thats what a negative exponent means
                    printf("\n%.2lf %c %.2lf = %.2lf\n", a, operation, b, (1 / ans));
                } else {
                    for (int i = 0; i < b; i++){    
                        ans *= a;
                    }
                    printf("\n%.2lf %c %.2lf = %.2lf\n", a, operation, b, ans);
                }
                break;
            
            default:
                printf("Invalid operation\nSelect an operation:\n[ + - * / %% ^ ]\n");
        }
        
    printf("Continue Calculator?\t(y/n)\n");
    /* leading space so input ignores leftover newline */
    scanf(" %c", &contCalc);

    } while (contCalc == 'y' || contCalc == 'Y');

    printf("Thank you for using the calculator!\n");
}