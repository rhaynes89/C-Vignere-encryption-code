/*
Name: Richard Haynes III
Assignment: Security in Computing Vignere encryption
Date: 2/12/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 512

int main(int argc, char **argv)
{
	int i = 0, j = 0, k = 0;
	int count = 0;
	char kyText;
	char pText;
	char key[SIZE];
	char plainText[SIZE];
	char encryptedText[SIZE];

	for(i = 0; i < argc; i++)
	{
		printf("%s ", argv[i]);
	}
	printf("\n\n");

	// reads key text file
	char *fname = argv[1];
	FILE *file = fopen(fname, "r");
	if(file == NULL)
	{
		printf("Key file doesn't exist....\n\n");\
		exit(1);
	}
	else
	{
		printf("\n\nKey file opened successfully\n\n");
	}
	i = 0;
	printf("Key:\n\n");
	while((kyText = fgetc(file)) != EOF && i < SIZE)
	{
		if(isalpha(kyText))
		{
			// make kyText lowercase
			key[i] = tolower(kyText);
			printf("%c", key[i]);
			i++;
			if(i % 80 == 0)
			{
				printf("\n");
			}
		}
	}
	int temp = i;
	count = temp;
	i = 0;
	while(temp < SIZE)
	{
		if(i >= count)
		{
			i = 0;
		}
		key[temp] = key[i];
		i++;
		temp++;
	}
	// reads plain text file
	char *fname2 = argv[2];
	FILE *fptr = fopen(fname2, "r");
	if(fptr == NULL)
	{
		printf("Plain text file doesn't exist....\n\n");
	}
	else
	{
		printf("\n\nPlain text file opened.\n\n");
	}
	while((pText = fgetc(fptr)) != EOF && j < SIZE)
	{
		if(isalpha(pText))
		{
			// make pText lowercase
			plainText[j] = tolower(pText);
			j++;
		}
	}
	if(j < SIZE)
	{
		while(j < SIZE)
		{
			plainText[j] = 'x';
			j++;
		}
	}
	printf("Plain Text:\n\n");
	j = 0;
   	while( j < SIZE){
	   	printf("%c", plainText[j]);
	   	j++;
	   	if(j % 80 == 0)
	   	{
		   	printf("\n");
	   	}
   	}
	printf("\n\n");
	//Encrytping starts here
	i = 0;
	j = 0;
	while(k < SIZE)
	{
		int temp = key[i] - 97;
        int temp2 = plainText[j] - 97;
		encryptedText[k] = ((temp + temp2) % 26) + 97;
		j++;
		k++;
		i++;
	}
	k = 0;
  	printf("Encrypted Text:\n\n");
    while(k < SIZE){
        printf("%c", encryptedText[k]);
        k++;
		if(k % 80 == 0)
		{
			printf("\n");
		}
    }
	printf("\n\n");
	fclose(file);
	fclose(fptr);
	return 0;
}
