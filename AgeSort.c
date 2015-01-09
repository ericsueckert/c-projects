//
//  People.c
//  CProjects
//
//  Created by Eric on 6/21/12.
//  Copyright (c) 2012 Eric. All rights reserved.
//

#include <stdio.h>
#include <string.h>

struct profile
{
    char firstName[50];
    char lastName[50];
    int age;
};

struct profile person[5];

void ageSort()
{
    int count = 0;
    int count2 = 0;
    int store = 0;
    char storeName[50];
    
    while (count < 5)
    {
        printf("\nEnter first name\n");
        scanf(" %s", person[count].firstName);
        printf("\nEnter last name\n");
        scanf(" %s", person[count].lastName);
        printf("\nEnter age\n");
        scanf(" %d", &person[count].age);
        count++;
    }
    while (count != 0)
    {
        while (count2 < count)
        {
            if (person[count].age < person[count2].age)
            {
                store = person[count].age;
                person[count].age = person[count2].age;
                person[count2].age = store;
                strcpy(storeName, person[count].firstName);
                strcpy(person[count].firstName, person[count2].firstName);
                strcpy(person[count2].firstName, storeName);
                strcpy(storeName, person[count].lastName);
                strcpy(person[count].lastName, person[count2].lastName);
                strcpy(person[count2].lastName, storeName);
            }
            count2++;
        }
        count--;
        count2 = 0;
    }
    while (count <= 5)
    {
        printf("\n%s %s %d", person[count].firstName, person[count].lastName, person[count].age);
        count++;
    }

}