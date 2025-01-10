#include<iostream>
#include<vector>

using namespace std;

void insertionSort(int * arr, int size){
    for(int i=1; i<size; i++){
        int j=i-1;
        int val = arr[i];
        while(j>=0 && arr[j]>val){
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = val;
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
