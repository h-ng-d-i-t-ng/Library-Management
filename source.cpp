#include <iostream>     //input, output
#include <iomanip>      //for setw(): stands for set width
#include <vector>       //for vector: arrays that can change their size during runtime
#include <fstream>      //for read, write file
#include <conio.h>      //for getch(): Get char entry from the console
#include <cstdlib>      //for system("cls"): clear screen
#include <windows.h>    //for graphics, gotoxy
#include <time.h>       //for sleep(): delay
using namespace std;

//////////////////////////////////////////////////
//				   	GOTOXY						//
//////////////////////////////////////////////////
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//////////////////////////////////////////////////
//   			SET FONT COLOR					//
//////////////////////////////////////////////////
void SET_COLOR(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}
/***************************CLASS BOOK***************************/
class Book
{
	protected:
		int nPubYear;
		string sId, sTitle, sAuthor, sCategory;
	public:
		//get variable from protected
		string getid() { return sId; }
		string getTitle() { return sTitle; }
		string getAuthor() { return sAuthor; }
		string getCategory() { return sCategory; }
		int getYear() { return nPubYear; }

		//Ham nhap, xuat 1 cuon
		virtual void Add();
		virtual void show();
};

void Book::Add()
{
	SET_COLOR(1);
	fflush(stdin);
	cout << "\n\nEnter ID: ";
	fflush(stdin);
	getline(cin,sId);
	cout << "\nEnter Title: ";
	fflush(stdin);
	getline(cin,sTitle);
	cout << "\nEnter Author: ";
	fflush(stdin);
	getline(cin,sAuthor);
	cout << "\nEnter Category: ";
	fflush(stdin);
	getline(cin,sCategory);
	cout << "\nEnter year of publishcation: ";
	cin >> nPubYear;
}

void Book::show()
{
	SET_COLOR(1);
	cout << setw(10) << sId << setw(30) << sTitle << setw(30) << sAuthor << setw(30) << sCategory << setw(30) << nPubYear << endl;
}
/**********************CLASS BOOK MANAGEMENT*********************/
class bookManager
{
	private:
		vector<Book *> book;
	public:
		//Ham nhap danh sach, xuat danh sach
		void addBook();
		void displayBook();

		//Sort
		void sortName();

		//Search
		void searchbId();
		void searchbTitle(string title);
		void searchbAuthor(string author);
		void searchbPub(string pyear);
		void searchbCate(string cate);

		//Sort
		void SbyId();
		void SbyTitle();
		void SbyAuthor();
		void SbyCategory();
		//void SbyPubYear();
		void menuSort();

		//Delete
		void dbyId();
		void dbyTitle();
		void dbyCategory();
		void dbyAuthor();
		void dbyPubYear();
		void menuDelete();
};

void bookManager::addBook()
{
	system("cls");
	Book *B;
	int n;
	char ch;
	SET_COLOR(4);
	do
	{
		system("cls");
		cout << "Enter the quantity of book: "; cin >> n;
		for (int i = 0; i < n; i++)
		{
			system("cls");
			cout<<endl;
			cout<< "In ADD function\n";
			cout << "Book no." << i+1 << endl;
			B = new Book;
			B->Add();
			book.push_back(B);
			cout << endl;
			SET_COLOR(5);
			cout << "\n\n\nBook Created...";
			Sleep(1000);
			cout << endl;
		}
		cout<<"\nDo you want to add more books? [y/n]";
		ch=getch();
	} while(ch!='n'&& ch!='N');
}

