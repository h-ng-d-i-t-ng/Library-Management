#include <iostream>     //input, output
#include <iomanip>      //for setw(): stands for set width
#include <fstream>      //for read, write file
#include <conio.h>      //for getch(): Get char entry from the console
#include <cstdlib>      //for system("cls"): clear screen
#include <windows.h>    //for graphics, gotoxy
#include <time.h>       //for sleep(): delay
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

void Menu();
void ThemSach();
void SuaSach();
void XoaSach();
void ThemSinhVien();
void SuaSinhVien();
void XoaSinhVien();
void MuonSach();
void TraSach();
void ToanBoSach();
void ToanBoSinhVien();
void SachMotSinhVienMuon();
void ToanBoSachDuocMuon();

//************************CLASS SACH**********************
class Sach
{
	protected:
        char MaSach[10];
        char TenSach[100];
        char TheLoai[100];
        char TacGia[100];
        int NamXuatBan;
    public:
        //Thiet lap mot so gia tri
        void setSach(char[], char[], char[], char[], int);
        void setMaSach(char[]);
        void setTenSach(char[]);
        void setTheLoai(char[]);
        void setTacGia(char[]);
        void setNamXuatBan(int);

        //Lay gia tri trong protected
        string getMaSach();
        string getTenSach();
        string getTheLoai();
        string getTacGia();
        int getNamXuatBan();
};
//Thiet lap 
void Sach::setSach(char Ma[], char Ten[], char Loai[], char TG[], int NXB)
{
    strcpy(MaSach,Ma);
    strcpy(TenSach,Ten);
    strcpy(TheLoai,Loai);
    strcpy(TacGia,TG);
    NamXuatBan = NXB;
}

void Sach::setMaSach(char Ma[])
{
    strcpy(MaSach,Ma);
}

void Sach :: setTenSach(char Ten[]) 
{
    strcpy(TenSach,Ten);
}

void Sach :: setTheLoai(char Loai[])
{
    strcpy(TheLoai,Loai);
}

void Sach :: setTacGia(char TG[]) 
{
    strcpy(TacGia,TG);
}

void Sach :: setNamXuatBan(int NXB)
{
    this -> NamXuatBan = NXB;
}

//Lay gia tri trong protected
string Sach::getMaSach()
{
    return MaSach;
}

string Sach::getTenSach()
{
    return TenSach;
}

string Sach::getTheLoai()
{
    return TheLoai;
}

string Sach::getTacGia()
{
    return TacGia;
}

int Sach::getNamXuatBan()
{
    return NamXuatBan;
}

//***********************CLASS SINH VIEN***********************
class SinhVien
{
    protected:
        char MSV[10];
        char HoTen[100];
        char NganhHoc[100];
    public:
        //Thiet lap mot so gia tri
        void setSinhVien(char [], char [], char []);
        void setMSV(char[]);
        void setHoTen(char[]);
        void setNganhHoc(char[]);

        //Lay gia tri trong protected
        string getMSV();
        string getHoTen();
        string getNganhHoc();
};
//**************Thiet lap mot so gia tri***************
void SinhVien::setSinhVien(char msv[], char hoten[], char nganhhoc[])
{
    strcpy(MSV,msv);
    strcpy(HoTen,hoten);
    strcpy(NganhHoc,nganhhoc);
}

void SinhVien::setMSV(char msv[])
{
    strcpy(MSV, msv);
}

void SinhVien::setHoTen(char hoten[])
{
    strcpy(HoTen, hoten);
}

void SinhVien::setNganhHoc(char nganhhoc[])
{
    strcpy(NganhHoc, nganhhoc);
}

//**********Lay gia tri trong protected***********
string SinhVien::getMSV()
{
    return MSV;
}

string SinhVien::getHoTen()
{
    return HoTen;
}

string SinhVien::getNganhHoc()
{
    return NganhHoc;
}
//*******************CLASS MUON TRA SACH*********************
class MuonTra:public Sach, public SinhVien
{
    public:
        void setMuon(char [], char []);
        void setTra(char [], char []);
};

