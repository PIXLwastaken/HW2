#include <stdio.h>

int main(){
    float grade = 0.0;

    printf("Enter the numerical grade (0-100):\n");
    scanf("%f", &grade);

    while (grade < 0 || grade > 100) {
        printf("Invalid grade. Please enter a grade between 0 and 100:\n");
        scanf("%f", &grade);
    }

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

