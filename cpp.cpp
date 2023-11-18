#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    double marks;
    string address;
    long long phone;
    int age;
    string department;
    string email;
    string birthDate;
    string guardianName;
    long long guardianPhone;
    Student* next;

public:
    Student(string name, int rollNumber, double marks, const string& address,
        long long phone, int age, const string& department, const string& email,
        const string& birthDate, const string& guardianName, long long guardianPhone)
        : name(name), rollNumber(rollNumber), marks(marks), address(address), phone(phone),
        age(age), department(department), email(email), birthDate(birthDate),
        guardianName(guardianName), guardianPhone(guardianPhone), next(nullptr) {}

    double calculateGPA() const {
        return (marks / 10.0);
    }

    // Public getters for private attributes
    string getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    double getMarks() const {
        return marks;
    }

    string getAddress() const {
        return address;
    }

    long long getPhone() const {
        return phone;
    }

    int getAge() const {
        return age;
    }

    string getDepartment() const {
        return department;
    }

    string getEmail() const {
        return email;
    }

    string getBirthDate() const {
        return birthDate;
    }

    string getGuardianName() const {
        return guardianName;
    }

    long long getGuardianPhone() const {
        return guardianPhone;
    }

    // Public setter for phone and guardian phone
    void setPhone(long long newPhone) {
        phone = newPhone;
    }

    void setGuardianPhone(long long newGuardianPhone) {
        guardianPhone = newGuardianPhone;
    }

    // Public method to update student info
    void updateInfo(double newMarks, const string& newAddress, int newAge, const string& newDepartment,
        const string& newEmail, const string& newBirthDate, const string& newGuardianName) {
        marks = newMarks;
        address = newAddress;
        age = newAge;
        department = newDepartment;
        email = newEmail;
        birthDate = newBirthDate;
        guardianName = newGuardianName;
    }

    // Public method to display student details
    void displayDetails() const {
        cout << "Name: " << name << ", Roll Number: " << rollNumber
            << ", Marks: " << marks << ", GPA: " << fixed << setprecision(2) << calculateGPA() << endl;
        cout << "Address: " << address << ", Phone: " << phone << endl;
        cout << "Age: " << age << ", Department: " << department << endl;
        cout << "Email: " << email << ", Birth Date: " << birthDate << endl;
        cout << "Guardian Name: " << guardianName << ", Guardian Phone: " << guardianPhone << endl;
    }

    friend class StudentList;
};

class StudentList {
private:
    Student* head;

public:
    StudentList() : head(nullptr) {}

    void addStudent(string name, int rollNumber, double marks, string address, long long phone, int age,
        string department, string email, string birthDate, string guardianName, long long guardianPhone) {
        if (isValidPhoneNumber(phone) && isValidPhoneNumber(guardianPhone)) {
            Student* newStudent = new Student(name, rollNumber, marks, address, phone, age, department, email, birthDate, guardianName, guardianPhone);
            newStudent->next = head;
            head = newStudent;
            cout << "Student added successfully." << endl;
        } else {
            cout << "Invalid phone number or guardian phone number. Please enter 10-digit integers." << endl;
        }
    }

    void displayStudents() const {
        Student* current = head;
        cout << "Student List:" << endl;
        while (current != nullptr) {
            current->displayDetails();
            current = current->next;
        }
    }

