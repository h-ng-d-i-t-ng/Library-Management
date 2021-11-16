#include<iostream>   /////////////////////////////////////////
#include<iomanip>    /////////////////////////////////////////
#include<fstream>    /////////////////////////////////////////
#include<conio.h>    //////////////////Header/////////////////
#include<string.h>   //////////////////Files//////////////////
#include<stdio.h>    /////////////////////////////////////////
#include <cstdlib>   /////////////////////////////////////////
#include <windows.h> /////////////////////////////////////////
using namespace std;

/*class Book
{
	private:
		int nId, nPubYear;
		string sTitle, sAuthor, sCategory;
	public:
		//setters - assigning user value to private variables
		void setTitle(string a){sTitle = a;}
		void setAuthor(string c){sAuthor = c;}
		void setEdition(string d){edition = d;}
		void setPublication(string e){publication = e;}
		//getters - getting the values from private variables
		string getIsbn(){return isbn;}
		string getTitle(){return title;}
		string getAuthor(){return author;}
		string getEdition(){return edition;}
		string getPublication(){return publication;}
};*/

//counter for Book array
//int g_nCounter = 0;

//////////////////////////////////////////////////
/////////////////GOTOXY //////////////////////////
//////////////////////////////////////////////////
void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//////////////////////////////////////
/////////////Main Menu////////////////
/////////////////////////////////////
int main()
{
	//char ch1;
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
		 	case 1: //add(); break;
         
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