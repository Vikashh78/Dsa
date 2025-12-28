#include <iostream>
using namespace std;
#include <vector>

int simpleSieve(int n){

    int count = 0;
    vector<bool> prime(n+1, true); // initially marked all as prime
    prime[0] = prime[1] = false;
    for(int i=2; i<n; i++){
        if(prime[i])
        count++;

        for(int j=2*i; j<n; j=j+i){ // jo i ke table me aa rha usko unprime mark karo
            prime[j]=false;
        }
    }
    return count;
}

int main(){

    cout<<"Enter a number : ";
    int n;
    cin >> n;

    int result = simpleSieve(n);
    cout<<"Tota number of prime number that are strictly less then n : "<<result<<endl;;
    


    return 0;
}