/*
Jay Marquez Febles
November 3, 2025
Problem Description:
    Write a C program that takes a numerical score (0-100) as input
    and outputs the corresponding letter grade. Additionally, it should:
    1. Validate input (must be an integer between 0 and 100)
    2. Handle decimal inputs
    3. Display '+' for scores in the top 3% of each grade range
    4. Display '-' for scores in the bottom 3% of each grade range
*/

#include <stdio.h>

int main(){
    //declare a float variable that can handle both integer and decimal inputs 
    float grade;

    printf("Enter the numerical grade (0-100):\n");

    /*
    Input validation. Checks if any of the following conditions are true:
    1. The input is not an integer or decimal
    2. The input is less than 0
    3. The input is greater than 100
    If one or more are true, the input is deemed invalid and will loop until a valid input is entered

    Example 1
        Input  :  a
        Output : "Invalid grade. Please enter a grade between 0 and 100:"
    Example 2    
        Input  :  -12
        Output : "Invalid grade. Please enter a grade between 0 and 100:"
    Example 3    
        Input  :  103
        Output : "Invalid grade. Please enter a grade between 0 and 100:"
    */
    while ((scanf("%f", &grade) != 1) || grade < 0 || grade > 100) {
        printf("Invalid grade. Please enter a grade between 0 and 100:\n");
        //Line 17, Suggested by Copilot (there was an infinite loop if Condition #1 was true, this fixes it):
        //Clear input buffer to handle invalid input 
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        /*
        this loop is empty because the condition in while() takes care of everything 
        getchar() reads a char input from stdin 
        so this loop essentially just reads any char in the input buffer until it encounters a new line
        or the input stream ends
        */
    }

    /*
    If-statement chain that checks the range of the inputed value and prints the associated letter grade
    with a '+' for top 3% of range, and a '-' for bottom 3% of range

    Example 4
        "Enter the numerical grade (0-100):"
        Input  :  97
        Output : "A+"
    Example 5
        "Enter the numerical grade (0-100):"
        Input  :  85
        Output : "B"
    Example 6
        "Enter the numerical grade (0-100):"
        Input  :  72.05
        Output : "C-"
    */
    if (grade >= 97){
        printf("A+\n");
    }
    else if (grade >= 93){
        printf("A\n");
    }
    else if (grade >= 90){
        printf("A-\n");
    }
    else if (grade >= 87){
        printf("B+\n");
    }
    else if (grade >= 83){
        printf("B\n");
    }
    else if (grade >= 80){
        printf("B-\n");
    }
    else if (grade >= 77){
        printf("C+\n");
    }
    else if (grade >= 73){
        printf("C\n");
    }
    else if (grade >= 70){
        printf("C-\n");
    }
    else if (grade >= 67){
        printf("D+\n");
    }
    else if (grade >= 63){
        printf("D\n");
    }
    else if (grade >= 60){
        printf("D-\n");
    }
    else {
        printf("F\n");
    }
}