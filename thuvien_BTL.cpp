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
//tao class sach
class Book {
	//tinh dong goi trong huong doi tuong 
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
		//ham tao 
		Book(){
			this->sid="null";
			this->stitle="null";
			this->sAuthor="null";
			this->sCategory="null";
			this->nPubYear=0;
			this->nsl=0; 
		}
		//ham huy
		~Book(){
		}
	};
	//nhap thong tin sach
	void Book::add(){
		cout<<"\nNhap Ten Sach:";
		fflush(stdin); 
		getline(cin,stitle);
		cout<<"\nNhap ID Sach:";
		fflush(stdin);
		getline(cin,sid);
		cout<<"\nNhap Ten Tac Gia:";
		fflush(stdin);
		getline(cin,sAuthor);
		cout<<"\nNhap Nam Xuat Ban:";
		cin>>nPubYear;
		cout<<"\nNhap The Loai:";
		fflush(stdin);
		getline(cin,sCategory);
		cout<<"\nNhap So Luong:";
		cin>>nsl;
	}
	//xuat thong tin sach
void Book::in(){
	cout<<"\nTen sach: "<<stitle<<"\nID sach: "<<sid<<"\nTen Tac Gia: "<<sAuthor<<"\nNam Xuat Ban: "<<nPubYear<<"\nThe Loai: "<<sCategory<<"\nSo Luong: "<<nsl;
	cout<<"\n_______________________________________________________________________________________________________";
}
//nhap danh sach sach
class thuvien{
	private :
				vector<Book *> B;
				int n;
	public:
		void adddanhsach();
		void indanhsach();
		void timkiemten();
		void timkiemID();
		void timkiemNXB();
		void timkiemTL();
		void timkiemTG();
		void themsach();
		void SapXepSoLuongSachTangDan();
		void sapxeptheotensach();
		void SapXepSoLuongSachGiamDan();
		void sapxeptheoNXBtangdan();
		void sapxeptheoNXBgiamdan();
		void sapxeptheotenTG();
		void sapxeptheotheloai();
		void suadoi_1_tuong();
		void suadoitoanbo();
		int tongsosach();
		void xoasachtheoten();
		void xoasachtheoID();
		void xoasachtheoNXB();
		void xoasachtheoTL();
		void xoasachtheoTG();
		int TimKiem();
		int SapXep();
		int Sua();
		int xoasach();
};
void thuvien::adddanhsach(){
	fflush(stdin); 
	cout<<"\nNhap So Loai Sach Ban Muon Quan Ly:";
	cin>>this->n;
	fflush(stdin);
    Book *tv;
	for(int i=0;i<this->n;i++){
		cout<<"\nNhap Thong Tin Sach Thu "<<i+1<<":";
        tv=new Book;
        tv->add();
		B.push_back(tv);  
	}
}
//in danh sach sach
void thuvien::indanhsach(){
	for(int i=0;i<this->n;i++){
			cout<<"\n_______________________________________________________________________________________________________";
			cout<<"\nQuan Sach Thu "<<i+1<<":";
			this->B.at(i)->in();
	}
}
//ham tim kiem theo ten
void thuvien::timkiemten(){
	int j=0;
	string ten;
	cout<<"\nnhap ten sach ban muon tim: ";
	fflush(stdin);
	getline(cin,ten);
	//cau truc du lieu: thuat toan so sanh
    for(int i=0;i<this->n;i++){
    	if(B.at(i)->getTitle()==ten){
    		B.at(i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}  	
}
//ham tim kiem theo ID
void thuvien::timkiemID(){
	int j=0;
	string ID;
	cout<<"\nnhap ID sach ban muon tim: ";
	fflush(stdin);
	getline(cin,ID);
    for(int i=0;i<this->n;i++){
    	if(B.at(i)->getid()==ID){
    		B.at(i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}  	
}
//ham tim kiem theo nam xuat ban
void thuvien::timkiemNXB(){
	int j=0;
	int NXB;
	cout<<"\nnhap nam xuat ban cua sach ban muon tim: ";
	fflush(stdin);
	cin>>NXB;
    for(int i=0;i<this->n;i++){
    	if(B.at(i)->getYear()==NXB){
    		B.at(i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}  	
}	
void thuvien::timkiemTL(){
	int j=0;
	string TL;
	cout<<"\nnhap the loai sach ban muon tim: ";
	fflush(stdin);
	getline(cin,TL);
    for(int i=0;i<this->n;i++){
    	if(B.at(i)->getCategory()==TL){
    		B.at(i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}  
}
void thuvien::timkiemTG(){
	int j=0;
	string TG;
	cout<<"\nnhap ten tac gia sach ban muon tim: ";
	fflush(stdin);
	getline(cin,TG);
    for(int i=0;i<this->n;i++){
    	if(B.at(i)->getAuthor()==TG){
    		B.at(i)->in();
    		j=j+1;
		}
	}
	if(j<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	} 
}
//ham them sach 
//con tro (mang dong)
 void thuvien::themsach(){
	this->n++;
    Book *m;
    m=new Book;
	m->add();
    B.push_back(m);
} 
void thuvien::SapXepSoLuongSachTangDan(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(B.at(i)->getsl()>B.at(j)->getsl()){
				Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
			}
		}
	}
	indanhsach(); 
}
void thuvien::sapxeptheotensach(){
	for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         if(B.at(i)->getTitle()>B.at(j)->getTitle()){
         	Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
         }
      }
      indanhsach();
} 
void thuvien::SapXepSoLuongSachGiamDan(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(B.at(i)->getsl()<B.at(j)->getsl()){
				Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
			}
		}
	}
	indanhsach();
}
void thuvien::sapxeptheoNXBtangdan(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(B.at(i)->getYear()>B.at(j)->getYear()){
				Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
			}
		}
	}
	indanhsach();
}
void thuvien::sapxeptheoNXBgiamdan(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(B.at(i)->getYear()<B.at(j)->getYear()){
				Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
			}
		}
	}
	indanhsach();
}
void thuvien::sapxeptheotenTG(){
	for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         if(B.at(i)->getAuthor()>B.at(j)->getAuthor()){
         	Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
         }
      }
      indanhsach();
}
void thuvien::sapxeptheotheloai(){
	for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
         if(B.at(i)->getCategory()>B.at(j)->getCategory()){
         	Book *temp= B.at(i);
				B.at(i) = B.at(j);
				B.at(j)= temp;
         }
      }
      indanhsach();
}
void thuvien::suadoi_1_tuong(){
	int j=0;
	string TS;
	cout<<"\nnhap ten sach ban muon sua thong tin: ";
	fflush(stdin);
	getline(cin,TS);
	for(int i=0;i<n;i++){
		if(B.at(i)->getTitle()==TS){
			Book *t=new Book;
			t->add() ;
			B.at(i) =t;
			j++;
		}
	}
	if(j<=0) cout<<"Trong Thu Vien Khong Co Sach Nay!!!";
}
void thuvien::suadoitoanbo(){
	int m;
	cout<<"\nnhap so loai sach ban muon quan ly:";
	cin>>m;
	this->n=m;
	adddanhsach(); 
}
int thuvien::tongsosach(){
	int ts=0;
	for(int i=0;i<n;i++){
		ts+=B.at(i)->getsl();
	}
	return ts;
}
void thuvien::xoasachtheoten(){
	string TS;
	cout<<"\nnhap ten sach ban muon xoa: ";
	fflush(stdin);
	getline(cin,TS);
	int k=0;
	for(int i=0; i<n ; i++){
		if(B.at(i)->getTitle()==TS){
		    for(int j=i; j<n; j++){
				B.at(i) = B.at(j);
			}
			B.pop_back();
            n--;
            k++;
            cout<<"Da xoa thanh cong!!!";
		}
	}
    if(k<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	} 
}
void thuvien::xoasachtheoID(){
	string TS;
	cout<<"\nNhap ID sach ban muon xoa: ";
	fflush(stdin);
	getline(cin,TS);
    int k=0;
	for(int i=0; i<n ; i++){
		if(B.at(i)->getid()==TS){
			for(int j=i; j<n; j++){
				B.at(i) = B.at(j);
			}
			B.pop_back();
             n--;
            k++;
            cout<<"Da xoa thanh cong!!!";
		}
	}
    if(k<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}
}
void thuvien::xoasachtheoNXB(){
	int TS;
	cout<<"\nNhap nam xuat ban sach ban muon xoa: ";
	cin>>TS;
     int k=0;
	for(int i=0; i<n ; i++){
		if(B.at(i)->getYear()==TS){
			for(int j=i; j<n; j++){
				B.at(i) = B.at(j);
			}
			B.pop_back();
             n--;
            k++;
            cout<<"Da xoa thanh cong!!!";
		}
	}if(k<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}

}
void thuvien::xoasachtheoTL(){
	string TS;
	cout<<"\nNam the loai sach ban muon xoa: ";
	fflush(stdin);
	getline(cin,TS);
    int k=0;
	for(int i=0; i<n ; i++){
		if(B.at(i)->getCategory()==TS){
			for(int j=i; j<n; j++){
				B.at(i) = B.at(j);
			}
			B.pop_back();
             n--;
            k++;
            cout<<"Da xoa thanh cong!!!";
		}
	}if(k<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
	}
}
void thuvien::xoasachtheoTG(){
	string TS;
	cout<<"\nnhap ten tac gia sach ban muon xoa: ";
	fflush(stdin);
	getline(cin,TS);
    int k=0;
	for(int i=0; i<n ; i++){
		if(B.at(i)->getAuthor()==TS){
			for(int j=i; j<n; j++){
				B.at(i) = B.at(j);
			}
			B.pop_back();
             n--;
            k++;
            cout<<"Da xoa thanh cong!!!";
		}
	}if(k<=0){
		cout<<"\ntrong thu vien khong co sach nay!!!!";
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
	fflush(stdin);
	getline(cin,HoTen);
	cout<<"\nNhap Ngay Thang Nam Ngay Tao The:";
	cin>>ngay>>thang>>nam;
	cout<<"\nNhap So Thang Co Hieu Luc Cua The:";
	cin>>HieuLuc;	
	}
	virtual void xuat(){
	cout<<"\nHo Ten The Doc Gia: "<<HoTen<<"\nNgay Tao The: "<<ngay<<"/"<<thang<<"/"<<nam;
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
 		fflush(stdin);
 		getline(cin,HoTenNDD);	
 		}
 		void xuat(){
 		thedocgia::xuat();
 		cout<<"\nten nguoi dai dien: "<<HoTenNDD;
          this->tinhtienlamthe(); 
        cout<<"\nSo tien lam the : "<<gia;
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
			fflush(stdin);
			getline(cin,CMND);
		}
		void xuat(){
			thedocgia::xuat() ;
			cout<<"\nCMND/CCCD: "<<CMND;
            this->tinhtienlamthe(); 
            cout<<"\nSo tien lam the : "<<gia;	
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
int thuvien::TimKiem(){
    int ch2;
    cout<<"\n\n\n\tCHUONG TRINH TIM KIEM ";
    cout<<"\n\n\t1.TIM KIEM THEO TEN SACH";
    cout<<"\n\n\t2.TIM KIEM THEO ID ";
    cout<<"\n\n\t3.TIM KIEM THEO NAM XUAT BAN ";
    cout<<"\n\n\t4.TIM KIEM THEO THE LOAI";
    cout<<"\n\n\t5.TIM KIEM THEO TEN TAC GIA";
    cout<<"\n\n\t6.TRO VE CHUONG TRINH CHINH";
    cout<<"\n\n\tHay Nhan Nut Chon Tu (1-6) ";
    cin>>ch2;
    switch(ch2)
    {
            case 1:
                this->timkiemten();break;
            case 2: 
				this->timkiemID();break;
            case 3:
                this->timkiemNXB();  break;
            case 4: 
			  	this->timkiemTL();break;
            case 5: 
			  	this->timkiemTG();break;
        	case 6:
        	 	return 0 ;
              	default:cout<<"\a";
       }
}
int thuvien::SapXep(){
    int ch2;
    cout<<"\n\n\n\tCHUONG TRINH SAP XEP ";
    cout<<"\n\n\t1.SAP XEP SO LUONG SACH TANG DAN ";
    cout<<"\n\n\t2.SAP XEP SO LUONG SACH GIAM DAN ";
    cout<<"\n\n\t3.SAP XEP THEO TEN SACH TU A->Z ";
    cout<<"\n\n\t4.SAP XEP THEO NAM XUAT BAN TANG DAN";
    cout<<"\n\n\t5.SAP XEP THEO NAM XUAT BAN GIAM DAN";
    cout<<"\n\n\t6.SAP XEP THEO TEN TAC GIA TU A->Z";
    cout<<"\n\n\t7.SAP XEP THEO THE LOAI  ";
    cout<<"\n\n\t8.TRO VE CHUONG TRINH CHINH";
    cout<<"\n\n\tHay Nhan Nut Chon Tu (1-8) ";
    cin>>ch2;
    switch(ch2)
    {
            case 1:
                this->SapXepSoLuongSachTangDan();break;
            case 2: 
				this->SapXepSoLuongSachGiamDan ();break;
            case 3:
                this->sapxeptheotensach ();  break;
            case 4: 
			  	this->sapxeptheoNXBtangdan();break;
            case 5: 
			  	this->sapxeptheoNXBgiamdan();break;
			case 6: 
			  	this->sapxeptheotenTG();break;  
			case 7: 
			  	this->sapxeptheotheloai();break;	
        	case 8:
        	 	return 0 ;
              	default:cout<<"\a";
       }
}
int thuvien::Sua(){
    int ch2;
    cout<<"\n\n\n\tCHUONG TRINH SUA ";
    cout<<"\n\n\t1.SUA 1 DOI TUONG ";
    cout<<"\n\n\t2.SUA TOAN BO ";
    cout<<"\n\n\t3.TRO VE CHUONG TRINH CHINH";
    cout<<"\n\n\tHay Nhan Nut Chon Tu (1-3) ";
    cin>>ch2;
    switch(ch2)
    {
            case 1:
                this->suadoi_1_tuong();break;
            case 2: 
				this->suadoitoanbo ();break;
            case 3:
        	 	return 0 ;
              	default:cout<<"\a";
       }
}

int thuvien::xoasach(){
	int ch2;
    cout<<"\n\n\n\tCHUONG TRINH XOA SACH ";
    cout<<"\n\n\t1.XOA THEO TEN SACH";
    cout<<"\n\n\t2.XOA KIEM THEO ID ";
    cout<<"\n\n\t3.XOA KIEM THEO NAM XUAT BAN ";
    cout<<"\n\n\t4.XOA KIEM THEO THE LOAI";
    cout<<"\n\n\t5.XOA KIEM THEO TEN TAC GIA";
    cout<<"\n\n\t6.TRO VE CHUONG TRINH CHINH";
    cout<<"\n\n\tHay Nhan Nut Chon Tu (1-6) ";
    cin>>ch2;
    switch(ch2)
    {
            case 1:
                this->xoasachtheoten();break;
            case 2: 
				this->xoasachtheoID();break;
            case 3:
                this->xoasachtheoNXB();  break;
            case 4: 
			  	this->xoasachtheoTL();break;
            case 5: 
			  	this->xoasachtheoTG();break;
        	case 6:
        	 	return 0 ;
              	default:cout<<"\a";
       }
}
void SetColor1(int text_color){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int color_code = text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

int main(){
	//int n;
	//cin.ignore();
	//Book *B=new Book[n];
	thuvien b;
	QLthedocgia a;
	bool DaNhap = false;
	bool thedoc = false;
	SetColor1(5);
	system("color 4");
	int chon;
	while(true){
		system("cls");
		cout<<"\t\n*========================CHUONG TRINH QUAN THU VIEN SACH=========================*";
		cout<<"\t\n==                                                                           ==";
		cout<<"\t\n==                1.NHAP DANH SACH SACH                                      ==";
		cout<<"\t\n==                2.XUAT DANH SACH SACH                                      ==";
		cout<<"\t\n==                3.TIM KIEM SACH                                            ==";
		cout<<"\t\n==                4.SAP XEP DANH SACH                                        ==";
		cout<<"\t\n==                5.SUA DU LIEU TRONG THU VIEN                               ==";
		cout<<"\t\n==                6.XOA SACH TRONG THU VIEN                                  ==";
		cout<<"\t\n==                7.TONG SO QUAN SACH TRONG THU VIEN                         ==";
		cout<<"\t\n==                8.THEM SACH VAO TRONG THU VIEN                             ==";
		cout<<"\t\n==                9.NHAP DANH SACH THE DOC SACH                              ==";
		cout<<"\t\n==                10.XUAT DANH SACH THE DOC SACH                             ==";
		cout<<"\t\n==                11.SAP XEP DANH SACH THE DOC THEO SO TIEN TANG DAN         ==";
		cout<<"\t\n==                12.SAP XEP DANH SACH THE DOC THEO SO TIEN GIAM DAN         ==";
		cout<<"\t\n==                13.TONG SO TIEN LAM THE DOC SACH                           ==";
		cout<<"\t\n==                0.Thoat Chuong Trinh                                       ==";
		cout<<"\t\n==                                                                           ==";
		cout<<"\t\n*===============================================================================*\n";
		cout<<"\n\nNHAP LUA CHON CUA BAN: ";
		cin>>chon;
		switch(chon){
			case 1:
				b.adddanhsach() ;
				DaNhap=true;
				thedoc =true;
				cout<<"\nBam phim bat ky de tiep tuc!";
				getch();
				break;
			case 2:
				thedoc =true;
				if(DaNhap){
					b.indanhsach() ;
				} else cout<<"\nBan chua nhap danh sach sach!!!!!!!!!!!!!!!!";
				
				cout<<"\nBam phim bat ky de tiep tuc!";
				getch();
				break;
			case 3:
				thedoc =true;
				if(DaNhap){
				b.TimKiem() ;
					} else cout<<"\nBan chua nhap danh sach sach!!!!!!!!!!!!!!!!";
				cout<<"\nBam phim bat ky de tiep tuc!";
				getch();
				break;
			case 4:
				thedoc =true;
				if(DaNhap){
					b.SapXep(); 
						
				}else cout<<"\nBan chua nhap danh sach sach!!!";
				cout<<"\nBam phim bat ky de tiep tuc!";
				getch();
				break;
			case 5:
				thedoc =true;
				if(DaNhap){
				b.Sua (); 
				} else cout<<"\nBan chua nhap danh sach sach !!!";
				
				cout<<"\nBam phim bat ky de tiep tuc!";
				getch();
				break;
			case 6:
				thedoc =true;
				if(DaNhap){
				b.xoasach(); 	
				}else cout<<"\nBan chua nhap danh sach sach !!!";
				
				cout<<"\nBam phim bat ky de tiep tuc!";
				getch();
				break;
			case 7:
				thedoc =true;
				if(DaNhap){
					cout<<"\n--> Tong so sach cua thu vien la: "<<b.tongsosach()<<"\n" ;
				} else cout<<"\nBan chua nhap danh sach sach !!!";
				
				cout<<"\nBam phim bat ky de tiep tuc!";
				getch();
				break;
			case 8:
				thedoc =true;
				b.themsach();
				DaNhap=true;
				cout<<"\nBam phim bat ky de tiep tuc!";
				getch();
				break;
			case 9:
				thedoc =true;
				DaNhap=true;
				a.NhapDS();
				cout<<"\nBam phim bat ky de tiep tuc!";
                getch();
                break;
            case 10:
            	DaNhap=true;
            	if(thedoc){
            		a.XuatDS();
            	}else cout<<"\n\nBan chua nhap danh sach the doc !!!";
            	
            	cout<<"\nBam phim bat ky de tiep tuc!";
                getch();
                break;
            case 11:
            	DaNhap=true;
            	if(thedoc){
            		a.SapXepTangDan() ;
            	}else cout<<"\n\nBan chua nhap danh sach the doc !!!";
            	cout<<"\nBam phim bat ky de tiep tuc!";
                getch();
                break;
            case 12:
            	DaNhap=true;
            	if(thedoc){
            		a.SapXepGiamDan() ;
            	}else cout<<"\n\nBan chua nhap danh sach the doc !!!";
            	cout<<"\nBam phim bat ky de tiep tuc!";
                getch();
                break;
            case 13:
            	DaNhap=true;
            	if(thedoc){
            		a.TongTien() ;
            	}else cout<<"\n\nBan chua nhap danh sach the doc !!!";
            	cout<<"\nBam phim bat ky de tiep tuc!";
                getch();
                break;
			case 0:
                cout<<"\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout<<"\nKhong co chuc nang nay!";
                getch();
                break;
		}		
	} 
	
	
}
