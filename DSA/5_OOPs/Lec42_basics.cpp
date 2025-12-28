#include <iostream>
using namespace std;

class person{

    //properties of person

    public:
    string name;
    int age;
    int mobile;

    //consructor manually created
    person(){
        cout<<"Constructor called at the time of object creation"<<endl;
    }

};

int main(){

    // creating object of person class
    person p1;

    person *p2 = new person();

    // p1.name ="Ram";
    // p1.age = 20;
    // p1.mobile = 6323827;

    // cout<<"Name : "<< p1.name <<endl;
    // cout<<"Age : "<< p1.age <<endl;
    // cout<<"Contact : "<< p1.mobile <<endl;


    return 0;
}