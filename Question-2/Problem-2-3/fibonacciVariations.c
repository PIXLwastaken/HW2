/*
Jay Marquez Febles
November 3, 2025
Problem Description:
    Implement 3 different approaches to generate Fibonacci numbers:
        > Using a for loop
        > Using a while loop
        > Using a do-while loop 
    The program should:
        1. Generate the first 10 Fibonacci numbers
        2. Find the sum of even Fibonacci numbers below a given limit
        3. Determine if a given number is in the Fibonacci sequence
        4. Display the Golden Ratio approximation using consecutive Fibonacci numbers
*/

#include <stdio.h>
#include <math.h>

void fibonacciRecursive(int n){
    //declare empty array of size n where all fibonacci numbers will be stored
    int F[n];
    //initialize F(0) = 0 and F(1) = 1
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i <= n; i++){
        F[i] = F[i-1] + F[i-2];
        printf("%d, ", F[i]);
    }
}

void findInFibonacci(int num){

}

int main(){
    fibonacciRecursive(9);
}