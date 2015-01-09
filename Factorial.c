//
//  Factorial.c
//  CProjects
//
//  Created by Eric on 7/11/12.
//  Copyright (c) 2012 Eric. All rights reserved.
//

#include <stdio.h>

long calcFactorial(int num);
void CalRandomResult( int inputNum, long *factorial, int *modTenResult);


void factorial()
{
    long factorialResult;
    int modTenResult;
    int factorialNumber = 1;
    
    printf("\nEnter a number\n");
    scanf(" %d", &factorialNumber);
    CalRandomResult(factorialNumber, &factorialResult, &modTenResult);
    printf("\nThe factorial is %ld, and mod 10 is %d \n", factorialResult, modTenResult);
}

long calcFactorial(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return (num * calcFactorial(num - 1));
}

void CalRandomResult( int inputNum, long *factorialResult, int *modTenResult)
{
    *factorialResult = calcFactorial (inputNum);
    *modTenResult = inputNum % 10;

}