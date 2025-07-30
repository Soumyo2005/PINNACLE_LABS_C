#include <stdio.h>

int main() {
    printf("\nSimple Calculator\n");
    printf("----------------\n");
    printf("Choose an operation:\n");
    printf("+  Add two numbers\n");
    printf("-  Subtract two numbers\n");
    printf("*  Multiply two numbers\n");
    printf("/  Divide two numbers\n\n");

    double first_num, second_num;
    char operation;
    
    printf("Enter first number: ");
    scanf("%lf", &first_num);
    
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    
    printf("Enter second number: ");
    scanf("%lf", &second_num);

    double result;
    int error = 0;
    
    switch(operation) {
        case '+':
            result = first_num + second_num;
            printf("\n%.2f + %.2f = %.2f\n", first_num, second_num, result);
            break;
            
        case '-':
            result = first_num - second_num;
            printf("\n%.2f - %.2f = %.2f\n", first_num, second_num, result);
            break;
            
        case '*':
            result = first_num * second_num;
            printf("\n%.2f * %.2f = %.2f\n", first_num, second_num, result);
            break;
            
        case '/':
            if(second_num == 0) {
                printf("\nError: Cannot divide by zero!\n");
                error = 1;
            } else {
                result = first_num / second_num;
                printf("\n%.2f / %.2f = %.2f\n", first_num, second_num, result);
            }
            break;
            
        default:
            printf("\nError: Invalid operation '%c'\n", operation);
            error = 1;
    }

    return error;
}