//Cydni Turner
//October 30 2016
//COP 2220
//Program 2 - Pointers

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

//Displays the list of apps available
//Prompts for the user's selection and sets the value of the section
void DisplayApps(char *selectionPtr);

//sets the cost of the item based on value stored in purchase
void SetCost(char selection, double *costPtr);

//Displays the codes for the user to input money - gets user input amounts
//Compares the int codes and updates the deposit amount
void PaymentOptions(double *depositPtr, double cost);

//compares the amount the user has in deposits to the price of app selected.
//It returns 1 if the amount is enough to cover the cost, 0 if there is not enough.
int Compare(double deposit, double choiceCost);

//uses PaymentOptions function to display and collect dollar amounts from the user
//uses Compare function to keep comparing the added deposited amount to the item cost.
void Pay(double *depositPtr, double choiceCost);

//calculates the amount of leftover from your deposits
void GetChange(double *depositPtr, double choiceCost);

//Asks the user if they want another app
void DoItAgain(char *quitPtr);

//BONUS FUNCION
//takes an array of all the purchase transaction costs
//and the number of items purchased
//and displays the information onto the screen
void DisplayPurchases(double priceList[], int num);


int main()
{
	char quit, selection;
	double cost, bank = 0.0, price[20];
	int count = 0;
	//greet
	printf("Welcome to the App Store.\n\n");
	printf("You have $%.2f in your bank.\n", bank);

	do {
		//Show app choices
		DisplayApps(&selection);
		//Set the cost of the chosen app
		SetCost(selection, &cost);
		//Pay for the app
		price[count] = cost;
		count++;
		Pay(&bank, cost);
		//Calculate the money left over in the bank
		printf("\nYou have purchased %c.", selection);
		GetChange(&bank, cost);
		//Ask user if they'd like to buy another app
		DoItAgain(&quit);
	} while (quit == 'Y' || quit == 'y');
	printf("\n                __________________________________________________");
	DisplayPurchases(price, count);
	printf("                __________________________________________________");
	printf("\n\nThank you for using the App Store. Enjoy your purchase(s).\n\n");
	

	return 0;
}

//Displays the list of apps available
//Prompts for the user's selection and sets the value of the section
void DisplayApps(char *selectionPtr)
{
	printf("\n                __________________________________________________");
	printf("\n\nHere are the choices:\n\n");
	printf("C -- Clown Punching                                 $299.99\n");
	printf("V -- Virtual Snow Globe                             $349.99\n");
	printf("R -- Remote PC                                      $999.99\n");
	printf("G -- Grocery List Helper                            $2.99\n");
	printf("M -- Mobile Cam Viewer                              $89.99\n");
	printf("\nPlease enter a selection: ");
	scanf(" %c", selectionPtr);
}

//sets the cost of the item based on value stored in purchase
void SetCost(char selection, double *costPtr)
{
	if (selection == 'c' || selection == 'C')
	{
		*costPtr = 299.99;
	}
	else if (selection == 'v' || selection == 'V')
	{
		*costPtr = 349.99;
	}
	else if (selection == 'r' || selection == 'R')
	{
		*costPtr = 999.99;
	}
	else if (selection == 'g' || selection == 'G')
	{
		*costPtr = 2.99;
	}
	else if (selection == 'm' || selection == 'M')
	{
		*costPtr = 89.99;
	}
	else
	{
		printf("\nInvalid.");
	}
}

//Displays the codes for the user to input money - gets user input amounts
//Compares the int codes and updates the deposit amount
void PaymentOptions(double *depositPtr, double cost)
{ 
	int num;
	printf("\n                __________________________________________________");
	printf("\n\nYou do not have enough money in your bank.\n\n");
	printf("The item costs $%.2lf.", cost);
	printf(" Please credit your money by selection.\n\n");
	printf("1----$1000.00\n");
	printf("2----$500.00\n");
	printf("3----$100.00\n");
	printf("4----$10.00\n");
	printf("\nSelection: ");
	scanf("%d", &num);
	if (num == 1)
	{
		*depositPtr += 1000.00;
	}
	else if (num == 2)
	{
		*depositPtr += 500.00;
	}
	else if (num == 3)
	{
		*depositPtr += 100.00;
	}
	else if (num == 4)
	{
		*depositPtr += 10.00;
	}
	else
	{
		printf("\nInvalid");
	}
}

//compares the amount the user has in deposits to the price of app selected.
//It returns 1 if the amount is enough to cover the cost, 0 if there is not enough.
int Compare(double deposit, double choiceCost)
{
	if (choiceCost <= deposit)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//uses PaymentOptions function to display and collect dollar amounts from the user
//uses Compare function to keep comparing the added deposited amount to the item cost.
void Pay(double *depositPtr, double choiceCost)
{
	int enough;
	enough = Compare(*depositPtr, choiceCost);
	while (enough == 0)
	{
		PaymentOptions(depositPtr, choiceCost);
		enough = Compare(*depositPtr, choiceCost);
		
	}
}

//calculates the amount of leftover from your deposits
void GetChange(double *depositPtr, double choiceCost)
{
	*depositPtr = *depositPtr - choiceCost;
	printf("\n                __________________________________________________");
	printf("\n\nYou have $%.2lf left in your bank.", *depositPtr);

}

//Asks the user if they want another app
void DoItAgain(char *quitPtr)
{
	printf("\n\nWould you like to make another purchase? Y or N: ");
	scanf(" %c", quitPtr);
}


//BONUS FUNCION
//takes an array of all the purchase transaction costs
//and the number of items purchased
//and displays the information onto the screen
void DisplayPurchases(double priceList[], int num)
{
	int i;
	printf("\n\nYou made %d purchase(s) as follows:\n\n", num);
	for (i = 0; i < num; i++)
	{
		printf("%.2lf\n", priceList[i]);
	}

}