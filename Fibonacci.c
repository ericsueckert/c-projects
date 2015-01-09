//
//  Fibonacci.c
//  CProjects
//
//  Created by Eric on 7/11/12.
//  Copyright (c) 2012 Eric. All rights reserved.
//

#include <stdio.h>

long calcFib(int num);

void fibonacci()
{
    long fibResult;
    int enterNum = 0;
    
    printf("Which Fibonacci number would you like to know?\n");
    printf("Enter a number:\n");
    scanf(" %d", &enterNum);
    fibResult = calcFib(enterNum);
    printf("\nThe Fibonacci number is %ld\n", fibResult);
}

long calcFib(int num)
{
    if (num <= 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    return (calcFib(num - 2) + calcFib(num - 1));
}