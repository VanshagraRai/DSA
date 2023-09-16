#include <iostream>
using namespace std;

bool linearSearch(int *arr,int num , int size){
    
    if(size == 0){
        return false;
    }
    if(arr[0] == num)
        return true;

    else
        return linearSearch(arr+1,num,size-1);
}

int main(){

    int arr[6] = {1,2,3,4,5,6};
    int num = 9;
    if(linearSearch(arr,num,6))
        cout << "Element is Present" << endl;
    else
        cout << "Element is not Present" << endl;
}  