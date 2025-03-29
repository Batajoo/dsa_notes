#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> *, int);
void displayVector(vector<int> *);
void selectionSort(vector<int> *);
void insertionSort(vector<int> *);

int main(){
    vector<int> arr1 {1,4,2,10,9,23,8,3,5,6};
    displayVector(&arr1);

    /*
    // for binarySearch test

    sort(arr1.begin(), arr1.end());
    displayVector(&arr1);
    cout << binarySearch(&arr1, 6);

    */

    /*
    // for selection sort
    
    selectionSort(&arr1);
    displayVector(&arr1);

    */
    

    return 0;
}

int binarySearch(vector<int> * arr, int value){
    int first = 0;
    int last = arr->size() - 1;
    
    while(first <= last){
        int middle = last - (last - first)/2;
        if((*arr)[middle] == value) return middle;
        else if((*arr)[middle] > value) last = middle - 1;
        else first = middle + 1;
    }
}

void displayVector(vector<int> * arr){
    for(int item: *arr){
        cout << item << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> *arr){
    int n = arr->size();
    for(int i=0; i<n; i++){
        int minIndex = i;

        for(int j=i+1; j<n; j++){
            if(arr->at(j) < (*arr)[minIndex]) minIndex = j;
        }

        swap((*arr)[i], (*arr)[minIndex]);
    }
}