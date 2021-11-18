#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <time.h>
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
	void addBook();
	void add(Book *B, int n);
	void print();
	void displayBook(Book *B, int n);
	void modify_book();
	string getid() { return sId; }
	string getTitle() { return sTitle; }
	string getAuthor() { return sAuthor; }
	string getCategory() { return sCategory; }
	int getYear() { return nPubYear; }
};
Book g_book;
void delBook(Book *B, int n);
void dbyTitle(Book *B, int n);
void dbyId(Book *B, int n);
void dbyAuthor(Book *B, int n);
void dbyCategory(Book *B, int n);
void dbyPubYear(Book *B, int n);

void Book::addBook()
{
	SET_COLOR(1);
	fflush(stdin);
	cout << "\n\nNhap ID: ";
	getline(cin, sId);
	cout << endl;
	fflush(stdin);
	cout << "Nhap tua de: ";
	getline(cin, sTitle);
	cout << endl;
	fflush(stdin);
	cout << "Nhap tac gia: ";
	getline(cin, sAuthor);
	cout << endl;
	fflush(stdin);
	cout << "Nhap the loai ";
	getline(cin, sCategory);
	cout << endl;
	cout << "Nhap nam xuat ban: ";
	cin >> nPubYear;
	cout << endl;
}

void Book::add(Book *B, int n)
{
	char ch;
	do
	{
		system("cls");
		SET_COLOR(4);
		cout << "So luong quyen sach ban muon them vao: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			system("cls");
			cout << endl;
			cout << "THEM THONG TIN SACH\n\n";
			SET_COLOR(0);
			cout << "Quyen thu " << i + 1;
			(B + i)->addBook();
			SET_COLOR(5);
			cout << "\n\n\nSach da duoc them...";
			Sleep(1000);
		}
		SET_COLOR(4);
		cout << "Ban co muon nhap tiep? [y/n]";
		ch = getch();
	} while (ch != 'n' && ch != 'N');
}

void Book::print()
{
	SET_COLOR(1);
	cout << setw(10) << sId << setw(50) << sTitle << setw(30) << sAuthor << setw(30) << sCategory << setw(30) << nPubYear << endl;
}

void Book::displayBook(Book *B, int n)
{
	system("cls");
	SET_COLOR(4);
	cout << "Danh sach cac quyen sach\n";
	cout << "__________"
		 << "__________________________________________________"
		 << "______________________________"
		 << "______________________________"
		 << "______________________________" << endl;
	SET_COLOR(5);
	cout << setw(10) << "\"ID\"" << setw(50) << "\"Tua de\"" << setw(30) << "\"Ten tac gia\"" << setw(30) << "\"The loai\"" << setw(30) << "\"Nam xuat ban\"" << endl;
	SET_COLOR(4);
	cout << "__________"
		 << "__________________________________________________"
		 << "______________________________"
		 << "______________________________"
		 << "______________________________" << endl;
	for (int i = 0; i < n; i++)
	{
		SET_COLOR(2);
		(B + i)->print();
		SET_COLOR(4);
		cout << "__________"
			 << "__________________________________________________"
			 << "______________________________"
			 << "______________________________"
			 << "______________________________" << endl;
	}
	cout << "Nhan enter de ve main menu.....";
	getch();
}

////////////Delete//////////////////////
void delBook(Book *B, int n)
{
	system("cls");

	cout << setw(29) << "In Delete Function" << endl
		 << setw(52) << "Please choose one of the options below: "

		 << endl
		 << setw(71)

		 << "--------------------------------------------------------------"

		 << endl
		 << endl

		 << setw(31) << "( N ) Delete by name" << endl
		 << endl

		 << setw(29) << "( I ) Delete by Id" << endl
		 << endl

		 << setw(38) << "( T ) Delete by author name" << endl
		 << endl

		 << setw(35) << "( C ) Delete by Category" << endl
		 << endl

		 << setw(46) << "( P ) Delete by Publication Company" << endl
		 << endl

		 << setw(43) << "( Y ) Delete by Publication Year" << endl
		 << endl

		 << setw(32) << "Enter Option      [ ]" << endl
		 << endl;
	gotoxy(30, 16);
	//	cin>>ch1;

	switch (getche())
	//switch(ch1)
	{
	case 'n':
	case 'N':
		dbyTitle(B, n);
		break;

	case 'i':
	case 'I':
		dbyId(B, n);
		break;

	case 't':
	case 'T':
		dbyAuthor(B, n);
		break;

	case 'c':
	case 'C':
		dbyCategory(B, n);
		break;

	case 'y':
	case 'Y':
		dbyPubYear(B, n);
		break;

	default:
		puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
		getch();
		delBook(B, n);
		getch();
	}
}

