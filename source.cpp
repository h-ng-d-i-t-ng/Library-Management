#include <iostream>     //input, output
#include <iomanip>      //for setw(): stands for set width
#include <vector>       //for vector: arrays that can change their size during runtime
#include <fstream>      //for read, write file
#include <conio.h>      //for getch(): Get char entry from the console
#include <cstdlib>      //for system("cls"): clear screen
#include <windows.h>    //for graphics, gotoxy
#include <time.h>       //for sleep(): delay
#include<string>        //for work with string
using namespace std;

//////////////////////////////////////////////////
//                       GOTOXY                        //
//////////////////////////////////////////////////
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//////////////////////////////////////////////////
//               SET FONT COLOR                    //
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

class Book
{
	protected:
		int nPubyear;
		char cId[20], cTitle[100], cAuthor[100], cCategory[100];
	public:
	virtual void Add()
	{
		cout << "\nEnter ID: ";
		fflush(stdin);
		getline(cin,cId);
		cout << "\nEnter Title: ";
		fflush(stdin);
		getline(cin,cTitle);
		cout << "\nEnter Author: ";
		fflush(stdin);
		getline(cin,cAuthor);
		cout << "\nEnter Category: ";
		fflush(stdin);
		getline(cin,cCategory);
		cout << "\nEnter year of publishcation: ";
		cin >> nPubyear;
	}

	virtual void show()
	{
		cout << setw(10) << cId << setw(30) << cTitle << setw(30) << cAuthor << setw(30) << cCategory << setw(20) << nPubyear << endl ;
		cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	}
};

class bookManager
{
	private:
		vector<Book *> book; 
	public:
		void addBook()
		{
			Book *B;
			int n;
			cout << "Enter the quantity of book: "; cin >> n;
			for(int i = 0; i < n; i++)
			{
				system("cls");
				cout << "Book no." << i+1 << endl;
				B = new Book;
				B->Add();
				book.push_back(B);
				cout << endl;
				cout << "\n\n\nBook Created...";
				Sleep(1000);
				cout << endl;
			}
		}

		void displayBook()
		{
		cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		cout<<setw(10)<<"\"Book ID\""<<setw(30)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30) <<"\"Year of Publication\""<<endl;
		cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
		for(int i = 0; i< this -> book.size(); i++)
			{
				this->book.at(i) -> show();
			}
		}

	void Sort();
	
};

void bookManager::Sort()
{
	char t[100];
	for(int i=0; i<book.size()-1;i++)
	{
		for(int j = i+1;j < book.size(); j++)
		{
			if (strcmp(cTitle[i], cTitle[j]) > 0)
		 {
            strcpy(t, cTitle[j-1]);
            strcpy(cTitle[j - 1], cTitle[j]);
            strcpy(cTitle[j], t);
         }
			
		}
	}
}



int main()
{
	bookManager b;

	b.addBook();
	b.displayBook();

	cout << endl;
	system("pause");
	return 0;
}