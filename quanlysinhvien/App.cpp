#include<bits/stdc++.h>
#include "Danhsachsinhvien.cpp"

#ifndef App
#define App

using namespace std;

class App{
private:
    Danhsachsinhvien danhsach;
public:
    void menu(){
        int luachon;
        string filename = "sinhvien.txt";
        danhsach.docfile(filename);
        do{
            cout << "\n====== MENU QUAN LY SINH VIEN ======" << endl;
            cout << "1. In danh sach sinh vien" << endl;
            cout << "2. Them sinh vien" << endl;
            cout << "3. Sua thong tin sinh vien" << endl;
            cout << "4. Xoa thong tin sinh vien" << endl;
            cout << "5. Tim kiem sinh vien" << endl;
            cout << "6. Sap xep sinh vien" << endl;
            cout << "7. Thong ke sinh vien" << endl;
            cout << "8. Sao luu danh sach sinh vien" << endl;
            cout << "0. Thoat" << endl;
            cout << "Nhap lua chon: ";
            cin >> luachon;

            switch(luachon){
                case 1:{
                    danhsach.indssinhvien();
                    break;
                }
                case 2:{
                    int n;
                    cout << "Nhap so luong sinh vien: ";
                    cin >> n;
                    danhsach.themsinhvien(n);
                    break;
                }
                case 3:{
                    string msv;
                    cout << "Nhap msv can sua: ";
                    cin >> msv;
                    danhsach.suathongtinsinhvien(msv);
                    break;
                }
                case 4:{
                    string msv;
                    cout << "Nhap ma sinh vien can xoa: ";
                    cin >> msv;
                    danhsach.xoasinhvien(msv);
                    break;
                }
                case 5:{
                    danhsach.timkiemsinhvien();
                    break;
                }   
                case 6:{
                    danhsach.sapxep();
                    break;
                }
                case 7:{
                    danhsach.thongkesinhvien();
                    break;
                }
                case 8:{
                    danhsach.luufile(filename);
                    break;
                }
                case 0:
                    cout << "Thoat chuong trinh!" << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le!" << endl;
            }
        }
        while(luachon != 0);
    }
};

#endif