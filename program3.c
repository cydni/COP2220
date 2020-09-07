//Cydni Turner
//COP 2220
//November 20, 2016
//Arrays and Strings

#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <string.h>
#include <stdio.h>

//FUNCTION PROTOTYPES

//Greets user.
void Greet();

//Get yes or no from user to start pluralizer.
char GetChoice();

//Gets word from user to pluralize.
void GetWord(char word[]);

//Changes the word to all upper case.
int ToUppercase(char word[], char plural[]);

//Determines which rule needs to be  used
int FindRule(char word[], int len);

//Carries out changes for rule RULE 1.
void RuleOne(char word[], char plural[], int len);

//Carries out changes for RULE 2.
void RuleTwo(char word[], char plural[], int len);

//Carries out changes for RULE 3.
void RuleThree(char word[], char plural[], int len);

//Save words to output file.
void SaveWords(char word[], char plural[], FILE *outPtr);

//Says goodbye to the user.
void SayGoodbye();


int main()
{
	FILE *outPtr;
	char word[20];
	char plural[25];
	char choice;
	int rule, len;

	//Greet user
	Greet();
	//Connect to ouptut file
	outPtr = fopen("pluralWords.txt", "w");
	printf("\nThe output file pluralWords.txt is open.\n");
	printf("\n--------------------------------\n\n");

	//Get Y or N from user
	choice = GetChoice();

	//Set up the while loop that runs pluralizer
	while (choice == 'y' || choice == 'Y')
	{
		//Get the word
		GetWord(word);

		//Change everything to uppercase and make a copy of the word.
		len = ToUppercase(word, plural);

		//Determine the appropriate rule for the word.
		rule = FindRule(word, len);

		//Carry out the changes to plural using condititons.
		if (rule == 1)
		{
			RuleOne(word, plural, len);
		}
		else if (rule == 2)
		{
			RuleTwo(word, plural, len);
		}
		else
		{
			RuleThree(word, plural, len);
		}

		//Save words to output file pluralWords.txt.
		SaveWords(word, plural, outPtr);

		//Update
		choice = GetChoice();
	}

	//Say goodbye
	SayGoodbye();

	return 0;
}

//FUNCTION DEFINITIONS

//Greets user.
void Greet()
{
	printf("\n* * * Welcome to the pluralizer * * *\n");
}

//Get yes or no from user to start pluralizer.
char GetChoice()
{
	char choice;
	printf("\nWould you like to enter a word (Y or N): ");
	scanf(" %c", &choice);
	return choice;
}

//Gets word from user to pluralize.
void GetWord(char word[])
{
	printf("\n\nEnter a word: ");
	scanf(" %s", word);
	printf("\n");
}

//Changes the word to all upper case.
int ToUppercase(char word[], char plural[])
{
	int i, num;
	num = strlen(word);
	
	for (i = 0; i < num; i++)
	{
		word[i] = toupper(word[i]);
	}

	strcpy(plural, word);

	return num;

}

//Determines which rule needs to be  used
int FindRule(char word[], int len)
{
	
	if (word[len - 1] == 'Y')
	{
		printf("\nRULE 1.");
		return 1;
	}
	else if (word[len-1]=='S')
	{
		printf("\nRULE 2.");
		return 2;
	}
	else if (word[len - 1] == 'H' && word[len - 2] == 'C')
	{
		printf("\nRULE 2.");
		return 2;
	}
	else if (word[len - 1] == 'H'&& word[len - 2] == 'S')
	{
		printf("\nRULE 2.");
		return 2;
	}
	else
	{
		printf("\nRULE 3.");
		return 3;
	}

}

//Carries out changes for rule RULE 1.
void RuleOne(char word[], char plural[], int len)
{
	plural[len - 1] = '\0';
	strcat(plural, "IES");
	printf("\nThe word is %s and the plural is %s.\n", word, plural);
}

//Carries out changes for RULE 2.
void RuleTwo(char word[], char plural[], int len)
{
	strcat(plural, "ES");
	printf("\nThe word is %s and the plural is %s.\n", word, plural);

}

//Carries out changes for RULE 3.
void RuleThree(char word[], char plural[], int len)
{
	strcat(plural, "S");
	printf("\nThe word is %s and the plural is %s.\n", word, plural);
}

//Save words to output file.
void SaveWords(char word[], char plural[], FILE *outPtr)
{
	fprintf(outPtr, "\nThe word is %s and the plural is %s.\n", word, plural);
	fprintf(outPtr, "\n------------------------------\n\n");

	//TEST 
	printf("\n\n* * Printing to output file * *");
	printf("\n------------------------------\n\n");

}




//Says goodbye to the user
void SayGoodbye()
{
	printf("\n------------------------------");
	printf("\n\nThanks for trying out the pluralizer.\n\n");
}