void MuonTra::setMuon (char msv[], char Ma[])
{
    strcpy(MSV,msv);
    strcpy(MaSach,Ma);
}

void MuonTra::setTra (char msv[], char Ma[])
{
    strcpy(MSV,msv);
    strcpy(MaSach,Ma);
}
//**************Chuc nang*****************
void ThemSach()
{
    char ch;
    do
    {
        system("cls");
        SET_COLOR(4);
        cout << "\t\t----------ADD NEW BOOK---------" << endl << endl;
        char MS[10], Ten[100], Loai[100], TG[100];
        int NXB;
        SET_COLOR(5);
        fflush(stdin);
        cout << "\n\n- Enter ID: ";
        cin.getline(MS,10);
        cout << "\n- Enter Title: ";
        cin.getline(Ten, 100);
        cout << "\n- Enter Category: ";
        cin.getline(Loai, 100);
        cout << "\n- Enter Author: ";
        cin.getline(TG, 100);
        cout << "\n- Enter Year Publishcation: ";
        cin >> NXB;
        Sach New;
        New.setSach(MS, Ten, Loai, TG, NXB);
        cout << endl << endl;
        Sleep(300);
        SET_COLOR(4);
        cout << "\n\nBOOK CREATED..." << endl;
        ofstream saveSach("sach.bin", ios :: binary | ios :: app);
        saveSach.write((char*)(&New), sizeof(Sach));
        saveSach.close();
        cout<<"\nDo you want to add more books? [y/n]";
	    ch = getch();
    } while(ch!='n'&& ch!='N');
}

void SuaSach()
{
    // Tìm và sửa theo mã sách
    system("cls");
    cout << "\t\t----------MODIFY BOOK---------" << endl << endl;
    string Find;
    char newMa[10], newTen[100], newLoai[100], newTG[100];
    int newNXB;
    Sach change;
    fflush(stdin);
    cout << "Enter book's id to modify: ";
    getline(cin, Find);
    ifstream readSach("sach.bin", ios :: binary);
    ofstream changeSach("changesach.bin", ios :: binary);
    if(!readSach) {// Kiểm tra file, nếu mở file không thành công thì báo lỗi!
        cout << endl;
        cout << "\t\tData read!" << endl;
    }
    else {
        system("cls");
        bool check = false;
        while(!readSach.eof()) {// Đọc từ đầu đến cuối file
            readSach.read((char *)(&change), sizeof(Sach));
            if(readSach.good()) {
                if(Find == change.getMaSach()) {
                    strcpy(newMa, Find.c_str());// Convert string sang char và copy vào newMa
                    change.setMaSach(newMa);
                    cout << "- Enter new title: ";
                    cin.getline(newTen, 100);
                    change.setTenSach(newTen);
                    cout << "\n- Enter new Category: ";
                    cin.getline(newLoai, 100);
                    change.setTheLoai(newLoai);
                    cout << "\n- Enter new Author: ";
                    cin.getline(newTG, 100);
                    change.setTacGia(newTG);
                    cout << "\n- Enter new Publishcation: ";
                    cin >> newNXB;
                    change.setNamXuatBan(newNXB);
                    cout << endl;
                    Sleep(100);
                    cout << "\t\tMODIFY SUCCESSFUL" << endl;
                    check = true;
                }
                changeSach.write((char*)(&change), sizeof(Sach));
            }
        }
        if(check == false) {
            cout << endl;
            cout << "\t\tBook not found! Please try again" << endl;
        }
    }
    changeSach.close();
    readSach.close();
    // Sao chép data từ file changesach.bin vào file sach.bin
    ofstream save_readSach("sach.bin", ios :: binary);
    ifstream read_changeSach("changesach.bin", ios :: binary);
    while(!read_changeSach.eof()) {
        read_changeSach.read((char*)(&change), sizeof(Sach));
        if(read_changeSach.good()) {
            save_readSach.write((char*)(&change), sizeof(Sach));
        }
    }
    read_changeSach.close();
    save_readSach.close();
    cout << "Press enter to goto main menu.....";
	getch();
}

