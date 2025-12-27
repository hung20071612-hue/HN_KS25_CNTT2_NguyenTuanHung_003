#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class co s? - Base class
class QuanLy {
protected:
    string ma;
    string ten;
public:
    virtual void hienThi() = 0;
    virtual void nhap() = 0;
    virtual string getMa() { return ma; }
    virtual void capNhat() = 0;
    virtual ~QuanLy() {}
};

// Class LopHoc k? th?a QuanLy
class LopHoc : public QuanLy {
private:
    string chuyenNganh;
    string phanLoai;
    
public:
    void nhap() {
        cout << "Nhap ma lop: ";
        cin >> ma;
        cin.ignore();
        cout << "Nhap ten lop: ";
        getline(cin, ten);
        cout << "Nhap chuyen nganh: ";
        getline(cin, chuyenNganh);
        cout << "Nhap phan loai (CNTT/Ngoai ngu): ";
        getline(cin, phanLoai);
    }
    
    void hienThi() {
        cout << "Ma: " << ma << " | Ten: " << ten 
             << " | CN: " << chuyenNganh << " | Loai: " << phanLoai << endl;
    }
    
    void capNhat() {
        cin.ignore();
        cout << "Nhap ten lop moi: ";
        getline(cin, ten);
        cout << "Nhap chuyen nganh moi: ";
        getline(cin, chuyenNganh);
        cout << "Nhap phan loai moi: ";
        getline(cin, phanLoai);
    }
};

// Class SinhVien k? th?a QuanLy
class SinhVien : public QuanLy {
private:
    string ngaySinh;
    string email;
    string soDienThoai;
    
public:
    void nhap() {
        cout << "Nhap ma sinh vien: ";
        cin >> ma;
        cin.ignore();
        cout << "Nhap ten sinh vien: ";
        getline(cin, ten);
        cout << "Nhap ngay sinh: ";
        getline(cin, ngaySinh);
        cout << "Nhap email: ";
        getline(cin, email);
        cout << "Nhap so dien thoai: ";
        getline(cin, soDienThoai);
    }
    
    void hienThi() {
        cout << "Ma: " << ma << " | Ten: " << ten << " | NS: " << ngaySinh 
             << " | Email: " << email << " | SDT: " << soDienThoai << endl;
    }
    
    void capNhat() {
        cin.ignore();
        cout << "Nhap ten sinh vien moi: ";
        getline(cin, ten);
        cout << "Nhap ngay sinh moi: ";
        getline(cin, ngaySinh);
        cout << "Nhap email moi: ";
        getline(cin, email);
        cout << "Nhap so dien thoai moi: ";
        getline(cin, soDienThoai);
    }
};

// Danh sách l?p h?c
vector<LopHoc*> dsLop;

void hienThiLop() {
    if (dsLop.empty()) {
        cout << "Danh sach rong!\n";
        return;
    }
    for (int i = 0; i < dsLop.size(); i++) {
        dsLop[i]->hienThi();
    }
}

void themLop() {
    LopHoc* lop = new LopHoc();
    lop->nhap();
    dsLop.push_back(lop);
    cout << "Them thanh cong!\n";
}

void xoaLop() {
    string ma;
    cout << "Nhap ma lop can xoa: ";
    cin >> ma;
    for (int i = 0; i < dsLop.size(); i++) {
        if (dsLop[i]->getMa() == ma) {
            delete dsLop[i];
            dsLop.erase(dsLop.begin() + i);
            cout << "Xoa thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

void capNhatLop() {
    string ma;
    cout << "Nhap ma lop can cap nhat: ";
    cin >> ma;
    for (int i = 0; i < dsLop.size(); i++) {
        if (dsLop[i]->getMa() == ma) {
            dsLop[i]->capNhat();
            cout << "Cap nhat thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

// Danh sách sinh viên
vector<SinhVien*> dsSV;

void hienThiSV() {
    if (dsSV.empty()) {
        cout << "Danh sach rong!\n";
        return;
    }
    for (int i = 0; i < dsSV.size(); i++) {
        dsSV[i]->hienThi();
    }
}

void themSV() {
    SinhVien* sv = new SinhVien();
    sv->nhap();
    dsSV.push_back(sv);
    cout << "Them thanh cong!\n";
}

void xoaSV() {
    string ma;
    cout << "Nhap ma sinh vien can xoa: ";
    cin >> ma;
    for (int i = 0; i < dsSV.size(); i++) {
        if (dsSV[i]->getMa() == ma) {
            delete dsSV[i];
            dsSV.erase(dsSV.begin() + i);
            cout << "Xoa thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

void capNhatSV() {
    string ma;
    cout << "Nhap ma sinh vien can cap nhat: ";
    cin >> ma;
    for (int i = 0; i < dsSV.size(); i++) {
        if (dsSV[i]->getMa() == ma) {
            dsSV[i]->capNhat();
            cout << "Cap nhat thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay!\n";
}

// Menu con cho l?p h?c
void menuLopHoc() {
    while (true) {
        cout << "\n=== QUAN LY LOP HOC ===\n";
        cout << "1. Hien thi\n";
        cout << "2. Them moi\n";
        cout << "3. Xoa\n";
        cout << "4. Cap nhat\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        int chon;
        cin >> chon;
        
        switch (chon) {
            case 1: hienThiLop(); break;
            case 2: themLop(); break;
            case 3: xoaLop(); break;
            case 4: capNhatLop(); break;
            case 0: return;
            default: cout << "Khong hop le!\n";
        }
    }
}

// Menu con cho sinh viên
void menuSinhVien() {
    while (true) {
        cout << "\n=== QUAN LY SINH VIEN ===\n";
        cout << "1. Hien thi\n";
        cout << "2. Them moi\n";
        cout << "3. Xoa\n";
        cout << "4. Cap nhat\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        int chon;
        cin >> chon;
        
        switch (chon) {
            case 1: hienThiSV(); break;
            case 2: themSV(); break;
            case 3: xoaSV(); break;
            case 4: capNhatSV(); break;
            case 0: return;
            default: cout << "Khong hop le!\n";
        }
    }
}

// Menu chính
int main() {
    while (true) {
        cout << "\n=== HE THONG RIKKEI EDU ===\n";
        cout << "1. Quan ly lop hoc\n";
        cout << "2. Quan ly sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        int chon;
        cin >> chon;
        
        switch (chon) {
            case 1: menuLopHoc(); break;
            case 2: menuSinhVien(); break;
            case 0: 
                cout << "Tam biet!\n";
                return 0;
            default: cout << "Khong hop le!\n";
        }
    }
    return 0;
}
