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
//                       GOTOXY                 //
//////////////////////////////////////////////////
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//////////////////////////////////////////////////
//               SET FONT COLOR                 //
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

class Bookcase;
class rentBill;
class Reader;

class Book
{
		friend class Bookcase;
	protected:
		int countBooks;
		Bookcase *tbooks;
		static int books;
		static Book *storage[500];
		int nPubyear;
		string sId, sTitle, sAuthor, sCategory;
	public:
		//get variable from protected
		string getid() { return sId; }
		string getTitle() { return sTitle; }
		string getAuthor() { return sAuthor; }
		string getCategory() { return sCategory; }
		int getYear() { return nPubyear; }

		//Ham nhap, xuat 1 cuon
		virtual void Add();
		virtual void show();

		//function book borrower
		Bookcase *fnotRent()(); //Sach chua duoc muon
		static Book *findBook(char *bookid);
		static Bookcase *findtBook(char *, int );

};

void Book::Add()
{
	cout << "\nEnter ID: ";
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
	cin >> nPubyear;
}

void Book::show()
{
	cout << setw(10) << sId << setw(30) << sTitle << setw(30) << sAuthor << setw(30) << sCategory << setw(20) << nPubyear << endl ;
	cout <<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
}

class bookManager
{
	private:
		vector<Book *> book;
	public:
		//Ham nhap danh sach, xuat danh sach
		void addBook();
		void displayBook();
};

void bookManager::addBook()
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

void bookManager::displayBook()
{
	cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	cout<<setw(10)<<"\"Book ID\""<<setw(30)<<"\"Book Name\""<<setw(30)<<"\"Author Name\""<<setw(30)<<"\"Category\""<<setw(30) <<"\"Year of Publication\""<<endl;
	cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	for(int i = 0; i< this -> book.size(); i++)
	{
		this->book.at(i) -> show();
	}
}

void menu()
{
	while(1)
 	{
		cout << "\n\n Lua chon cong viec theo so \n\n" ;
		cout << " 1. Dang ki ban doc \n";
		cout << " 2. Muon sach \n";
		cout << " 3. Tra sach \n";
		cout << " 4. Danh sach ban doc\n";
		cout << " 5. Thoat khoi chuong trinh\n";
	int i = _getch();
	switch(i)
	{
		case '1':
		{
			bandoc::dangki();
		break;
		}

		case '2':
		{
			muon();
			break;
		}

		case '3':
		{
			tra();
			break;
		}

		case '4':
		{
			bandoc::inds();
			break;
		}

		case '6':
		{
			sach::inds();
		}
		
		if(i=='5') break;
		_getch();
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