void XoaSach()
{
    // Tìm và xoá theo mã sách, không xoá được nếu sinh viên đang mượn cuốn sách này
    system("cls");
    cout << "\t\t----------DELETE BOOK---------" << endl << endl;
    cout << endl;
    string Find;
    Sach Delete;
    MuonTra Muon;
    fflush(stdin);
    cout << "- Enter Book's ID to delete: ";
    getline(cin, Find);
    ifstream readSach("sach.bin", ios :: binary);
    ifstream readMuon("muontra.bin", ios :: binary);
    ofstream deleteSach("deletesach.bin", ios :: binary);
    if(!readMuon) {
        cout << endl;
        cout << "\n\nData read!" << endl;
    }
    else {
        bool check_1 = false;
        while(!readMuon.eof()) {
            readMuon.read((char *)(&Muon), sizeof(MuonTra));
            if(Find == Muon.getMaSach()) {
                check_1 = true;
            }
        }
        if(check_1 == false) {
            if(!readSach) {
                cout << endl;
                cout << "\n\nData read!" << endl;
            }
            else {
                bool check_2 = false;
                while(!readSach.eof()) {
                    readSach.read((char *)(&Delete), sizeof(Sach));
                    if(Find == Delete.getMaSach()) {
                        readSach.read((char *)(&Delete), sizeof(Sach));
                        check_2 = true;
                    }
                    if(readSach.good()) {
                        deleteSach.write((char *)(&Delete), sizeof(Sach));
                    }
                }
                if(check_2 == false) {
                    cout << endl;
                    cout << "Unvalid book's id. Please try again." << endl;
                }
                else {
                    cout << endl;
                    cout << "\n\nDelete successful!" << endl;
                }
            }
        }
        else {
            cout << endl;
            cout << "\n\nThis book is borrowed, cannot be deleted" << endl;
            return;
        }
    }
    deleteSach.close();
    readMuon.close();
    readSach.close();
    // Sao chép dữ liệu từ file deletesach.bin sang file sach.bin
    ofstream save_readSach("sach.bin", ios :: binary);
    ifstream read_deleteSach("deletesach.bin", ios :: binary);
    while(!read_deleteSach.eof()) {
        read_deleteSach.read((char *)(&Delete), sizeof(Sach));
        if(read_deleteSach.good()) {
            save_readSach.write((char *)(&Delete), sizeof(Sach));
        }
    }
    read_deleteSach.close();
    save_readSach.close();
    cout << "Press enter to goto main menu.....";
	getch();
}

void ThemSinhVien()
{   
    char ch;
    do
    {
        system("cls");
        cout << "\t\t----------ADD STUDENT---------" << endl << endl;
        cout << endl;
        char msv[10], hoten[100], nganhhoc[100];
        fflush(stdin);
        cout << "\n\n- Enter student's ID: ";
        cin.getline(msv, 10);
        fflush(stdin);
        cout << "\n- Enter full name: ";
        cin.getline(hoten, 100);
        fflush(stdin);
        cout << "\n- Enter a major: ";
        cin.getline(nganhhoc, 100);
        SinhVien New;
        New.setSinhVien(msv, hoten, nganhhoc);
        cout << endl;
        Sleep(100);
        cout << "\t\tADD STUDENT SUCCESSFUL" << endl;
        ofstream saveSinhVien("sinhvien.bin", ios :: binary | ios :: app);
        saveSinhVien.write((char*)(&New), sizeof(SinhVien));
        saveSinhVien.close();
        cout<<"\nDo you want to add more students? [y/n]";
		ch=getch();
    } while(ch!='n'&& ch!='N');
}

