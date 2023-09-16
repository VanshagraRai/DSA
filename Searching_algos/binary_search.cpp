#include <iostream>
using namespace std;

int binarySearch(int arr[],int size,int num){
    int mid,low = 0;
    int high = size - 1;
    while(low <= high){

        mid = low + (high-low)/2; // See comments down
        
        if(arr[mid] == num){
            return 1;
        }
        else if (arr[mid] < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


int main(){
    int arr[6] = {1,2,3,4,6,8};
    int n = 2;
    cout << binarySearch(arr,6,n) << endl;
    
}
/*
integer range = 2³¹ - 1

if low = 2³¹ - 1
if high = 2³¹ - 1

low + high > int range 

so we use = low + (high-low)/2 
*/