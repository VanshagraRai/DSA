#include <iostream>
using namespace std;

void sayDigit(int n){
    
    string digitWords[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    if (n==0)
        return;
    
    int dig = n % 10;
    n = n / 10;
    sayDigit(n);
    cout << digitWords[dig] << endl;
}

int main(){
    int n = 432;
    sayDigit(n);
}