void SuaSinhVien() {
    // Tìm và sửa theo mã sinh viên
    system("cls");
    cout << "\t\t----------MODIFY STUDENT---------" << endl << endl;
    cout << endl;
    char newMSV[10], newHoTen[100], newNganhHoc[100];
    string Find;
    SinhVien change;
    fflush(stdin);
    cout << "Enter student's id to modify: ";
    getline(cin, Find);
    ifstream readSinhVien("sinhvien.bin", ios :: binary);
    ofstream changeSinhVien("changesinhvien.bin", ios :: binary);
    if(!readSinhVien) {// Kiểm tra file, nếu mở file không thành công thì báo lỗi!
        cout << endl;
        cout << "\t\tData read!" << endl;
    }
    else {
        bool check = false;
        while(!readSinhVien.eof()) {// Đọc từ đầu đến cuối file
            readSinhVien.read((char *)(&change), sizeof(SinhVien));
            if(readSinhVien.good()) {
                if(Find == change.getMSV()) {
                    strcpy(newMSV, Find.c_str());// Convert string sang char và copy vào newMSV
                    change.setMSV(newMSV);
                    system("cls");
                    cout << "\n- Enter new name: ";
                    cin.getline(newHoTen, 100);
                    change.setHoTen(newHoTen);
                    cout << "\n- Enter new major: ";
                    cin.getline(newNganhHoc, 100);
                    change.setNganhHoc(newNganhHoc);
                    cout << endl;
                    Sleep(100);
                    cout << "\n\nMODIFY STUDENT'S INFORMATION SUCCESSFUL..." << endl;
                    check = true;
                }
                changeSinhVien.write((char*)(&change), sizeof(SinhVien));
            }
        }
        if(check == false) {
            cout << endl;
            cout << "\n\nId unvalid! Please try again." << endl;
        }
    }
    changeSinhVien.close();
    readSinhVien.close();
    // Sao chép data từ file changesinhvien.bin vào file sinhvien.bin
    ofstream save_readSinhVien("sinhvien.bin", ios :: binary);
    ifstream read_changeSinhVien("changesinhvien.bin", ios :: binary);
    while(!read_changeSinhVien.eof()) {
        read_changeSinhVien.read((char*)(&change), sizeof(SinhVien));
        if(read_changeSinhVien.good()) {
            save_readSinhVien.write((char*)(&change), sizeof(SinhVien));
        }
    }
    read_changeSinhVien.close();
    save_readSinhVien.close();
    cout << "Press enter to goto main menu.....";
	getch();
}

void XoaSinhVien()
{
    system("cls");
    cout << "\t\t----------DELETE STUDENT---------" << endl << endl;
    cout << endl << endl;
    string Find;
    SinhVien Delete;
    MuonTra Muon;
    fflush(stdin);
    cout << "- Enter student's ID to delete: ";
    getline(cin, Find);
    ifstream readSinhVien("sinhvien.bin", ios :: binary);
    ifstream readMuon("muontra.bin", ios :: binary);
    ofstream deleteSinhVien("deletesinhvien.bin", ios :: binary);
    if(!readMuon) {
        cout << endl;
        cout << "\n\nData read!" << endl;
    }
    else {
        bool check_1 = false;
        while(!readMuon.eof()) {
            readMuon.read((char *)(&Muon), sizeof(MuonTra));
            if(Find == Muon.getMSV()) {
                check_1 = true;
            }
        }
        if(check_1 == false) {
            if(!readSinhVien) {
                cout << endl;
                cout << "\n\nData read!" << endl;
            }
            else {
                bool check_2 = false;
                while(!readSinhVien.eof()) {
                    readSinhVien.read((char *)(&Delete), sizeof(SinhVien));
                    if(Find == Delete.getMSV()) {
                        readSinhVien.read((char *)(&Delete), sizeof(SinhVien));
                        check_2 = true;
                    }
                    if(readSinhVien.good()) {
                        deleteSinhVien.write((char *)(&Delete), sizeof(SinhVien));
                    }
                }
                if(check_2 == false) {
                    cout << endl;
                    cout << "Unvalid Id! Please try again." << endl;
                }
                else
                {
                    cout << endl;
                    Sleep(100);
                    cout << "\t\tDELETE SUCCESSFUL!" << endl;
                }
            }
        }
        else {
            cout << endl;
            cout << "\n\nThis student is borrowing a book, cannot delete" << endl;
            return;
        }
    }
    deleteSinhVien.close();
    readMuon.close();
    readSinhVien.close();
    // Sao chép dữ liệu từ file deletesach.bin sang file sach.bin
    ofstream save_readSinhVien("sinhvien.bin", ios :: binary);
    ifstream read_deleteSinhVien("deletesinhvien.bin", ios :: binary);
    while(!read_deleteSinhVien.eof()) {
        read_deleteSinhVien.read((char *)(&Delete), sizeof(SinhVien));
        if(read_deleteSinhVien.good()) {
            save_readSinhVien.write((char *)(&Delete), sizeof(SinhVien));
        }
    }
    read_deleteSinhVien.close();
    save_readSinhVien.close();
    cout << "Press enter to goto main menu.....";
	getch();
}

