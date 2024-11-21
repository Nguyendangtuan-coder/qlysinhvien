#include<bits/stdc++.h>
#include "sinhvien.cpp"

#ifndef Danhsachsinhvien
#define Danhsachsinhvien

using namespace std;

class Danhsachsinhvien{
private:
    list<Sinhvien> ds;
public:
    void docfile(const string &filename){
        ifstream file(filename);
        if(!file.is_open()){
            cout << "Khong mo duoc file: " << filename << endl;
            return;
        }
        Sinhvien sv;
        while(file >> sv){
            ds.push_back(sv);
           
        }
        file.close();
    }
    
    void indssinhvien() const{
        cout << "\nDanh sach sinh vien " << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
        cout << "| Ma SV     | Ten sinh vien      | Tuoi  | Diem trung binh |" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
        for (const auto& sv : ds) {
            cout << sv;
        }
    }

    void themsinhvien(int n){
        for(int i = 0; i < n; i++){
            Sinhvien sv;
            cout << "\nNhap thong tin sinh vien thu " << (i + 1) << endl;
            cin >> sv;
            ds.push_back(sv);
        }
        sapxeptheoten();
    }

    void suathongtinsinhvien(const string &msv){
        bool thongtin = false;
        for(auto &sv : ds){
                if(sv.getmsv() == msv){
                    cout << "Nhap thong tin moi cho sinh vien: " << endl;
                    cin >> sv;
                    thongtin = true;
                    break;
                }
            }
        if(!thongtin){
            cout << "Khong thay thong tin sinh vien voi ma " << msv << endl;
        }
    }

    void xoasinhvien(const string &msv){
        for(auto xoa = ds.begin(); xoa != ds.end(); ){
                if(xoa->getmsv() == msv){
                    xoa = ds.erase(xoa);
                }
                else{
                    ++xoa;
                }
        }
    }

    void timkiemtheokitu(const string &ten){
    	cout << endl;
    	cout << "+-----------+--------------------+-------+-----------------+" << endl;
        cout << "| Ma SV     | Ten sinh vien      | Tuoi  | Diem trung binh |" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
        
        for(const auto &sv : ds){
            if(sv.getten().find(ten) != string::npos){
                cout << sv;
            }
        }

    }
    void timkiemtheomsv(const string &msv){
        cout << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
        cout << "| Ma SV     | Ten sinh vien      | Tuoi  | Diem trung binh |" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
        
        for(const auto &sv : ds){
            if(sv.getmsv().find(msv) != string::npos){
                cout << sv;
            }
        }
    }
    void timkiemdiem(const float &diem){
        cout << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
        cout << "| Ma SV     | Ten sinh vien      | Tuoi  | Diem trung binh |" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
       
        for(const auto &sv : ds){
            if(sv.getdiem() == diem){
                cout << sv;
            }
        }
    }
    
    void timkiemsinhvien(){
        int luachon;
        cout << "\nTim kiem danh sach theo?" << endl;
        cout << "\t5.1Tim kiem theo ki tu " << endl;
        cout << "\t5.2Tim kiem theo ma sinh vien " << endl;
        cout << "\t5.3Tim kiem theo diem " << endl;
        cout << "Nhap lua chon: ";
        cin >> luachon;

        switch (luachon){
            case 1:{
                string ten;
                cout << "Nhap ki tu can tim: ";
                cin.ignore();
                getline(cin,ten);
                timkiemtheokitu(ten);
                break;
            }
            case 2:{
                string msv;
                cout << "Nhap ma sinh vien can tim: ";
                cin >> msv;
                timkiemtheomsv(msv);
                break;
            }
            case 3:{
                float diem;
                cout << "Nhap diem can tim: ";
                cin >> diem;
                timkiemdiem(diem);
                break;
            }
            default:{
                cout << "Lua chon khong hop le!" << endl;
                return; 
            }   
        }
    }

   void sapxeptheoten(){
        ds.sort([](const Sinhvien &a, const Sinhvien &b){
            return a.getten() < b.getten(); 
        });
        indssinhvien();
    }
    void sapxeptheodiem(){
        ds.sort([](const Sinhvien &a, const Sinhvien &b){
            return a.getdiem() < b.getdiem(); 
        });
        indssinhvien();
    }
    void sapxeptheotuoi(){
        ds.sort([](const Sinhvien &a, const Sinhvien &b){
            return a.gettuoi() < b.gettuoi(); 
        });
        indssinhvien();
    }
    void sapxeptheomsv(){
        ds.sort([](const Sinhvien &a, const Sinhvien &b){
            return a.getmsv() < b.getmsv();
        });
        indssinhvien();
    }

