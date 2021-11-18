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
/***************************CLASS BOOK***************************/
class Book {
	private:
		string sid,stitle,sAuthor,sCategory; //private variables
		int nPubYear,nsl;
	public:
		void add();
		void in();
		string getid(){return sid;}
		string getTitle(){return stitle;}
		string getAuthor(){return sAuthor;}
		string getCategory(){return sCategory;}
		int getYear(){return nPubYear;}
		int getsl(){return nsl;}
		
		Book(){
			sid="null";
			stitle="null";
			sAuthor="null";
			sCategory="null";
			nPubYear=0;
		}
		~Book(){
		}
	};
	void Book::add(){
		cout<<"\nNhap Ten Sach:";
		//cin.ignore() ;
		getline(cin,stitle);
		cout<<"\nNhap ID Sach:";
		//cin.ignore();
		getline(cin,sid);
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
	cout<<"\nTen sach: "<<stitle<<"\nID sach: "<<sid<<"\nTen Tac Gia: "<<sAuthor<<"\nNam Xuat Ban: "<<nPubYear<<"\nThe Loai: "<<sCategory<<"\nSo Luong: "<<nsl;
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
int main(){
	int n;
	cout<<"Nhap So Sach Ban Muon Quan Ly:";
	cin>>n;
	cin.ignore();
	Book *B=new Book[n];
	adddanhsach(B,n);
	//indanhsach(B,n);
	//Xuatvaofile(B,n); 
	//write_book(B,n);
	//Nhaptufile(B,n);
	indanhsach(B,n); 
	timkiemten(B,n);
	
}
	
