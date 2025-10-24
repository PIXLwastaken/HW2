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
    int F[n + 2];
    //initialize F(0) = 0 and F(1) = 1
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i <= n; i++){
        F[i] = F[i-1] + F[i-2];
        printf("%d ", F[i]);
    }
}

void findInFibonacci(int n){
    int fib = 0, a = 0, b = 1;

    //check that n isn't 0 or 1
    if (n == 0){
        printf("0 is in the Fibonacci sequence\n");
    } else if (n == 1){
        printf("1 is in the Fibonacci sequence\n");
    } else {
        //compute fib for each number using a while-loop until fib is greater than or equal to n
        do {
            fib = a + b;
            a = b;
            b = fib;
            // printf("%d ", fib); //debug line
        } while (fib < n);
        // printf("\n"); //debug line

        if (fib == n){
            printf("%d is in the Fibonacci sequence\n", n);
        } else {
            printf("%d is not in the Fibonacci sequence\n", n);
        }
    }
}

void sumOfEvenFibonacci(int limit){
    int fib = 0, a = 0, b = 1, sum = 0;
    //compute fib for each number using a while-loop up until limit
    while (fib < limit) {
        fib = a + b;
        a = b;
        b = fib;
        // printf("%d ", fib); //debug line
        if ((fib % 2) == 0){
            sum += fib;
        }
    }
    printf("The sum of even Fibonacci Numbers below %d is:\n%d\n", limit, sum);
}

int main(){
    fibonacciRecursive(9);
    printf("\n");
    findInFibonacci(233);
    printf("\n");
    sumOfEvenFibonacci(233);
}