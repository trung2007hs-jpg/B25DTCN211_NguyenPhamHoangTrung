#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ===================================
// LOP TRUU TUONG - DA HINH
// ===================================
class Manager {
public:
    virtual void display() = 0;
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
    virtual ~Manager() {}
};

// ===================================
// DOI TUONG LOP HOC
// ===================================
class ClassRoom {
private:
    string classId;
    string className;
    string major;
    string classType; // CNTT / NGOAI_NGU

public:
    ClassRoom(string id, string name, string m, string type) {
        classId = id;
        className = name;
        major = m;
        classType = type;
    }

    string getId() {
        return classId;
    }

    void setName(string name) {
        className = name;
    }

    void show() {
        cout << "Ma lop: " << classId
             << " | Ten lop: " << className
             << " | Chuyen nganh: " << major
             << " | Phan loai: " << classType
             << endl;
    }
};

// ===================================
// QUAN LY LOP HOC
// ===================================
class ClassManager : public Manager {
private:
    vector<ClassRoom> classes;

public:
    ClassManager() {
        classes.push_back(ClassRoom("C01", "C++ Co Ban", "CNTT", "CNTT"));
        classes.push_back(ClassRoom("C02", "Java Web", "CNTT", "CNTT"));
        classes.push_back(ClassRoom("E01", "Tieng Anh IT", "Ngoai ngu", "NGOAI NGU"));
    }

    void display() {
        if (classes.empty()) {
            cout << "Danh sach lop trong\n";
            return;
        }
        for (int i = 0; i < classes.size(); i++) {
            classes[i].show();
        }
    }

    void add() {
        string id, name, major;
        char choice;
        string type;

        cout << "Ma lop: ";
        getline(cin, id);

        cout << "Ten lop: ";
        getline(cin, name);

        cout << "Chuyen nganh: ";
        getline(cin, major);

        cout << "Chon phan loai lop:\n";
        cout << "C - CNTT\n";
        cout << "N - Ngoai ngu\n";
        cout << "Lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 'C':
            case 'c':
                type = "CNTT";
                break;
            case 'N':
            case 'n':
                type = "NGOAI NGU";
                break;
            default:
                cout << "Lua chon khong hop le\n";
                return;
        }

        classes.push_back(ClassRoom(id, name, major, type));
        cout << "Them lop thanh cong\n";
    }

    void remove() {
        string id;
        cout << "Nhap ma lop can xoa: ";
        getline(cin, id);

        for (int i = 0; i < classes.size(); i++) {
            if (classes[i].getId() == id) {
                classes.erase(classes.begin() + i);
                cout << "Xoa lop thanh cong\n";
                return;
            }
        }
        cout << "Khong tim thay lop\n";
    }

    void update() {
        string id, newName;
        cout << "Nhap ma lop: ";
        getline(cin, id);

        for (int i = 0; i < classes.size(); i++) {
            if (classes[i].getId() == id) {
                cout << "Ten lop moi: ";
                getline(cin, newName);
                classes[i].setName(newName);
                cout << "Cap nhat thanh cong\n";
                return;
            }
        }
        cout << "Khong tim thay lop\n";
    }
};

// ===================================
// DOI TUONG SINH VIEN
// ===================================
class Student {
private:
    string studentId;
    string name;
    string birthDate;
    string email;
    string phone;

public:
    Student(string id, string n, string dob, string e, string p) {
        studentId = id;
        name = n;
        birthDate = dob;
        email = e;
        phone = p;
    }

    string getId() {
        return studentId;
    }

    void show() {
        cout << "Ma SV: " << studentId
             << " | Ten: " << name
             << " | Ngay sinh: " << birthDate
             << " | Email: " << email
             << " | SDT: " << phone
             << endl;
    }
};

// ===================================
// QUAN LY SINH VIEN
// ===================================
class StudentManager : public Manager {
private:
    vector<Student> students;

public:
    StudentManager() {
        students.push_back(Student("SV01", "Nguyen Van A", "01/01/2004",
                                   "a@gmail.com", "0901234567"));
    }

    void display() {
        if (students.empty()) {
            cout << "Danh sach sinh vien trong\n";
            return;
        }
        for (int i = 0; i < students.size(); i++) {
            students[i].show();
        }
    }

    void add() {
        string id, name, dob, email, phone;

        cout << "Ma SV: ";
        getline(cin, id);
        cout << "Ten SV: ";
        getline(cin, name);
        cout << "Ngay sinh: ";
        getline(cin, dob);
        cout << "Email: ";
        getline(cin, email);
        cout << "So dien thoai: ";
        getline(cin, phone);

        students.push_back(Student(id, name, dob, email, phone));
        cout << "Them sinh vien thanh cong\n";
    }

    void remove() {
        string id;
        cout << "Nhap ma SV can xoa: ";
        getline(cin, id);

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "Xoa sinh vien thanh cong\n";
                return;
            }
        }
        cout << "Khong tim thay sinh vien\n";
    }

    void update() {
        cout << "Chuc nang cap nhat sinh vien chua trien khai\n";
    }
};

// ===================================
// HAM MAIN
// ===================================
int main() {
    ClassManager classManager;
    StudentManager studentManager;
    Manager* manager = NULL;

    while (true) {
        cout << "\n===== MENU TONG =====\n";
        cout << "1. Quan ly lop hoc\n";
        cout << "2. Quan ly sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        if (choice == 1)
            manager = &classManager;
        else if (choice == 2)
            manager = &studentManager;
        else {
            cout << "Lua chon khong hop le\n";
            continue;
        }

        cout << "\n===== MENU CHUC NANG =====\n";
        cout << "1. Hien thi\n";
        cout << "2. Them moi\n";
        cout << "3. Xoa\n";
        cout << "4. Cap nhat\n";
        cout << "Chon: ";

        int sub;
        cin >> sub;
        cin.ignore();

        if (sub == 1) manager->display();
        else if (sub == 2) manager->add();
        else if (sub == 3) manager->remove();
        else if (sub == 4) manager->update();
        else cout << "Lua chon sai\n";
    }

    return 0;
}

