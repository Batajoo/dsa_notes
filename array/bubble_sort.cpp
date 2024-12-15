#include <iostream>

//Time Complexity - O(n^2)
//Bubble Sort 
void bubbleSortPractice(int*, int);

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

void bubbleSortAdaptive(int * arr, int n){
    int temp = 0;
    int isSorted = 0;

    for(int i=0; i<n-1; i++){
        isSorted = 1;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

int main(){
    int arr[] = {1,4,3,5,0,2};
    int arr2[] = {10,9,3,2,0,6,4,3,1,5,8};
    int size1 = 6, size2 = 10;
    // bubble sort unadaptive part
    std::cout << "Unsorted array" << std::endl;
    printArray(arr, size1);
    bubbleSort(arr, size1);
    std::cout << "Sorted array" << std::endl;
    printArray(arr, size1);
     std::cout << std::endl;

    //bubble Sort Adaptive part 
    std::cout <<"Unsorted array - Adaptive" << std::endl;
    printArray(arr2, size2);
    bubbleSortPractice(arr2, size2);
    std::cout << "Sorted array " << std::endl;
    printArray(arr2, size2);
    return 0;
}

void bubbleSortPractice(int * arr, int size){
    int temp;
    int isSorted = 0;
    for(int i=0; i<size-1; i++){
        isSorted = 1;
        for(int j=0; j<size-1-i;j++){
            if(arr[j] > arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}