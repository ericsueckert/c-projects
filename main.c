//
//  main.c
//  CProjects
//
//  Created by Eric on 6/21/12.
//  Copyright (c) 2012 Eric. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

extern void randomNumbers();
extern void reverseString();
extern void ageSort();
extern void nameSort();
extern void hangman();
extern void nameSortLinkList();
extern void factorial();
extern void fibonacci();

int main (int argc, const char * argv[])
{
    int choice;
    while (1)
    {
        printf("\nWhat program would you like to run?\n");
        printf("\t1. Random Numbers\n");
        printf("\t2. Reverse String\n");
        printf("\t3. Age Sort\n");
        printf("\t4. Name Sort\n");
        printf("\t5. Hangman\n");
        printf("\t6. Name Sort (Link List)\n");
        printf("\t7. Factorial\n");
        printf("\t8. Fibonacci\n");
        printf("\t9. Exit program\n");
        printf("Enter your choice.\n");
        scanf(" %d", &choice);
        switch (choice)
        {
            case (1): printf("Running Random Numbers\n");
                randomNumbers();
                break;
            case (2): printf("Running Reverse String\n");
                reverseString();
                break;
            case (3): printf("Running Age Sort\n");
                ageSort();
                break;
            case (4): printf("Running Name Sort\n");
                nameSort();
                break;
            case (5): printf("Running Hangman\n");
                hangman();
                break;
            case (6): printf("Running Name Sort (Link List)");
                nameSortLinkList();
                break;
            case (7): printf("Running Factorial\n");
                factorial();
                break;
            case (8): printf("Running Fibonacci\n");
                fibonacci();
                break;
            case (9): printf("Exiting program.\n");
                exit(0);
            default: printf("Not a valid choice.\n");
                break;
        }
    }
}