#include <iostream>
using namespace std;

bool binarySearch(int *arr, int low ,int high, int num){
    if(low > high)
        return false;

    int mid = low + (high - low) / 2;
    
    if(arr[mid] == num)
        return true;
    
    else if (arr[mid] < num)
        return binarySearch(arr,mid+1,high,num);
    
    else
        return binarySearch(arr,low,mid-1,num);
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int num = 7;
    int low = 0;
    int high = 6 - 1;

    if(binarySearch(arr,low,high,num))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;
}