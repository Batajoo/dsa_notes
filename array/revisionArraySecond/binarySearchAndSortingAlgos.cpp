#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int binarySearch(vector<int> *, int);
void displayVector(vector<int> *);
void selectionSort(vector<int> *);
void insertionSort(vector<int> *);
void generateRandomArray(vector<int> *, int);

int main(){
    vector<int> arr1;
    generateRandomArray(&arr1, 10);

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

    insertionSort(&arr1);
    displayVector(&arr1);
    

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

void insertionSort(vector<int> * arr){
    int n = arr->size();
    for(int i = 1; i<n; i++){
        int key = arr->at(i);
        int j = i - 1;
        while(j>=0 && arr->at(j) > key){
            arr->at(j+1) = arr->at(j);
            j--;
        }
        (*arr)[j+1] = key;
    }
}

void generateRandomArray(vector<int> *arr, int size){
    random_device myDevice;
    uniform_int_distribution<int> random_number_range (0, 20);
    int counter = 0;
    while(counter < size){
        int randomNumber = random_number_range(myDevice);
        arr->push_back(randomNumber);
        counter++;
    }
}