void bookManager::displayBook()
{
		system("cls");
		SET_COLOR(4);
		cout<< "In display function\n";
		cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		SET_COLOR(5);
		cout<<setw(10)<<"\"Book ID\""<<setw(50)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Year of Publication\""<<endl;
		SET_COLOR(4);
		cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		for(unsigned int i = 0; i< this -> book.size(); i++)
		{
			SET_COLOR(2);
			this->book.at(i)->show();
			cout<<"__________"<<"__________________________________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		}
	cout << "Press enter to goto main menu.....";
	getch();
}

void bookManager::SbyId()
{
	for (unsigned int i = 0; i < book.size() - 1; i++)
    {
        for (unsigned int j =book.size() - 1; j > i; j--)
        {
            char *name1 = new char[book[j]->getid().length()];
            strcpy(name1, book[j]->getid().c_str());
            char *name2 = new char[book[j - 1]->getid().length()];
            strcpy(name2, book[j - 1]->getid().c_str());
            if (strcmp(name1, name2) < 0)
            {
                Book *tmp;
                tmp = book[j];
                book[j] = book[j - 1];
                book[j - 1] = tmp;
            }
        }
    }
	displayBook();
}

void bookManager::SbyTitle()
{
	for (unsigned int i = 0; i < book.size() - 1; i++)
    {
        for (unsigned int j =book.size() - 1; j > i; j--)
        {
            char *name1 = new char[book[j]->getTitle().length()];
            strcpy(name1, book[j]->getTitle().c_str());
            char *name2 = new char[book[j - 1]->getTitle().length()];
            strcpy(name2, book[j - 1]->getTitle().c_str());
            if (strcmp(name1, name2) < 0)
            {
                Book *tmp;
                tmp = book[j];
                book[j] = book[j - 1];
                book[j - 1] = tmp;
            }
        }
    }
	displayBook();
}

void bookManager::SbyAuthor()
{
	for (unsigned int i = 0; i < book.size() - 1; i++)
    {
        for (unsigned int j =book.size() - 1; j > i; j--)
        {
            char *name1 = new char[book[j]->getAuthor().length()];
            strcpy(name1, book[j]->getAuthor().c_str());
            char *name2 = new char[book[j - 1]->getAuthor().length()];
            strcpy(name2, book[j - 1]->getAuthor().c_str());
            if (strcmp(name1, name2) < 0)
            {
                Book *tmp;
                tmp = book[j];
                book[j] = book[j - 1];
                book[j - 1] = tmp;
            }
        }
    }
	displayBook();
}

void bookManager::SbyCategory()
{
	for (unsigned int i = 0; i < book.size() - 1; i++)
    {
        for (unsigned int j = book.size() - 1; j > i; j--)
        {
            char *name1 = new char[book[j]->getCategory().length()];
            strcpy(name1, book[j]->getCategory().c_str());
            char *name2 = new char[book[j - 1]->getCategory().length()];
            strcpy(name2, book[j - 1]->getCategory().c_str());
            if (strcmp(name1, name2) < 0)
            {
                Book *tmp;
                tmp = book[j];
                book[j] = book[j - 1];
                book[j - 1] = tmp;
            }
        }
	}
	displayBook();
}

void bookManager::menuSort()
{
		system("cls");
	   
	   	cout <<setw( 27 )<< "In Sort Function"<<endl
          << setw( 52 )<< "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << setw( 29 ) << "( N ) Sort by name" << endl << endl

          << setw( 27 ) << "( I ) Sort by Id" << endl << endl
          
          << setw( 36 ) << "( T ) Sort by author name" << endl << endl

          << setw( 33 ) << "( C ) Sort by Category" << endl << endl

          << setw( 41 ) << "( Y ) Sort by Publication Year" << endl << endl
          
		  <<setw( 32 ) << "\n\tEnter Option      [ ]" << endl << endl;
			gotoxy(27,15);
		//	cin>>ch1;
	     
	   switch(getche())
       {
			case 'n':
			case 'N':SbyTitle(); break;
			
			case 'i':
			case 'I': SbyId(); break;
			
			case 't':
			case 'T': SbyAuthor(); break;
			
			case 'c':
			case 'C': SbyCategory(); break;

			//case 'y':
			//case 'Y': SbyPubYear(); break;
			
			default:
			puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
			getch();
			menuSort();
			getch();
       }
}

void bookManager::dbyId()
{
int found = 0;
            string del;
            cout << "  \n\n\nEnter the ID you want to delete: " << endl;
            fflush(stdin);
            getline(cin, del);
            for (unsigned int i = 0; i <= book.size() - 1; i++)
            {
                if (del == book[i]->getid())
                {
                    found = 1;
                   
                        book.erase(book.begin() + i);
                       
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID not Found !!!\n\n"<< endl;
            }
		displayBook();
}

void bookManager::dbyTitle()
{
	int found = 0;
            string del;
            cout << "  \n\n\n Enter the Title you want to delete : " << endl;
            fflush(stdin);
            getline(cin, del);
            for (unsigned int i = 0; i <= book.size() - 1; i++)
            {
                if (del == book[i]->getTitle())
                {
                    found = 1;
                   
                        book.erase(book.begin() + i);
                       
                    break;
                }
            }
            if (found == 0){
                cout << "\n  Title not Found!!!\n\n"<< endl;
            }
		displayBook();
}

void bookManager::dbyCategory()
{
	int found = 0;
            string del;
            cout << "  \n\n\n Enter the Category you want to delete : " << endl;
            fflush(stdin);
            getline(cin, del);
            for (unsigned int i = 0; i <= book.size() - 1; i++)
            {
                if (del == book[i]->getCategory())
                {
                    found = 1;
                   
                        book.erase(book.begin() + i);
                       
                    break;
                }
            }
            if (found == 0){
                cout << "\n  Category not Found!!!\n\n"<< endl;
            }
		displayBook();
}

void bookManager::dbyAuthor()
{
	int found = 0;
            string del;
            cout << "  \n\n\n Enter the Author you want to delete : " << endl;
            fflush(stdin);
            getline(cin, del);
            for (unsigned int i = 0; i <= book.size() - 1; i++)
            {
                if (del == book[i]->getAuthor())
                {
                    found = 1;
                   
                        book.erase(book.begin() + i);
                       
                    break;
                }
            }
            if (found == 0){
                cout << "\n  Author not Found !!!\n\n"<< endl;
            }
		displayBook();
}

void bookManager::dbyPubYear()
{
	int found = 0;
            int del;
            cout << "  \n\n\n Enter the Author you want to delete : " << endl;
            cin >> del;
            for (unsigned int i = 0; i <= book.size() - 1; i++)
            {
                if (del == book[i]->getYear())
                {
                    found = 1;
                   
                        book.erase(book.begin() + i);
                       
                    break;
                }
            }
            if (found == 0){
                cout << "\n Year of Publication  not Found !!!\n\n"<< endl;
            }
		displayBook();
}

void bookManager::menuDelete()
{
	system("cls");
	   
	cout <<setw( 29 )<< "In Delete Function"<<endl
         << setw( 52 )<< "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

          << setw( 31 ) << "( N ) Delete by name" << endl << endl

          << setw( 29 ) << "( I ) Delete by Id" << endl << endl
          
          << setw( 38 ) << "( A ) Delete by author name" << endl << endl

          << setw( 35 ) << "( C ) Delete by Category" << endl << endl

          << setw( 43 ) << "( Y ) Delete by Publication Year" << endl << endl
          
		  <<setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,14);
		switch(getche())
       	{
			case 'n':
			case 'N': dbyTitle(); break;
			
			case 'i':
			case 'I': dbyId(); break;
			
			case 'a':
			case 'A': dbyAuthor(); break;
			
			case 'c':
			case 'C':dbyCategory(); break;
			
			case 'y':
			case 'Y':dbyPubYear(); break;
			
			default:
			puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
			getch();
			menuDelete();
			getch();
       }
}
/***************************************************************/
//////////////////////////////////////////////////
//   				MAIN MENU		 			//
//////////////////////////////////////////////////
int main()
{
	bookManager b;
	system("color Bf");
	while (1)
    {
		system("cls");
	   	SET_COLOR(4);
		cout << setw( 25 ) << "-------------" << endl

          << setw( 25 ) << "| MAIN MENU |" << endl

          << setw( 25 ) << "-------------" << endl << endl;
		  SET_COLOR(6);
          cout << setw( 52 )

          << "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl;

		SET_COLOR(5);

    cout  << setw( 25 ) << "( A ) Add Book" << endl << endl

          << setw( 31 ) << "( O ) Sort all Books" << endl << endl

          << setw( 33 ) << "( S ) Search all Books" << endl << endl

          << setw( 33 ) << "( D ) Diplay all Books" << endl << endl

          << setw( 30 ) << "( T ) Delete a Book" << endl << endl

          << setw( 40 ) << "( M ) Update Book Information" << endl << endl
         
		  << setw( 21 ) << "( Q ) Quit" << endl << endl;
		  SET_COLOR(4);
	cout  << setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,21);
	     
		switch(getche())
		{
			case 'a':
		 	case 'A': b.addBook(); break;
         
			case 'd':
		 	case 'D': b.displayBook(); break;
         
		 	//case 'S':
		 	//case 's':search();break;
         
		 	case 't':
		 	case 'T': b.menuDelete(); break;
		 
		 	case 'O':
		 	case 'o': b.menuSort(); break;
         
		 	//case 'm':
		 	//case 'M':modify();break;
		 
		 	case 'q':
		 	case 'Q':exit(0);break;
         
		 	default:
				puts("\n\n \t\tSelect only from the given menu.....\n \t\tpress enter to to go to main menu......");
				getch();
       } //end switch
     }//end while
    
	getch();

	system("pause");
	return 0;
}
