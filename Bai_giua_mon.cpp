#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    Employee(int id, string name, float salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    Employee() {
        this->id = 0;
        this->name = "";
        this->salary = 0;
    }

    void input(int id) {
        this->id = id;
        cout << "Nhap ten nhan vien: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap luong nhan vien: ";
        cin >> salary;
    }

    void printInfo() {
        cout << "ID: " << id << " - Ten: " << name << " - Luong: " << (int)salary << endl;
    }

    int getId() {
        return id;
    }

    void setSalary(float salary) {
        this->salary = salary;
    }

    float getSalary() {
        return salary;
    }
};

class EmployeeManager {
private:
    vector<Employee> list;
    int nextId;

public:
    EmployeeManager() {
        nextId = 3001;
    }

    void addEmployee() {
        Employee emp;
        emp.input(nextId);
        list.push_back(emp);
        nextId++;
        cout << "Da them nhan vien thanh cong!" << endl;
    }

    void addExistingEmployee(Employee emp) {
        list.push_back(emp);
        nextId = emp.getId() + 1;
    }

    void showAll() {
        if (list.empty()) {
            cout << "Danh sach nhan vien rong!" << endl;
            return;
        }
        cout << "=== DANH SACH NHAN VIEN ===" << endl;
        for (int i = 0; i < list.size(); i++) {
            list[i].printInfo();
        }
    }

    void updateSalaryById() {
        if (list.empty()) {
            cout << "Danh sach nhan vien rong!" << endl;
            return;
        }

        int id;
        cout << "Nhap ma nhan vien can cap nhat luong: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                float newSalary;
                cout << "Nhap luong moi: ";
                cin >> newSalary;
                list[i].setSalary(newSalary);
                cout << "Da cap nhat luong thanh cong!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Khong tim thay nhan vien co ma " << id << endl;
        }
    }

    void deleteById() {
        if (list.empty()) {
            cout << "Danh sach nhan vien rong!" << endl;
            return;
        }

        int id;
        cout << "Nhap ma nhan vien can xoa: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                list.erase(list.begin() + i);
                cout << "Da xoa nhan vien thanh cong!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
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
            cout << "Lua chon cua ban: ";
            cin >> choice;

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
                    cout << "Lua chon khong hop le! Vui long chon lai." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    EmployeeManager manager;
    
    // Them du lieu mau ngam
    Employee emp1(3001, "Nguyen Van A", 12000000);
    Employee emp2(3002, "Tran Thi B", 15000000);
    Employee emp3(3003, "Le Van C", 18000000);
    
    manager.addExistingEmployee(emp1);
    manager.addExistingEmployee(emp2);
    manager.addExistingEmployee(emp3);
    
    manager.menu();
    return 0;
}
