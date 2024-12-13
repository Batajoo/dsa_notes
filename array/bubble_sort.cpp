#include <iostream>

//Time Complexity - O(n^2)
//Bubble Sort 

void printArray(int* arr, int size){
    std::cout << "-----------------------------" << std::endl;
    for(int i=0; i<size; i++){
        std::cout << arr[i] << " ";
    }
        std::cout << std::endl << "-----------------------------" << std::endl;
}

void bubbleSort(int * arr, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {12,1,4,3,5,0,2};
    std::cout << "Unsorted array" << std::endl;
    printArray(arr, 7);
    bubbleSort(arr, 7);
    std::cout << "Sorted array" << std::endl;
    printArray(arr, 7);
    return 0;
}