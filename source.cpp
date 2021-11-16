#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h> 
#include<string.h>
#include<stdio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;


/************************************************
 * 					GLOBAL VARIABLE				*
 ************************************************/
//counter for Book array
int g_nCounter = 0;
Book books[10];

//function for incrementing counter
void increment(int a){
	a++;
	g_nCounter=a;
}

//function for decrementing counter
void decrement(int a){
	a--;
	g_nCounter=a;
}

/****************CLASS BOOK*********************/
class Book
{
	private:
		int nPubYear;
		string sId, sTitle, sAuthor, sCategory;
	public:
		//setters - assigning user value to private variables
		void setId(string a){sId = a;}
		void setTitle(string b){sTitle = b;}
		void setAuthor(string c){sAuthor = c;}
		void setCategory(string d){sCategory = d;}
		void setPublication(string e){nPubYear = e;}

		//getters - getting the values from private variables
		string getId(){return sId;}
		string getTitle(){return sTitle;}
		string getAuthor(){return sAuthor;}
		string getCategory(){return sCategory;}
		int getPublication(){return nPubYear;}

		//initializing functions with counter as parameter
		void addBook(int g_nCounter);
		void deleteBook(int g_nCounter);
		void editBook(int g_nCounter);
		void searchBook(int g_nCounter);
		void viewAllBooks(int g_nCounter);
		void quit();
};

void Book::addBook(int g_nCounter)
{
	cout<<"ADD BOOK\n\n";
	if(g_nCounter<10){
		cout<<"Enter ID: "; getline(cin,sId);
		cout<<"Enter Title: "; getline(cin,sTitle);
		cout<<"Enter Author: "; getline(cin,sAuthor);
		cout<<"Enter Edition: "; getline(cin,sCategory);
		cout<<"Enter Publication: "; cin >> nPubYear;
		books[g_nCounter].setId(sId);
		//assigning the values entered to book object
		books[g_nCounter].setTitle(sTitle);
		books[g_nCounter].setAuthor(sAuthor);
		books[g_nCounter].setCategory(sCategory);
		books[g_nCounter].setPublication(nPubYear);	
		increment(g_nCounter);	//calling function to increment counter
		cout<<"\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	else{
		cout<<"YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TOBE ADDED!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
}

/**************END CLASS BOOK*****************************/
=======

//counter for Book array
//int g_nCounter = 0;
>>>>>>> Stashed changes

/************************************************
 * 					GOTOXY 						*
 ************************************************/
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/************************************************
 * 					MAIN MENU 					*
 ************************************************/
int main()
{
	Book h;
	while (1)
    {
		system("cls");
	   
		cout << setw( 25 ) << "-------------" << endl

          << setw( 25 ) << "| MAIN MENU |" << endl

          << setw( 25 ) << "-------------" << endl << endl

          << setw( 52 )

          << "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << setw( 25 ) << "( 1 ) Add Book" << endl << endl

          << setw( 31 ) << "( 2 ) Sort all Books" << endl << endl

          << setw( 33 ) << "( 3 ) Search all Books" << endl << endl

          << setw( 33 ) << "( 4 ) Diplay all Books" << endl << endl

          << setw( 30 ) << "( 5 ) Delete a Book" << endl << endl

          << setw( 40 ) << "( 6 ) Update Book Information" << endl << endl
         
		  << setw( 21 ) << "( 0 ) Quit" << endl << endl
		  <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,21);
	     
		switch(getche())
		{
		 	case 1: b.addBook(); break;
         
		 	case 2: //display(); break;
         
		 	case 3: //search(); break;
         
		 	case 4: //del(); break;
		 
		 	case 5: //sort(); break;
         
		 	case 6: //edit(); break;
		 
		 	case 0: //exit(0); break;
         
		 	default:
				puts("\n\n \t\tSelect only from the given menu.....\n \t\tpress enter to to go to main menu......");
				getch();
       } //end switch
     }//end while
    
	getch();
}