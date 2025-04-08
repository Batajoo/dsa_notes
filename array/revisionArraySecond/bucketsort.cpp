#include <iostream>
#include <vector>

using namespace std;

void bucketSort(double arr[], int n);
void insertionSort(vector<double> &buckets);

int main(){
    double arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


void bucketSort(double arr[], int n){
    vector<vector<double>> b(n);

    for(int i = 0; i<n ;i++){
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for(vector<double> &n: b){
        insertionSort(n);
    }

    int index = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < b[i].size(); j++){
            arr[index++] = b[i][j];
        }
    }

}


void insertionSort(vector<double> &buckets){
    int n = buckets.size();
    for(int i = 1; i<n; i++){
        double key = buckets[i];
        int j = i - 1;
        while(j >= 0 && buckets[j] > key){
            buckets[j+1] = buckets[j];
            j--;
        }
        buckets[j + 1] = key;
    }
}