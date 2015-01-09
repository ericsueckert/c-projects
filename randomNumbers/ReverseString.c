#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *myword);

void reverseString()
{
    char scwrd[200] = " ";
    char rv[200] = " ";
    char * words;
    printf("Enter your word:\n");
    scanf("%s", scwrd);
    words = malloc(2 * strlen(scwrd)+1);
    strcpy(words, scwrd);
    printf("The input string is %s\n", words);
    strcpy(rv, words);
	reverse(rv);
    printf("The reversed word is %s\n", rv);
    strcat(words, rv);
	printf("The reverse is %s", words);
    free(words);
    return;
}

void reverse(char *myword)
{
	//initialize
	int length = 1;
	char letter = myword[0];
	int letternum = 0;
	char store;
	int count;
	//counts the length of the string
	while (letter != '\0')
	{
		letter = myword[length];
		length++;
	}
	count = length;
	//swaps the first and last letters and ends with the middle
	while (count > 1)
	{
		store = myword [length - 2];
		myword [length - 2] = myword[letternum];
		myword[letternum] = store;
		letternum++;
		length--;
		count = count - 2;
	}
	myword[letternum + length] = '\0';
	return;
}