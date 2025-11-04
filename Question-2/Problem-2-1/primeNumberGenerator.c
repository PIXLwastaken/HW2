/*
Jay Marquez Febles
November 3, 2025
Problem Description:
    Write a C program that:
    1. Finds all the prime numbers between 1 and n (user input) 
    2. Uses the Sieve of Eratosthenes Algorithm
    3. Displays all primes in a formatted table (10 per row)
    4. Calculates and displays the total count of primes found
    5. Measures and displays the execution time
*/

#include <stdio.h>
#include <time.h>
#include <math.h>

void sieveOfEratosthenes(int n){

    // printf("Step 1: Create a boolean array and init all entries as true\n"); //debug line

    int isPrime[n+1]; //declare an empty array of size n+1 to accomodate all numbers from 0 to n
    isPrime[0] = isPrime[1] = 0; //init index 0 and 1 as false since those arent primes

    for (int i = 2; i <= n; i++){
        isPrime[i] = 1; //init all array entries from 2 to n as true
        // printf("%d | %d\n", i, isPrime[i]); //debug line
    } 

    // printf("\nStep 2: Mark multiples of each prime as composite\n"); //debug line
    
    double sqrtN = sqrt(n); //declare and init this outside of for-loop so it isnt calculated every loop
    for (int p = 2; p <= sqrtN; p++){
        if (isPrime[p] == 1){
            //Mark all multiples of p as not prime
            for (int i = p * p; i <= n; i += p){
                isPrime[i] = 0;
                // printf("%d | %d\n", i, isPrime[i]); //debug line
            }
        }
    }

    // printf("\nStep 3: Collect all numbers that remain marked as prime\n"); //debug line

    //declare empty array of size n and primeCount to count how many primes are found
    int primes[n], primeCount = 0; 

    for (int i = 2; i <= n; i++){
        if (isPrime[i] == 1){ //if a number is prime
            primes[primeCount] = i; //add it to the primes array
            // printf("%d | %d\n", primes[primeCount], primeCount+1); //debug line
            primeCount++; //increase the count of primes found
        }
    }

    //print primes in a formatted table
    for (int i = 0; i < primeCount; i++) {
        if (i % 10 == 0) {
            printf("---------------------------------------------------------------------------------\n|");
        }
        printf(" %5d |", primes[i]);
        if ((i + 1) % 10 == 0 || i == primeCount - 1) {
            printf("\n");
        }
    }
    printf("---------------------------------------------------------------------------------\n");
    //print total number of primes found
    printf("Number of primes found: %d\n", primeCount);
}

int main(){
    int n;

    printf("Enter a number to look for primes from 1 to n:\n");
    //input validation
    while(scanf("%d", &n) != 1){
        printf("Invalid Input. Enter an integer to look for primes from 1 to n:\n");
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }

    clock_t start = clock();
    sieveOfEratosthenes(n);
    clock_t end = clock();

    double delta = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Time elapsed: %lf\n", delta);
}