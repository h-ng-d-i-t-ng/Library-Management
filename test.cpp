#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
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
			gotoxy(20,16);
	cout << endl;
	return 0;
}