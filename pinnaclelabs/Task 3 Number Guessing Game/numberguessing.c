#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, guess;
    
    srand(time(0));
    secret = rand() % 100 + 1;
    
    printf("I'm thinking of a number between 1 and 100.\n");
    
    do {
        printf("Your guess? ");
        scanf("%d", &guess);
        
        if (guess < secret) {
            printf("Too low! Try again.\n");
        } else if (guess > secret) {
            printf("Too high! Try again.\n");
        }
    } while (guess != secret);
    
    printf("Congratulations! You guessed it!\n");
    
    return 0;
}