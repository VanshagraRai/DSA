#include <iostream>
using namespace std;

int euclid(int m , int n){
    while (n%m!=0){
        int r = n % m;
        n = m;
        m = r;
    }
    return m;
}

int main(){
    int m = 48;
    int n = 36;
    cout << "GCD of " << m << " and " << n << " is " << euclid(m,n);
}