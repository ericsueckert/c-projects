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

extern int compareStrings(char* string1, char* string2);
void printProfiles();

FILE *profilesptr;
FILE *profileprint;
struct profile
{
    struct profile *nextPtr;
    char firstName[50];
    char lastName[50];
    int age;
};

void switchProfile();
int compareStrings(char* string1, char* string2);

struct profile *person; // profile that was just scanned in
struct profile *headPtr; // first profile
struct profile *tailPtr; // last profile
struct profile *tempPtr; // pointer that compares every profile to person

void nameSortLinkList()
{
    int count = 0;
    int result;
    char fileLine[80];
    
    profilesptr = fopen("/Users/eric/CPrograms/PeopleProfile", "r");
    profileprint = fopen("/Users/eric/CPrograms/PeopleSort", "w");
    
    if (profilesptr == 0)
    {
        printf("There was no such file");
        return;
    }
    else
    {
        headPtr = malloc(sizeof(struct profile));
        headPtr->nextPtr = NULL;
        fgets(fileLine, 80, profilesptr);
        sscanf(fileLine, "\n %s %s %d\n", headPtr->firstName, headPtr->lastName, &headPtr->age);
        printf("\n %s %s %d\n", headPtr->firstName, headPtr->lastName, headPtr->age);
        
        /*while (!feof(profilesptr))
        {
            person = malloc(sizeof(struct profile));
            fgets(fileLine, 80, profilesptr);
            sscanf(fileLine, "\n %s %s %d\n", person->firstName, person->lastName, &person->age);
            printf("\nline is %s %s\n", fileLine, person->firstName);
            tempPtr = headPtr;
            result = compareStrings(person->lastName, headPtr->lastName);
            if (result == 1) //comparing the last names
            {
                person->nextPtr = headPtr;
                headPtr = person;
                
            }
            else if (result == 0)
            {
            }
            else if (result == 2)
            {
                result = compareStrings(person->firstName, headPtr->firstName);
                if (result == 1) //if last names are equal, compare first names
                {
                    tempPtr->nextPtr = headPtr;
                }
                else if (result == 0)
                {
                }
                else if (result == 2)
                {
                }
            }
            while (tempPtr != NULL)
            {
                person = malloc(sizeof(struct profile));
                fgets(fileLine, 80, profilesptr);
                sscanf(fileLine, "\n %s %s %d\n", tempPtr->firstName, tempPtr->lastName, &tempPtr->age);
                printf("\nline is %s %s\n", fileLine, tempPtr->firstName);

                result = compareStrings(person->lastName, tempPtr->lastName);
                if (result == 1) //comparing the last names
                {
                    person->nextPtr = tempPtr;
                    tempPtr = person;
                }
                else if (result == 0)
                {
                }
                else if (result == 2)
                {
                    result = compareStrings(person->firstName, tempPtr->firstName);
                    if (result == 1) //if last names are equal, compare first names
                    {
                        person->nextPtr = tempPtr;
                        tempPtr = person;
                    }
                    else if (result == 0)
                    {
                    }
                    else if (result == 2)
                    {
                    }
                }
                tempPtr = tempPtr->nextPtr;
            }
        }*/
    }
    printProfiles();
    fclose(profileprint);
    fclose(profilesptr);
    free(person);
}

void printProfiles()
{
    struct profile *holdPtr;
    holdPtr = headPtr;
    while (holdPtr != NULL)
    {
        printf("\n%s %s %d\n", holdPtr->firstName, holdPtr->lastName, holdPtr->age);
        holdPtr = holdPtr->nextPtr;
    }
}