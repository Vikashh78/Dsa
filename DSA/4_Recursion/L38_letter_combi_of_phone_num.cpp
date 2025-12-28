#include <iostream>
using namespace std;
#include <vector>

void solve(string digits, string output, int index, vector<string>& answer, string mapping[]){

    //base case-
    if(index >= digits.size()){
        answer.push_back(output);
        return;
    }

    int number = digits[index] - '0'; // converting string to numeric
    string value = mapping[number];
    for(int i=0; i<value.size(); i++){
        output.push_back(value[i]);

        //Recursive call
        solve(digits, output, index+1, answer, mapping);

        output.pop_back();  //back_tracked
    }
}


vector<string> letterCombinations(string digits) {

    vector<string> digits = {"23"}; 

    vector<string> answer;

    if(digits.size() == 0)
    return answer;

    string output = "";
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, output, index, answer, mapping);

    return answer;
        
}
