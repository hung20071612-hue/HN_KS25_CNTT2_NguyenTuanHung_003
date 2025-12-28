#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// L?p Employee
class Employee {
private:
    int id;
    string name;
    float salary;

public:
    // Hàm t?o có tham s?
    Employee(int id, string name, float salary) : id(id), name(name), salary(salary) {}
    
    // Hàm t?o không tham s?
    Employee() : id(0), name(""), salary(0) {}
    
    // Nh?p thông tin (mã du?c truy?n t? ngoài)
    void input() {
        cout << "Nhap ten nhan vien: ";
        getline(cin, name);
        
        while (true) {
            cout << "Nhap luong: ";
            cin >> salary;
            
            if (cin.fail() || salary < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Luong khong hop le! Vui long nhap lai.\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
    }
    
    // Hi?n th? thông tin
    void printInfo() const {
        cout << "ID: " << id << " - Ten: " << name << " - Luong: " << salary << endl;
    }
    
    // Tr? v? mã nhân viên
    int getId() const {
        return id;
    }
    
    // C?p nh?t luong
    void setSalary(float salary) {
        this->salary = salary;
    }
};

// L?p EmployeeManager
class EmployeeManager {
private:
    vector<Employee> list;
    int nextId;
    
    // Hàm h? tr? tìm index theo ID
    int findIndexById(int id) const {
        for (size_t i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }
    
    // Hàm nh?p s? nguyên an toàn
    int inputInteger(const string& prompt) {
        int value;
        while (true) {
            cout << prompt;
            cin >> value;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Vui long nhap so nguyen hop le!\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }
    
    // Hàm nh?p s? th?c an toàn
    float inputFloat(const string& prompt) {
        float value;
        while (true) {
            cout << prompt;
            cin >> value;
            
            if (cin.fail() || value < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Vui long nhap so hop le (>= 0)!\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
        }
    }

public:
    // Kh?i t?o nextId = 3001
    EmployeeManager() : nextId(3001) {}
    
    // Thêm nhân viên m?i
    void addEmployee() {
        Employee emp(nextId, "", 0);
        emp.input();
        list.push_back(emp);
        cout << "Them nhan vien thanh cong! Ma NV: " << nextId << endl;
        nextId++;
    }
    
    // Hi?n th? danh sách nhân viên
    void showAll() const {
        if (list.empty()) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        cout << "\n===== DANH SACH NHAN VIEN =====" << endl;
        for (const auto& emp : list) {
            emp.printInfo();
        }
    }
    
    // C?p nh?t luong theo ID
    void updateSalaryById() {
        if (list.empty()) {
            cout << "Danh sach rong! Khong the cap nhat." << endl;
            return;
        }
        
        int id = inputInteger("Nhap ma nhan vien can cap nhat: ");
        int index = findIndexById(id);
        
        if (index != -1) {
            float newSalary = inputFloat("Nhap luong moi: ");
            list[index].setSalary(newSalary);
            cout << "Cap nhat luong thanh cong!" << endl;
        } else {
            cout << "Khong tim thay nhan vien co ma " << id << endl;
        }
    }
    
    // Xóa nhân viên theo ID
    void deleteById() {
        if (list.empty()) {
            cout << "Danh sach rong! Khong the xoa." << endl;
            return;
        }
        
        int id = inputInteger("Nhap ma nhan vien can xoa: ");
        int index = findIndexById(id);
        
        if (index != -1) {
            list.erase(list.begin() + index);
            cout << "Xoa nhan vien thanh cong!" << endl;
        } else {
            cout << "Khong tim thay nhan vien co ma " << id << endl;
        }
    }
    
    // Menu chính
    void menu() {
        int choice;
        do {
            cout << "\n----- MENU -----" << endl;
            cout << "1. Them nhan vien" << endl;
            cout << "2. Hien thi danh sach" << endl;
            cout << "3. Cap nhat luong" << endl;
            cout << "4. Xoa nhan vien" << endl;
            cout << "5. Thoat" << endl;
            cout << "----------------" << endl;
            choice = inputInteger("Nhap lua chon: ");
            
            switch (choice) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    showAll();
                    break;
                case 3:
                    updateSalaryById();
                    break;
                case 4:
                    deleteById();
                    break;
                case 5:
                    cout << "Tam biet!" << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le! Vui long chon tu 1-5." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    EmployeeManager manager;
    manager.menu();
    return 0;
}
