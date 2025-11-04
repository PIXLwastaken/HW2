/*
Jay Marquez Febles
November 3, 2025
Problem Description:
    Write a C program that generates the following patterns based on user input n:
    1. Pattern A (Diamond)
        *     
       ***    
      *****   
     *******    
      *****     
       ***      
        * 
    2. Pattern B (Number Pyramid)
        1     
       121    
	  12321   
     1234321 
*/

#include <stdio.h>

int main(){

    //Declare a char "choice" which will be assigned the input
    char choice;

    printf("Select a pattern to generate:\nA) Diamond\tB) Number Pyramid\n");

    /*
    Validate the input by checking the following conditions:
    1. The input is not a char
    OR
    2. The input is not equal to 'A' AND 'a' AND 'B' AND 'b'
    */
    while (scanf(" %c", &choice) != 1 || (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b')) {
        //If either condition is true, then prompt for input again and clear the input buffer
        printf("Invalid input. Please select a pattern to generate:\nA) Diamond\tB) Number Pyramid\n");
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }

    //If the input is 'a' OR 'A', then print the diamond
    if (choice == 'a' || choice == 'A') {
        printf("        *\n");
        printf("       ***\n");
        printf("      *****\n");
        printf("     *******\n");
        printf("      *****\n");
        printf("       ***\n");
        printf("        *\n");
    }
    //if the input is 'b' OR 'b', then print the number pyramid
    else if (choice == 'b' || choice == 'B') {
        printf("        1\n");
        printf("       121\n");
        printf("      12321\n");
        printf("     1234321\n");
        printf("    123454321\n");
        printf("   12345654321\n");
        printf("  1234567654321\n");
    }

}