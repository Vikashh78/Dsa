#include <iostream>
using namespace std;
class Student {

    private:
    string studentName;
    int studentRollno;
    int studentAge;
    // get method for student name to access  
    // private variable studentName
    public:
        string getStudentName() {
            return studentName;
        }
    // set method for student name to set 
    // the value in private variable studentName
    void setStudentName(string studentName) {
        this -> studentName = studentName;
    }
    
    int getStudentRollno() {
        return studentRollno;
    }
    void setStudentRollno(int studentRollno) {
        this -> studentRollno = studentRollno;
    }
    
    int getStudentAge() {
        return studentAge;
    }
    void setStudentAge(int studentAge) {
        this -> studentAge = studentAge;
    }
};

int main() {
    Student obj;
    
    obj.setStudentName("Rahul");
    obj.setStudentRollno(101);
    obj.setStudentAge(22);
    
    cout << "Student Name : " << obj.getStudentName() << endl;
    cout << "Student Rollno : " << obj.getStudentRollno() << endl;
    cout << "Student Age : " << obj.getStudentAge();
}