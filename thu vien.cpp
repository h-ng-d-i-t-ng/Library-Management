#include<iostream>
#include<iomanip>  
#include<fstream>  
#include<conio.h>  
#include<string.h>
#include<stdio.h>   
#include <cstdlib> 
#include <windows.h>
#include<time.h>
#include<vector> 
using namespace std;
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
		cin.ignore() ;
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
void themsach(Book *B,int &n){
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
void sapxeptheotensach(Book *B, int n){
	for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         if((B+i)->getTitle()>(B+j)->getTitle()){
         	Book temp=*(B+i);
         	*(B+i)=*(B+j);
         	*(B+j)=temp;
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
void sapxeptheoNXBtangdan(Book *B, int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if((B+i)->getYear()>(B+j)->getYear()){
				Book temp;
				temp = *(B+i);
				*(B+i) = *(B+j);
				*(B+j)=temp;
			}
		}
	}
}
void sapxeptheoNXBgiamdan(Book *B, int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if((B+i)->getYear()<(B+j)->getYear()){
				Book temp;
				temp = *(B+i);
				*(B+i) = *(B+j);
				*(B+j)=temp;
			}
		}
	}
}
void sapxeptheotenTG(Book *B ,int n){
	for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         if((B+i)->getAuthor()>(B+j)->getAuthor()){
         	Book temp=*(B+i);
         	*(B+i)=*(B+j);
         	*(B+j)=temp;
         }
      }
}
void sapxeptheotheloai(Book *B ,int n){
	for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         if((B+i)->getCategory()>(B+j)->getCategory()){
         	Book temp=*(B+i);
         	*(B+i)=*(B+j);
         	*(B+j)=temp;
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
int tongsosach(Book *B , int n){
	for(int i=0;i<n;i++){
		int ts=0;
		ts+=(B+i)->getsl();
	}
}

class thedocgia{
	protected:
		float gia; 
		string HoTen;
		int ngay,thang,nam;
		int HieuLuc;
	public:
	virtual float tinhtienlamthe() = 0;
	virtual void nhap(){
	cout<<"\nNhap Ho Ten The Doc Gia :";
	cin.ignore();
	getline(cin,HoTen);
	cout<<"\nNhap Ngay Thang Nam Ngay Tao The:";
	cin>>ngay>>thang>>nam;
	cout<<"\nNhap So Thang Co Hieu Luc Cua The:";
	cin>>HieuLuc;	
	}
	virtual void xuat(){
	cout<<"\nHo Ten The Doc Gia: "<<HoTen<<"\nNgay Tao The: "<<ngay<<"/"<<thang<<"/nam";
	cout<<"\nSo Thang Co Hieu Luc: "<<HieuLuc;
	}
	thedocgia(){
		HoTen="null";
		ngay=0;
		thang=0;
		nam=0;
		HieuLuc=0;
	}
	~thedocgia(){
	}		
	
};

class DocGiaTreEm:public thedocgia{
    private:
 		string HoTenNDD;
 	public :
 		
 		void nhap(){
 		thedocgia::nhap();
		cout<<"\nNhap Ho Ten Nguoi Dai Dien:";
 		cin.ignore() ;
 		getline(cin,HoTenNDD);	
 		}
 		void xuat(){
 		thedocgia::xuat();
 		cout<<"\nten nguoi dai dien: "<<HoTenNDD;
		}
 		float tinhtienlamthe(){
 			return gia=HieuLuc*5000;
		 }
};
class DocGiaNguoiLon:public thedocgia{
	private: 
	  string CMND;
	public:
		void nhap(){
			thedocgia::nhap();
			cout<<"\nNhap So Chung Minh Nhan Dan/ Can Cuoc Cong Dan :";
			cin.ignore() ;
			getline(cin,CMND);
		}
		void xuat(){
			thedocgia::xuat() ;
			cout<<"\nCMND/CCCD: "<<CMND;	
		}
		float tinhtienlamthe(){
			return gia=HieuLuc*10000;
		}
};
class QLthedocgia{
	private:
		vector<thedocgia *> TD;
		
	public:
		void NhapDS(){
            thedocgia *dg;
            int n,m;
            cout<<"Nhap so luong the doc gia tre em : ";
            cin>>n;
            for(int i=0;i<n;i++){
                dg=new DocGiaTreEm;
                dg->nhap();
                TD.push_back(dg);
                cout<<endl;
            }
            cout<<"Nhap so luong the doc gia nguoi lon : ";
            cin>>m;
            for(int i=0;i<m;i++){
                dg=new DocGiaNguoiLon;
                dg->nhap();
                TD.push_back(dg);
                cout<<endl;
            }
        }
        void XuatDS(){
            cout<<endl<<"*******Danh sach Doc Gia*******"<<endl;
            for(int i=0; i<this->TD.size();i++){
                this->TD.at(i)->xuat();
                cout<<endl;
            }
        }
        void SapXepTangDan(){
            for(int i=0;i<TD.size()-1;i++){
                for(int j=i+1;j<TD.size();j++){
                    if(TD.at(i)->tinhtienlamthe() > TD.at(j)->tinhtienlamthe()){
                        thedocgia *t= TD.at(i);
                        TD.at(i)=TD.at(j);
                        TD.at(j)=t;
                    }
                }
            }
            XuatDS();
        }
        void SapXepGiamDan(){
            for(int i=0;i<TD.size()-1;i++){
                for(int j=i+1;j<TD.size();j++){
                    if(TD.at(i)->tinhtienlamthe() < TD.at(j)->tinhtienlamthe()){
                        thedocgia *t= TD.at(i);
                        TD.at(i)=TD.at(j);
                        TD.at(j)=t;
                    }
                }
            }
            XuatDS();
        }
        void TongTien(){
            float tong=0;
            for(int i=0;i<TD.size();i++){
                tong+=TD.at(i)->tinhtienlamthe();
            }
            cout<<endl<<"Tong so tien lam the la : "<<setprecision(2)<<fixed<<tong<<endl;
        }
        
	
};
int main(){
	int n;
	cout<<"Nhap So Sach Ban Muon Quan Ly:";
	cin>>n;
	//cin.ignore();
	Book *B=new Book[n];
	
}
	