void MuonSach()
{
    // Quản lý theo mã sinh viên và mã sách
    system("cls");
    cout << "\t\t----------BORROW BOOK---------" << endl << endl;
    cout << endl << endl;
    string MSV, MS;
    char msv[10], ms[10];
    fflush(stdin);
    cout << "- Enter student's ID: ";
    getline(cin, MSV);
    strcpy(msv, MSV.c_str());// Convert string sang char và copy vào mảng msv
    cout << "- Enter book's ID: ";
    getline(cin, MS);
    strcpy(ms, MS.c_str());// Convert string sang char và copy vào mảng ms
    MuonTra Muon;
    Sach sach;
    SinhVien sinhvien;
    Muon.setMuon(msv, ms);
    bool check_1 = false, check_2 = false;
    ifstream readSinhVien("sinhvien.bin", ios :: binary);
    if(!readSinhVien) {
        cout << endl;
        cout << "\n\nData read" << endl;
    }
    else {
        while(!readSinhVien.eof()) {
            readSinhVien.read((char *)(&sinhvien), sizeof(SinhVien));
            if(readSinhVien.good()) {
                if(MSV == sinhvien.getMSV()){
                    check_1 = true;
                }
            }
        }
    }
    readSinhVien.close();
    ifstream readSach("sach.bin", ios :: binary);
    if(!readSach) {
        cout << endl;
        cout << "\t\tData read" << endl;
    }
    else {
        while(!readSach.eof()) {
            readSach.read((char *)(&sach), sizeof(Sach));
            if(readSach.good()) {
                if(MS == sach.getMaSach()) {
                    check_2 = true;
                }
            }
        }
    }
    readSach.close();
    if(check_1 == true && check_2 == true) {
        ofstream saveMuon("muontra.bin", ios :: binary | ios :: app);
        saveMuon.write((char*)(&Muon), sizeof(MuonTra));
        saveMuon.close();
        cout << endl;
        cout << "\t\tBorrow book successful" << endl;
    }
    else if(check_1 == true && check_2 != true) {
        cout << endl;
        cout << "\n\nUnvalid book's id. Please try again!" << endl;
    }
    else if(check_1 != true && check_2 == true) {
        cout << endl;
        cout << "\n\nUnvalid student's id. Please try again!" << endl;
    }
    else {
        cout << endl;
        cout << "\n\nUnvalid book's id and student's id. Please try again!" << endl;
    }
    cout << "Press enter to goto main menu.....";
	getch();
}

