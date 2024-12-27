#include <iostream>
#include <climits>

void printArray(int* arr, int size){
    std::cout << "-----------------------------" << std::endl;
    for(int i=0; i<size; i++){
        std::cout << arr[i] << " ";
    }
        std::cout << std::endl << "-----------------------------" << std::endl;
}


void merge(int * arr, int low, int mid, int high){
    int i,j,k;
    int b[high+1];
    i=k=low;
    j=mid+1;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            b[k] = arr[i];
            i++;
            k++;
        } else{
            b[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        b[k] = arr[i];
        i++;
        k++;
    }

    while(j<=high){
        b[k] = arr[j];
        j++;
        k++;
    }

    for(int l=low; l<high+1; l++){
        arr[l] = b[l];
    }
}

void mergeSort(int * arr, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1 , high);
        merge(arr, low, mid, high);
    }
}

void countSort(int * arr, int size){
    int i, j;
    int max = INT_MIN;
    for(i=0; i<size; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    int b[max+1];
    
    for(i=0; i<max+1; i++){
        b[i] = 0;
    }

    for(j=0; j<size; j++){
        b[arr[j]]++;
    }
    i=j=0;

    while(i<max+1){
        if(b[i] > 0){
            arr[j] = i;
            b[i]--;
            j++;
        } else {
            i++;
        }
    }
}

int partition(int * arr, int low, int high){
    int temp;
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do {
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

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int * arr, int low, int high){
    if(low<high){
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void bubbleSort(int * arr, int size){
    int temp;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int * arr, int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int * arr, int size){
    int temp;
    for(int i=0; i<size; i++){
        int min = i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    int arr[] = {10,9,3,2,0,6,4,3,1,5,8};
    int arr2[] = {10,9,3,2,0,6,4,3,1,5,8};
    int arr3[] = {10,9,3,2,0,6,4,3,1,5,8};
    int arr4[] = {10,9,3,2,0,6,4,3,1,5,8};
    int arr5[] = {10,9,3,2,0,6,4,3,1,5,8};
    int arr6[] = {10,9,3,2,0,6,4,3,1,5,8};
    int size = 11;
    
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
    std::cout << std::endl;
    std::cout << "mergeSort - Sorted array" << std::endl;
    printArray(arr5, size);
    mergeSort(arr5, 0, size-1);
    printArray(arr5,size);
    std::cout << "countSort - Sorted array" << std::endl;
    printArray(arr6, size);
    countSort(arr6, size);
    printArray(arr6,size);

    return 0;
}