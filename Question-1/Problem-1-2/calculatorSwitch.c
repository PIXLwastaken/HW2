#include <stdio.h>

int main() {
    float a;
    float b;
    char operation;

    //The format for expression input should be: [float a] [operation] [float b])

    printf("Enter an expression ([number a] [operation: +, -, /, *, %, or ^] [number b])\nor type 'exit' to quit:\n");


    /*The character "operation" can be one of the following:
    1. plus (+)
    2. minus (-)
    3. mult (*)
    4. div (/)
    5. mod (%) 
    6. exp (^)*/
    
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
        printf("\nEnter an expression ([number a] [operation: +, -, /, *, %, or ^] [number b])\nor type 'exit' to quit:\n");
    }

}