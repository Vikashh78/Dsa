#include<iostream>
using namespace std;

int findSqrt(int size){
    int start = 0, end = size, ans = -1;
    while(start < end){
        int mid = start + (end-start)/2;
        if(mid*mid == size){
            return mid;
        }
        else if(mid*mid < size){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid;
        }  
    }
    return ans;
}

double morePrecision(int size, int precision, int result){
    double factor = 1;
    double ans = result;
    for(int i=0; i<precision; i++){
        factor=factor/10;
            for(double j=ans; j*j<size; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int size;
    cout<<"Enter the number to find sqrt : ";
    cin>>size;
    int result = findSqrt(size);
    if(result != -1){
    cout<<"Sqaure root of " << size <<" is "<< morePrecision(size, 4, result) <<endl;
    }
    else{
        cout<<"Unable to find sqrt of "<< size <<" as it is NEGATIVE"<< endl;
    }
    return 0;
}