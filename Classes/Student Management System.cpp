#include <iostream>
#include <string>
using namespace std;

const int MAX_COURSES = 10, MAX_STUDENTS = 100;
class Student {
private:
    string name;
    string roll;
    string courses[MAX_COURSES];
    double cgpa;
    int courseCount;

public:
    Student() : cgpa(0), courseCount(0) {} 
    Student(string n, string r, double g) : name(n), roll(r), cgpa(g), courseCount(0) {}
    void addCourse(string course) {
        if (courseCount < MAX_COURSES) {
            courses[courseCount++] = course;
        } else {
            cout << "Course limit reached!\n";
        }
    }
    void updateCGPA(double newCGPA) {
        if (newCGPA >= 0 && newCGPA <= 4) {
            cgpa = newCGPA;
        } else {
            cout << "Invalid CGPA!\n";
        }
    }

    void display() const {
        cout << "Name: " << name << "\nRoll: " << roll << "\nCGPA: " << cgpa << "\nCourses: ";
        for (int i = 0; i < courseCount; ++i) {
            cout << courses[i] << " ";
        }
        cout << endl;
    }

    string getRoll() const { return roll; }
};
class StudentManagementSystem {
private: 
    Student students[MAX_STUDENTS];
    int studentCount; 

public:
    StudentManagementSystem() : studentCount(0) {} 
    void addStudent(const Student& student) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = student;
        } else {
            cout << "Student limit reached!\n";
        }
    }
    Student* searchStudent(string roll) {
        for (int i = 0; i < studentCount; ++i) {
            if (students[i].getRoll() == roll) {
                return &students[i];
            }
        }
        return nullptr; 
    }
    void displayAll() const {
        if (studentCount == 0) {
            cout << "No students found.\n";
            return;
        }
        for (int i = 0; i < studentCount; ++i) {
            students[i].display();
        }
    }
};

int main() {
    StudentManagementSystem sms;
    sms.addStudent({"Harry", "1", 7.5});
    sms.addStudent({"Jasmine", "2", 8.9});
    Student* student1 = sms.searchStudent("1");
    if (student1) {
        student1->addCourse("Math");
    }
    Student* student2 = sms.searchStudent("2");
    if (student2) {
        student2->updateCGPA(4.0);
        student2->addCourse("Science");
    }
    sms.displayAll();

    return 0;
}
