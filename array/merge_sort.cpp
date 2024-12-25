#include <iostream>


void printArray(int* arr, int size){
    std::cout << "-----------------------------" << std::endl;
    for(int i=0; i<size; i++){
        std::cout << arr[i] << " ";
    }
        std::cout << std::endl << "-----------------------------" << std::endl;
}

void merge(int A[], int low, int mid, int high){
    int i,j,k;
    int B[high+1];
    i=k=low;
    j=mid+1; 

    while(i <= mid && j <= high){
        if(A[i]<A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while(i <= mid){
        B[k] = A[i];
        i++;
        k++;
    }
    while(j <= high){
        B[k] = A[j];
        j++;
        k++;
    }
    
    for(int l=low; l<high+1; l++){
        A[l] = B[l];
    }

}   

void mergeSort(int a[], int low, int high){
    if(low<high){
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main(){
    int arr[] = {10,9,3,2,0,6,4,3,1,5,8};
    int size = 11;
    // bubble sort unadaptive part
    std::cout << "Unsorted array" << std::endl;
    printArray(arr, size);
    mergeSort(arr, 0, size-1);
    // merge(arr, 0, 5, size);
    std::cout << "Sorted array" << std::endl;
    printArray(arr, size);
     std::cout << std::endl;
    return 0;
}