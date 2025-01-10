#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j= high;
    
    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }

    }while(i<j);

    swap(arr[j], arr[low]);
    return j;
}


int partition2(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low;j<=high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}


void quickSort(vector<int> &arr, int low, int high){
    if(low<high){
        int partitionIndex = partition2(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}