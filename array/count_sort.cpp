#include<iostream>
#include<climits>

void printArray(int* arr, int size){
    std::cout << "-----------------------------" << std::endl;
    for(int i=0; i<size; i++){
        std::cout << arr[i] << " ";
    }
        std::cout << std::endl << "-----------------------------" << std::endl;
}

int maximum(int * arr, int n){
    int max = INT_MIN;
    for(int i=0;i<n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }   
    return max;
}

void count_sort(int * arr, int size){
    int i, j;
    int max = maximum(arr, size);   
    int * count = new int[max+1];
    for(i=0; i<max+1; i++){
        count[i] = 0;
    }
    
    for(i=0; i<size; i++){
        count[arr[i]]++;
    }

    i = 0;
    j = 0;

    while(i<=max){
        if(count[i]>0){
            arr[j] = i;
            count[i]--;
            j++;
        }
        else {
            i++;
        }
    }


}

int main(){
    int arr[] = {10,9,3,2,0,6,4,3,1,5,8};
    int size = 11;
    // bubble sort unadaptive part
    std::cout << "Unsorted array" << std::endl;
    printArray(arr, size);
    count_sort(arr, size);
    std::cout << "Sorted array" << std::endl;
    printArray(arr, size);
     std::cout << std::endl;
    return 0;
}