#include <iostream>
using namespace std;

bool isSorted(int *arr, int size){
    if(size == 0 || size == 1)
        return true;
    if(arr[0] > arr[1])
        return false;
    else
        return isSorted(arr+1,--size);

}

int main(){
    int arr[6] = {1,2,3,7,5,6};
    if(isSorted(arr,6))
        cout << "Array is Sorted" << endl;
    else
        cout << "Array is not Sorted" << endl;
}