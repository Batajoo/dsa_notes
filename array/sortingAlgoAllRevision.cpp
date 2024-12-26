#include <iostream>
#include <climits>

void printArray(int *, int);

void bubbleSort(int * arr, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int * arr, int size){
    int temp;
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = key;
    }
}

void selectionSort(int * arr, int size){
    int temp;
    for(int i=0; i<size; i++){
        int min=i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[min]){
                min = j;        
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int partition(int * arr, int low, int high){
    int temp;
    int i = low+1;
    int pivot = arr[low];
    int j = high;

    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);

    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}

void quickSort(int * arr, int low, int high){
    int partitionIndex;
    if(low<high){
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex +1, high);
    }
}

void merge(int * arr, int size, int low, int high){
    
}

int main(){
    int arr[] = {10,9,3,2,0,6,4,3,1,5,8};
    int arr2[] = {10,9,3,2,0,6,4,3,1,5,8};
    int arr3[] = {10,9,3,2,0,6,4,3,1,5,8};
    int arr4[] = {10,9,3,2,0,6,4,3,1,5,8};
    int size = 11;
    // bubble sort unadaptive part
    
    std::cout << "BubbleSort - Sorted array" << std::endl;
    printArray(arr, size);
    bubbleSort(arr, size);
    printArray(arr, size);
    std::cout << std::endl;
    std::cout << "InsertionSort - Sorted array" << std::endl;
    printArray(arr2, size);
    insertionSort(arr2, size);
    printArray(arr2, size);
    std::cout << std::endl;
    std::cout << "SelectionSort - Sorted array" << std::endl;
    printArray(arr3, size);
    selectionSort(arr3, size);
    printArray(arr3, size);
    std::cout << std::endl;
    std::cout << "quickSort - Sorted array" << std::endl;
    printArray(arr4, size);
    quickSort(arr4, 0, size-1);
    printArray(arr4, size);

    return 0;
}

void printArray(int* arr, int size){
    std::cout << "-----------------------------" << std::endl;
    for(int i=0; i<size; i++){
        std::cout << arr[i] << " ";
    }
        std::cout << std::endl << "-----------------------------" << std::endl;
}