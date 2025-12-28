#include <iostream>
using namespace std;
#include <unordered_map>
#include <map>

int main() {

    // map creation
    unordered_map <string, int> map;


    // insertion - there are three ways to insert in map  TC:O(1)
    // 1st.
    pair<string, int> pair1 = make_pair("hello", 1);
    map.insert(pair1);

    // 2nd way
    pair<string, int> pair2("hii", 3);
    map.insert(pair2);

    // 3rd way
    map["hey"] = 2;



    // searching  --  Tc: O(1)
    cout<< map["hello"] <<endl;

    cout<< map.at("hii") <<endl;

    // importanat point
    //cout<< map.at("unknown") <<endl;      // it will through an error 'out of range'
    cout<< map["unknown"] <<endl;           // it will create a new key with value 0 and display ans 0
    cout<< map.at("unknown") <<endl;        // now it will also result 0



    // to check presence
    cout<< map.count("hello") <<endl;



    // erase
    map.erase("hey");
    cout<< map.size() <<endl;



    // iterator                                                  
    unordered_map<string, int> :: iterator it = map.begin();
    while(it != map.end()) {
        cout<< it->first <<" " << it->second <<endl;
        it++;
    }
    // or you can use a for each loop to iterate


    return 0;
}