    void sapxep(){
        int luachon;
        cout << "Sap xep theo?" << endl;
        cout << "\t6.1 Sap xep theo ten " << endl;
        cout << "\t6.2 Sap xep theo diem " << endl;
        cout << "\t6.3 Sap  xep theo tuoi " << endl;
        cout << "\t6.4 Sap xep theo ma sinh vien" << endl;
        cout << "Nhap lua chon: ";
        cin >> luachon;
        cin.ignore();

        switch (luachon){
            case 1:{
                sapxeptheoten();
                break;
            }
            case 2:{
                sapxeptheodiem();
                break;
            }
            case 3:{
                sapxeptheotuoi();
                break;
            }
            case 4:{
                sapxeptheomsv();
                break;
            }
            default:{
                cout << "Lua chon khong hop le!" << endl;
                return;
            }
        }
    }

    void thongkediemcaonhat() const{
        float maxdiem = INT_MIN;
        for (const auto& sv : ds){
            if (sv.getdiem() > maxdiem){
                maxdiem = sv.getdiem();
            }
        }
        if (maxdiem == INT_MIN){
            cout << "Khong co sinh vien nao trong danh sach" << endl;
            return;
        }
        cout << "\nSinh vien co diem cao nhat" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
        cout << "| Ma SV     | Ten sinh vien      | Tuoi  | Diem trung binh |" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;

        for (const auto& sv : ds){
            if (sv.getdiem() == maxdiem){
                cout << sv;
            }
        }
        
    }
    void thongkediemthapnhat() const{
        float mindiem = INT_MAX;
        for (const auto& sv : ds){
            if (sv.getdiem() < mindiem){
                mindiem = sv.getdiem();
            }
        }
        if (mindiem == INT_MAX){
            cout << "Khong co sinh vien nao trong danh sach" << endl;
            return;
        }
        cout << "\nSinh vien co diem cao nhat" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
        cout << "| Ma SV     | Ten sinh vien      | Tuoi  | Diem trung binh |" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;

        for (const auto& sv : ds){
            if (sv.getdiem() == mindiem){
                cout << sv;
            }
        }    
    }
    void thongketuoicaonhat() const{
        int maxtuoi = INT_MIN;  
        for (const auto& sv : ds){
            if (sv.gettuoi() > maxtuoi){
                maxtuoi = sv.gettuoi();
            }
        }
        if (maxtuoi == INT_MIN) {
            cout << "Khong co sinh vien nao trong danh sach" << endl;
            return;
        }
        cout << "\nSinh vien co tuoi lon nhat" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
        cout << "| Ma SV     | Ten sinh vien      | Tuoi  | Diem trung binh |" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;

        for (const auto& sv : ds){
            if (sv.gettuoi() == maxtuoi){
                cout << sv;
            }
        }
    }
    void thongketuoithapnhat() const{
        int mintuoi = INT_MAX;  
        for (const auto& sv : ds){
            if (sv.gettuoi() < mintuoi){
                mintuoi = sv.gettuoi();
            }
        }
        if (mintuoi == INT_MAX) {
            cout << "Khong co sinh vien nao trong danh sach" << endl;
            return;
        }
        cout << "\nSinh vien co tuoi thap nhat" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;
        cout << "| Ma SV     | Ten sinh vien      | Tuoi  | Diem trung binh |" << endl;
        cout << "+-----------+--------------------+-------+-----------------+" << endl;

        for (const auto& sv : ds){
            if (sv.gettuoi() == mintuoi){
                cout << sv;
            }
        }
    }
    void thongkediemtrungbinh() const{
        if (ds.empty()){
            cout << "Khong co sinh vien nao trong danh sach de tinh diem trung binh." << endl;
            return;
        }
        float tongdiem = 0.0;
        for (const auto& sv : ds){
            tongdiem += sv.getdiem();
        }
        
        float diemtrungbinh = tongdiem / ds.size();
        cout << "Diem trung binh cua danh sach sinh vien la: " << fixed << setprecision(2) << diemtrungbinh << endl;
    }

    void thongkesinhvien(){
        int luachon;
        cout << "Thong ke" << endl;
        cout << "\t7.1 Thong ke diem cao nhat" << endl;
        cout << "\t7.2 Thong ke diem thap nhat" << endl;
        cout << "\t7.3 Thong ke tuoi cao nhat" << endl;
        cout << "\t7.4 Thong ke tuoi thap nhat" << endl;
        cout << "\t7.5 Thong ke diem trung binh" << endl;
        cout << "nhap lua chon: ";
        cin >> luachon;
        cin.ignore();

        switch(luachon){
            case 1:{
                thongkediemcaonhat();
                break;
            }
            case 2:{
                thongkediemthapnhat();
                break;
            }
            case 3:{
                thongketuoicaonhat();
                break;
            }
            case 4:{
                thongketuoithapnhat();
                break;
            }
            case 5:{
                thongkediemtrungbinh();
                break;
            }
            default:{
                cout << "Lua chon khong hop le!" << endl;
                return;
            }
        }
    }

    void luufile(const string &filename)const{
        ofstream file(filename);
        if(!file.is_open()){
            cout << "Khong mo duoc file: " << filename << endl;
            return;
        }

        for(const auto &sv : ds){
            file << sv;
        }

        file.close();
        cout << "Da luu vao file " << endl;
    }
};

#endif