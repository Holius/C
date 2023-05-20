#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MIN 0
#define MAX 20
#define GUESSES 5


int main(void) {
    srand(time(NULL));
    int secret_number = rand() % (MAX + 1);
    unsigned int g = 0;
    printf("Guess a number between %d and %d\n", MIN, MAX);
    printf("You have %d guesses\n", GUESSES);
    for(int guess = GUESSES; guess > 0; guess--) {
        printf("Enter guess: ");
        int input_received = scanf("%o", &g);
        char c;
        // EMPTY it out because scanf forgot to!
        // edge case is entering "12 asdf\n" which will still work
        // however, the user did not actually input a string
        // resolved by resetting input_received
        // (other edge case is entering completely wrong input which algo gets cleared about by below)
        while (c = getchar() != '\n') {
            // this will never fire when "12\n" is inputted
            // since getchar returns "\n" because of scanf
            // and "12" gets read/converted into the pointer/address at "g"
            input_received = 0;
            // must set to 0 explicitly when "12 asdf\n" is inputted
            // the reason is that "12" gets read into "g"; however, the user inputted non
            // numerical data!
            // we could aslo reset "g" to be safe
        }; 
        if (input_received != 1) {
            printf("Input must be a positive number\n");
            printf("You have %d guesses left\n", guess -1);
            continue;
        }
        if (g < MIN || g > MAX) {
           printf("Input %o is out of bounds: %d - %d\n", g, MIN, MAX);
           printf("You have %d guesses left\n", guess - 1);
           continue;
        }
        if( g != secret_number) {
            printf("You have %d guesses left\n", guess -1);
            continue;
        }
        break;
    }
    if ( g == secret_number) {
        printf("You guessed correctly! The secret number is %d\n", secret_number);
    } else {
        printf("You ran out of guesses.  The secret number is %d\n", secret_number);
    }
}