///////Delete by id///////

void dbyid(Book *B, int n)
{
	string Id;
	int found = 0;
	system("cls");
	cout << endl;
	cout << "Deleting by Id of book\n";
	cout << "Enter the id of book you want to delete: ";
	fflush(stdin);
	getline(cin, Id);

	for (int i = 0; i < n; i++)
	{
		if ((B + i)->getid() == Id)
		{

			*(B + i) = *(B + i + 1);
			found++;
			n--;
			return;
		}
	}
	if (found <= 0)
		cout << "Record not Found" << endl;
	cout << "Press enter to goto main manu.....";
	getch();
}
//////Delete by Title///////
void dbyTitle(Book *B, int n)
{
	string Tname;
	int found = 0;
	system("cls");
	cout << endl;
	cout << "Deleting by name of book\n";
	cout << "Enter the name of book you want to delete: ";
	fflush(stdin);
	getline(cin, Tname);

	for (int i = 0; i < n; i++)
	{
		if ((B + i)->getTitle() == Tname)
		{
			for (int j = i; j < n; j++)
			{
				*(B + j) = *(B + j + 1);
			}
			found++;
			n--;
			return;
		}
	}
	if (found <= 0)
		cout << "Record not Found" << endl;
	cout << "Press enter to goto main menu.....";
	getch();
}

///////Delete by author///////

void dbyAuthor(Book *B, int n)
{
	string Aname;
	int found = 0;
	system("cls");
	cout << endl;
	cout << "Deleting by author of book\n";
	cout << "Enter the author of book you want to delete: ";
	fflush(stdin);
	getline(cin, Aname);
	for (int i = 0; i < n; i++)
	{
		if ((B + i)->getAuthor() == Aname)
		{
			for (int j = i; j < n; j++)
			{
				*(B + j) = *(B + j + 1);
			}
			found++;
			n--;
			return;
		}
	}
	if (found <= 0)
		cout << "Record not Found" << endl;
	cout << "Press enter to goto main manu.....";
	getch();
}
/**********************CLASS STUDENT***************************/
/*class Student
{

};*/
/***************************************************************/
//////////////////////////////////////////////////
//   				MAIN MENU		 			//
//////////////////////////////////////////////////
int main()
{
	system("color Bf");
	int n;
	Book *B = new Book[n];
	while (1)
	{
		system("cls");
		SET_COLOR(4);
		cout << setw(25) << "-------------" << endl

			 << setw(25) << "| MAIN MENU |" << endl

			 << setw(25) << "-------------" << endl
			 << endl;

		SET_COLOR(6);
		cout << setw(52)

			 << "Chon mot trong cac chuc nang sau: "

			 << endl
			 << setw(71)

			 << "--------------------------------------------------------------"

			 << endl
			 << endl;

		SET_COLOR(5);

		cout << setw(25) << "( A ) Them sach" << endl
			 << endl

			 << setw(31) << "( O ) Loc sach" << endl
			 << endl

			 << setw(33) << "( S ) Tim kiem sach" << endl
			 << endl

			 << setw(33) << "( D ) Hien thi sach" << endl
			 << endl

			 << setw(30) << "( T ) Xoa sach" << endl
			 << endl

			 << setw(40) << "( M ) Cap nhat thong tin sach" << endl
			 << endl

			 << setw(21) << "( Q ) Thoat" << endl
			 << endl;

		SET_COLOR(4);

		cout << setw(32) << "Nhap lua chon      [ ]" << endl
			 << endl;
		gotoxy(30, 21);

		switch (getche())
		{
		case 'a':
		case 'A':
			g_book.add(B, n);
			break;

		case 'd':
		case 'D':
			g_book.displayBook(B, n);
			break;

			//case 'S':
			//case 's': search(); break;

			case 't':
			case 'T': delBook(B,n); break;

			//case 'O':
			//case 'o': sort(); break;

			//case 'm':
			//case 'M': modify(); break;

		case 'q':
		case 'Q':
			exit(0);
			break;

		default:
			puts("\n\n \t\tSelect only from the given menu.....\n \t\tpress enter to to go to main menu......");
			getch();
		} //end switch
	}	  //end while

	getch();

	system("pause");
	return 0;
}
