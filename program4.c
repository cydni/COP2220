//Cydni Turner
//COP 2220
//December 7, 2016
//Structs

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 50

typedef struct
{
	char bname[40];
	char aname[20];
	double price;
	double rating;
	int id;
	int pages;
}book;

//Function Prototypes

//Greets the user
void Greeting();

//hardcodes six entries
void HardCodeSix(book[]);

//runs the menu and gets the user choice
void Menu(char*);

//prints the contents of the list onto the screen
void PrintList(book[], int);

//prints a report to a file
void PrintReport(book[], int);

//adds an item to the list
void Add(book[], int);

//removes an item from the list
//takes three arguments, the list, the number of items and the location
void Delete(book[], int, int);

//updates the sale price
//takes three arguments, the list, the number of items and the location
void UpdatePrice(book[], int, int);

//searches the list by id and returns the index, if there is a match or returns -1
//three arguments: list, number of items, id
int Search(book[], int, int);

//displays the ids in the list, gets the id from the user and returns it
int DisplayIDs(book[], int);



int main()
{	
	//Declare all necessary variables
	char choice;
	book list[SIZE];
	int count;
	int loc, id;

	//Greet user
	Greeting();

	//Make hardode and update count
	HardCodeSix(list);
	count = 6;

	//Get a letter for choice
	Menu(&choice);

	//Set up main loop
	while (choice != 'q'&&choice != 'Q')
	{
		switch (choice) {
		case 'P':
		case 'p':
			//Call PrintList function
			PrintList(list, count);
			//Update choice
			Menu(&choice);
			break;
		case 'A':
		case 'a':
			printf("\n********************\n\n");
			//Call add function to input a new book into array
			Add(list, count);
			//Update counting variable
			count++;
			//Update choice
			Menu(&choice);
			break;
		case 'C':
		case 'c':
			//'Clear' array by resetting count
			count = 0;
			printf("\n********************\n\n");
			printf("All records have been cleared.\n");
			printf("-----------------------------\n\n");
			//Update choice
			Menu(&choice);
			break;
		case 'S':
		case 's':
			//Call function to print to file
			PrintReport(list, count);
			printf("\n********************\n\n");
			printf("Inventory file report.txt has been created.\n");
			printf("-----------------------------\n\n");
			//Update choice
			Menu(&choice);
			break;
		case 'D':
		case 'd':
			//Formatting
			printf("\n********************\n\n");
			//Call all necessary functions
			id = DisplayIDs(list, count);
			loc = Search(list, count, id);
			
			//Set up condition statements
			if (loc != -1) 
			{
				Delete(list, count, loc);
				count--;
				printf("\n********************\n");
				printf("\nBook %d has been deleted from invnetory.\n", id);
			}
			else
			{
				printf("\n********************\n");
				printf("ID not in inventory.\n");
	
			}
			printf("-----------------------------\n\n");
			//Update choice
			Menu(&choice);
			break;
		case 'U':
		case 'u':
			printf("\n********************\n\n");
			UpdatePrice(list, count, loc);
			//Update choice
			Menu(&choice);
			break;
		case 'Q':
		case 'q':
			printf("Q");
			//Update choice
			Menu(&choice);
			break;
		default:
			printf("Not Recognized.");
			//Update choice
			Menu(&choice);
		}
	}

	//Say Goodbye
	printf("\n********************\n");
	printf("\nGoodbye.\n\n");

	return 0;
}

//Function Definitions

//Greets the user
void Greeting()
{
	printf("Each book has a unique id.\n\n");
	printf("Please follow the prompts in the menu.\n\n");
	printf("_______________________________________\n\n");
}


//hardcodes six entries
void HardCodeSix(book list[])
{
	//Book 1
	strcpy(list[0].bname, "Divergent");
	strcpy(list[0].aname, "Veronica_Roth");
	list[0].price = 6.99;
	list[0].rating = 6.7;
	list[0].pages = 487;
	list[0].id = 463;

	//Book 2
	strcpy(list[1].bname, "The_Hunger_Games");
	strcpy(list[1].aname, "Suzanne_Collins");
	list[1].price = 7.99;
	list[1].rating = 7.3;
	list[1].pages = 374;
	list[1].id = 512;

	//Book 3
	strcpy(list[2].bname, "Inkheart");
	strcpy(list[2].aname, "Cornelia_Funke");
	list[2].price = 10.99;
	list[2].rating = 6.1;
	list[2].pages = 560;
	list[2].id = 257;

	//Book 4
	strcpy(list[3].bname, "The_School_For_Good_and_Evil");
	strcpy(list[3].aname, "Soman_Chainani");
	list[3].price = 8.99;
	list[3].rating = 8.5;
	list[3].pages = 488;
	list[3].id = 635;

	//Book 5
	strcpy(list[4].bname, "Silver");
	strcpy(list[4].aname, "Chris_Wooding");
	list[4].price = 10.99;
	list[4].rating = 7.6;
	list[4].pages = 313;
	list[4].id = 441;

	//Book 6
	strcpy(list[5].bname, "The_Book_Thief");
	strcpy(list[5].aname, "Markus_Zusak");
	list[5].price = 8.99;
	list[5].rating = 8.4;
	list[5].pages = 553;
	list[5].id = 583;

}

