//
//  main.c
//  randomNumbers
//
//  Created by Eric on 6/21/12.
//  Copyright (c) 2012 Eric. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int randInt();

void randomNumbers()
{
    int nums[10];
    int count = 0;
    int count2 = 0;
    int store;
    printf("The integers are: ");
    while (count < 10)
    {
        nums[count] = randInt();
        printf("%d, ", nums[count]);
        count++;
    }
    count = 9;
    while (count != 0)
    {
        while (count2 < count)
        {
            if (nums[count] < nums[count2])
            {
                store = nums[count];
                nums[count] = nums[count2];
                nums[count2] = store;
            }
            count2++;
        }
        count--;
        count2 = 0;
    }
    printf("\nThe integers in increasing order are: ");
    while (count < 10)
    {
        printf("%d, ", nums[count]);
        count++;
    }

}

int randInt()
{
    int number = (rand() % 100) + 1;
    return number;
}

