#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;


class Employee {
private:
    int id;
    string name;
    float salary;

public:

    Employee(int id, string name, float salary) : id(id), name(name), salary(salary) {}
    

    Employee() : id(0), name(""), salary(0) {}
    

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
    

    void printInfo() const {
        cout << "ID: " << id << " - Ten: " << name << " - Luong: " << salary << endl;
    }
    

    int getId() const {
        return id;
    }
    

    void setSalary(float salary) {
        this->salary = salary;
    }
};


class EmployeeManager {
private:
    vector<Employee> list;
    int nextId;
    

    int findIndexById(int id) const {
        for (size_t i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }
    

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

    EmployeeManager() : nextId(3001) {}
    

    void addEmployee() {
        Employee emp(nextId, "", 0);
        emp.input();
        list.push_back(emp);
        cout << "Them nhan vien thanh cong! Ma NV: " << nextId << endl;
        nextId++;
    }
    

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
