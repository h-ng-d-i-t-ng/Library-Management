#include<iostream>
#include<iomanip>  
#include<fstream>  
#include<conio.h>  
#include<string.h>
#include<stdio.h>   
#include <cstdlib> 
#include <windows.h>
#include<time.h>

using namespace std;
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

class Book {
	protected:
		string sId,sTitle,sAuthor,sCategory; //private variables
		int nPubYear,nsl;
	public:
		void add();
		void in();
	
		string getid(){return sId;}
		string getTitle(){return sTitle;}
		string getAuthor(){return sAuthor;}
		string getCategory(){return sCategory;}
		int getYear(){return nPubYear;}
		int getsl(){return nsl;}
		
		Book(){
			this->sId="null";
			sTitle="null";
			sAuthor="null";
			sCategory="null";
			nPubYear=0;
		}
		~Book(){
		}
	};
	void Book::add(){
		cout<<"\nNhap Ten Sach:";
		cin.ignore() ;
		getline(cin,sTitle);
		cout<<"\nNhap ID Sach:";
		//cin.ignore();
		getline(cin,sId);
		cout<<"\nNhap Ten Tac Gia:";
		//cin.ignore(256, '\n');
		getline(cin,sAuthor);
		cout<<"\nNhap Nam Xuat Ban:";
		cin>>nPubYear;
		cout<<"\nNhap The Loai:";
		cin.ignore();
		getline(cin,sCategory);
		cout<<"\nNhap So Luong:";
		cin>>nsl;
	}
void Book::in(){
	cout<<"\nTen sach: "<<sTitle<<"\nID sach: "<<sId<<"\nTen Tac Gia: "<<sAuthor<<"\nNam Xuat Ban: "<<nPubYear<<"\nThe Loai: "<<sCategory<<"\nSo Luong: "<<nsl;
}
void adddanhsach(Book *B,int n){
	for(int i=0;i<n;i++){
		cout<<"\nNhap Thong Tin Sach Thu "<<i+1<<":";
		(B+i)->add();  
	}
}
void indanhsach(Book *B, int n){
	for(int i=0;i<n;i++){
			cout<<"\nQuan Sach Thu "<<i+1<<":";
			(B+i)->in();
	}
}
void timkiemten(Book *B, int n){
	int j=0;
	string ten;
	cout<<"\nnhap ten sach ban muon tim: ";
	//cin.ignore();
	getline(cin,ten);
    for(int i=0;i<n;i++){
    	if((B+i)->getTitle()==ten){
    		(B+i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}  	
}
void timkiemID(Book *B,int n){
	int j=0;
	string ID;
	cout<<"\nnhap ID sach ban muon tim: ";
	//cin.ignore();
	getline(cin,ID);
    for(int i=0;i<n;i++){
    	if((B+i)->getid()==ID){
    		(B+i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}  	
}
void timkiemNXB(Book *B,int n){
	int j=0;
	int NXB;
	cout<<"\nnhap nam xuat ban cua sach ban muon tim: ";
	//cin.ignore();
	cin>>NXB;
    for(int i=0;i<n;i++){
    	if((B+i)->getYear()==NXB){
    		(B+i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}  	
}	
void timkiemTL(Book *B,int n){
	int j=0;
	string TL;
	cout<<"\nnhap the loai sach ban muon tim: ";
	//cin.ignore();
	getline(cin,TL);
    for(int i=0;i<n;i++){
    	if((B+i)->getCategory()==TL){
    		(B+i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}  
}
void timkiemTG(Book *B ,int n){
	int j=0;
	string TG;
	cout<<"\nnhap ten tac gia sach ban muon tim: ";
	//cin.ignore();
	getline(cin,TG);
    for(int i=0;i<n;i++){
    	if((B+i)->getAuthor()==TG){
    		(B+i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	} 
}
void themsach(Book *B,int n){
	n++;
	(B+n-1)->add();
} 
void SapXepSoLuongSachTangDan(Book *B, int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if((B+i)->getsl()>(B+j)->getsl()){
				Book temp;
				temp = *(B+i);
				*(B+i) = *(B+j);
				*(B+j)=temp;
			}
		}
	}
}
void SapXepSoLuongSachGiamDan(Book *B, int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if((B+i)->getsl()<(B+j)->getsl()){
				Book temp;
				temp = *(B+i);
				*(B+i) = *(B+j);
				*(B+j)=temp;
			}
		}
	}
}
void suadoi_1_tuong(Book *B , int n){
	int j=0;
	string TS;
	cout<<"\nnhap ten sach ban muon sua thong tin: ";
	cin.ignore();
	getline(cin,TS);
	for(int i=0;i<n;i++){
		if((B+i)->getTitle()==TS){
			Book temt;
			temt.add() ;
			*(B+i)=temt;
			j++;
		}
	}
	if(j<=0) cout<<"Trong Thu Vien Khong Co Sach Nay!!!";
}
void suadoitoanbo(Book *B , int &n){
	int m;
	cout<<"\nnhap so loai sach ban muon quan ly:";
	cin>>m;
	n=m;
	adddanhsach(B,m); 
}


///////Delete by id///////

void dbyId(Book *B, int &n)
{
	string Id;
	int found = 0;
	system("cls");
	cout << endl;
	cout << "Deleting by Id of book\n";
	cout << "Enter the id of book you want to delete: ";

	getline(cin, Id);

	for (int i = 0; i < n; i++)
	{
		if ((B + i)->getid() == Id)
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
//////Delete by Title///////
void dbyTitle(Book *B, int &n)
{
	string Tname;
	int found = 0;
	system("cls");
	cout << endl;
	cout << "Deleting by name of book\n";
	cout << "Enter the name of book you want to delete: ";

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

void dbyAuthor(Book *B, int &n)
{
	string Aname;
	int found = 0;
	system("cls");
	cout << endl;
	cout << "Deleting by author of book\n";
	cout << "Enter the author of book you want to delete: ";
	
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



void delBook(Book *B, int &n)
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

/*	case 'c':
	case 'C':
		dbyCategory(B, n);
		break;

	case 'y':
	case 'Y':
		dbyPubYear(B, n);
		break; */

	default:
		puts("\n\n \t\tSelect only from the given menu.....\n\t\tPress enter to select again.....");
		getch();
		delBook(B, n);
		getch();
	}
}





int main(){
	int n;
	cout<<"Nhap So Sach Ban Muon Quan Ly:";
	cin>>n;
	//cin.ignore();
	Book *B=new Book[n];
	adddanhsach(B,n);
	 
	indanhsach(B,n);
	//suadoituong(B,n);
	suadoitoanbo(B,n);
	 indanhsach(B,n);
	delBook(B, n);
	
	 
	//timkiemten(B,n);
	
	//indanhsach(B,n);  
	
}
	
