# CSI-1420 — Homework 2

**Author:** Jay Marquez Febles  
**Course:** CSI-1420 "Intro to Unix and C Programming"
**Assignment:** Homework 2 "C Control Flow Structures" 

This code can be found here on my Github repository:
https://github.com/PIXLwastaken/HW2

## Compilation Instructions
The .zip archive is organized in the following way:
HW2/
├── Question-1
│   ├── Problem-1-1
│   │   ├── gradeCalculator
│   │   └── gradeCalculator.c
│   └── Problem-1-2
│       ├── calculatorSwitch
│       └── calculatorSwitch.c
└── Question-2
    ├── Problem-2-1
    │   ├── primeNumberGenerator
    │   └── primeNumberGenerator.c
    ├── Problem-2-2
    │   ├── patternGenator
    │   └── patternGenator.c
    └── Problem-2-3
        ├── fibonacciVariations
        └── fibonacciVariations.c

### On Ubuntu Linux
1. Open a terminal and navigate to the directory where the project files are located.
    e.g., to access Question 1, problem 1-1:

    ```bash
    cd ~/Downloads/HW2/Question-1/Problem-1-1/

2. An already compiled version of the code is included in the problem folder, which can be run using this command:
    e.g., running Question 1, Problem 1-1:

    ```bash
    ./gradeCalculator

3. If you wish to recompile the *.c file anyway, you can run the following commands to compile and run:
    e.g., compiling and running Question 1, Problem 1-1:

    ```bash
    gcc gradeCalculator.c -o gradeCalculator -lm
    ./gradeCalculator

Note: Include the option "-lm" when compiling programs just in case they use the <time.h> or <math.h> libraries
