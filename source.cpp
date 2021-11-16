#include<iostream>
#include<iomanip>  
#include<fstream>  
#include<conio.h>  
#include<string.h>
#include<stdio.h>   
#include <cstdlib> 
#include <windows.h>
using namespace std;

/***************************CLASS BOOK***************************/
class Book
{
	private:
		int nPubYear;
		string sId, sTitle, sAuthor, sCategory;
	public:
		void addBook();
		void displayBook();
};

void Book::addBook()
{
	int n;
	char ch;
	cout << "Enter the quantity of books you want to add: "; cin >> n;
	do{
	for (int i = 0; i < n; i++)
	{
		system("cls");
		cout<<endl;
		cout<<"ADD BOOK\n\n";
		cout<<"Enter ID: ";
		getline(cin,sId);
		cout<<"Enter Title: ";
		getline(cin,sTitle);
		cout<<"Enter sAuthor: ";
		getline(cin,sAuthor);
		cout<<"Enter Category: ";
		getline(cin,sCategory);
		cout<<"Enter Publication: ";
		cin >> nPubYear;
        cout<<"\n\n\nBook Created..";
	}
		cout<<"Do you want to add more books? [y/n]";
		ch = getch();
	} while(ch!='n'&& ch!='N');
}

void Book::displayBook()
{
	system("cls");
		cout<< "In display function\n";
		cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Year of Publication\"" << endl;
		cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		for(int i = 0; i < n; i++)
			{
				cout<<setw(10)<<sId<<setw(50)<<sTitle<<setw(30)<<sAuthor<<setw(30)<<sCategory<<setw(30)<<nPubYear << endl;
				cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
			}
			cout<<"Press enter to go to main menu.....";
			getch();
}
/*************************CLASS STUDENT*************************/
/*class Student
{

};*/
/***************************************************************/
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
	Book book;
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
		 	case 1: book.addBook(); break;
         
		 	case 2: book.displayBook(); break;
         
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