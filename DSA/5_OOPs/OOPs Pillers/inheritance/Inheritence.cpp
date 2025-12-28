#include <iostream>
using namespace std;

class Human{  //parent class
    public:
    //properties
    int height;
    int weight;
    int age;

    public:
    int getAge(){
        return age;
    }
    void setAge(int age){
        this->age = age;
    }
};

class Male : public Human{ //Single inheritance
    public:
    string colour;

    public:
    string getColour(){
        return colour;
    }
    void setColour(string col){
        this->colour = col;
    }

};

int main(){

    //creating an object for male class
    Male person1;
    person1.age=22;
    person1.weight=50;
    person1.height=170;
    person1.setAge(23);

    cout<<"person age is "<<person1.age<<endl;

    person1.setColour("brown");
    cout<<"person colour is "<<person1.getColour()<<endl;


    return 0;
}