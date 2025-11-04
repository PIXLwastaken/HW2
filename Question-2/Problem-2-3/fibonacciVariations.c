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
#include <unistd.h>

//function to print Fibonacci numbers from F[0] to F[n]
void fibonacciRecursive(int n){
    //declare empty array of size n+2 where all Fibonacci numbers will be stored
    int F[n + 2];

    //starting from F[2], use the recursive definition of the Fibonacci sequence, 
    //F[n] = F[n-1] + F[n-2], to compute all Fibonacci numbers from F[0] to F[n]
    for (int i = 0; i <= n; i++){
        //This if-statement initializes F[0] and F[1], and allows them to be printed by the loop
        if (i == 0){
            F[i] = 0; 
        } else if (i == 1){
            F[i] = 1;
        } else {
            F[i] = F[i-1] + F[i-2];
        }
        printf("%d ", F[i]); //print F[n] after being computed 
    }
}

//function that prints whether or not a given number n is in the Fibonacci sequence
void findInFibonacci(int n){
    int fib = 0, a = 0, b = 1;

    //check that n isn't 0 or 1
    if (n == 0){
        printf("0 is in the Fibonacci sequence\n");
    } else if (n == 1){
        printf("1 is in the Fibonacci sequence\n");
    } else {
        //compute fib for each number using a while-loop until fib is greater than or equal to n
        while (fib < n) {
            fib = a + b;
            a = b;
            b = fib;
        } 

        //check if the final computed fibonacci number is equal to n, and print whether n is in the sequence or not
        if (fib == n){ //if they're equal that means n is in the Fibonacci sequence
            printf("%d IS in the Fibonacci sequence\n", n);
        } else { //if they're not equal, that means n was not in the sequence
            printf("%d IS NOT in the Fibonacci sequence\n", n);
        }
    }
}

//function that prints the sum of even Fibonacci numbers below a given limit
void sumOfEvenFibonacci(int limit){
    int fib = 0, a = 0, b = 1, sum = 0;
    //compute fib for each number using a do-while-loop up until the given limit
    do {
        fib = a + b;
        a = b;
        b = fib;
        //check if the computed fibonacci number is even
        if ((fib % 2) == 0){
            sum += fib; //if so, add it to the sum
        }
    } while (fib < limit); //loop until fib >= limit
    printf("The sum of even Fibonacci Numbers below %d is:\n%d\n", limit, sum);
}

//function that displays the Golden Ratio approximation using consecutive Fibonacci numbers
void goldenRatio(int n){
    //this function will be a modified version of the fibonacciRecursive() function
    int F[n + 2];
    double ratio;

    for (int i = 0; i <= n; i++){
        //This if-statement initializes F[0] and F[1], and allows them to be printed by the loop
        if (i == 0){
            F[i] = 0; 
        } else if (i == 1){
            F[i] = 1;
        } else {
            F[i] = F[i-1] + F[i-2];
        }

        //only calculate and print the ratio when i > 1, since F[-1] does not exist
        if (i > 1){
            /*
            The Golden Ratio is ϕ ≈ 1.61803...
            and can be approximated using the Fibonacci sequence like so:
            ratio = F[n] / F[n-1]
            */
            ratio = (double) F[i] / F[i-1];
            printf("F[%d] = %d, F[%d] = %d, ratio = %.6lf\n", i, F[i], i-1, F[i-1], ratio);
            //add a time delay for readability
            sleep(1);
        }
    }
}

int main(){
    int findN, sumN;
    
    //start the program by printing the first 10 Fibonacci numbers
    printf("The first 10 Fibonacci Numbers are:\n");
    fibonacciRecursive(9); //prints first 10 fibonacci numbers, from F[0] to F[9]
    printf("\n");

    //prompt the user for a limit to compute the sum of even Fibonacci numbers below that limit 
    printf("Enter a number to compute the sum of even Fibonacci numbers below it.\nlimit = ");
    //Make sure the input is an integer
    while (scanf("%d", &sumN) != 1){
        printf("Invalid Input\nNumber must be an integer.\nn = ");
        //clear input buffer after invalid input
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }
    sumOfEvenFibonacci(sumN);

    //prompt the user for a number n to find in the fibonacci sequence
    printf("Enter a number to determine if it is in the Fibonacci sequence.\nn = ");
    //Make sure the input is an integer
    while (scanf("%d", &findN) != 1){
        printf("Invalid Input\nNumber must be an integer.\nn = ");
        //clear input buffer after invalid input
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }
    findInFibonacci(findN); //find the given number n in the Fibonacci sequence

    printf("The Golden Ratio approximation will now be displayed: \n");
    sleep(1);
    goldenRatio(20);
}

/*
Example
    Output  :
        The first 10 Fibonacci Numbers are:
        0 1 1 2 3 5 8 13 21 34 
    "Enter a number to compute the sum of even Fibonacci numbers below it."
    "limit =" 
    Input  :  100
    Output :  The sum of even Fibonacci Numbers below 100 is:
    Input  :  188
    "Enter a number to determine if it is in the Fibonacci sequence."
    "n =" 
    Input  :  233
    Output :  "233 IS in the Fibonacci sequence"    
    Output :
        "The Golden Ratio approximation will now be displayed: 
        F[2] = 1, F[1] = 1, ratio = 1.000000
        F[3] = 2, F[2] = 1, ratio = 2.000000
        F[4] = 3, F[3] = 2, ratio = 1.500000
        F[5] = 5, F[4] = 3, ratio = 1.666667
        F[6] = 8, F[5] = 5, ratio = 1.600000
        F[7] = 13, F[6] = 8, ratio = 1.625000
        F[8] = 21, F[7] = 13, ratio = 1.615385
        F[9] = 34, F[8] = 21, ratio = 1.619048
        F[10] = 55, F[9] = 34, ratio = 1.617647
        F[11] = 89, F[10] = 55, ratio = 1.618182
        F[12] = 144, F[11] = 89, ratio = 1.617978
        F[13] = 233, F[12] = 144, ratio = 1.618056
        F[14] = 377, F[13] = 233, ratio = 1.618026
        F[15] = 610, F[14] = 377, ratio = 1.618037
        F[16] = 987, F[15] = 610, ratio = 1.618033
        F[17] = 1597, F[16] = 987, ratio = 1.618034
        F[18] = 2584, F[17] = 1597, ratio = 1.618034
        F[19] = 4181, F[18] = 2584, ratio = 1.618034
        F[20] = 6765, F[19] = 4181, ratio = 1.618034"
*/