void TraSach() {

    system("cls");
    cout << "\t\t----------RETURN BOOK---------" << endl << endl;
    cout << endl;
    string msv, ms;
    MuonTra Tra;
    fflush(stdin);
    cout << "- Enter student's id: ";
    getline(cin, msv);
    cout << "- Enter book's id: ";
    getline(cin, ms);
    ifstream readMuon("muontra.bin", ios :: binary);
    ofstream deleteMuon("deletemuon.bin", ios :: binary);
    if(!readMuon) {// Kiểm tra file, nếu mở file không thành công thì báo lỗi!
        cout << endl;
        cout << "\n\nData read" << endl;
    }
    else {
        bool check = false;
        while(!readMuon.eof()) {// Đọc từ đầu đến cuối file
            readMuon.read((char *)(&Tra), sizeof(MuonTra));
            if(msv == Tra.getMSV() && ms == Tra.getMaSach()) {
                readMuon.read((char *)(&Tra), sizeof(MuonTra));
                cout << endl;
                cout << "\n\nReturns book successful" << endl;
                check = true;
            }
            if(readMuon.good()) {
                deleteMuon.write((char *)(&Tra), sizeof(MuonTra));
            }
        }
        if (check == false) {
            cout << endl;
            cout << "\n\nUnvalid student's id or book's id. Please try again!" << endl;
        }
    }
    deleteMuon.close();
    readMuon.close();
    // Sao chép dữ liệu từ file deletemuon.bin sang file muontra.bin
    ofstream save_readMuon("muontra.bin", ios :: binary);
    ifstream read_deleteMuon("deletemuon.bin", ios :: binary);
    while(!read_deleteMuon.eof()) {
        read_deleteMuon.read((char *)(&Tra), sizeof(MuonTra));
        if(read_deleteMuon.good()) {
            save_readMuon.write((char *)(&Tra), sizeof(MuonTra));
        }
    }
    read_deleteMuon.close();
    save_readMuon.close();
    cout << "Press enter to goto main menu.....";
	getch();
}

void ToanBoSach()
{
    system("cls");
    SET_COLOR(4);
    cout << "\t\t----------DISPLAY ALL BOOK---------" << endl << endl;
    cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	SET_COLOR(5);
	cout<<setw(10)<<"\"No.\""<<setw(30)<<"\"Book ID\""<<setw(30)<<"\"Title\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Author\""<<setw(30)<<"\"Year of Publication\""<<endl;
	SET_COLOR(4);
    cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
    int stt = 0;
    Sach old;
    ifstream printSach("sach.bin", ios :: binary);
    if(!printSach) {// Kiểm tra file, nếu mở file không thành công thì báo lỗi!
        cout << endl;
        cout << "\n\nData read" << endl;
    }
    else {
        while(!printSach.eof()) {// Đọc từ đầu đến cuối file (Chưa đọc đến cuối file thì tiếp tục đọc)
            printSach.read((char *)(&old), sizeof(Sach));
            if(printSach.good())
            {// Nếu đọc file không gặp lỗi gì cả thì in ra màn hình
            SET_COLOR(5);
            cout << setw(8) << stt+1 << setw(30) << old.getMaSach() << setw(34) << old.getTenSach() << setw(33) << old.getTheLoai() << setw(30) << old.getTacGia() << setw(20) << old.getNamXuatBan() << endl;
	        SET_COLOR(4);
            cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            }
            stt++;
        }
    }
    printSach.close();
    cout << "\n\nPress enter to goto main menu.....";
	getch();
}

void ToanBoSinhVien()
{
    system("cls");
    SET_COLOR(4);
    cout << "\t\t----------DISPLAY ALL STUDENT---------" << endl << endl;
    cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	SET_COLOR(5);
	cout<<setw(10)<<"\"No.\""<<setw(30)<<"\"Student ID\""<<setw(30)<<"\"Full name\""<<setw(30)<<"\"Major\""<<endl;
	SET_COLOR(4);
    cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
    int stt = 0;
    SinhVien old;
    ifstream printSinhVien("sinhvien.bin", ios :: binary);
    if(!printSinhVien) {
        cout << endl;
        cout << "\t\tData read" << endl;
    }
    else {
        while(!printSinhVien.eof()) {
            printSinhVien.read((char *)(&old), sizeof(SinhVien));
            if(printSinhVien.good()) {  
                SET_COLOR(5);                   
                cout << setw(8) << stt+1 << setw(25) << old.getMSV() << setw(34) << old.getHoTen() << setw(33) << old.getNganhHoc() << endl;
             	SET_COLOR(4);
                cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
            }
            stt++;
        }
    }
    printSinhVien.close();
    cout << "Press enter to goto main menu.....";
	getch();
}

