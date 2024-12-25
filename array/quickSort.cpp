#include <iostream>

void bubbleSort(int *, int);
void printArray(int* arr, int size){
    std::cout << "-----------------------------" << std::endl;
    for(int i=0; i<size; i++){
        std::cout << arr[i] << " ";
    }
        std::cout << std::endl << "-----------------------------" << std::endl;
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }

        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i<j);

    temp = A[j];
    A[j] = A[low];
    A[low] = temp;
    return j;
}

void quickSort(int A[], int low, int high){
    int partitionIndex; 

    if(low<high){
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex -1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main(){
    int arr[] = {10,9,3,2,0,6,4,3,1,5,8};
    int size = 11;
    // bubble sort unadaptive part
    std::cout << "Unsorted array" << std::endl;
    printArray(arr, size);
    quickSort(arr, 0, size-1);
    // bubbleSort(arr, size);
    std::cout << "Sorted array" << std::endl;
    printArray(arr, size);
     std::cout << std::endl;
    return 0;
}


void bubbleSort(int * arr, int size){
    int temp;
    for(int i=0;i<size-1; i++){
        for(int j=0; j<size-1-i; j++){
            if(arr[j]> arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
