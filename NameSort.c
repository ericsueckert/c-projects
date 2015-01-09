//
//  People.c
//  CProjects
//
//  Created by Eric on 6/21/12.
//  Copyright (c) 2012 Eric. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *profilesptr;
FILE *profileprint;
struct profile
{
    char firstName[50];
    char lastName[50];
    int age;
};

void switchProfile();
int compareStrings(char* string1, char* string2);

struct profile *person;

void nameSort()
{
    int initcount = 0;
    int count = 0;
    int count2 = 0;
    int result;
    char fileLine[80];
    
    /*while (count < 5)
    {
        printf("\nEnter first name\n");
        scanf(" %s", person[count].firstName);
        printf("\nEnter last name\n");
        scanf(" %s", person[count].lastName);
        printf("\nEnter age\n");
        scanf(" %d", &person[count].age);
        count++;
    }*/
    profilesptr = fopen("/Users/eric/CPrograms/PeopleProfile", "r");
    profileprint = fopen("/Users/eric/CPrograms/PeopleSort", "w");
    
    if (profilesptr == 0)
    {
        printf("There was no such file");
        return;
    }
    else
    {
        while (!feof(profileprint))
        {
            fgets(fileLine, 80, profilesptr);
            initcount++;
        }
        fclose(profilesptr);
        count = initcount;
        person = malloc(initcount * sizeof(person));
        profilesptr = fopen("/Users/eric/CPrograms/PeopleProfile", "r");
        while (initcount != 0)
//        while (count < 5)
        {
            fgets(fileLine, 80, profilesptr);
            sscanf(fileLine, "\n %s %s %d\n", person[count].firstName, person[count].lastName, &person[count].age);
            printf("\nline is %s %s\n", fileLine, person[count].firstName);
            count--;
        }
    }
    count--;
    while (count != 0) //sets each string as the comparer
    {
        while (count2 < count) //sets every other string as the comparee
        {
            result = compareStrings(person[count].lastName, person[count2].lastName);
            printf("\n%d %d\n", count, count2);
            printf("\nresult: %d\n", result);
            printf("\n%s\n%s\n%s\n%s\n%s\n\n", person[0].lastName, person[1].lastName, person[2].lastName, person[3].lastName, person[4].lastName);
            if (result == 1) //comparing the last names
            {
                printf("\nSwitch %d and %d\n", count, count2);
                switchProfile(count, count2);
            }
            else if (result == 0)
            {
            }
            else if (result == 2)
            {
                result = compareStrings(person[count].firstName, person[count2].firstName);
                if (result == 1) //if last names are equal, compare first names
                {
                    printf("\nSwitch %d and %d", count, count2);
                    switchProfile(count, count2);
                }
                else if (result == 0)
                {
                }
                else if (result == 2)
                {
                }

            }
            count2++;
        }
        count--;
        count2 = 0;
    }
    while (count < 5) //print the names in order
    {
        fprintf(profileprint, "\n%s %s %d", person[count].firstName, person[count].lastName, person[count].age);
        count++;
    }
    fclose(profileprint);
    fclose(profilesptr);
    free(person);
}

void switchProfile(int count, int count2)
{
    int store = 0;
    char storeName[50] = " ";
    
    //swap the variables by using a store variable
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

int compareStrings(char* string1, char* string2)
{
    //return 0 = don't switch strings
    //return 1 = switch strings
    //return 2 = strings are equal
    int count = 0;
    
    while (1)
    {
        if (string1[count] < string2[count])
        {   
            return 1;
        }
        else if (string1[count] == string2[count])
        {
            if (string1[count] == '\0' && string2[count] == '\0')
            {
                return 2;
            }
            count++;
            continue;
        }
        else
        {
            return 0;
        }
    }
}