    Student* findStudentByRollNumber(int rollNumber) {
        Student* current = head;
        while (current != nullptr) {
            if (current->getRollNumber() == rollNumber) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void removeStudent(int rollNumber) {
        if (head == nullptr) {
            cout << "Student list is empty." << endl;
            return;
        }

        if (head->getRollNumber() == rollNumber) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Student removed successfully." << endl;
            return;
        }

        Student* current = head;
        while (current->next != nullptr) {
            if (current->next->getRollNumber() == rollNumber) {
                Student* temp = current->next;
                current->next = current->next->next;
                delete temp;
                cout << "Student removed successfully." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Student not found with the given Roll Number." << endl;
    }

    void updateStudentInfo(int rollNumber, double newMarks, const string& newAddress, int newAge, const string& newDepartment,
        const string& newEmail, const string& newBirthDate, const string& newGuardianName, long long newPhone, long long newGuardianPhone) {
        if (isValidPhoneNumber(newPhone) && isValidPhoneNumber(newGuardianPhone)) {
            Student* studentToUpdate = findStudentByRollNumber(rollNumber);
            if (studentToUpdate) {
                studentToUpdate->updateInfo(newMarks, newAddress, newAge, newDepartment, newEmail, newBirthDate, newGuardianName);
                studentToUpdate->setPhone(newPhone); // Set the new phone
                studentToUpdate->setGuardianPhone(newGuardianPhone); // Set the new guardian phone
                cout << "Student information updated successfully." << endl;
            } else {
                cout << "Student not found with the given Roll Number." << endl;
            }
        } else {
            cout << "Invalid phone number or guardian phone number. Please enter 10-digit integers." << endl;
        }
    }



    static bool isValidPhoneNumber(long long number) {
        return to_string(number).length() == 10;
    }

    ~StudentList() {
        while (head != nullptr) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    StudentList studentList;

    while (true) {
        int choice;
        cout << "Student Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search by Roll Number" << endl;
        cout << "4. Remove Student" << endl;
        cout << "5. Update Student Info" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
    string name;
    int rollNumber;
    double marks;
    string address;
    long long phone;
    int age;
    string department;
    string email;
    string birthDate;
    string guardianName;
    long long guardianPhone;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    cout << "Enter Marks: ";
    cin >> marks;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, address);
    
    // Input validation for the phone number
    do {
        cout << "Enter Phone (10 digits): ";
        cin >> phone;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a 10-digit number." << endl;
        }
        else {
            string phoneStr = to_string(phone);
            if (phoneStr.length() != 10) {
                cout << "Phone number must be exactly 10 digits." << endl;
            }
            else {
                break;
            }
        }
    } while (true);
    
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Department: ";
    getline(cin, department);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Birth Date: ";
    getline(cin, birthDate);
    cout << "Enter Guardian Name: ";
    getline(cin, guardianName);
    cout << "Enter Guardian Phone (10 digits): ";
    
    // Input validation for the guardian phone number
    do {
        
        cin >> guardianPhone;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a 10-digit number." << endl;
        }
        else {
            string guardianPhoneStr = to_string(guardianPhone);
            if (guardianPhoneStr.length() != 10) {
                cout << "Guardian phone number must be exactly 10 digits." << endl;
            }
            else {
                break;
            }
        }
    } while (true);

    studentList.addStudent(name, rollNumber, marks, address, phone, age, department, email, birthDate, guardianName, guardianPhone);
    break;
}

        case 2:
            studentList.displayStudents();
            break;
        case 3: {
            int rollNumber;
            cout << "Enter Roll Number to search for a student: ";
            cin >> rollNumber;
            Student* student = studentList.findStudentByRollNumber(rollNumber);
            if (student) {
                student->displayDetails();
            } else {
                cout << "Student not found with the given Roll Number." << endl;
            }
            break;
        }
        case 4: {
            int rollNumber;
            cout << "Enter Roll Number to remove a student: ";
            cin >> rollNumber;
            studentList.removeStudent(rollNumber);
            break;
        }
        case 5: {
            int rollNumber;
            double newMarks;
            string newAddress;
            int newAge;
            string newDepartment;
            string newEmail;
            string newBirthDate;
            string newGuardianName;
            long long newPhone;
            long long newGuardianPhone;
            cout << "Enter Roll Number to update student info: ";
            cin >> rollNumber;
            cout << "Enter new Marks: ";
            cin >> newMarks;
            cin.ignore();
            cout << "Enter new Address: ";
            getline(cin, newAddress);
            cout << "Enter new Age: ";
            cin >> newAge;
            cin.ignore();
            cout << "Enter new Department: ";
            getline(cin, newDepartment);
            cout << "Enter new Email: ";
            getline(cin, newEmail);
            cout << "Enter new Birth Date: ";
            getline(cin, newBirthDate);
            cout << "Enter new Guardian Name: ";
            getline(cin, newGuardianName);
            cout << "Enter new Phone: ";
            cin >> newPhone;
            cout<<"Enter newGuardianPhone";
            cin>>newGuardianPhone;
            studentList.updateStudentInfo(rollNumber, newMarks, newAddress, newAge, newDepartment, newEmail, newBirthDate, newGuardianName, newPhone,newGuardianPhone);
            break;
        }
        case 6:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}