//runs the menu and gets the user choice
void Menu(char *choice)
{
	//Display menu choices
	printf("Select an option:\n\n");
	printf("P....Print the inventory list onto the screen\n\n");
	printf("A....Add a new book entry\n\n");
	printf("C....Clear all records\n\n");
	printf("S....Create a current report\n\n");
	printf("D....Delete a book from the inventory\n\n");
	printf("U....Update the price of a book\n\n");
	printf("Q....Quit\n\n\n");

	//Get choice
	printf("--Choice: ");
	scanf(" %c", choice);
}

//prints the contents of the list onto the screen
void PrintList(book list[], int count) 
{
	int i;

	printf("\n********************\n\n");
	
	//Set up if condition and printing loop
	if (count == 0)
	{
		printf("Empty inventory.\n");
	}
	for (i = 0; i < count; i++)
	{
		printf("--Book %d:\n", i+1);
		printf("ID: %d\n", list[i].id);
		printf("Title: %s\n", list[i].bname);
		printf("Author: %s\n", list[i].aname);
		printf("Price: $%.2f\n", list[i].price);
		printf("Pages: %d\n", list[i].pages);
		printf("Rating: %.2f/10\n\n", list[i].rating);
	}
	printf("-----------------------------\n\n");
}

//prints a report to a file
void PrintReport(book list[], int count)
{
	int i;
	FILE *outptr;
	//Open output file
	outptr = fopen("report.txt", "w");

	//Setup if condiditon and loop
	if (count == 0)
	{
		fprintf(outptr, "Inventory is empty.");
	}
	
	for (i = 0; i < count; i++)
	{
		fprintf(outptr, "--Book %d:\n", i + 1);
		fprintf(outptr, "ID: %d\n", list[i].id);
		fprintf(outptr, "Title: %s\n", list[i].bname);
		fprintf(outptr, "Author: %s\n", list[i].aname);
		fprintf(outptr, "Price: $%.2f\n", list[i].price);
		fprintf(outptr, "Pages: %d\n", list[i].pages);
		fprintf(outptr, "Rating: %.2f/10\n\n", list[i].rating);
	}

	//Close file
	fclose(outptr);
}

//adds an item to the list
void Add(book list[], int count)
{
	printf("\nEnter ID: ");
	scanf("%d", &list[count].id);
	printf("\nEnter title: ");
	scanf("%s", list[count].bname);
	printf("\nEnter author: ");
	scanf("%s", list[count].aname);
	printf("\nEnter price: $");
	scanf("%lf", &list[count].price);
	printf("\nEnter page count: ");
	scanf("%d", &list[count].pages);
	printf("\nEnter rating: ");
	scanf("%lf", &list[count].rating);

	//Formatting
	printf("-----------------------------\n\n");
}

//removes an item from the list
//takes three arguments, the list, the number of items and the location
void Delete(book list[], int count, int loc)
{
	list[loc] = list[count - 1];

}

//displays the ids in the list, gets the id from the user and returns it
int DisplayIDs(book list[], int count)
{
	int i, id;

	for (i = 0; i < count; i++)
	{
		printf("%d - %s\n", list[i].id, list[i].bname);
		
	}

	printf("\nEnter deletion selection: ");
	scanf("%d", &id);
	return id;
}

//searches the list by id and returns the index, if there is a match or returns -1
//three arguments: list, number of items, id
int Search(book list[], int count, int id)
{
	int i;
	for (i = 0; i < count; i++)
	{
		if (id == list[i].id)
		{
			return i;
		}
	}
	return -1;
}

//updates the sale price
//takes three arguments, the list, the number of items and the location
void UpdatePrice(book list[], int count, int loc)
{
	int i, id;

	printf("Here are the ID number and the book titles:\n\n");

	for (i = 0; i < count; i++)
	{
		printf("%d - %s\n", list[i].id, list[i].bname);

	}

	//Get id
	printf("\n\nEnter the ID number: ");
	scanf("%d", &id);
	
	//Get location
	for (i = 0; i < count; i++)
	{
		if (id == list[i].id)
		{
			loc = i;
		}
		
	}

	//Change price
	printf("\n* * The current price of book %d is $%.2f * *\n", id, list[loc].price);
	
	printf("\nEnter new price: $");
	scanf("%lf", &list[loc].price);

	//Inform user
	printf("\n********************\n\n");
	printf("Book %d price has been changed to $%.2lf.\n",id, list[loc].price);

	printf("-----------------------------\n\n");
	



}

/*int i, a, id;

//Part 1 - Get selection
for (i = 0; i < count; i++)
{
	printf("%d - %s\n", list[i].id, list[i].bname);

}
printf("\nEnter selection: ");
scanf("%d", &id);

//Part 2 - Get location
for (a = 0; a < count; a++)
{
	if (id == list[i].id)
	{
		loc = i;
	}

}


//Part 3 -Change price
printf("Input new price for book: ");
scanf("%lf", &list[loc].price);

//Part 4 - Inform user
printf("Price of book %d has been changed.\n", id);*/