void SachMotSinhVienMuon()
{
    system("cls");
    SET_COLOR(4);
    cout << "\t\t----------SEARCH THE QUANTITY OF BOOKS A STUDENT BORROW---------" << endl << endl;
    string Find;
    int stt = 0;
    cout << "Enter student ID: ";
    getline(cin, Find);
    cout << endl;
    cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
	SET_COLOR(5);
	cout<<setw(10)<<"\"No.\""<<setw(30)<<"\"Student ID\""<<setw(30)<<"\"Book name\""<<setw(30)<<"\"Major\""<<setw(30)<<"\"Author\""<<setw(30)<<"\"Year publising\""<<endl;
	SET_COLOR(4);
    cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
    ifstream readMuon("muontra.bin", ios :: binary);
    MuonTra printMuon;
    Sach Muon;
    if(!readMuon) {// Kiểm tra file, nếu mở file không thành công thì báo lỗi!
        cout << endl;
        cout << "\n\nData read!" << endl;
    }
    else {
        bool check = false;
        while(!readMuon.eof()) {// Đọc từ đầu đến cuối file
            readMuon.read((char *)(&printMuon), sizeof(MuonTra));
            if(readMuon.good()) {
                if(Find == printMuon.getMSV()) 
                {
                    SET_COLOR(5);
                    cout << setw(8) << stt+1 << setw(30) << printMuon.getMaSach();
                    ifstream readSach("sach.bin", ios :: binary);
                    if(!readSach) {// Kiểm tra file, nếu mở file không thành công thì báo lỗi!
                        cout << endl;
                        cout << "\t\tLoi doc du lieu !" << endl;
                    }
                    else {
                        while(!readSach.eof()) {
                            readSach.read((char *)(&Muon), sizeof(Sach));
                            if(readSach.good()) {
                                if(printMuon.getMaSach() == Muon.getMaSach()) {
                                    cout << setw(34) << Muon.getTenSach() << setw(33) << Muon.getTheLoai() << setw(30) << Muon.getTacGia() << setw(20) << Muon.getNamXuatBan() << endl;
                                    SET_COLOR(4);
                                    cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;

                                }
                            }
                        }
                    }
                    readSach.close();
                    stt++;
                    check = true;
                }
            }
        }
        if (check == false) {
            cout << endl;
            cout << "\n\nUnvalid ID. Please try again!" << endl;
        }
    }
    readMuon.close();
    cout << "Press enter to goto main menu.....";
	getch();
}

void ToanBoSachDuocMuon()
{
    system("cls");
    SET_COLOR(4);
    cout << "\t\t----------DISPLAY ALL BOOK BORRWED IN LIBRARY---------" << endl << endl;
    cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
    SET_COLOR(5);
    cout<<setw(10)<<"\"Student ID\""<<setw(30)<<"\"Full name\""<<setw(30)<<"\"Book ID\""<<setw(30)<<"\"Title\""<<setw(30)<<"\"Category\""<<setw(30)<<"\"Author\""<<setw(30)<<"\"Year Publishing\""<<endl;
    SET_COLOR(4);
    cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;
    int stt = 0;
    ifstream readMuon("muontra.bin", ios :: binary);
    SinhVien printSinhVien;
    MuonTra printMuon;
    Sach printSach;
    if(!readMuon) {// Kiểm tra file, nếu mở file không thành công thì báo lỗi!
        cout << endl;
        cout << "\t\tLoi doc du lieu !" << endl;
    }
    else {
        while(!readMuon.eof()) {// Đọc từ đầu đến cuối file
            readMuon.read((char *)(&printMuon), sizeof(MuonTra));
            if(readMuon.good())
            {
                cout << setw(8) << printMuon.getMSV();
                //Đọc dữ liệu từ file sinhvien.bin
                ifstream readSinhVien("sinhvien.bin", ios :: binary);
                if(!readSinhVien) {// Kiểm tra file, nếu mở file không thành công thì báo lỗi!
                    cout << endl;
                    cout << "\n\nData read!" << endl;
                }
                else {
                    while(!readSinhVien.eof()) {
                        readSinhVien.read((char *)(&printSinhVien), sizeof(SinhVien));
                        if(readSinhVien.good()) {
                            if(printMuon.getMSV() == printSinhVien.getMSV())
                            {   
                                cout << setw(34) << printSinhVien.getHoTen();
                            }
                        }
                    }
                }
                readSinhVien.close();
                //Đọc dữ liệu từ file sach.bin
                ifstream readSach("sach.bin", ios :: binary);
                if(!readSach) {// Kiểm tra file, nếu mở file không thành công thì báo lỗi!
                    cout << endl;
                    cout << "\n\nData read!" << endl;
                }
                else {
                    while(!readSach.eof()) {
                        readSach.read((char *)(&printSach), sizeof(Sach));
                        if(readSach.good()) {
                            if(printMuon.getMaSach() == printSach.getMaSach())
                            {
                                cout << setw(30) << printSach.getMaSach() << setw(34) << printSach.getTenSach() << setw(33) << printSach.getTheLoai() << setw(30) << printSach.getTacGia() << setw(20) << printSach.getNamXuatBan() << endl;
                                SET_COLOR(4);
                                cout<<"__________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<"______________________________"<<endl;

                            }
                        }
                    }
                }
                readSach.close();
                stt++;
            }
        }
    }
    readMuon.close();
    cout << "Press enter to goto main menu.....";
	getch();
}

