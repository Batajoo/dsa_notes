#include<bits/stdc++.h>

using namespace std;

//naive approach
void reverseArray(std::vector<int> &arr){
    std::vector<int> temp;
    for(auto it = arr.end()-1; it != arr.begin(); it--){
        temp.push_back(*it);
    }
    arr.swap(temp);
}

//two pointer approach
void reverseArrayTwoPointer(std::vector<int> &arr){
    int left = 0;
    int right = arr.size() -1, temp;
    while(left < right){
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

//swapping approach

void reverseArraySwap(std::vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n/2; i++){
        std::swap(arr[i], arr[n-i-1]);
    }
}

//recursive approach

void reverseArrayRecursive(std::vector<int> &arr, int l, int r){
    if(l >= r){
        return;
    }
    std::swap(arr[l], arr[r]);
    reverseArrayRecursive(arr, ++l, --r);
}
int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5, 1 };

    // reverseArraySwap(arr);
    reverseArrayRecursive(arr, 0, arr.size()-1);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}