#include <bits/stdc++.h>

using namespace std;

//right rotation in array


//rotate one by one method 
//time complexity - O(n*d);
//space complexity = O(1)
void rotateArr(std::vector<int> &arr, int d){
    int lastEl;
    int n = arr.size();

    for(int i=0; i<d; i++){
        lastEl = arr[n-1];
        for(int j=n-1;j>0;j--){
            arr[j] = arr[j-1];
        }
        arr[0] = lastEl;
    }
}

 

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6};
    int d = 2;

    rotateArr(arr, d);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}