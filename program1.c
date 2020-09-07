//Cydni Turner
//COP 2220
//5 October 2016
//Letter Guessing Game



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define MAXGUESSES 5



//paste all the function prototypes here
//with the comments

//this function provides instructions to the user on how to play the game
void LetterGuessRules();

//Gets the numberof games the user wants to play.
int NumGames();

//this function runs one game.
//input: character from the file, void return type
//all other functions to Play one round of a game
//are called from within the GuessTheLetter function
void GuessTheLetter(char);

//this function prompts the player to make a guess and returns that guess
//this function is called from inside the GuessTheLetter( ) function described above
char GetTheGuess();

//this function takes two arguments, the guess from the player
//and the solution letter from the file.
//The function returns 1 if the guess matches the solution and returns a 0 if they do not match
//This function also lets the user know if the guess comes alphabetically before or after the answer
int CompareLetters(char, char);


int main()
{
	//declare additional variables
	//declare FILE pointer
	int numGames, i = 0;
	FILE * inPtr;

	
	//letter from file
	char solution;

	//display game rules
	LetterGuessRules();
	//Ask and get number of games to play
	numGames = NumGames();

	//connect to the file HINT: use fopen
	inPtr = fopen("letterList.txt", "r");

	//extra variable to tell user what game number they are on.
	int gamenum = 0;
	//this for loop will allow the player to play more than one game
	//without recompiling
	for (i = 0; i < numGames; i++)
	{	
		gamenum++;
		printf("\n\n--------------------------------------------------------------------------------\n");
		printf("Starting game number %d.", gamenum);
		printf("\n\n               ---------------------------------------------");
		//get a solution letter from file - use fscanf
		fscanf(inPtr, " %c", &solution);
		//change the solution to lowercase
		solution = tolower(solution);
		//print the solution back onto the screen to test
		//call the GuessTheLetter function and pass it the solution
		GuessTheLetter(solution);
	}

	printf("\n\n--------------------------------------------------------------------------------\n");
	printf("Thanks for playing.\n\n");

	//close file pointer
	fclose(inPtr);

	return 0;
}

//this function provides instructions to the user on how to play the game
void LetterGuessRules()
{
	printf("Welcome to the Letter Guessing Game.\n\n");
	printf("First, enter the number of games you would like to play (1-10).\n");
	printf("For each game, you will have 5 chances to guess the correct letter.\n\n");
	
}

//Gets the numberof games the user wants to play.
int NumGames()
{
	int games;
	printf("Please enter the number of games you would like to play: ");
	scanf("%d", &games);
	return games;
}

//this function prompts the player to make a guess and returns that guess
//this function is called from inside the GuessTheLetter( ) function described above
char GetTheGuess()
{
	char guess;
	printf("\n\nPlease enter a guess: ");
	scanf(" %c", &guess);
	return guess;
}

//this function takes two arguments, the guess from the player
//and the solution letter from the file.
//The function returns 1 if the guess matches the solution and returns a 0 if they do not match
//This function also lets the user know if the guess comes alphabetically before or after the answer
int CompareLetters(char guess, char solution)
{
	if (guess == solution)
	{
		return 1;
	}
	else if (guess > solution)
	{
		printf("\nThe correct letter comes before your guess.");
		printf("\n               ---------------------------------------------");
		return 0;
	}
	else
	{
		printf("\nThe correct letter comes after your guess.");
		printf("\n               ---------------------------------------------");
		return 0;
	}
}


//this function runs one game. 
//input: character from the file, void return type
//all other functions to Play one round of a game 
//are called from within the GuessTheLetter function
//this function lets the user know if they have won or lost the game
void GuessTheLetter(char solution)
{
	int win = 0;
	int numGuesses = 0;
	//declare additional variables 
	char guess;
	//extra varialble to tell the user what guess they are on.
	int guessnum = 0;

	while (numGuesses < MAXGUESSES && win == 0)
	{	
		printf(" \n\nYou are on guess number %d.", guessnum + 1);
		//get a guess from the user  by calling the GetTheGuess function
		guess = GetTheGuess();
		//change the guess to lowercase
		guess = tolower(guess);
		//win = call the function to compare the guess with the solution
		win = CompareLetters(guess, solution);
		guessnum = guessnum + 1;
		//count the number of guesses so far
		numGuesses++;

	}
	//use conditions to let the user know if they won or lost the round of the game
	if (win == 1)
	{
		printf("\n               ---------------------------------------------");
		printf("\n\nCongratulations! You guessed correctly.");
	}
	else
	{
		printf("\n\nYou lost; the correct letter was %c.\nBetter luck next time.", solution);
	}
}