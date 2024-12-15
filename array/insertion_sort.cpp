#include <iostream>
// Time Complexity - Worst Case = O(n^2) - Best Case = O(n)
void insertion_sort_practice(int*, int);

void printArray(int* arr, int size){
    std::cout << "-----------------------------" << std::endl;
    for(int i=0; i<size; i++){
        std::cout << arr[i] << " ";
    }
        std::cout << std::endl << "-----------------------------" << std::endl;
}

void insertion_sort(int * arr, int size){
    int key, j;
    for(int i=1; i<size; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    int arr[] = {10,9,3,2,0,6,4,3,1,5,8};
    int size = 11;
    // bubble sort unadaptive part
    std::cout << "Unsorted array" << std::endl;
    printArray(arr, size);
    insertion_sort_practice(arr, size);
    std::cout << "Sorted array" << std::endl;
    printArray(arr, size);
     std::cout << std::endl;
    return 0;
}


void insertion_sort_practice(int * arr, int size){
    int temp;
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = key;
    }
}