class GiaoDien
{
        friend class Sach;
        friend class SinhVien;
        friend class MuonTra;
    private:
    public:
        void Menu();
};

void GiaoDien::Menu()
{
	while (1)
    {
		system("cls");
	   	SET_COLOR(4);
		cout << setw( 25 ) << "-------------" << endl

          << setw( 25 ) << "| MAIN MENU |" << endl

          << setw( 25 ) << "-------------" << endl << endl;
		  SET_COLOR(6);
          cout << setw( 52 )

          << "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl;

		SET_COLOR(5);

    cout  << setw( 33 ) << "( A ) Add Book\t\t\t"

          << setw( 33 ) << "( M ) Modify Book" << endl << endl

          << setw( 33 ) << "( S ) Delete Book"

          << setw( 48 ) << "( E ) Add Student" << endl << endl

          << setw( 36 ) << "( T ) Modify Student"

          << setw( 48 ) << "( U ) Delete Student" << endl << endl
          
          << setw( 33 ) << "( B ) Borrow Book"

          << setw( 48 ) << "( R ) Return Book" << endl << endl

		  << setw( 35 ) << "( D ) Display Books"

		  << setw( 50 ) << "( N ) Display Student" << endl << endl

		  << setw( 51 ) << "( O ) Search Book Borrow by Student"

		  << setw( 43 ) << "( V ) Search All Book Borrowed" << endl << endl

          << setw( 26 ) << "( Q ) Quit" << endl << endl;
		  SET_COLOR(4);
	cout  << setw( 32 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(30,21);
	     
		switch(getche())
		{
			case 'a': 
		 	case 'A': ThemSach(); break;
         
			case 'm': 
		 	case 'M': SuaSach(); break;
         
		 	case 's':
		 	case 'S': XoaSach(); break;
         
		 	case 'e':
		 	case 'E': ThemSinhVien(); break;
		 
		 	case 't':
		 	case 'T': SuaSinhVien(); break;
         
		 	case 'u':
		 	case 'U': XoaSinhVien(); break;

            case 'b':
            case 'B': MuonSach(); break;

            case 'r':
            case 'R': TraSach(); break;

            case 'd':
            case 'D': ToanBoSach(); break;

            case 'n':
            case 'N': ToanBoSinhVien(); break;

            case 'o':
            case 'O': SachMotSinhVienMuon(); break;

            case 'v':
            case 'V': ToanBoSachDuocMuon(); break;
		 
		 	case 'q':
		 	case 'Q': exit(0); break;
         
		 	default:
				puts("\n\n \t\tSelect only from the given menu.....\n \t\tpress enter to to go to main menu......");
				getch();
       } //end switch
     }//end while
    
	getch();
}
/***************************************************************/
//////////////////////////////////////////////////
//   				MAIN MENU		 			//
//////////////////////////////////////////////////
int main()
{
    GiaoDien d;
	system("color Bf");
	d.Menu();
	system("pause");
	return 0;
}