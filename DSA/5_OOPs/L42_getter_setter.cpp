#include <iostream>
using namespace std;

class person{

    //properties of person

    private:
    string name;

    public:
    int age;
    int mobile;

    string getName(){
       return name;
    }

    void setName(string s){
       name = s;
    }

};

int main(){

    //creating object of person class
    
    person p1;   //static allocation
    p1.age = 20;
    p1.mobile = 461796;

    p1.setName("Ram");

    cout<<"Name is : "<< p1.getName() <<endl;

    cout<<"Age : "<< p1.age <<endl; 
    cout<<"Contact : "<< p1.mobile <<endl<<endl;


    person *p2 = new person;  //Dynamic allocation
    (*p2).age = 30;
    p2-> mobile = 738268829;

    (*p2).setName("Bunty");

    cout<<"Name is : "<< (*p2).getName() <<endl;

    cout<<"Age : "<< (*p2).age <<endl;
    cout<<"Contact : "<< p2-> mobile <<endl;


    return 0;
}