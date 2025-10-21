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
    
    //Declare two float variables for number a and number b, since float can handle both int and float operations
    float a;
    float b;
    /*The char "operation" can be one of the following:
    1. plus (+)
    2. minus (-)
    3. mult (*)
    4. div (/)
    5. mod (%) 
    6. exp (^)*/
    char operation;

    //The format for expression input should be: [number a] [operation] [number b])
    printf("Enter an expression ([number a] [operation: + - / * %% ^] [number b])\nor type anything to quit:\n");

    while (scanf("%f %c %f", &a, &operation, &b) == 3) {
        
        switch (operation) {
        
            case '+':
                printf("Result: %.2f\n", a + b);
                break;
            
            case '-':
                printf("Result: %.2f\n", a - b);
                break;
            
            case '*':
                printf("Result: %.2f\n", a * b);
                break;

            case '/':
                if (b != 0) {
                    printf("Result: %.2f\n", a / b);
                } else {
                    printf("Error: Division by zero.\n");
                }
                break;

            case '%':
                if ((int)b != 0) {
                    printf("Result: %d\n", (int)a % (int)b);
                } else {
                    printf("Error: Division by zero.\n");
                }
                break;
            
            case '^': {
                float result = 1.0;
                for (int i = 0; i < (int)b; i++) {
                    result *= a;
                }
                printf("Result: %.2f\n", result);
                break;
            }
            
            default:
                printf("Error: Unknown operation '%c'.\n", operation);
        }
        printf("\nEnter an expression ([number a] [operation:  + - / * %% ^] [number b])\nor type anything to quit:\n");
    }

}