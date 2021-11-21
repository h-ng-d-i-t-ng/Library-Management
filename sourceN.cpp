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

	void SbyId();
	void SbyTitle();
	void SbyAuthor();
	void SbyCategory();
	void SbyPubYear();

	void dbyId();
	void dbyTitle();
	void dbyCategory();
	void dbyAuthor();
	void dbyPubYear();
	
    void searchbTitle();
};



/*void bookManager::SbyId()
{
	for (int i = 0; i < book.size() - 1; i++)
    {
        for (int j =book.size() - 1; j > i; j--)
        {
            char *name1 = new char[book[j]->getId().length()];
            strcpy(name1, book[j]->getId().c_str());
            char *name2 = new char[book[j - 1]->getId().length()];
            strcpy(name2, book[j - 1]->getId().c_str());
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

void bookManager::SbyAuthor()
{
	for (int i = 0; i < book.size() - 1; i++)
    {
        for (int j =book.size() - 1; j > i; j--)
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
	for (int i = 0; i < book.size() - 1; i++)
    {
        for (int j =book.size() - 1; j > i; j--)
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
} */
void bookManager::SbyPubYear()
{
	int a, b;
	for (int i = 0; i < book.size() - 1; i++)
    {
        for (int j =book.size() - 1; j > i; j--)
        {
           a = book[j]->getYear() ;
		    b =	book[j-1]->getYear() ;
            if (a < b) 
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
/*void bookManager::dbyId()
{
int found = 0;
            string del;
            cout << "  \n\n\nEnter the ID you want to delete: " << endl;
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
            for (int i = 0; i <= book.size() - 1; i++)
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
            for (int i = 0; i <= book.size() - 1; i++)
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
            for (int i = 0; i <= book.size() - 1; i++)
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
            for (int i = 0; i <= book.size() - 1; i++)
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

void bookManager::searchbTitle()
{   
    string h;
    cout << " Enter Title to search:";
    fflush(stdin);
    getline(cin,h);
    for (int i = 0; i <= book.size(); i++)
    {
        if(h == book[i]->getTitle())
        {
           book[i].displayBook();
        }

    }
}*/
int main()
{
	bookManager b;

	b.addBook();
	b.displayBook();

	//b.searchbTitle();
/*	b.SbyId();
	b.SbyTitle();
	b.SbyAuthor();
	b.SbyCategory();  */
	b.SbyPubYear();

	
/*	b.dbyId();
	b.dbyTitle();
	b.dbyAuthor();
	b.dbyCategory();
	b.dbyPubYear();
*/	
	
	cout << endl;
	system("pause");
	return 0;
}