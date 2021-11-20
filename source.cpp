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

class Book
{
	protected:
		int nPubyear;
		string sId, sTitle, sAuthor, sCategory;
	public:
	
	virtual void Add()
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

	virtual void show()
	{
		cout << setw(10) << sId << setw(30) << sTitle << setw(30) << sAuthor << setw(30) << sCategory << setw(20) << nPubyear << endl ;
		cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	}
		string getId() { return sId; }
		string getTitle() { return sTitle; }
		string getAuthor() { return sAuthor; }
		string getCategory() { return sCategory; }
		int getYear() { return nPubyear; }
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

	void SortN();
	void delBook();
	void searchbId();
};

void bookManager::SortN()
{
	for (int i = 0; i < book.size() - 1; i++)
    {
        for (int j =book.size() - 1; j > i; j--)
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
void bookManager::delBook(){
int found = 0;
            string del;
			
            cout << "  \n\n\nNhap ID de xoa: " << endl;
            fflush(stdin);
            getline(cin, del);
            for (int i = 0; i <= book.size() - 1; i++)
            {
                if (del == book[i]->getId())
                {
                    found = 1;
                   
                        book.erase(book.begin() + i);
                       
                    break;
                }
            }
            if (found == 0){
                cout << "\n  ID khong ton tai!!!\n\n"<< endl;
            }
		displayBook();
}


int main()
{
	bookManager b;

	b.addBook();
	b.displayBook();
	b.SortN();
	b.delBook();
	
	cout << endl;
	system("pause");
	return 0;
}