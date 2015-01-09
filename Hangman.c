//
//  Hangman.c
//  CProjects
//
//  Created by Eric on 6/26/12.
//  Copyright (c) 2012 Eric. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void hangman()
{
    int length = 0;
    char guess = ' '; // holds the character you guess
    char word[50] = " "; // holds the original word throughout the program
    char guessedLetters[27] = " "; // holds all the letters you guess
    int guessCount = 0;
    int wordCount = 0;
    char guessWord[50] = " "; // serves as the playing board, is originally full of dashes
    int errorCount = 0;
    int error = 0;
    int success = 0;
    int doneLetters = 0;
    int indicator;
    
    printf("Enter a word:\n");
    scanf(" %s", word);
    //determine the length of the word, and enter proper amount of blanks into the second array
    while (word[length] != '\0')
    {
        guessWord[length] = '-';
        length++;
    }
    printf("\n%s\n", guessWord);
    while (1)
    {
        indicator = 0;
        printf("\nGuess letter:\n");
        scanf(" %c", &guess);
        //tests whether you already guessed the letter
        while (guessedLetters[doneLetters] != '\0')
        {
            if (guess == guessedLetters[doneLetters])
            {
                printf("\nYou already guessed that letter.\n");
                // allows program to continue the loop
                indicator = 1;
                break;
            }
            doneLetters++;
        }
        // continues the guessing if you repeat a letter
        if (indicator == 1)
        {
            continue;
        }
        // adds letter to array of guessed letters
        guessedLetters[guessCount] = guess;
        doneLetters = 0;
        guessCount++;
        
        //checks the whole word for the character you enter
        while (wordCount < length)
        {
            if (word[wordCount] == guess)
            {
                //if the letter is in the word, that letter from the original is copied to the blanks
                guessWord[wordCount] = word[wordCount];
                //every time a blank is replaced by a letter, success increases
                success++;
            }
            else
            {
                //if the letter is not matched in every iteration of the loop, errorCount will equal length, i.e. the letter is not in the word
                errorCount++;
            }
            wordCount++;
        }
        printf("\n%s\n", guessWord);
        wordCount = 0;
        //determines whether the letter was in the word
        if (errorCount == length)
        {
            //decreases tries
            error++;
            printf("\nThat letter is not in the word.\n");
        }
        errorCount = 0;
        //determines if you are out of tries and if you lose the game
        if (error == 6)
        {
            printf("\nYou have no more guesses. You lose.\n");
            break;
        }
        //determines whether you guessed the word, i.e. if all the blanks are replaced by letters
        else if (success == length)
        {
            printf("\nYou win! You correctly guessed the word %s\n", word);
            break;
        }
        //tells you how many tries you have left
        printf("\nYou have %d tries left.\n", 6 - error);
        wordCount = 0;
    }
    
}